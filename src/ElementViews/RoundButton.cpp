#include "RoundButton.h"
#include <algorithm>

RoundButton::RoundButton(const char* itemOn, const char* itemOff, const Color& color, const std::function<void()> button_callback, ExternalButtonValue* const value):
    Button(button_callback, value),
    color(color), 
    itemOn(Display::createItem(itemOn)), 
    itemOff(Display::createItem(itemOff)),
    d(std::min(sizeX, sizeY) * 0.9) 
    {}

RoundButton::RoundButton(const char* itemOn, const char* itemOff, const Color& color, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value):
    Button(switch_callback, value), 
    color(color), 
    itemOn(Display::createItem(itemOn)), 
    itemOff(Display::createItem(itemOff)),
    d(std::min(sizeX, sizeY) * 0.9) 
    {}

RoundButton::~RoundButton () {
    delete itemOn;
    delete itemOff;
}

bool RoundButton::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {
    // TODO: anpassen
    itemOn->setWith(d);
    itemOn->setHeight(d);

    itemOff->setWith(d);
    itemOff->setHeight(d);
    return sizeX > 30 && sizeY > 30;
}

void RoundButton::setTouch(Inputs& input) {
    uint16_t d = std::min(sizeX, sizeY);
    const uint16_t xr = posX + sizeX/2 - d/2;
    const uint16_t yr = posY + sizeY/2 - d/2;
    const uint16_t xl = posX + sizeX/2 + d/2;
    const uint16_t yl = posY + sizeY/2 + d/2;
    if (input.touchX > xr && input.touchX < xl && input.touchY > yr && input.touchY < yl) Button::setTouch(input);
    else LOGGER_PATTERN("Touch punkt bei Runden Button liegt außerhalb: _<_<_, _<_<_", xr, input.touchX, xl, yr, input.touchY, yl)
}

void RoundButton::draw() {
    uint16_t d = std::min(sizeX, sizeY) * 0.9;
 
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