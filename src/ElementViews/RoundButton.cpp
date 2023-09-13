#include "RoundButton.h"
#include <algorithm>
#include <WiFi.h>

RoundButton::RoundButton(const char* itemOn, const char* itemOff, const Color& color, const button_func_ptr button_callback, bool* const value):
    Button(button_callback, value), color(color), itemOn(Display::createItem(itemOn)), itemOff(Display::createItem(itemOff)) {}

RoundButton::RoundButton(const char* itemOn, const char* itemOff, const Color& color, const switch_func_ptr switch_callback, bool* const value):
    Button(switch_callback, value), color(color), itemOn(Display::createItem(itemOn)), itemOff(Display::createItem(itemOff)) {}

RoundButton::~RoundButton () {
    delete itemOn;
    delete itemOff;
}

bool RoundButton::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {
    // TODO: anpassen
    return sizeX > 50 && sizeY > 50;
}

void RoundButton::draw() {
    uint16_t d = std::min(sizeX, sizeY) * 0.9;
    LOGGER_PATTERN("Zeichne Runden Button(state=_) mit d=_, d*0.1=_", value, d, d*0.1)
    LOGGER_PATTERN("Color: _, BorderColor: _, SecColor: _, SecRand: _", color.toString(), color.getBorderColor().toString(), color.getSecondaryColor().toString(), color.getSecondaryBorderColor().toString())
 
    if (value){
        display->circle(posX + sizeX/2, posY + sizeY/2, d, 8, color.getBorderColor(), color);

        if (itemOn) display->drawItem(posX + sizeX/2, posY + sizeY/2, itemOn, color.getItemColor());
        else LOGGER_ERROR("itemOn ist nicht gültig!")
    } else {
        display->circle(posX + sizeX/2, posY + sizeY/2, d, 8, color.getSecondaryBorderColor(), color.getSecondaryColor());
        
        if (itemOff) display->drawItem(posX + sizeX/2, posY + sizeY/2, itemOff, color.getSecondaryItemColor());
        else LOGGER_ERROR("itemOff ist nicht gültig!")
    }
}

uint16_t RoundButton::getHeight(){
    return sizeX;
}

uint16_t RoundButton::getWidth(){
    return sizeY;
}