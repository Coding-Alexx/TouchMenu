#pragma once

#include "Item.h"

class Symbol : public Item {
private:
    const uint16_t width;
    const uint16_t height;
    const Color color;

public:
    Symbol(const std::string& symbol, Display* const display, const Color& color = Color(0, 0, 0), uint16_t height = 20, uint16_t width = 20);
    
    void draw(uint16_t x, uint16_t y, const Color& color) override;
    void draw(uint16_t x, uint16_t y) override;
    void drawOn(uint16_t x, uint16_t y) override;
    void drawOff(uint16_t x, uint16_t y) override;
};
