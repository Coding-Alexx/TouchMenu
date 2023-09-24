#include "Button_Round.h"
#include <algorithm>
#include <cmath>

Button_Round::Button_Round(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const std::function<void()> button_callback, ExternalButtonValue* const value):
    Button(button_callback, value),
    color(color),
    borderSize(borderSize),
    itemOn(Display::createItem(itemOn, color.getItemColor())),
    itemOff(Display::createItem(itemOff, color.getSecondaryItemColor()))
    {}
    
Button_Round::Button_Round(const char* item, const Color& color, const uint8_t borderSize, const std::function<void()> button_callback, ExternalButtonValue* const value):
    Button(button_callback, value),
    color(color),
    borderSize(borderSize),
    itemOn(Display::createItem(item, color.getItemColor())),
    itemOff(Display::createItem(item, color.getSecondaryItemColor()))
    {}
    
Button_Round::Button_Round(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value):
    Button(button_callback, longpress_callback, value),
    color(color),
    borderSize(borderSize),
    itemOn(Display::createItem(itemOn, color.getItemColor())),
    itemOff(Display::createItem(itemOff, color.getSecondaryItemColor()))
    {}
    
Button_Round::Button_Round(const char* item, const Color& color, const uint8_t borderSize, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value):
    Button(button_callback, longpress_callback, value),
    color(color),
    borderSize(borderSize),
    itemOn(Display::createItem(item, color.getItemColor())),
    itemOff(Display::createItem(item, color.getSecondaryItemColor()))
    {}

Button_Round::Button_Round(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value):
    Button(switch_callback, value),
    color(color),
    borderSize(borderSize),
    itemOn(Display::createItem(itemOn, color.getItemColor())),
    itemOff(Display::createItem(itemOff, color.getSecondaryItemColor()))
    {}
    
Button_Round::Button_Round(const char* item, const Color& color, const uint8_t borderSize, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value):
    Button(switch_callback, value),
    color(color),
    borderSize(borderSize),
    itemOn(Display::createItem(item, color.getItemColor())),
    itemOff(Display::createItem(item, color.getSecondaryItemColor()))
    {}
    
Button_Round::Button_Round(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value):
    Button(switch_callback, longpress_callback, value),
    color(color),
    borderSize(borderSize),
    itemOn(Display::createItem(itemOn, color.getItemColor())),
    itemOff(Display::createItem(itemOff, color.getSecondaryItemColor()))
    {}
    
Button_Round::Button_Round(const char* item, const Color& color, const uint8_t borderSize, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value):
    Button(switch_callback, longpress_callback, value),
    color(color),
    borderSize(borderSize),
    itemOn(Display::createItem(item, color.getItemColor())),
    itemOff(Display::createItem(item, color.getSecondaryItemColor()))
    {}
    

Button_Round::~Button_Round () {
    delete itemOn;
    delete itemOff;
}

bool Button_Round::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {
    // TODO: anpassen
    d = std::min(sizeX, sizeY) * scale;
    uint16_t tmp = std::sqrt((d-borderSize) * (d-borderSize) / 2.0);
    itemOn->setResolution(tmp, tmp);
    itemOff->setResolution(tmp, tmp);

    return sizeX > 30 && sizeY > 30;
}

void Button_Round::setTouch(Inputs& input) {
    uint16_t d = std::min(sizeX, sizeY);
    const uint16_t xr = posX + sizeX/2 - d/2;
    const uint16_t yr = posY + sizeY/2 - d/2;
    const uint16_t xl = posX + sizeX/2 + d/2;
    const uint16_t yl = posY + sizeY/2 + d/2;
    if (input.touchX > xr && input.touchX < xl && input.touchY > yr && input.touchY < yl) Button::setTouch(input);
    else LOGGER_PATTERN("Touch punkt bei Runden Button liegt außerhalb: _<_<_, _<_<_", xr, input.touchX, xl, yr, input.touchY, yl)
}

void Button_Round::draw() {
    // uint16_t d = std::min(sizeX, sizeY) * 0.9;
 
    if (value){
        display->circle(posX + sizeX/2, posY + sizeY/2, d, borderSize, color.getBorderColor(), color);

        if (itemOn) display->drawItem(posX + sizeX/2, posY + sizeY/2, itemOn, color.getItemColor());
        else LOGGER_ERROR("itemOn ist nicht gültig!")
    } else {
        display->circle(posX + sizeX/2, posY + sizeY/2, d, borderSize, color.getSecondaryBorderColor(), color.getSecondaryColor());
        
        if (itemOff) display->drawItem(posX + sizeX/2, posY + sizeY/2, itemOff, color.getSecondaryItemColor());
        else LOGGER_ERROR("itemOff ist nicht gültig!")
    }
}

uint16_t Button_Round::getHeight(){
    return sizeX;
}

uint16_t Button_Round::getWidth(){
    return sizeY;
}