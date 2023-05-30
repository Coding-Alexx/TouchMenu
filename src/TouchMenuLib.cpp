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

    if (screenHistory.empty()) {
        // print error "at least one screen must be added before init function were called"
        return;
    }

    // nachdem das Display inizialisiert wurde, werden alle nötigen Werte der Screens gesetzt
    for (const auto& screenPair : screens) {
        Screen* screen = screenPair.second.get();
        // Auflösung setzen, falls 0 oder zu groß
        if (screen->getResolutionHeight() == 0 || screen->getResolutionHeight() == 0 || screen->getResolutionHeight() > display->getHeight() || screen->getResolutionWidth() > display->getWigth()) {
            screen->setResolution(display->getHeight(), display->getWigth());
        }
    }

    screens[screenHistory.top()].get()->draw(); // rufe den obersten Screen auf und lasse ihn Zeichnen

    isDisplayInit = true;
}

void TouchMenuLib::add (uint8_t id, Screen* screen) {

    screen->setDisplay(display);

    std::unique_ptr<Screen> uptr (screen);
    screens[id] = std::move(uptr);

    if (isDisplayInit) {
        if (screen->getResolutionHeight() == 0 || screen->getResolutionHeight() == 0 || screen->getResolutionHeight() > display->getHeight() || screen->getResolutionWidth() > display->getWigth()) {
            screen->setResolution(display->getHeight(), display->getWigth());
        }
    }

    screen = nullptr;   // damit der Nutzer keinen Schaden anrichten kann (z.B. pointer löschen)

    // der erste Screen, den man hinzufügt wird auch als Homescreen genutzt
    if (screenHistory.empty()) {
        screenHistory.push(id);
    }
}

void TouchMenuLib::back() {

}
void TouchMenuLib::back(size_t i){

}

bool TouchMenuLib::goTo(size_t id, bool toHistory=true){
    return false;
}

void TouchMenuLib::loop(){

}