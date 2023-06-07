#include "TouchMenuLib.h"

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

    // if (screenHistory.empty()) {
    //     // print error "at least one screen must be added before init function were called"
    //     return;
    // }

    // nachdem das Display inizialisiert wurde, werden alle nötigen Werte der Screens gesetzt
    // for (const auto& screenPair : screens) {
    //     Screen* screen = screenPair.second.get();
    //     // Auflösung setzen, falls 0 oder zu groß
    //     setAutoResolution(screen);
    // }

    //draw();

    isDisplayInit = true;
}

void TouchMenuLib::add (uint8_t id, Screen* screen) {

    if (!isDisplayInit) init();

    if (!screen) {
        LOGGER_ERROR("screen Pointer ist NULL")
        return;
    }

    screen->setDisplay(display);

    std::unique_ptr<Screen> uptr (screen);
    screens[id] = std::move(uptr);

    setAutoResolution(screen);

    screen = nullptr;   // damit der Nutzer keinen Schaden anrichten kann (z.B. pointer löschen)

    // der erste Screen, den man hinzufügt wird auch als Homescreen genutzt
    if (screenHistory.empty()) {
        screenHistory.push(id);
        screenHistoryLevel = 1;
        LOGGER("Ersten Element hinzugefügt");
    }
}

// gehe i Schritte in der Histroy zurück
void TouchMenuLib::back(size_t i){
    // TODO: gehe max. bis zum Homescreen (erstes Element im Stack zurück)
    for(int j = i; j > 0 && screenHistoryLevel > 1; j--) {
        screenHistory.pop();
        screenHistoryLevel--;
    }
    draw();
}

// jehe zum Screen id, wenn toHistory=false, dann will man keine neue Ebene in der History
bool TouchMenuLib::goTo(size_t id, bool toHistory){
    if (screens.count(id) == 0) return false;

    if (!toHistory) screenHistory.pop();
    else screenHistoryLevel++;
    screenHistory.push(id);
    draw();
    return true;
}

void TouchMenuLib::loop(){

}

void TouchMenuLib::draw() {
    if (screenHistoryLevel == 0) return;
    screens[screenHistory.top()]->draw(); // rufe den obersten Screen auf und lasse ihn Zeichnen
}

void TouchMenuLib::setAutoResolution(Screen* screen){

    screen->setResolution(display->getHeight(), display->getWigth());

    // if (screen->getResolutionHeight() == 0 || screen->getResolutionHeight() == 0 || screen->getResolutionHeight() > display->getHeight() || screen->getResolutionWidth() > display->getWigth()) {
    //     screen->setResolution(display->getHeight(), display->getWigth());
    // }
}