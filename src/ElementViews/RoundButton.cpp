#include "RoundButton.h"

RoundButton::RoundButton(const Color& infill, const Color& border, const button_func_ptr button_callback) : 
    infill(infill), 
    border(border), 
    Button(button_callback) {}

RoundButton::RoundButton(const Color& infill, const Color& border, const switch_func_ptr switch_callback) : 
    infill(infill),
    border(border), 
    Button(switch_callback) {}

void RoundButton::loop(uint16_t touchX, uint16_t touchY) {
    
}

bool RoundButton::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {
    // TODO: anpassen

    return sizeX > 50 && sizeY > 50;
}

void RoundButton::draw() {
    
}