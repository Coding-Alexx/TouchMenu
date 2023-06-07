#include <Arduino.h>
#include "Element.h"

void Element::setPosition(uint16_t posX, uint16_t posY) {
    this->posX = posX;
    this->posY = posY;
}

bool Element::setSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {
    //if (!checkSize(sizeX, sizeY, rotation)) return false;
    
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->rotation = rotation;

    return true;
}

void Element::setDisplay(Display* const disp) {
    display = disp;
}

Element::~Element() {}
Element::Element() {}