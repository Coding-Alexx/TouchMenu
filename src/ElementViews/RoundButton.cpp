#include "RoundButton.h"
#include <algorithm>

RoundButton::RoundButton(const Color& infill, const Color& border, const button_func_ptr button_callback) : 
    Button(button_callback),
    infill(infill), 
    border(border){}

RoundButton::RoundButton(const Color& infill, const Color& border, const switch_func_ptr switch_callback) : 
    Button(switch_callback),
    infill(infill),
    border(border){}

RoundButton::RoundButton(const switch_func_ptr switch_callback) : 
    Button(switch_callback),
    infill(COLOR_WHITE),
    border(COLOR_BLUE){}

void RoundButton::loop() {}

bool RoundButton::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {
    // TODO: anpassen

    return sizeX > 50 && sizeY > 50;
}

void RoundButton::draw() {
    LOGGER_PATTERN("Zeichne Runden Button, value=_", value)
    uint16_t d = std::min(sizeX, sizeY);

    if (value) display->circle(posX + sizeX/2, posY + sizeY/2, d, 2, border);
    else display->circle(posX + sizeX/2, posY + sizeY/2, d, 2, border, infill);
}