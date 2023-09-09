#pragma once

#include "../Color.h"
#include <Arduino.h>
#include <string>

class Display;

struct Item {
    virtual void draw(uint16_t x, uint16_t y, const Color& color) = 0;
    virtual void draw(uint16_t x, uint16_t y) = 0;
    virtual void drawOn(uint16_t x, uint16_t y) = 0;
    virtual void drawOff(uint16_t x, uint16_t y) = 0;

    void test() {
        // LOGGER("Dies ist ein Item test")
    }

    inline Item(Display* const display): display(display) {}
    inline virtual ~Item() {}

protected:
    Display* const display;
};