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

    void setDisplay(Display* const display);
    virtual void setResolution(int16_t height, int16_t width);
    virtual void setOffsetPosition(int16_t x, int16_t y);
    const int16_t getResolutionHeight() const;
    const int16_t getResolutionWidth() const;
    const int16_t getOffsetX() const;
    const int16_t getOffsetY() const;

protected:
    int16_t height = 0;
    int16_t width = 0;
    int16_t offsetX = 0;
    int16_t offsetY = 0;
    Display* display = nullptr;
};