#pragma once

#include "../Color.h"
#include <Arduino.h>
#include <string>

class Display;

struct Item {
    Item(const double scale = 1): scale(scale) {}

    virtual void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) = 0;
    virtual void draw(uint16_t x, uint16_t y, Display* disp) = 0;

    virtual void drawOn(uint16_t x, uint16_t y, Display* disp) = 0;
    virtual void drawOff(uint16_t x, uint16_t y, Display* disp) = 0;
    virtual ~Item() = default;

    virtual void setResolution(const uint16_t width, const uint16_t height, const bool override = false) {LOGGER("leere Funktion aufgerufen")}
    virtual void setSize(const uint8_t size, const bool override = false) {LOGGER("leere Funktion aufgerufen")}

    virtual uint16_t getWith()   { return 0; }
    virtual uint16_t getHeight() { return 0; }
    virtual uint8_t  getSize()   { return 0; }
    virtual uint8_t  getScale()  { return 0; }

    const double scale = 1;
};