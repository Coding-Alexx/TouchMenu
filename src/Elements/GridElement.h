#include <Arduino.h>
#include "../Element.h"

class GridElement: public Element {
public:
    GridElement(uint16_t posX, uint16_t posY, uint16_t sizeX, uint16_t sizeY);
    //void loop(uint16_t touchX, uint16_t touchY) override;
    //bool select() override;
private:
    const uint16_t posX;
    const uint16_t posY;
    const uint16_t sizeX;
    const uint16_t sizeY;
    
    GridElement() = default;
};