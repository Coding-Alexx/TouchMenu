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
        setAutoResolution(screen);
    }

    draw();

    isDisplayInit = true;
}

void TouchMenuLib::add (uint8_t id, Screen* screen) {

    screen->setDisplay(display);

    std::unique_ptr<Screen> uptr (screen);
    screens[id] = std::move(uptr);

    if (isDisplayInit) setAutoResolution(screen);

    screen = nullptr;   // damit der Nutzer keinen Schaden anrichten kann (z.B. pointer löschen)

    // der erste Screen, den man hinzufügt wird auch als Homescreen genutzt
    if (screenHistory.empty()) {
        screenHistory.push(id);
    }
}

// gehe i Schritte in der Histroy zurück
void TouchMenuLib::back(size_t i=1){
    for(int j = i; i > 0; i--) {
        screenHistory.pop();
    }
    draw();
}

// jehe zum Screen id, wenn toHistory=false, dann will man keine neue Ebene in der History
bool TouchMenuLib::goTo(size_t id, bool toHistory=true){
    if (screens.count(id) == 0) return false;

    if (!toHistory) screenHistory.pop();
    screenHistory.push(id);
    draw();
    return true;
}

void TouchMenuLib::loop(){

}

void TouchMenuLib::draw() {
    screens[screenHistory.top()].get()->draw(); // rufe den obersten Screen auf und lasse ihn Zeichnen
}

void TouchMenuLib::setAutoResolution(Screen* screen){
    if (screen->getResolutionHeight() == 0 || screen->getResolutionHeight() == 0 || screen->getResolutionHeight() > display->getHeight() || screen->getResolutionWidth() > display->getWigth()) {
        screen->setResolution(display->getHeight(), display->getWigth());
    }
}