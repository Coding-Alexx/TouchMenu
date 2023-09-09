#pragma once

#include "Item.h"
#include "../Display.h"

class Text : public Item {
private:
    const uint8_t size;
    const Color color;
    const char* text;

public:
    Text(const char* text, Display* const display, const Color& color = Color(0, 0, 0), uint8_t size = 1);

    void draw(uint16_t x, uint16_t y, const Color& color) override;
    void draw(uint16_t x, uint16_t y) override;
    void drawOn(uint16_t x, uint16_t y) override;
    void drawOff(uint16_t x, uint16_t y) override;
};
