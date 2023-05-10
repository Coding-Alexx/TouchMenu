#include "TouchMenuLib.h"

TouchMenuLib::TouchMenuLib (const size_t heigth, const size_t wigth): 
    resolutionHeigth(heigth),
    resolutionWigth(wigth)
    {}
    
TouchMenuLib::~TouchMenuLib (){}


void TouchMenuLib::init() {
    
}

void TouchMenuLib::add (uint8_t id, Screen* screen) {
    
    // Auflösung setzen, falls 0 oder zu groß
    if (screen->getResolutionHeight() == 0 || screen->getResolutionHeight() == 0 || screen->getResolutionHeight() > resolutionHeigth || screen->getResolutionWidth() > resolutionWigth) {
        screen->setResolution(resolutionHeigth, resolutionWigth);
    }

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