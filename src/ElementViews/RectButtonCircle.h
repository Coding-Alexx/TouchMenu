#include <Arduino.h>
#include "../Elements/Button.h"
#include "../Color.h"

#pragma once

class RectButtonCircle: public Button {
public:
    RectButtonCircle(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& border, const uint8_t borderRadius, const button_func_ptr button_callback, bool* const value=nullptr);
    RectButtonCircle(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& borderOn, const Color& borderOff,  const uint8_t borderRadius, const button_func_ptr button_callback, bool* const value=nullptr);
    RectButtonCircle(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& border,   const uint8_t borderRadius,const switch_func_ptr switch_callback, bool* const value=nullptr);
    RectButtonCircle(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& borderOn, const Color& borderOff,  const uint8_t borderRadius, const switch_func_ptr switch_callback, bool* const value=nullptr);
    void loop();
    void draw() override;
    uint16_t getHeight();
    uint16_t getWidth();

private:
    bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override;
    const Color colorInfillOn;
    const Color colorInfillOff;
    const Color colorBorderOn;
    const Color colorBorderOff;
    const char* textOn;
    const char* textOff;
    const uint8_t borderRadius;
};