#include <Arduino.h>
#include <algorithm>
#include "../Elements/Textbox.h"
#include "../Color.h"

#pragma once

class Textbox_Rect: public Textbox {
public:
    inline Textbox_Rect(char* text, const Color& textColor, const Color& infillColor, const Color& borderColor, char* const value=nullptr):
        Textbox(value),
        colorText(textColor),
        colorInfill(infillColor),
        colorBorder(borderColor)
    {
        this->text = text;
    }

    inline ~Textbox_Rect () {
        delete text;
    }

    inline void draw() {
        display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - t*2, sizeY - t*2, b, r, colorBorder, colorInfill);
        display->text_center(posX + sizeX/2, posY + sizeY/2, 1, text, colorText);
    }
        // Getter methods
    char* getText() const {
        return text;
    }

    Color getColorText() const {
        return colorText;
    }

    Color getColorInfill() const {
        return colorInfill;
    }

    Color getColorBorder() const {
        return colorBorder;
    }

private:
    inline bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override {
        // TODO: prüfe, ob Textgröße hier rein passt
        return true;
    }

    const Color colorText;
    const Color colorInfill;
    const Color colorBorder;

    const uint16_t t = 10; // distance to border
    const uint16_t b = 10; // border
    const uint16_t r = 6; // border radius
};