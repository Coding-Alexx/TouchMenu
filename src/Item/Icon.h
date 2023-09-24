#pragma once

#include "Item.h"
#include <array>

// https://diyusthad.com/image2cpp
class Icon: public Item {
    const unsigned char** bitmap;
    const Color color;

    uint8_t resolution = 0;

public:
    Icon(const unsigned char** bitmap, const uint16_t w, const uint16_t h, const double scale = 1, const Color& color = Color(0,0,0));
    Icon(const unsigned char** bitmap, const double scale = 1, const Color& color = Color(0,0,0));
    static Icon* create(const std::string str, const double scale, const Color& color);
    void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) override;
    void draw(uint16_t x, uint16_t y, Display* disp) override;
    void drawOn(uint16_t x, uint16_t y, Display* disp) override;
    void drawOff(uint16_t x, uint16_t y, Display* disp) override;

    uint16_t getWith() override;
    uint16_t getHeight() override;

    void setResolution(const uint16_t width, const uint16_t height, const bool override = false) override;
};