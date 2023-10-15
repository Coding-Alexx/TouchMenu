#include <Arduino.h>
#include "Color.h"
#include "Display.h"
#include "Input.h"

#pragma once

class Screen {
public:

    // TODO: Datentypen überprüfen
    Screen ();
    virtual void loop (Inputs& input) = 0;   // aktualisiere die Elemente
    virtual void draw() = 0;    // Zeichne den Screen und alle Elemente neu

    virtual void setDisplay(Display* const display);
    virtual void setResolution(uint16_t width, uint16_t height);
    virtual void setOffsetPosition(uint16_t x, uint16_t y);
    const int16_t getResolutionHeight() const;
    const int16_t getResolutionWidth() const;
    const int16_t getOffsetX() const;
    const int16_t getOffsetY() const;

protected:
    uint16_t height = 0;
    uint16_t width = 0;
    uint16_t offsetX = 0;
    uint16_t offsetY = 0;
    Display* display = nullptr;
};