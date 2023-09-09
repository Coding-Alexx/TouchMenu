#pragma once

#include "Item.h"
#include <array>

// https://diyusthad.com/image2cpp
class Icon: public Item {
    const uint16_t w;
    const uint16_t h;
    const uint8_t* bitmap;
    const Color color;

public:
    Icon(const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& color = Color(0,0,0));
    static Icon* create(const std::string str);
    void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) override;
    void drawOn(uint16_t x, uint16_t y, Display* disp) override;
    void drawOff(uint16_t x, uint16_t y, Display* disp) override;
};