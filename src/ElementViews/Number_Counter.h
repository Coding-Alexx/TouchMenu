#include <Arduino.h>
#include <algorithm>
#include <string>
#include "../Elements/NumberInput.h"
#include "../Color.h"

#pragma once

class Number_Counter: public NumberInput {
public:
    inline Number_Counter(const char* item1, const char* item2, const Color& color, const bool show_number, const std::function<void(int)> slider_callback, ExternalNumberValue* value=nullptr):
        NumberInput(slider_callback, value),
        color(color),
        item1(Display::createItem(item1, color.getItemColor() + Color(color.getItemColor(), -50))),    //Second color is by default a funkier variant of the main item colour
        item2(Display::createItem(item2, color.getSecondaryItemColor() + Color(color.getSecondaryItemColor(), -50))), 
        showNumber(show_number)
        {}

    inline ~Number_Counter() {
        delete item1;
        delete item2;
    }

    inline void draw() {

        display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - 2*padding, sizeY - 2*padding, borderStrength, borderRadius, color.getBorderColor(), color);
        if (showNumber) {
            char buffer[8];
            snprintf(buffer, sizeof(buffer), "%u", value);
            display->text_center(posX + sizeX/2, posY + sizeY/2, fontSize, buffer, color.getSecondaryBorderColor());
        } 

        drawItems();
    }

    inline void setTouch(Inputs& input) override {

        uint16_t rect1_x1, rect1_y1, rect1_x2, rect1_y2;
        uint16_t rect2_x1, rect2_y1, rect2_x2, rect2_y2;
        auto tmp = value;
        
        if (isVertical) {
            rect1_x1 = posX + padding;
            rect1_y1 = posY + sizeY - triangleHight - triangleDistance;
            rect1_x2 = posX + sizeX - padding;
            rect1_y2 = posY + sizeY - padding;

            rect2_x1 = rect1_x1;
            rect2_y1 = posY + padding;
            rect2_x2 = rect1_x2;
            rect2_y2 = posY + triangleHight + triangleDistance;
        } else {
            rect1_x1 = posX + padding;
            rect1_y1 = posY + padding;
            rect1_x2 = posX + triangleHight + triangleDistance;
            rect1_y2 = posY + sizeY - padding;
            
            rect2_x1 = posX + sizeX - triangleHight - triangleDistance;
            rect2_y1 = rect1_y1;
            rect2_x2 = posX + sizeX - triangleDistance;
            rect2_y2 = rect1_y2;
        }
        
        if (input.touchX >= rect1_x1 && input.touchX <= rect1_x2 && input.touchY >= rect1_y1 && input.touchY <= rect1_y2) {
            LOGGER("Dreieck 1 Berührt");
            if (value > minValue) {
                value = std::max(value - static_cast<int>(steps), minValue);
                if (activateAnimation) timerTriang2 = millis();
            }
        }

        if (input.touchX >= rect2_x1 && input.touchX <= rect2_x2 && input.touchY >= rect2_y1 && input.touchY <= rect2_y2) {
            LOGGER("Dreieck 2 Berührt");
            if (value < maxValue) {
                value = std::min(value + static_cast<int>(steps), maxValue);
                if (activateAnimation) timerTriang1 = millis();
            }
        }

        if (value != tmp) {
            callback(value);
            if (externalValue) externalValue->setValue(value);
            draw();
        }
    }

private:
    inline bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override {
        double x = 1.2;
        if (showNumber) x = 1.4;

        if (sizeY >= x * sizeX) {
            isVertical = true;
            // triangleHight = min((uint16_t)(sizeY/2 - (showNumber*12) - borderDistance), sizeX);
            triangleHight = (sizeY-triangleDistance)/2 - padding - borderStrength;
            if (showNumber) triangleHight -= fontSize*10;

            item1->setResolution(sizeX - 2*padding - 2*borderStrength, triangleHight);
            item2->setResolution(sizeX - 2*padding - 2*borderStrength, triangleHight);

            LOGGER("Slider ist Vertikal")
            return true;
        }

        if (sizeX >= x * sizeY) {    
            LOGGER("Slider ist Horrizontal")
            // triangleHight = min((uint16_t)(sizeX/2- (showNumber*12) - borderDistance), sizeY);
            triangleHight = (sizeX-triangleDistance)/2 - padding - borderStrength;
            if (showNumber) triangleHight -= fontSize*10;

            item1->setResolution(triangleHight, sizeY - 2*padding - 2*borderStrength);
            item2->setResolution(triangleHight, sizeY - 2*padding - 2*borderStrength);

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

        if ((isVertical && timerTriang1 == 0) || (!isVertical && timerTriang2 == 0)) item1->drawOn(x1, y1, display);
        else item1->drawOff(x1, y1, display);

        if ((isVertical && timerTriang2 == 0) || (!isVertical && timerTriang1 == 0)) item2->drawOn(x2, y2, display);
        else item2->drawOff(x2, y2, display);
    }

    inline void loop (Inputs& input) override {
        NumberInput::loop(input);
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

    const uint16_t padding = 5; // distance to border
    const uint16_t borderStrength = 4; // border
    const uint16_t borderRadius = 6; // border radius
    const uint16_t triangleDistance = 1.5*padding + borderStrength;

    const uint8_t fontSize = 3;
    
    uint16_t triangleHight; 
    bool isVertical = false;

    const uint16_t time = 200; // animation time
    bool activateAnimation = true;

    unsigned long timerTriang1 = 0;
    unsigned long timerTriang2 = 0;
};