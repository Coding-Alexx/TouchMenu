#include <Arduino.h>
#include "Color.h"

class Screen {
public:

    // TODO: Datentypen überprüfen
    Screen (int height, int width);
    virtual void loop () = 0;

private:
    int height;
    int width;
};