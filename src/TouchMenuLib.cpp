#include "TouchMenuLib.h"
#include "Config.h"

#ifndef TOUCH_INPUT_TIMER
    #define TOUCH_INPUT_TIMER 300
#endif

TouchMenuLib::TouchMenuLib (): 
    display(new DisplayTFTeSPI())
    {}

TouchMenuLib::TouchMenuLib (Display* disp): 
    display(disp) 
    {}

TouchMenuLib::~TouchMenuLib (){
    delete display;
}

// init menu and display
void TouchMenuLib::init(uint8_t rotation) {
    display->init();
    display->setRotation(rotation);
    isDisplayInit = true;
    LOGGER("Touch Menu is initialized")
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
    // LOGGER("Füge neuen Schreen + Sitebar hinzu")
    add (id, screen);
    if (sitebars.count(sitebarID) == 0) {
        LOGGER_ERROR_PATTERN("Sitebar id _ doesn't exists", sitebarID)
        return;
    }
    
    Screen* sitebar = sitebars[sitebarID].get();
    
    // calculate the size of the Screen
    uint16_t w = (sitebar->getResolutionWidth() == display->getWidth()) ? display->getWidth() : display->getWidth() - sitebar->getResolutionWidth();
    uint16_t h = (sitebar->getResolutionHeight() == display->getHeight()) ? display->getHeight() : display->getHeight() - sitebar->getResolutionHeight();
    uint16_t x = (sitebar->getOffsetX() == 0 && w != display->getWidth()) ? sitebar->getResolutionWidth() : 0;
    uint16_t y = (sitebar->getOffsetY() == 0 && h != display->getHeight()) ? sitebar->getResolutionHeight() : 0;

    // LOGGER_PATTERN("Berechnete größen: x:_, y:_, w:_, h:_", x, y, w, h)
    
    screens[id].get()->setResolution(w, h);
    screens[id].get()->setOffsetPosition(x, y);

    sitebarConnector[id] = sitebarID;
}

void TouchMenuLib::addSitebar (const uint8_t id, Screen* sitebar, uint16_t size, uint8_t site) {
    // LOGGER("füge neue Sitebar hinzu")
    if (!isDisplayInit) init();

    if (!sitebar) {
        LOGGER_ERROR("screen Pointer ist NULL")
        return;
    }

    sitebar->setDisplay(display);

    std::unique_ptr<Screen> uptr (sitebar);
    sitebars[id] = std::move(uptr);

    // LOGGER("berechne größen")

    // Sitebar is up
    if (site == 0  || site > 3) {
        sitebar->setResolution(display->getWidth(), size);
        sitebar->setOffsetPosition(0, 0);

    // Sitebar is right
    } else if (site == 1) {
        sitebar->setResolution(size, display->getHeight());
        sitebar->setOffsetPosition(display->getWidth()-size, 0);

    // Sitebar is down
    } else if (site == 2) {
        sitebar->setResolution(size, display->getHeight());
        sitebar->setOffsetPosition(0, display->getHeight()-size);

    // Sitebar is left
    } else if (site == 3) {
        sitebar->setResolution(size, display->getHeight());
        sitebar->setOffsetPosition(0, 0);
    }
}

// gehe i Schritte in der Histroy zurück
void TouchMenuLib::back(const uint8_t i){
    LOGGER("go back")
    // TODO: gehe max. bis zum Homescreen (erstes Element im Stack zurück)
    for(int j = i; j > 0 && screenHistory.size() > 1; j--) {
        screenHistory.pop();
    }
    updateAll = true;
}

// jehe zum Screen id, wenn toHistory=false, dann will man keine neue Ebene in der History
bool TouchMenuLib::goTo(const uint8_t id, const bool toHistory){
    LOGGER_PATTERN("goTo Screen _", id)
    if (screens.count(id) == 0) return false;

    if (!toHistory) screenHistory.pop();
    screenHistory.push(id);
    updateAll = true;
    return true;
}

void TouchMenuLib::loop(){

    if (updateAll) {
        // if (currentSitebar == UINT8_MAX) LOGGER_PATTERN("zeichne Screen _ und keine Sitebar", screenHistory.top())
        // else LOGGER_PATTERN("zeichne Screen _ und Sitebar _", screenHistory.top(), currentSitebar)
        draw();
        updateAll = false;
    }

    if (screens.size() == 0) {
        // LOGGER_ERROR("No Screen found")
        return;
    }

    // set touch coordinates 
    input.isTouched = display->getTouch(&input.touchX, &input.touchY);

    // touch input counter
    if (input.isTouched && inputTimer < millis()) {
        input.updateTouchPoint = true;
        // if (input.isTouched) display->circle(input.touchX, input.touchY, 4, 0, COLOR_BLACK, COLOR_BLACK);
        inputTimer = millis() + TOUCH_INPUT_TIMER;
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

    // Exit screensaver: reset Screensaver timer
    if (isScreensaverEnable && input.hasInput() && screensaverTimer == 0) {
        LOGGER("reset Screensaver timer")
        screensaverTimer = millis() + screensaverTime;

        // go back if this option is active
        if (screensaverBackOnInput) {
            back();
            return;
        }
    }

    // Update main Screen
    screens[screenHistory.top()]->loop(input);
    if (input.back > 0) back(input.back);
    else if (input.update) {
        LOGGER("Zeichne Screen neu")
        screens[screenHistory.top()]->draw();
        input.update = false;
    }

    // Update Sitebar
    if (currentSitebar != UINT8_MAX) {
        sitebars[currentSitebar]->loop(input);
        if (input.back > 0) back(input.back);
        else if (input.update) {
            LOGGER("Zeichne Sitebar neu")
            sitebars[currentSitebar]->draw();
        }
    }

    input.reset();
}

void TouchMenuLib::draw() {
    // LOGGER("Zeichne Menu")
    if (screenHistory.empty()) return;
    screens[screenHistory.top()]->draw(); // draw current Screen

    if (!disableSitebarAutomatic && sitebarConnector.count(screenHistory.top()) != 0) 
        currentSitebar = sitebarConnector[screenHistory.top()];
    
    if (!disableSitebarAutomatic && sitebarConnector.count(screenHistory.top()) == 0)
        currentSitebar = UINT8_MAX;
    
    // if sitebar is available, draw this too
    if (currentSitebar != UINT8_MAX)
        sitebars[currentSitebar]->draw();
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

// set Sitebar for curent Screen
bool TouchMenuLib::setSitebar (const uint8_t sitebarID, const bool disableAutomatic) {
    if (sitebars.count(sitebarID) == 0) return false;
    
    disableSitebarAutomatic = disableAutomatic;
    currentSitebar = sitebarID;
    updateAll = true;
    return true;
}

bool TouchMenuLib::enableSitebar () {
    disableSitebarAutomatic = false;
    updateAll = true;
    return false;
}

void TouchMenuLib::disableSitebar (const bool deactivate) {
    currentSitebar = UINT8_MAX;
    disableSitebarAutomatic = true;
    updateAll = true;
}

uint8_t TouchMenuLib::getScreenID() {
    return screenHistory.top();
}

uint8_t TouchMenuLib::getScreensNumber() {
    return screens.size();
}