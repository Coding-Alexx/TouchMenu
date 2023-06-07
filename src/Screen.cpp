#include "Screen.h"

Screen::Screen () {}

void Screen::setResolution(const int16_t h, const int16_t w) {
    height = h;
    width = w;
}

const int16_t Screen::getResolutionHeight(){
    return height;
}

const int16_t Screen::getResolutionWidth(){
    return width;
}

void Screen::setDisplay(Display* const disp) {
    display = disp;
}