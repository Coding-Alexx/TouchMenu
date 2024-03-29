#pragma once

#include <Arduino.h>
#include <algorithm>
#include "Logger.h"

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

class Color {
private:
    uint8_t r_prim,  g_prim,    b_prim;
    uint8_t r_item,  g_item,    b_item;
    uint8_t r_border, g_border, b_border;
    Color* secondaryColor = nullptr;

    const bool isBorderSet = false;

    // vollständige Farbe
    inline Color(const Color& prim, const Color& item, const Color& border, const Color* secondary, bool isBorderSet = false): 
                r_prim(prim.getRed()), g_prim(prim.getGreen()), b_prim(prim.getBlue()), 
                r_item(item.getRed()), g_item(item.getGreen()), b_item(item.getBlue()), 
                r_border(border.getRed()), g_border(border.getGreen()), b_border(border.getBlue()),
                isBorderSet(isBorderSet) 
                {
                    // LOGGER_PATTERN("Erstelle Farbe (_,_,_)", prim.r_prim, prim.g_prim, prim.b_prim)
                    if (secondary) secondaryColor = new Color(*secondary);
                    else secondaryColor = nullptr;
                }
    
    // Farbe ohne zusatzfarben aus rgb Werten
    inline Color(const uint8_t r, const uint8_t g, const uint8_t b, const bool): 
        r_prim(r), g_prim(g), b_prim(b), 
        r_item(0), g_item(0), b_item(0), 
        r_border(0), g_border(0), b_border(0),
        secondaryColor(nullptr),
        isBorderSet(false)
        {}
    
    // Farbe ohne zusatzfarben
    inline Color(const bool, const Color& other):
        r_prim(other.r_prim), g_prim(other.g_prim), b_prim(other.b_prim),
        r_item(0), g_item(0), b_item(0), 
        r_border(0), g_border(0), b_border(0),
        secondaryColor(nullptr),
        isBorderSet(false)
        {}

    inline const Color setColorOffset(const Color& color, const int offset) const {
        if (offset == 0) return Color(0, color);

        LOGGER_PATTERN ("_ + _ + _ + _ < 0", static_cast<int>(color.r_prim), static_cast<int>(color.g_prim), static_cast<int>(color.b_prim), offset)

        // Very dark colours should only become lighter
        if (static_cast<int>(color.r_prim) + static_cast<int>(color.g_prim) + static_cast<int>(color.b_prim) + offset <= 0) return Color(color, std::abs(offset));
        
        const uint8_t r = std::min(std::max(static_cast<int>(color.r_prim) + offset, 0), 255);
        const uint8_t g = std::min(std::max(static_cast<int>(color.g_prim) + offset, 0), 255);
        const uint8_t b = std::min(std::max(static_cast<int>(color.b_prim) + offset, 0), 255);

        LOGGER_PATTERN("Berechne Offset: _ + _ = _", color.toString(), offset, Color(r, g, b, 0).toString())

        return Color(r, g, b, 0);
    }

    inline const Color createItemColor(const Color& color) const {
        if (r_prim + g_prim + b_prim < (120*3)) return Color(255,255,255, 0);
        else return Color(0,0,0, 0);
    }

    inline const Color createBorderColor(const Color& color) const {
        if (r_prim + g_prim + b_prim < (60*3)) return Color(255,255,255, 0);
        else return Color(0,0,0, 0);
    }

public:
    inline Color(const Color& other): Color(other, other.getItemColor(), other.getBorderColor(), other.secondaryColor) {}
    inline Color(const Color& prim, const int offset): Color(setColorOffset(prim, offset), createItemColor(prim), createBorderColor(prim), nullptr) {}
    inline Color(const Color& prim, const Color& item): Color(prim, item, createBorderColor(prim), nullptr) {}
    inline Color(const Color& prim, const bool, const Color& border): Color(prim, createItemColor(prim), border, nullptr) {}
    inline Color(const Color& prim, const Color& item, const Color& border): Color(prim, item, border, nullptr) {}
    inline Color(const Color& prim, const bool, const bool, const Color& secondary): Color(prim, createItemColor(prim), createBorderColor(prim), new Color(secondary)) {}
    inline Color(const Color& prim, const bool, Color& border, const Color& secondary): Color(prim, createItemColor(prim), border, new Color(secondary)) {}
    inline Color(const Color& prim, const Color& item, const bool, const Color& secondary): Color(prim, item, createBorderColor(prim), new Color(secondary)) {}
    inline Color(const Color& prim, const Color& item, const Color& border, const Color& secondary): Color(prim, item, border, new Color(secondary)) {}

