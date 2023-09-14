#include <Arduino.h>
#include <algorithm>
#include "../Elements/Textbox.h"
#include "../Color.h"

#pragma once

class Textbox_Rect: public Textbox {
public:
    inline Textbox_Rect(char* text, const Color& color, uint8_t textSize, char* const value=nullptr):
        Textbox(text, value),
        color(color),
        size(textSize)
    {}

    inline ~Textbox_Rect () {
        delete text;
    }

    inline void draw() {
        display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - t*2, sizeY - t*2, b, r, color.getBorderColor(), color);
        display->text_center(posX + sizeX/2, posY + sizeY/2, 1, text, color.getItemColor());
    }
        // Getter methods
    char* getText() const {
        return text;
    }

    Color getColor() const {
        return color;
    }

private:
    inline bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override {
        // TODO: prüfe, ob Textgröße hier rein passt
        return true;
    }

    const Color color;
    uint8_t size = 1;

    const uint16_t t = 10; // distance to border
    const uint16_t b = 10; // border
    const uint16_t r = 6; // border radius
};