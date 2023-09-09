#include <Arduino.h>
#include <algorithm>
#include <string>
#include "../Elements/NumberInput.h"
#include "../Color.h"

#pragma once

class Slider_Arrow: public NumberInput {
public:
    inline Slider_Arrow(const Color& infill_color, const Color& triangle_color, const Color& border_color, const bool show_number, const slider_func_ptr slider_callback, uint16_t* value=nullptr):
        NumberInput(slider_callback, value),
        colorInfill(infill_color),
        colorTriangleOn(triangle_color.getSecondaryColor()),
        colorTriangleOff(triangle_color),
        colorBorder(border_color),
        showNumber(show_number)
    {}

    inline void draw() {

        // uint16_t xl = posX + t + b;
        // uint16_t xr = xl + sizeX - (2*b) - (2*t);

        char buffer[8];
        snprintf(buffer, sizeof(buffer), "%u", value);

        display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - borderDistance*2, sizeY - borderDistance*2, borderStrength, borderRadius, colorBorder, colorInfill);
        if (showNumber) display->text_center(posX + sizeX/2, posY + sizeY/2, 3, buffer, COLOR_BLACK);

        drawTriangle();
    }

    inline void setTouch(uint16_t x, uint16_t y) override {

        uint16_t rect1_x1, rect1_y1, rect1_x2, rect1_y2;
        uint16_t rect2_x1, rect2_y1, rect2_x2, rect2_y2;
        auto tmp = value;
        
        if (isVertical) {
            rect1_x1 = posX + borderDistance;
            rect1_y1 = posY + sizeY - triangleHight - borderDistance;
            rect1_x2 = posX + sizeX - borderDistance;
            rect1_y2 = posY + sizeY - borderDistance;

            rect2_x1 = rect1_x1;
            rect2_y1 = posY + borderDistance;
            rect2_x2 = rect1_x2;
            rect2_y2 = posY + triangleHight + borderDistance;
        } else {
            rect1_x1 = posX + borderDistance;
            rect1_y1 = posY + borderDistance;
            rect1_x2 = posX + triangleHight + borderDistance;
            rect1_y2 = posY + sizeY - borderDistance;
            
            rect2_x1 = posX + sizeX - triangleHight - borderDistance;
            rect2_y1 = rect1_y1;
            rect2_x2 = posX + sizeX - borderDistance;
            rect2_y2 = rect1_y2;
        }
        
        if (x >= rect1_x1 && x <= rect1_x2 && y >= rect1_y1 && y <= rect1_y2) {
            LOGGER("Dreieck 1 Berührt");
            colorTriangle1 = &colorTriangleOn;
            if (value > 0) {
                value --;
                if (activateAnimation) timerTriang2 = millis();
            }
        }

        if (x >= rect2_x1 && x <= rect2_x2 && y >= rect2_y1 && y <= rect2_y2) {
            LOGGER("Dreieck 2 Berührt");
            colorTriangle2 = &colorTriangleOn;
            if (value < UINT16_MAX) {
                value ++;
                if (activateAnimation) timerTriang1 = millis();
            }
        }

        if (value != tmp) {
            slider_callback(value);
            if (externalValue) *externalValue = value;
            draw();
        }
    }

private:
    inline bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override {
        double x = 1.2;
        if (showNumber) x = 1.4;
        if (sizeY >= x * sizeX) {
            isVertical = true;
            LOGGER("Slider ist Vertikal")
            triangleHight = min((uint16_t)(sizeY/2 - (showNumber*12) - borderDistance), sizeX);
            return true;
        }

        if (sizeX >= x * sizeY) {    
            LOGGER("Slider ist Horrizontal")
            triangleHight = min((uint16_t)(sizeX/2- (showNumber*12) - borderDistance), sizeY);
            return true;
        }

        LOGGER_PATTERN("ERROR: Slider ist nicht Lang genug mit (_, _)", sizeX, sizeY)
        return false;
    }

    inline void drawTriangle() {
        if (isVertical){
            display->triangle(posX + 0.5*sizeX, posY + triangleDistance, posX+triangleDistance, posY+triangleHight, posX+sizeX-triangleDistance, posY+triangleHight, 0, COLOR_BLACK, *colorTriangle2);
            display->triangle(posX + 0.5*sizeX, posY - triangleDistance + sizeY, posX+triangleDistance, posY+sizeY-triangleHight, posX+sizeX-triangleDistance, posY+sizeY-triangleHight, 0, COLOR_BLACK, *colorTriangle1);
        } else {
            display->triangle(posX + triangleDistance, posY + 0.5*sizeY, posX+triangleHight, posY+triangleDistance, posX+triangleHight, posY+sizeY-triangleDistance, 0, COLOR_BLACK, *colorTriangle1);
            display->triangle(posX + sizeX - triangleDistance, posY + 0.5*sizeY, posX+sizeX-triangleHight, posY+triangleDistance, posX+sizeX-triangleHight, posY+sizeY-triangleDistance, 0, COLOR_BLACK, *colorTriangle2);
        }
    }

    inline void loop () override {
        NumberInput::loop();
        // LOGGER_PATTERN("LOOP - _ < _", timerTriang2, millis() + time)

        if (!activateAnimation) return;

        if (timerTriang1 != 0 && millis() - timerTriang1 >= time) {
            LOGGER("Setzte Dreieck 1 zurück")
            timerTriang1 = 0;
            colorTriangle2 = &colorTriangleOff;
            drawTriangle();
        }

        if (timerTriang2 != 0 && millis() - timerTriang2 >= time) {
            LOGGER("Setzte Dreieck 2 zurück")
            timerTriang2 = 0;
            colorTriangle1 = &colorTriangleOff;
            drawTriangle();
        }
    }

    const Color colorInfill;
    const Color colorTriangleOn;
    const Color colorTriangleOff;
    const Color colorBorder;
    const bool showNumber = false;
    const Color* colorTriangle1 = &colorTriangleOff;
    const Color* colorTriangle2 = &colorTriangleOff;

    const uint16_t borderDistance = 10; // distance to border
    const uint16_t borderStrength = 6; // border
    const uint16_t borderRadius = 6; // border radius
    const uint16_t triangleDistance = 2*borderDistance + borderStrength;
    
    uint16_t triangleHight; 
    bool isVertical = false;

    const uint16_t time = 300; // animation time
    bool activateAnimation = true;

    unsigned long timerTriang1 = 0;
    unsigned long timerTriang2 = 0;
};