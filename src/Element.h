#include <Arduino.h>

#pragma once

class Element {
public:
    Element ();
    virtual ~Element();
    virtual bool select() = 0;
    virtual void loop(uint16_t touchX, uint16_t touchY) = 0;
    virtual void draw() = 0;

    void setPosition(const uint16_t posX, const uint16_t posY);
    bool setSize(const uint16_t sizeX, const uint16_t sizeY, const uint8_t rotation);  // true -> größe OK, false -> zu klein/groß zum Zeichnen
    
private:
    virtual bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) = 0;
    
    uint16_t posX;
    uint16_t posY;
    uint16_t sizeX;
    uint16_t sizeY;
    uint8_t rotation;
};