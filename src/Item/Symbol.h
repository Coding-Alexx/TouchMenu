#pragma once

#include "Item.h"

class Symbol: public Item {
public:
    inline Symbol() {}
    inline void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) override {};
    void drawOn(uint16_t x, uint16_t y, Display* disp) override {};
    void drawOff(uint16_t x, uint16_t y, Display* disp) override {};
};