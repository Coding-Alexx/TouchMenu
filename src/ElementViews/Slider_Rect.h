#include <Arduino.h>
#include <algorithm>
#include "../Elements/NumberInput.h"
#include "../Color.h"

#pragma once

class Slider_Rect: public NumberInput {
public:
    inline Slider_Rect(const Color& infillOn_color, const Color& infillOff_color, const Color& slider_color, const Color& border_color, const slider_func_ptr slider_callback, int16_t* const value=nullptr):
        NumberInput(slider_callback, value),
        colorInfillOn(infillOn_color),
        colorInfillOff(infillOff_color),
        colorBorder(border_color),
        colorSlider(slider_color)
    {}

    inline void draw() {

        // uint16_t xl = posX + t + b;
        // uint16_t xr = xl + sizeX - (2*b) - (2*t);

        if (isVertical) {
            uint16_t sy = sizeY - (2*b) - (2*t);
            uint16_t sliderPos = value * sy / maxValue;        

            display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - t*2, sizeY - t*2, b, r, colorBorder, colorInfillOff);
            display->rect(posX + t + b, posY + t + b + sliderPos, sizeX - t*2 - b*2, sizeY - sliderPos - 2*b - 2*t, 0, r, colorBorder, colorInfillOn);
            display->rect_center(posX + sizeX/2, posY + t + b + sliderPos, sizeX - t*2, r * 2, 0, r, colorBorder, colorSlider);
        } else {
            uint16_t sx = sizeX - (2*b) - (2*t);
            uint16_t sliderPos = value * sx / maxValue;        

            display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - t*2, sizeY - t*2, b, r, colorBorder, colorInfillOff);
            display->rect(posX + t + b, posY + t + b, sliderPos, sizeY - t*2 - b*2, 0, r, colorBorder, colorInfillOn);
            display->rect_center(posX + t + b + sliderPos, posY + sizeY/2, r * 2, sizeY - t*2, 0, r, colorBorder, colorSlider);
        }
    }

    inline void setTouch(uint16_t x, uint16_t y) override {
        LOGGER_PATTERN("slider Berührt: X = _ < _ < _,     _ < _ < _", posX, x, posX + sizeX, posY, y, posY + sizeY)

        uint16_t xl = posX + t + b;
        uint16_t xr = xl + sizeX - (2*b) - (2*t);

        uint16_t yl = posY + t + b;
        uint16_t yr = yl + sizeY - (2*b) - (2*t);

        if (!(yl < y && y < yr)) return;
        if (!(xl < x && x < xr)) return;
        if (isVertical) {
            value = (y - yl) * maxValue / (yr-yl);
        } else {
            // value = ((uint32_t)(x) * maxValue) / (posX + sizeX);
            value = (x - xl) * maxValue / (xr-xl);
            
        }

        //value = (value / 5) * 5;

        LOGGER(value)

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

    const Color colorInfillOn;
    const Color colorInfillOff;
    const Color colorBorder;
    const Color colorSlider;
    bool isVertical = false;

    const uint16_t maxValue = 100;
    const uint16_t t = 10; // distance to border
    const uint16_t b = 10; // border
    const uint16_t r = 6; // border radius
};