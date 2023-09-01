#pragma once

#include "Item.h"

class Symbol: public Item {
public:
    inline Symbol() {}
    inline void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) override {};
};