#include <Arduino.h>

#include "Logger.h"

#pragma once

#define COLOR_RED           Color(255,   0,   0 )
#define COLOR_GREEN         Color(0,   255,   0 )
#define COLOR_BLUE          Color(0,     0, 255 )
#define COLOR_BLACK         Color(0,     0,   0 )
#define COLOR_WHITE         Color(255, 255, 255 )
#define COLOR_YELLOW        Color(255, 255,   0 )
#define COLOR_MAGENTA       Color(255,   0, 255 )
#define COLOR_CYAN          Color(0,   255, 255 )
#define COLOR_GRAY          Color(128, 128, 128 )
#define COLOR_DARK_RED      Color(128,   0,   0 )
#define COLOR_DARK_GREEN    Color(0,   128,   0 )
#define COLOR_DARK_BLUE     Color(0,     0, 128 )
#define COLOR_DARK_YELLOW   Color(128, 128,   0 )
#define COLOR_DARK_MAGENTA  Color(128,   0, 128 )
#define COLOR_DARK_CYAN     Color(0,   128, 128 )
#define COLOR_LIGHT_RED     Color(255, 128, 128 )
#define COLOR_LIGHT_GREEN   Color(128, 255, 128 )
#define COLOR_LIGHT_BLUE    Color(128, 128, 255 )
#define COLOR_LIGHT_YELLOW  Color(255, 255, 128 )
#define COLOR_LIGHT_MAGENTA Color(255, 128, 255 )
#define COLOR_LIGHT_CYAN    Color(128, 255, 255 )
#define COLOR_ORANGE        Color(255, 165,   0 )
#define COLOR_PURPLE        Color(128,   0, 128 )
#define COLOR_PINK          Color(255, 192, 203 )
#define COLOR_LIME          Color(0,   255,   0 )
#define COLOR_TEAL          Color(0,   128, 128 )
#define COLOR_BROWN         Color(139,  69,  19 )
#define COLOR_NAVY          Color(0,     0, 128 )

class Color {
private:
    const uint8_t red;
    const uint8_t green;
    const uint8_t blue;

public:
    inline Color (const uint8_t r, const uint8_t g, const uint8_t b) : 
        red(r), 
        green(g), 
        blue(b) {};

    //inline Color () : red(0), green(0), blue(0) {};
    inline uint8_t getRed   () const {return red;}
    inline uint8_t getGreen () const {return green;}
    inline uint8_t getBlue  () const {return blue;}

    inline Color& operator= (const Color& other) {
        return *this = Color(other.red, other.green, other.blue);
    }

    inline Color(const Color& other) : 
        red(other.red),
        green(other.green),
        blue(other.blue) {}
    
    inline virtual ~Color() {}

    inline Color operator!() const {
        return Color(255-red, 255-green, 255-blue);
    }

    inline String toString() const {
        return "Color(r=" + String(red) + ", g=" + String(green) + ", b=" + String(blue) + ")";
    }
};