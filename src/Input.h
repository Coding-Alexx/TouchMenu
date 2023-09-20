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
    bool updateTouchPoint = false;

    bool update = true;
    uint8_t back = 0;

    void reset() {
        enter = false;
        right = false;
        left = false;
        up = false;
        down = false;
        isTouched = false;
        update = false;
        back = 0;
        updateTouchPoint = false;
    }

    bool hasInput() {
        return (updateTouchPoint && isTouched) || enter || right || left || up || down;
    }
};