    inline Color(const uint8_t r, const uint8_t g, const uint8_t b): Color(Color(r,g,b, true), 0) {
        // mögliches Probem erkannt: dieser Konstruktor wird sehr oft mit (0, 0, 0) aufgerufen
        // LOGGER_PATTERN("aus (_, _, _) wird COLOR(_, _, _) als String: (_, _, _)", r, g, b, r_prim, g_prim, b_prim, String(r_prim), String(g_prim), String(b_prim))
    }

    inline ~Color() { delete secondaryColor; }


    // operator -> for example: prim|item|rand + sec|item|rand

    inline Color operator!()                       const { return Color(255-r_prim, 255-g_prim, 255-b_prim); }
    inline Color operator+(const Color& secondary) const { return Color(*this, getItemColor(), getBorderColor(), secondary); }
    inline Color operator|(const Color& other)     const {
        // LOGGER_PATTERN("isBorderSet: _, prim: (_, _, _)|(_, _, _)|(_, _, _), other: (_, _, _)|(_, _, _)|(_, _, _)", isBorderSet, r_prim, g_prim, b_prim, r_item, g_item, b_item, r_border, g_border, b_border, other.r_prim, other.g_prim, other.b_prim, other.r_item, other.g_item, other.b_item, other.r_border, other.g_border, other.b_border)
        if (!isBorderSet) return Color(*this, other, getBorderColor(), secondaryColor, true);   // 1. add item color
        else return Color(*this, getItemColor(), other, secondaryColor);                        // 2. add border color
    }
    inline Color& operator=(const Color& other) {
        if (this != &other) { // Selbstzuweisung vermeiden
            r_prim = other.r_prim;     g_prim = other.g_prim;     b_prim = other.b_prim;
            r_item = other.r_item;     g_item = other.g_item;     b_item = other.b_item; 
            r_border = other.r_border; g_border = other.g_border; b_border = other.b_border;
            
            delete secondaryColor;
            secondaryColor = nullptr;
            
            if (other.secondaryColor != nullptr)
                secondaryColor = new Color(*other.secondaryColor);
        }
        return *this;
    }

    // getter:

    inline Color getPrimColor()            const { return Color( *this, 0 ); }
    inline Color getItemColor()            const { return Color( r_item,   g_item,   b_item  ); }
    inline Color getBorderColor()          const { return Color( r_border, g_border, b_border); }
    inline Color getSecondaryItemColor()   const { return getSecondaryColor().getItemColor(); }
    inline Color getSecondaryBorderColor() const { return getSecondaryColor().getBorderColor(); }
    inline Color getSecondaryColor()       const { 
        if (secondaryColor) return *secondaryColor;
        else return *this;
    }

    inline uint8_t getRed   () const { return r_prim; }
    inline uint8_t getGreen () const { return g_prim; }
    inline uint8_t getBlue  () const { return b_prim; }

    inline bool hasSecondaryColor() const { return secondaryColor != nullptr; }

    
    // setter

    inline Color setPrimaryColor(const Color& color)         const { return Color(color, getItemColor(), getBorderColor(), secondaryColor); }
    inline Color setItemColor(const Color& color)            const { return Color(getPrimColor(), color, getBorderColor(), secondaryColor); }
    inline Color setBorderColor(const Color& color)          const { return Color(getPrimColor(), getItemColor(), color, secondaryColor); }
    inline Color setSecondaryColor(const Color& color)       const { return Color(getPrimColor(), getItemColor(), getBorderColor(), color); }
    inline Color setSecondaryItemColor(const Color& color)   const { return Color(*this, getItemColor(), getBorderColor(), Color(*secondaryColor, secondaryColor->getItemColor(), color)); }
    inline Color setSecondaryBorderColor(const Color& color) const { return Color(*this, getItemColor(), getBorderColor(), Color(*secondaryColor, color, secondaryColor->getBorderColor())); }

    inline void setPrimaryColor(const Color& color)          { r_prim = color.r_prim; g_prim = color.g_prim; b_prim = color.b_prim; }
    inline void setItemColor(const Color& color)             { r_item = color.r_prim; g_item = color.g_prim; b_item = color.b_prim; }
    inline void setBorderColor(const Color& color)           { r_border = color.r_prim; g_border = color.g_prim; b_border = color.b_prim; }
    inline void setSecondaryColor(const Color& color)        { secondaryColor->r_prim = color.r_prim; secondaryColor->g_prim = color.g_prim; secondaryColor->b_prim = color.b_prim; }
    inline void setSecondaryItemColor(const Color& color)    { secondaryColor->r_item = color.r_prim; secondaryColor->g_item = color.g_prim; secondaryColor->b_item = color.b_prim; }
    inline void setSecondaryBorderColor(const Color& color)  { secondaryColor->r_border = color.r_prim; secondaryColor->g_border = color.g_prim; secondaryColor->b_border = color.b_prim; }

    // toString
    inline String toString() const {
        return "Color(" + String(r_prim) + ", " + String(g_prim) + ", " + String(b_prim) + ")";
    }
};