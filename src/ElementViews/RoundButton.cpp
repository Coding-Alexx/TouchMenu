#include "RoundButton.h"
#include <algorithm>

RoundButton::RoundButton(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& border, const button_func_ptr button_callback, bool* const value):
    Button(button_callback, value),
    colorInfillOn(infillOn),
    colorInfillOff(infillOff),
    colorBorderOn(border),
    colorBorderOff(border),
    textOn(textOn),
    textOff(textOff)
{}
RoundButton::RoundButton(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& borderOn, const Color& borderOff, const button_func_ptr button_callback, bool* const value):
    Button(button_callback, value),
    colorInfillOn(infillOn),
    colorInfillOff(infillOff),
    colorBorderOn(borderOn),
    colorBorderOff(borderOff),
    textOn(textOn),
    textOff(textOff)
{}
RoundButton::RoundButton(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& border, const switch_func_ptr switch_callback, bool* const value):
    Button(switch_callback, value),
    colorInfillOn(infillOn),
    colorInfillOff(infillOff),
    colorBorderOn(border),
    colorBorderOff(border),
    textOn(textOn),
    textOff(textOff)
{}
RoundButton::RoundButton(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& borderOn, const Color& borderOff, const switch_func_ptr switch_callback, bool* const value):
    Button(switch_callback, value),
    colorInfillOn(infillOn),
    colorInfillOff(infillOff),
    colorBorderOn(borderOn),
    colorBorderOff(borderOff),
    textOn(textOn),
    textOff(textOff)
{}

void RoundButton::loop() {}

bool RoundButton::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {
    // TODO: anpassen

    return sizeX > 50 && sizeY > 50;
}

void RoundButton::draw() {
    uint16_t d = std::min(sizeX, sizeY) * 0.9;
    LOGGER_PATTERN("Zeichne Runden Button(state=_) mit d=_, d*0.1=_", value, d, d*0.1)

    display->setGroup(sizeX, sizeY);
    if (value){
        display->circle(sizeX/2, sizeY/2, d, 8, colorBorderOn, colorInfillOn);
        display->text_center(sizeX/2, sizeY/2, d*0.04, textOn, colorBorderOn);
    } else {
        display->circle(sizeX/2, sizeY/2, d, 8, colorBorderOff, colorInfillOff);
        display->text_center(sizeX/2, sizeY/2, d*0.04, textOff, colorBorderOff);
    }
    display->drawGroup(posX, posY);
}