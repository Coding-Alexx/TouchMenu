#include <Arduino.h>
#include "Display.h"
#include "Input.h"

#pragma once

class Element {
public:
    Element ();
    virtual ~Element();
    virtual bool select(Inputs& input) = 0;
    virtual void loop(Inputs& input) = 0;
    // virtual void loop() = 0;
    virtual void draw() = 0;
    virtual void setTouch(Inputs& input) = 0;

    void setDisplay(Display* const display);
    void setPosition(const uint16_t posX, const uint16_t posY);
    bool setSize(const uint16_t sizeX, const uint16_t sizeY, const uint8_t rotation);  // true -> größe OK, false -> zu klein/groß zum Zeichnen
    
protected:
    virtual bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) = 0;
    
    uint16_t posX;
    uint16_t posY;
    uint16_t sizeX;
    uint16_t sizeY;
    uint8_t rotation;

    Display* display;
};