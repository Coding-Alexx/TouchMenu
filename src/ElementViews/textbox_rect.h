#include <Arduino.h>
#include <algorithm>
#include "../Elements/Textbox.h"
#include "../Color.h"

#pragma once

class Textbox_Rect: public Textbox {
public:
    inline Textbox_Rect(char* itemStr, const Color& color, ExternalTextboxValue* value=nullptr):
        Textbox(Display::createItem(itemStr, color.getItemColor()), value), color(color) {}

    inline Textbox_Rect(Item* item, const Color& color, ExternalTextboxValue* value=nullptr):
        Textbox(item, value), color(color) {}

    inline Textbox_Rect(char* itemStr, const uint8_t textsize, const Color& color, ExternalTextboxValue* value=nullptr):
        Textbox(Display::createItem(itemStr, color.getItemColor()), textsize, value), color(color) {}

    inline Textbox_Rect(Item* item, const uint8_t textsize, const Color& color, ExternalTextboxValue* value=nullptr):
        Textbox(item, textsize, value), color(color) {}

    inline void draw() {
        display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - t*2, sizeY - t*2, b, r, color.getBorderColor(), color);
        if(externalValue && externalValue->hasValue()) externalValue->draw(posX + sizeX/2, posY + sizeY/2, display);
        else display->drawItem(posX + sizeX/2, posY + sizeY/2, item);
    }

    Color getColor() const {
        return color;
    }

private:
    const Color color;

    const uint16_t t = 10; // distance to border
    const uint16_t b = 10; // border
    const uint16_t r = 6; // border radius
};