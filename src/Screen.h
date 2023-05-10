#include <Arduino.h>
#include "Color.h"

#pragma once

class Screen {
public:

    // TODO: Datentypen überprüfen
    Screen ();
    virtual void loop () = 0;

    //Screen() = default;

    void setResolution(size_t height, size_t width);
    const size_t getResolutionHeight();
    const size_t getResolutionWidth();

protected:
    size_t height;
    size_t width;
};