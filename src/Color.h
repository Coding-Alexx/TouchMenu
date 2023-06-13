#include <Arduino.h>

#include "Logger.h"

#pragma once

#define COLOR_RED       Color(255, 0,   0   )
#define COLOR_GREEN     Color(0,   255, 0   )
#define COLOR_BLUE      Color(0,   0,   255 )
#define COLOR_BLACK     Color(0,   0,   0   )
#define COLOR_WHITE     Color(255, 255, 255 )
#define COLOR_YELLOW    Color(255, 255, 0   )

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