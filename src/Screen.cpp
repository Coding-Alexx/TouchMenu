#include "Screen.h"

Screen::Screen () = default;

void Screen::setResolution(const size_t height, const size_t width) {
    this->height = height;
    this->width = width;
}

const size_t Screen::getResolutionHeight(){
    return height;
}

const size_t Screen::getResolutionWidth(){
    return width;
}