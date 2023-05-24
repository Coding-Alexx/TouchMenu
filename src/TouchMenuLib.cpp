#include "TouchMenuLib.h"

TouchMenuLib::TouchMenuLib (Display&& display): 
    display(new Display(display))
{}
    
TouchMenuLib::~TouchMenuLib (){}


void TouchMenuLib::init() {
    
}

void TouchMenuLib::add (uint8_t id, Screen* screen) {
    
    // Auflösung setzen, falls 0 oder zu groß
    if (screen->getResolutionHeight() == 0 || screen->getResolutionHeight() == 0 || screen->getResolutionHeight() > display->height || screen->getResolutionWidth() > display->wigth) {
        screen->setResolution(display->height, display->wigth);
    }

    screen->setDisplay(display);

    std::unique_ptr<Screen> uptr (screen);
    screens[id] = std::move(uptr);
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