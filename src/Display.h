#include <Arduino.h>
#include <array>
#include "Color.h"

#pragma once

class Display {
public:
    virtual ~Display() {};
    virtual void init() = 0;
    
    /*-----------------------------------------------------------------------------------------*/

    // pos_x    pos_y  size_x   size_y  border  border_color  radius    infill_color
    virtual void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color) = 0;
    virtual void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color) = 0;

    // pos_x    pos_y   d   border  border_color    infill_color
    virtual void circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color, const Color& infill_color) = 0;
    virtual void circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color) = 0;

    // pos_x    pos_y  size_x   size_y  text_size
    virtual void text (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const char* text, const Color& text_color) = 0;
    virtual void text_center(const uint16_t pos_x, const uint16_t pos_y, const uint8_t text_size, const char* text, const Color& text_color) = 0;

    // x1   y1  x2  y2  wide    color
    virtual void line(const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color& color) = 0;

    // x1   y1    color
    virtual void point(const uint16_t x1, const uint16_t y1, const Color& color) = 0;

    // color
    virtual void fillScreen(const Color& color) = 0;

    /*-----------------------------------------------------------------------------------------*/

    virtual int16_t getHeight() = 0;
    virtual int16_t getWigth() = 0;

    virtual uint8_t getRotation() = 0;

    virtual int16_t getTouch(uint16_t* x, uint16_t* y) = 0;

    virtual void setGroup(const uint16_t w, const uint16_t h) = 0;
    virtual void drawGroup(const uint16_t x, const uint16_t y) = 0;
};