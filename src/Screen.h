#include <Arduino.h>
#include "Color.h"
#include "Display.h"

#pragma once

class Screen {
public:

    // TODO: Datentypen überprüfen
    Screen ();
    virtual void loop () = 0;   // aktualisiere die Elemente
    virtual void draw() = 0;    // Zeichne den Screen und alle Elemente neu

    void setDisplay(Display* const display);
    void setResolution(int16_t height, int16_t width);
    const int16_t getResolutionHeight();
    const int16_t getResolutionWidth();

protected:
    int16_t height = 0;
    int16_t width = 0;
    Display* display;
};