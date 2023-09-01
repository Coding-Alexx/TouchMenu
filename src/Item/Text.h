#pragma once

#include "Item.h"

class Text: public Item {
public:
    inline Text(const char* txt) {}
    inline void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) override {}
};