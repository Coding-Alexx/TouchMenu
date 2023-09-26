#include <Arduino.h>
#include <algorithm>
#include "../Elements/NumberInput.h"
#include "../Color.h"

#pragma once

class Number_Slider: public NumberInput {
public:
    inline Number_Slider(const Color& color, const std::function<void(int)> slider_callback, ExternalNumberValue* value=nullptr):
        NumberInput(slider_callback, value),
        color(color)
    {
        // if (!color.hasSecondaryColor())
        //     this->color = color + !color;
    }

    inline void draw() {

        if (isVertical) {
            uint16_t sy = sizeY - (2*b) - (2*t); // Slider movement length
            // uint16_t sliderPos = value * sy / maxValue;
            uint16_t sliderPos = map(value, minValue-1, maxValue+1, 0, sy);

            display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - t*2, sizeY - t*2, b, r, color.getBorderColor(), color.getSecondaryColor());
            display->rect(posX + t + b, posY + t + b + sliderPos, sizeX - t*2 - b*2, sizeY - sliderPos - 2*b - 2*t, 0, r, color.getBorderColor(), color);
            display->rect_center(posX + sizeX/2, posY + t + b + sliderPos, sizeX - t*2 - b, r * 2, 0, r, color.getBorderColor(), color.getItemColor());
        } else {
            uint16_t sx = sizeX - (2*b) - (2*t); // Slider movement length
            // uint16_t sliderPos = value * sx / maxValue;
            uint16_t sliderPos = map(value, minValue-1, maxValue+1, 0, sx);

            display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - t*2, sizeY - t*2, b, r, color.getBorderColor(), color.getSecondaryColor());
            display->rect(posX + t + b, posY + t + b, sliderPos, sizeY - t*2 - b*2, 0, r, color.getBorderColor(), color);
            display->rect_center(posX + t + b + sliderPos, posY + sizeY/2, r * 2, sizeY - t*2 - b, 0, r, color.getBorderColor(), color.getItemColor());
        }
    }

    inline void setTouch(Inputs& input) override {
        LOGGER_PATTERN("slider Berührt: X = _ < _ < _,     _ < _ < _", posX, input.touchX, posX + sizeX, posY, input.touchY, posY + sizeY)

        uint16_t xl = posX + t + b;                 // left  X value
        uint16_t xr = xl + sizeX - (2*b) - (2*t);   // Right X value

        uint16_t yl = posY + t + b;                 // Left  Y value
        uint16_t yr = yl + sizeY - (2*b) - (2*t);   // Right Y value

        if (!(xl < input.touchX && input.touchX < xr)) return;
        if (!(yl < input.touchY && input.touchY < yr)) return;
        if (isVertical) {
            // value = (input.touchY - yl) * maxValue / (yr-yl);
            value = map(input.touchY, yl, yr, minValue, maxValue);  
        } else {
            // value = (input.touchX - xl) * maxValue / (xr-xl);
            value = map(input.touchX, xl, xr, minValue, maxValue);
        }
        if (externalValue) externalValue->setValue(value);
        callback(value);
        // LOGGER(value)

        draw();
    }

private:
    inline bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override {
        if (sizeY >= 1.5 * sizeX) {
            isVertical = true;
            LOGGER("Slider ist Vertikal")
            return true;
        }

        if (sizeX >= 1.5 * sizeY) {    
            LOGGER("Slider ist Horrizontal")
            return true;
        }

        LOGGER_PATTERN("ERROR: Slider ist nicht Lang genug mit (_, _)", sizeX, sizeY)
        return false;
    }

    const Color color;
    bool isVertical = false;

    const uint16_t t = 5; // distance to border
    const uint16_t b = 4; // border
    const uint16_t r = 6; // border radius
};