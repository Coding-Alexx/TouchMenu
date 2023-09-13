#include "TouchMenuLib.h"
#include "Config.h"

#ifndef TOUCH_INPUT_TIMER
    #define TOUCH_INPUT_TIMER 300
#endif

TouchMenuLib::TouchMenuLib (Display* disp): 
    display(disp)
{
    disp = nullptr;
}

TouchMenuLib::~TouchMenuLib (){
    delete display;
}


void TouchMenuLib::init() {
    display->init();
    isDisplayInit = true;
}

void TouchMenuLib::add (const uint8_t id, Screen* screen) {

    if (!isDisplayInit) init();

    if (!screen) {
        LOGGER_ERROR("screen Pointer ist NULL")
        return;
    }

    screen->setDisplay(display);

    std::unique_ptr<Screen> uptr (screen);
    screens[id] = std::move(uptr);

    screen->setResolution(display->getWidth(), display->getHeight());
    
    // der erste Screen, den man hinzufügt wird auch als Homescreen genutzt
    if (screenHistory.empty()) {
        screenHistory.push(id);
    }
}

void TouchMenuLib::add (const uint8_t id, Screen* screen, const uint8_t sitebarID) {
    if (!screen) return;
    LOGGER("Füge neuen Schreen + Sitebar hinzu")
    add (id, screen);
    Screen* sitebar = sitebars[sitebarID].get();
    
    // calculate the size of the Screen
    uint16_t w = (sitebar->getResolutionWidth() == display->getWidth()) ? display->getWidth() : display->getWidth() - sitebar->getResolutionWidth();
    uint16_t h = (sitebar->getResolutionHeight() == display->getHeight()) ? display->getHeight() : display->getHeight() - sitebar->getResolutionHeight();
    uint16_t x = (sitebar->getOffsetX() == 0 && w != display->getWidth()) ? sitebar->getResolutionWidth() : 0;
    uint16_t y = (sitebar->getOffsetY() == 0 && h != display->getHeight()) ? sitebar->getResolutionHeight() : 0;

    LOGGER_PATTERN("Berechnete größen: x:_, y:_, w:_, h:_", x, y, w, h)
    
    screens[id].get()->setResolution(w, h);
    screens[id].get()->setOffsetPosition(x, y);

    sitebarConnector[id] = sitebarID;

    LOGGER("ADD ENDE")
}

void TouchMenuLib::addSitebar (const uint8_t id, Screen* sitebar, uint16_t size, uint8_t site) {
    LOGGER("füge neue Sitebar hinzu")
    if (!isDisplayInit) init();

    if (!sitebar) {
        LOGGER_ERROR("screen Pointer ist NULL")
        return;
    }

    sitebar->setDisplay(display);

    std::unique_ptr<Screen> uptr (sitebar);
    sitebars[id] = std::move(uptr);

    LOGGER("berechne größen")

    // Sitebar is right
    if (site == 0 || size > 3) {
        sitebar->setResolution(size, display->getHeight());
        sitebar->setOffsetPosition(display->getWidth()-size, 0);

        LOGGER("Sitebar is right")

    // Sitebar is left
    } else if (site == 1) {
        sitebar->setResolution(size, display->getHeight());
        sitebar->setOffsetPosition(0, 0);

    // Sitebar is up
    } else if (site == 2) {
        sitebar->setResolution(display->getWidth(), size);
        sitebar->setOffsetPosition(0, 0);

    // Sitebar is down
    } else if (site == 3) {
        sitebar->setResolution(size, display->getHeight());
        sitebar->setOffsetPosition(0, display->getHeight()-size);
    }
}

// gehe i Schritte in der Histroy zurück
void TouchMenuLib::back(const uint8_t i){
    LOGGER("go back")
    // TODO: gehe max. bis zum Homescreen (erstes Element im Stack zurück)
    for(int j = i; j > 0 && screenHistory.size() > 1; j--) {
        screenHistory.pop();
    }
    draw();
}

// jehe zum Screen id, wenn toHistory=false, dann will man keine neue Ebene in der History
bool TouchMenuLib::goTo(const uint8_t id, const bool toHistory){
    if (screens.count(id) == 0) return false;

    if (!toHistory) screenHistory.pop();
    screenHistory.push(id);
    draw();
    return true;
}

void TouchMenuLib::loop(){
    if (screenHistory.empty()) {
        LOGGER_ERROR("No Screen found")
        return;
    }

    // touch input counter
    if (inputTimer < millis()) {
        // set touch coordinates 
        input.isTouched = display->getTouch(&input.touchX, &input.touchY);
        input.touchY = display->getHeight() - input.touchY;
        if (input.isTouched) inputTimer = millis() + TOUCH_INPUT_TIMER;
    }

    // reset Screensaver time on input
    if (isScreensaverEnable && screensaverTimer != 0 && input.hasInput()) 
        screensaverTimer = millis() + screensaverTime;

    // too long inactivity, go to the screensaver screen 
    if (isScreensaverEnable && screensaverTimer > 0 && screensaverTimer < millis()) {
        LOGGER("go to Screensaver Screen")
        goTo(screensaverID);
        screensaverTimer = 0;
        return;
    }

    // go back from screensaver screen on input
    if (isScreensaverEnable && input.hasInput() && screensaverTimer == 0 && screensaverBackOnInput) {
        LOGGER("gehe zurück zum Standartscreen")
        back();
        screensaverTimer = millis() + screensaverTime;
        return;
    }

    screens[screenHistory.top()]->loop(input);

    // If an element or screen wants a rebuild of the menu
    if (input.update) {
        draw(); 
        LOGGER("Update Menu")
    }

    input.reset();
}

void TouchMenuLib::draw() {
    LOGGER("Zeichne Menu")
    if (screenHistory.empty()) return;
    screens[screenHistory.top()]->draw(); // draw current Screen
    
    // if sitebar is available, draw this too
    if (sitebarConnector.count(screenHistory.top())) 
        sitebars[sitebarConnector[screenHistory.top()]]->draw();
}

void TouchMenuLib::setInputEnter(){
    input.enter = true;
}
void TouchMenuLib::setInputRight(){
    input.right = true;
}
void TouchMenuLib::setInputLeft(){
    input.left = true;
}
void TouchMenuLib::setInputUp(){
    input.up = true;
}
void TouchMenuLib::setInputDown(){
    input.down = true;
}

Display& TouchMenuLib::getDisplay(){
    if (!isDisplayInit) init();
    return *display;
}

void TouchMenuLib::setScreensaver(const uint8_t screenID, unsigned long time, bool backOnInput) {
    isScreensaverEnable = true;
    screensaverBackOnInput = backOnInput;
    screensaverID = screenID;
    screensaverTime = time;
    screensaverTimer = millis() + 2*screensaverTime;
}

bool TouchMenuLib::enableScreenSaver () {
    if (screensaverID != UINT8_MAX) isScreensaverEnable = true;
    return isScreensaverEnable;
}
void TouchMenuLib::disableScreenSaver () {
    isScreensaverEnable = false;
}