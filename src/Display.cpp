#include "Display.h"

Display::Display(const uint8_t pin_tft_CS, const uint8_t pin_tft_DC):
    height(tft.height()),
    wigth(tft.width()),
    tft(Adafruit_ILI9341(pin_tft_CS, pin_tft_DC))
{}

Display::Display (const Display& other):
    tft(Adafruit_ILI9341(other.tft)),
    height(other.height),
    wigth(other.wigth)
{}

Display& Display::operator= (const Display& other){
    tft = other.tft;
    height = other.height;
    wigth = other.wigth;
    return *this;
}

void Display::init() {
    tft.begin();
}


/*-----------------------------------------------------------------------------------------*/

// pos_x    pos_y  size_x   size_y  border  border_color  radius    infill_color
void Display::rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius, const Color* infill_color) {
    tft.fillRect(pos_x,pos_y,width, height, *infill_color);
}

void Display::rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius){

}
void Display::rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color){

}

// pos_x    pos_y   d   border  border_color    infill_color
void Display::circle (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color, const Color* infill_color){

}
void Display::circle (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color){

}

// pos_x    pos_y  size_x   size_y  text_size
void Display::text(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color){

}
void Display::text_center(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color){

}

// x1   y1  x2  y2  wide    color
void Display::line(const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color* color){

}

// x1   y1    color
void Display::point(const uint16_t x1, const uint16_t y1, const Color* color){

}

