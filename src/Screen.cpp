#include "Screen.h"

Screen::Screen () {}

void Screen::setDisplay(Display* const disp) {
    display = disp;
}

void Screen::setResolution(const int16_t w, const int16_t h) {
    height = h;
    width = w;
}

void Screen::setOffsetPosition(int16_t x, int16_t y) {
    offsetX = x;
    offsetY = y;
}

const int16_t Screen::getResolutionHeight() const{
    return height;
}

const int16_t Screen::getResolutionWidth() const{
    return width;
}

const int16_t Screen::getOffsetX() const {
    return offsetX;
}

const int16_t Screen::getOffsetY() const {
    return offsetY;
}