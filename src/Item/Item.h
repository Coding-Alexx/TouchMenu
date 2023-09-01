#pragma once

#include "../Color.h"
#include <Arduino.h>
#include <string>

class Display;

struct Item {
    virtual void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) = 0;
};