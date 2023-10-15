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
    {}

    inline void draw() {

        if (!display) {
            LOGGER_ERROR("DISPLAY IS NULLPTR!")
            return;
        }

        uint16_t size = isVertical? sizeY : sizeX;
        uint16_t boxes = (uint16_t)(getMaxValue() - getMinValue()) / steps;
        
        // calculate position for the slider
        if (getMaxValue() == getMinValue()) 
            sliderPos = size/2;

        else if (boxes * r > size) 
            sliderPos = map(value, minValue-1, maxValue+1, 0, size); 

        else {
            uint16_t boxSize = size / boxes;
            sliderPos = boxSize * value/steps + boxSize/2;   
        } 

        uint16_t sy = sizeY - (2*b) - (2*t); // Slider movement length
        uint16_t sx = sizeX - (2*b) - (2*t); // Slider movement length

        if (isVertical) {
            display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - t*2, sizeY - t*2, b, r, color.getBorderColor(), color.getSecondaryColor());        // 
            display->rect(posX + t + b, posY + t + b + sliderPos, sx, sy - sliderPos, 0, r, color.getBorderColor(), color);   // 
            display->rect_center(posX + sizeX/2, posY + t + b + sliderPos, sx + b, r * 2, 0, r, color.getBorderColor(), color.getItemColor());     // Slider

            // // Dubug Hitboxes:
            // if (getMinValue() != getMaxValue()) {
            //     uint16_t boxes = (uint16_t)(getMaxValue() - getMinValue()) / steps;
            //     for (int i = 0; i < boxes; i++)
            //         display->line(posX, sizeY/boxes*i + posY + t + b, posX+sizeX, sizeY/boxes*i + posY + t + b, COLOR_RED);
            //     LOGGER(boxes)
            // }

        } else {
            display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - t*2, sizeY - t*2, b, r, color.getBorderColor(), color.getSecondaryColor());
            display->rect(posX + t + b, posY + t + b, sliderPos, sy, 0, r, color.getBorderColor(), color);
            display->rect_center(posX + t + b + sliderPos, posY + sizeY/2, r * 2, sy + b, 0, r, color.getBorderColor(), color.getItemColor());
        }
    }


    // value soll 0 - 10 in 2er schritten abbilden können (also 0, 2, 4, 6, 8, 10)
    // Slider soll dabei auf der Mitte anhalten
    inline void setTouch(Inputs& input) override {
        uint16_t xl = posX + t + b;                 // left  X value
        uint16_t xr = xl + sizeX - (2*b) - (2*t);   // Right X value

        uint16_t yl = posY + t + b;                 // Left  Y value
        uint16_t yr = yl + sizeY - (2*b) - (2*t);   // Right Y value

        if (!(xl < input.touchX && input.touchX < xr)) return;
        if (!(yl < input.touchY && input.touchY < yr)) return;

        int new_value;
        if (isVertical) new_value = map(input.touchY, yl, yr, minValue, maxValue);
        else            new_value = map(input.touchX, xl, xr, minValue, maxValue);

        if (new_value == value) return;
        else value = getMinValue() + (int)((new_value - getMinValue()) / steps) * steps;

        if (externalValue) externalValue->setValue(value);
        callback(value);

        // LOGGER_PATTERN("slider Berührt: X = _ < _ < _,     _ < _ < _, value:_", posX, input.touchX, posX + sizeX, posY, input.touchY, posY + sizeY, value)
        // LOGGER_PATTERN("sliderPos: _, boxes: _, size: _", sliderPos, boxes, (isVertical)? yl - yr : xl - xr)

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

    uint16_t sliderPos = 0;

    const uint16_t t = 3; // distance to border
    const uint16_t b = 2; // border
    const uint16_t r = 6; // border radius
};