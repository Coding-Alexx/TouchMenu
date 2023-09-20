#include "RectButton.h"
#include <algorithm>

RectButton::RectButton(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, ExternalButtonValue* const value):
    Button(button_callback, value),
    color(color),
    itemOn(Display::createItem(itemOn, color.getItemColor())),
    itemOff(Display::createItem(itemOff, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

RectButton::RectButton(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value):
    Button(button_callback, longpress_callback, value),
    color(color),
    itemOn(Display::createItem(itemOn, color.getItemColor())),
    itemOff(Display::createItem(itemOff, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

RectButton::RectButton(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value):
    Button(switch_callback, value),
    color(color),
    itemOn(Display::createItem(itemOn, color.getItemColor())),
    itemOff(Display::createItem(itemOff, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

RectButton::RectButton(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value):
    Button(switch_callback, longpress_callback, value),
    color(color),
    itemOn(Display::createItem(itemOn, color.getItemColor())),
    itemOff(Display::createItem(itemOff, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

RectButton::RectButton(const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, ExternalButtonValue* const value):
    Button(button_callback, value),
    color(color),
    itemOn(Display::createItem(item, color.getItemColor())),
    itemOff(Display::createItem(item, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

RectButton::RectButton(const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value):
    Button(button_callback, longpress_callback, value),
    color(color),
    itemOn(Display::createItem(item, color.getItemColor())),
    itemOff(Display::createItem(item, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

RectButton::RectButton(const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value):
    Button(switch_callback, value),
    color(color),
    itemOn(Display::createItem(item, color.getItemColor())),
    itemOff(Display::createItem(item, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

RectButton::RectButton(const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value):
    Button(switch_callback, longpress_callback, value),
    color(color),
    itemOn(Display::createItem(item, color.getItemColor())),
    itemOff(Display::createItem(item, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

RectButton::~RectButton() {
    delete itemOn;
    delete itemOff;
}

bool RectButton::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {
    // TODO: anpassen
    return sizeX > 30 && sizeY > 30;
}
uint16_t RectButton::getHeight(){
    return sizeX;
}

uint16_t RectButton::getWidth(){
    return sizeY;
}

void RectButton::draw() {    
    const uint8_t t = 10;
    
    if (value){
        display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - t, sizeY - t, borderSize, borderRadius, color.getBorderColor(), color);
        
        if (externalValue && externalValue->hasItemOn()) display->drawItem(posX + sizeX/2, posY + sizeY/2, externalValue->getItemOn());
        else display->drawItem(posX + sizeX/2, posY + sizeY/2, itemOn);

    } else {
        display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - t, sizeY - t, borderSize, borderRadius, color.getSecondaryBorderColor(), color);
        
        if (externalValue && externalValue->hasItemOff()) display->drawItem(posX + sizeX/2, posY + sizeY/2, externalValue->getItemOff());
        else display->drawItem(posX + sizeX/2, posY + sizeY/2, itemOff);
    }
}