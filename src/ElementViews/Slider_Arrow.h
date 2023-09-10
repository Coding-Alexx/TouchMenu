#include <Arduino.h>
#include <algorithm>
#include <string>
#include "../Elements/NumberInput.h"
#include "../Color.h"

#pragma once

class Slider_Arrow: public NumberInput {
public:


    inline Slider_Arrow(const char* item1, const char* item2, const Color& color, const bool show_number, const slider_func_ptr slider_callback, uint16_t* value=nullptr):
        NumberInput(slider_callback, value),
        color(color),
        item1(Display::createItem(item1, Color(color.getItemColor(), -80))),
        item2(Display::createItem(item2, Color(color.getSecondaryItemColor(), -80))),
        showNumber(show_number)
    {}

    inline ~Slider_Arrow() {
        delete item1;
        delete item2;
    }

    inline void draw() {

        // uint16_t xl = posX + t + b;
        // uint16_t xr = xl + sizeX - (2*b) - (2*t);

        char buffer[8];
        snprintf(buffer, sizeof(buffer), "%u", value);

        display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - borderDistance*2, sizeY - borderDistance*2, borderStrength, borderRadius, color.getBorderColor(), color);
        if (showNumber) display->text_center(posX + sizeX/2, posY + sizeY/2, fontSize, buffer, COLOR_BLACK);

        drawItems();
    }

    inline void setTouch(uint16_t x, uint16_t y) override {

        uint16_t rect1_x1, rect1_y1, rect1_x2, rect1_y2;
        uint16_t rect2_x1, rect2_y1, rect2_x2, rect2_y2;
        auto tmp = value;
        
        if (isVertical) {
            rect1_x1 = posX + borderDistance;
            rect1_y1 = posY + sizeY - triangleHight - triangleDistance;
            rect1_x2 = posX + sizeX - borderDistance;
            rect1_y2 = posY + sizeY - borderDistance;

            rect2_x1 = rect1_x1;
            rect2_y1 = posY + borderDistance;
            rect2_x2 = rect1_x2;
            rect2_y2 = posY + triangleHight + triangleDistance;
        } else {
            rect1_x1 = posX + borderDistance;
            rect1_y1 = posY + borderDistance;
            rect1_x2 = posX + triangleHight + triangleDistance;
            rect1_y2 = posY + sizeY - borderDistance;
            
            rect2_x1 = posX + sizeX - triangleHight - triangleDistance;
            rect2_y1 = rect1_y1;
            rect2_x2 = posX + sizeX - triangleDistance;
            rect2_y2 = rect1_y2;
        }
        
        if (x >= rect1_x1 && x <= rect1_x2 && y >= rect1_y1 && y <= rect1_y2) {
            LOGGER("Dreieck 1 Berührt");
            if (value > 0) {
                value --;
                if (activateAnimation) timerTriang2 = millis();
            }
        }

        if (x >= rect2_x1 && x <= rect2_x2 && y >= rect2_y1 && y <= rect2_y2) {
            LOGGER("Dreieck 2 Berührt");
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

        item1->setWith(sizeX - triangleDistance*2);
        item1->setHeight(sizeY - triangleDistance*2);

        item2->setWith(sizeX - triangleDistance*2);
        item2->setHeight(sizeY - triangleDistance*2);

        if (sizeY >= x * sizeX) {
            isVertical = true;
            // triangleHight = min((uint16_t)(sizeY/2 - (showNumber*12) - borderDistance), sizeX);
            triangleHight = (sizeY-triangleDistance)/2;
            if (showNumber) triangleHight -= fontSize*10;

            item1->setHeight(triangleHight);
            item2->setHeight(triangleHight);
            LOGGER("Slider ist Vertikal")
            return true;
        }

        if (sizeX >= x * sizeY) {    
            LOGGER("Slider ist Horrizontal")
            // triangleHight = min((uint16_t)(sizeX/2- (showNumber*12) - borderDistance), sizeY);
            triangleHight = (sizeX-triangleDistance)/2;
            if (showNumber) triangleHight -= fontSize*10;

            item1->setWith(triangleHight);
            item2->setWith(triangleHight);
            return true;
        }

        LOGGER_PATTERN("ERROR: Slider ist nicht Lang genug mit (_, _)", sizeX, sizeY)
        return false;
    }

    inline void drawItems() {

        uint16_t x1, y1, x2, y2;
        if (isVertical) {
            x1 = posX + 0.5*sizeX;
            y1 = posY + triangleDistance + item1->getHeight()/2;
            x2 = posX + 0.5*sizeX;
            y2 = posY + sizeY - triangleDistance - item2->getHeight()/2 ;
        } else {
            x1 = posX + triangleDistance + item1->getWith()/2;
            y1 = posY + 0.5*sizeY;
            x2 = posX + sizeX - triangleDistance - item2->getWith()/2;
            y2 = posY + 0.5*sizeY;
        }

        LOGGER_PATTERN("Zeichne Slider _ mit item1: (_/_) in der größe _,_ und item2: (_/_) in der größe _,_", isVertical? "vertikal":"Horrizontal", x1, y1, item1->getWith(), item1->getHeight(), x2, y2, item2->getWith(), item2->getHeight())

        if ((isVertical && timerTriang1 == 0) || (!isVertical && timerTriang2 == 0)) item1->draw(x1, y1, display, color.getItemColor());
        else item1->draw(x1, y1, display);

        if ((isVertical && timerTriang2 == 0) || (!isVertical && timerTriang1 == 0)) item2->draw(x2, y2, display, color.getSecondaryItemColor());
        else item2->draw(x2, y2, display);
    }

    inline void loop () override {
        NumberInput::loop();
        // LOGGER_PATTERN("LOOP - _ < _", timerTriang2, millis() + time)

        if (!activateAnimation) return;

        if (timerTriang1 != 0 && millis() - timerTriang1 >= time) {
            LOGGER("Setzte Dreieck 1 zurück")
            timerTriang1 = 0;
            drawItems();
        }

        if (timerTriang2 != 0 && millis() - timerTriang2 >= time) {
            LOGGER("Setzte Dreieck 2 zurück")
            timerTriang2 = 0;
            drawItems();
        }
    }

    const Color color;
    Item* item1;
    Item* item2;

    const bool showNumber = false;

    const uint16_t borderDistance = 10; // distance to border
    const uint16_t borderStrength = 6; // border
    const uint16_t borderRadius = 6; // border radius
    const uint16_t triangleDistance = 1.5*borderDistance + borderStrength;

    const uint8_t fontSize = 3;
    
    uint16_t triangleHight; 
    bool isVertical = false;

    const uint16_t time = 300; // animation time
    bool activateAnimation = true;

    unsigned long timerTriang1 = 0;
    unsigned long timerTriang2 = 0;
};