#include <Arduino.h>
#include <algorithm>
#include "../Elements/Textbox.h"
#include "../Color.h"

#pragma once

class Textbox_Blank: public Textbox {
public:
    inline Textbox_Blank(const char* itemStr, ExternalTextboxValue* value=nullptr)
        : Textbox(Display::createItem(itemStr), value) {}
    
    inline Textbox_Blank(const char* itemStr, const Color& color, ExternalTextboxValue* value=nullptr)
        : Textbox(Display::createItem(itemStr, color), value) {}
    
    inline Textbox_Blank(const char* itemStr, const uint8_t textsize, const Color& color, ExternalTextboxValue* value=nullptr)
        : Textbox(Display::createItem(itemStr, color), textsize, value) {}

    inline Textbox_Blank(const char* itemStr, const uint8_t textsize, ExternalTextboxValue* value=nullptr)
        : Textbox(Display::createItem(itemStr), textsize, value) {}

    inline Textbox_Blank(Item* item, ExternalTextboxValue* value=nullptr)
        : Textbox(item, value) {}

    inline void draw() override {
        if(externalValue && externalValue->hasValue()) externalValue->draw(posX + sizeX/2, posY + sizeY/2, display);
        else display->drawItem(posX + sizeX/2, posY + sizeY/2, item);
    }

    inline void loop(Inputs& input) override {
        if (externalValue && externalValue->hasUpdate()) {
            LOGGER("Update Blank Textbox")
            input.update = true;
            externalValue->resetUpdate();
        }
    }

private:
    // inline bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override {
    //     return true;
    // }
};