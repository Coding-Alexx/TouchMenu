#include "RoundButton.h"

RoundButton::RoundButton(const uint16_t radius, const Color& infill, const Color& border, const button_func_ptr button_callback) : 
    Button(button_callback),
    infill(infill), 
    border(border),
    radius(radius)
{}

RoundButton::RoundButton(const uint16_t radius, const Color& infill, const Color& border, const switch_func_ptr switch_callback) : 
    Button(switch_callback),
    infill(infill),
    border(border),
    radius(radius)
{}

RoundButton::RoundButton(const uint16_t radius, const switch_func_ptr switch_callback) : 
    Button(switch_callback),
    infill(COLOR_WHITE),
    border(COLOR_BLUE),
    radius(radius)
{}

void RoundButton::loop(uint16_t touchX, uint16_t touchY) {
    
}

bool RoundButton::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {
    // TODO: anpassen

    return sizeX > 50 && sizeY > 50;
}

void RoundButton::draw() {
    display->circle(posX + sizeX/2, posY + sizeY/2, radius, 1, border);
    display->circle(posX, posY, radius, 1, !border);
}