#include <Arduino.h>

class Element {
public:
    Element ();
    Element (bool isVerticalFormat);
    virtual bool select() = 0;
    virtual void loop(uint16_t touchX, uint16_t touchY) = 0;
private:
    bool isVerticalFormat = false;
};