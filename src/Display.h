#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#include "Color.h"

#pragma once

class Display {
public:
    Display (const uint8_t pin_tft_CS, const uint8_t pin_tft_DC);
    Display (const Display& other);
    Display& operator= (const Display& other);
    
    void init();

    
    /*-----------------------------------------------------------------------------------------*/

    // pos_x    pos_y  size_x   size_y  border  border_color  radius    infill_color
    void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius, const Color* infill_color);
    void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius);
    void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color);

    // pos_x    pos_y   d   border  border_color    infill_color
    void circle (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color, const Color* infill_color);
    void circle (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color);

    // pos_x    pos_y  size_x   size_y  text_size
    void text(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color);
    void text_center(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color);

    // x1   y1  x2  y2  wide    color
    void line(const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color* color);

    // x1   y1    color
    void point(const uint16_t x1, const uint16_t y1, const Color* color);

    /*-----------------------------------------------------------------------------------------*/

    int16_t height;
    int16_t wigth;

private:
    Adafruit_ILI9341 tft;
};
