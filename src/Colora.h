#include <Arduino.h>

#include "Logger.h"

#pragma once

#define COLOR_RED           Color(255,   0,   0)
#define COLOR_GREEN         Color(0,   255,   0)
#define COLOR_BLUE          Color(0,     0, 255)
#define COLOR_BLACK         Color(0,     0,   0)
#define COLOR_WHITE         Color(255, 255, 255)
#define COLOR_YELLOW        Color(255, 255,   0)
#define COLOR_MAGENTA       Color(255,   0, 255)
#define COLOR_CYAN          Color(0,   255, 255)
#define COLOR_GRAY          Color(128, 128, 128)
#define COLOR_DARK_RED      Color(128,   0,   0)
#define COLOR_DARK_GREEN    Color(0,   128,   0)
#define COLOR_DARK_BLUE     Color(0,     0, 128)
#define COLOR_DARK_YELLOW   Color(128, 128,   0)
#define COLOR_DARK_MAGENTA  Color(128,   0, 128)
#define COLOR_DARK_CYAN     Color(0,   128, 128)
#define COLOR_LIGHT_RED     Color(255, 128, 128)
#define COLOR_LIGHT_GREEN   Color(128, 255, 128)
#define COLOR_LIGHT_BLUE    Color(128, 128, 255)
#define COLOR_LIGHT_YELLOW  Color(255, 255, 128)
#define COLOR_LIGHT_MAGENTA Color(255, 128, 255)
#define COLOR_LIGHT_CYAN    Color(128, 255, 255)
#define COLOR_ORANGE        Color(255, 165,   0)
#define COLOR_PURPLE        Color(128,   0, 128)
#define COLOR_PINK          Color(255, 192, 203)
#define COLOR_LIME          Color(0,   255,   0)
#define COLOR_TEAL          Color(0,   128, 128)
#define COLOR_BROWN         Color(139,  69,  19)
#define COLOR_NAVY          Color(0,     0, 128)

class Color;

class Color {
private:
    const uint8_t red;
    const uint8_t green;
    const uint8_t blue;
    Color* secondaryColor;
    Color* textColor;
    Color* borderColor;

    Color* createTextColor() const;
    Color* createSecondaryColor (const int steps) const;
    Color* createSecondaryColor (const int steps, const Color& text) const;

    Color(bool, const Color& primary); // Farbe ohne 2.Farbe oder Text Farbe

public:                                                                                             // Textfarbe wird immer wenn nicht gegeben automatisch generiert:
    Color(const Color& other);                                                                      // other wird vollständig übernommen
    Color(const Color& primary, int secColor);                                                      // Primärfarbe + automatische 2. Farbe
    Color(const Color& primary, const Color& text);                                                 // Primärfarbe + neue textfarbe
    Color(const Color& primary, const Color& text, int secColor);                                   // Primärfarbe + neue textfarbe + automatische 2.Farbe
    Color(const Color& primary, const Color& text, int secColor, const Color& SecText);             // Primärfarbe + neue textfarbe + automatische 2.Farbe
    Color(const Color& primary, bool, const Color& secondary);                                      // Primärfarbe + 2. Farbe
    Color(const Color& primary, const Color& text, const Color& secondary);                         // alle Farben menuell setzen -> 2. Textfarbe wird generiert
    Color(const Color& primary, const Color& text, const Color& secondary, const Color& SecText);   // alle Farben menuell setzen

    Color (const uint8_t r, const uint8_t g, const uint8_t b);
    Color (const uint8_t r, const uint8_t g, const uint8_t b, int secColor);
    Color (const uint8_t r, const uint8_t g, const uint8_t b, const Color& secondary);
    
    ~Color();

    Color setTet (const Color& text) {
        return Color(*this, text);
    }
    
    Color operator+(const Color& other);
    Color operator>>(const Color& other);

    uint8_t getRed   () const;
    uint8_t getGreen () const;
    uint8_t getBlue  () const;

    Color operator!() const;
    Color operator+(const Color& secondary) const;

    const Color single(bool newTextColor=false);
    const Color single(bool newTextColor=false) const;
    const bool hasSecondaryColor() const;

    const Color setPrimColor(const Color& color) const;
    const Color setPrimColor(const uint8_t r, const uint8_t g, const uint8_t b) const;
    const Color setSecColor(const Color& secondary) const;
    const Color setSecColor(const uint8_t r, const uint8_t g, const uint8_t b) const;
    const Color setSecText(const Color& text) const;
    const Color setSecText(const uint8_t r, const uint8_t g, const uint8_t b) const;
    const Color setText(const Color& text) const;
    const Color setText(const uint8_t r, const uint8_t g, const uint8_t b) const;

    const Color getSecColor() const;
    const Color getSecText() const;
    const Color getText() const;
    
    String toString() const;
};