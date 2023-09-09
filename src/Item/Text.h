#pragma once

#include "Item.h"


class Text: public Item {
    const uint8_t size;
    const Color color;
    const std::string text; // bei einem char* wurde der text irgendwann überschrieben -> Grund nach langem Suchen nicht gefunden
public:
    Text(const std::string text, const Color& color = Color(0, 0, 0), uint8_t size = 1);
    void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) override;
    void drawOn(uint16_t x, uint16_t y, Display* disp) override;
    void drawOff(uint16_t x, uint16_t y, Display* disp) override;
};