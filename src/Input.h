#include <Arduino.h>

#pragma once

struct Inputs {
    bool enter = false;
    bool right = false;
    bool left = false;
    bool up = false;
    bool down = false;

    uint16_t touchX = 0;
    uint16_t touchY = 0;
    bool isTouched = false;

    uint8_t back = 0;
    bool update = false;
};