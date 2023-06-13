#include <Arduino.h>
#include <array>

#include "../Screen.h"
#include "../Element.h"

#pragma once

class CalibrateTouchScreen: public Screen {
public:
    void loop(Inputs& input) override;
    void draw() override;

private:
    uint8_t state = 0;
    std::array<uint16_t, 8> coordinates;
    std::array<uint16_t, 8> testCoordinates;
    long timer = 0;
};