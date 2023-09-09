#pragma once

#include "Item.h"

// https://diyusthad.com/image2cpp
class Icon: public Item {
    const uint16_t w;
    const uint16_t h;
    const uint8_t* bitmap;

    Color color;

public:
    Icon(const uint16_t w, const uint16_t h, const uint8_t* bitmap, Display* const display, const Color& color);
    static Icon* create(const std::string str, Display* const display);
    static Icon* create(const std::string str, const Color& color, Display* const display);
    void draw(uint16_t x, uint16_t y, const Color& color) override;
    void draw(uint16_t x, uint16_t y) override;
    void drawOn(uint16_t x, uint16_t y) override;
    void drawOff(uint16_t x, uint16_t y) override;
};