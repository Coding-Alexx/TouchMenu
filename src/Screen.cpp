#include "Screen.h"

Screen::Screen () {}

void Screen::setResolution(const int16_t height, const int16_t width) {
    this->height = height;
    this->width = width;
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