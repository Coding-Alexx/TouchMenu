#pragma once

#include "Item.h"

class Symbol: public Item {
private:
    uint16_t width;
    uint16_t height;
    uint8_t borderSize;
    Color color;

    typedef void (*symbol_func_ptr) (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color);
    symbol_func_ptr drawSymbol;

public:
    Symbol(const symbol_func_ptr symbol, uint16_t width, uint16_t height, const Color& color = Color(0, 0, 0), uint8_t borderSize = 0);

    static Symbol* create(const std::string& symbol, uint16_t width, uint16_t height, const Color& color = Color(0, 0, 0), uint8_t borderSize = 0, const double scale = 1);
    
    void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) override;
    void draw(uint16_t x, uint16_t y, Display* disp) override;

    void drawOn(uint16_t x, uint16_t y, Display* disp) override;
    void drawOff(uint16_t x, uint16_t y, Display* disp) override;

    void setResolution(const uint16_t width, const uint16_t height, const bool override = false) override;
    void setSize(const uint8_t borderSize, const bool override) override;

    uint16_t getWith() override;
    uint16_t getHeight() override;
    uint8_t getSize() override;
};