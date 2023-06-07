#include <Arduino.h>
#include "../Elements/Button.h"
#include "../Color.h"

#pragma once

class RoundButton: public Button {
public:
    RoundButton(const uint16_t radius, const Color& infill, const Color& border, const button_func_ptr button_callback);
    RoundButton(const uint16_t radius, const Color& infill, const Color& border, const switch_func_ptr switch_callback);
    RoundButton(const uint16_t radius, const switch_func_ptr switch_callback);
    void loop(uint16_t touchX, uint16_t touchY) override;
    void draw() override;

private:
    bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override;
    const Color infill;
    const Color border;
    const uint16_t radius;
};