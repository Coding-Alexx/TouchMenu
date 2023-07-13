#include <Arduino.h>
#include "../Elements/Button.h"
#include "../Color.h"

#pragma once

class RoundButton: public Button {
public:
    RoundButton(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& border, const button_func_ptr button_callback, bool* const value=nullptr);
    RoundButton(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& borderOn, const Color& borderOff, const button_func_ptr button_callback, bool* const value=nullptr);
    RoundButton(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& border, const switch_func_ptr switch_callback, bool* const value=nullptr);
    RoundButton(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& borderOn, const Color& borderOff, const switch_func_ptr switch_callback, bool* const value=nullptr);
    void draw() override;
    uint16_t getHeight();
    uint16_t getWidth();
    uint16_t getMidX() const { return posX + sizeX/2; }
    uint16_t getMidY() const { return posY + sizeY/2; }

private:
    bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override;
    const Color colorInfillOn;
    const Color colorInfillOff;
    const Color colorBorderOn;
    const Color colorBorderOff;
    const char* textOn;
    const char* textOff;
};