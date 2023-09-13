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

    bool update = false;

    void reset() {
        enter = false;
        right = false;
        left = false;
        up = false;
        down = false;
        isTouched = false;
        update = false;
    }

    bool hasInput() {
        return isTouched || enter || right || left || up || down;
    }
};