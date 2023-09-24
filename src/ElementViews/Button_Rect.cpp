#include "Button_Rect.h"
#include <algorithm>

Button_Rect::Button_Rect(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, ExternalButtonValue* const value):
    Button(button_callback, value),
    color(color),
    itemOn(Display::createItem(itemOn, color.getItemColor())),
    itemOff(Display::createItem(itemOff, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

Button_Rect::Button_Rect(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value):
    Button(button_callback, longpress_callback, value),
    color(color),
    itemOn(Display::createItem(itemOn, color.getItemColor())),
    itemOff(Display::createItem(itemOff, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

Button_Rect::Button_Rect(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value):
    Button(switch_callback, value),
    color(color),
    itemOn(Display::createItem(itemOn, color.getItemColor())),
    itemOff(Display::createItem(itemOff, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

Button_Rect::Button_Rect(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value):
    Button(switch_callback, longpress_callback, value),
    color(color),
    itemOn(Display::createItem(itemOn, color.getItemColor())),
    itemOff(Display::createItem(itemOff, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

Button_Rect::Button_Rect(const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, ExternalButtonValue* const value):
    Button(button_callback, value),
    color(color),
    itemOn(Display::createItem(item, color.getItemColor())),
    itemOff(Display::createItem(item, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

Button_Rect::Button_Rect(const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value):
    Button(button_callback, longpress_callback, value),
    color(color),
    itemOn(Display::createItem(item, color.getItemColor())),
    itemOff(Display::createItem(item, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

Button_Rect::Button_Rect(const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value):
    Button(switch_callback, value),
    color(color),
    itemOn(Display::createItem(item, color.getItemColor())),
    itemOff(Display::createItem(item, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

Button_Rect::Button_Rect(const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value):
    Button(switch_callback, longpress_callback, value),
    color(color),
    itemOn(Display::createItem(item, color.getItemColor())),
    itemOff(Display::createItem(item, color.getSecondaryItemColor())),
    borderRadius(borderRadius),
    borderSize(borderSize)
    {}

Button_Rect::~Button_Rect() {
    delete itemOn;
    delete itemOff;
}

bool Button_Rect::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {
    // TODO: anpassen
    const uint8_t offset = t - borderSize*2;
    itemOn->setResolution(sizeX - offset, sizeY - offset);
    itemOff->setResolution(sizeX - offset, sizeY - offset);
    return sizeX > 30 && sizeY > 30;
}
uint16_t Button_Rect::getHeight(){
    return sizeX;
}

uint16_t Button_Rect::getWidth(){
    return sizeY;
}

void Button_Rect::draw() {
    if (value){
        display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - t, sizeY - t, borderSize, borderRadius, color.getBorderColor(), color);
        
        if (externalValue && externalValue->hasItemOn()) display->drawItem(posX + sizeX/2, posY + sizeY/2, externalValue->getItemOn());
        else display->drawItem(posX + sizeX/2, posY + sizeY/2, itemOn);

    } else {
        display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - t, sizeY - t, borderSize, borderRadius, color.getSecondaryBorderColor(), color.getSecondaryColor());
        
        if (externalValue && externalValue->hasItemOff()) display->drawItem(posX + sizeX/2, posY + sizeY/2, externalValue->getItemOff());
        else display->drawItem(posX + sizeX/2, posY + sizeY/2, itemOff);
    }
}