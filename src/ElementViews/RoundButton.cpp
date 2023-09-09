#include "RoundButton.h"
#include <algorithm>

RoundButton::RoundButton(const char* itemOn, const char* itemOff, const Color& color, const button_func_ptr button_callback, bool* const value):
    Button(button_callback, value), color(color), itemOnStr(itemOn), itemOffStr(itemOff) {}

RoundButton::RoundButton(const char* itemOn, const char* itemOff, const Color& color, const switch_func_ptr switch_callback, bool* const value):
    Button(switch_callback, value), color(color), itemOnStr(itemOn), itemOffStr(itemOff) {}

RoundButton::~RoundButton () {
    delete itemOn;
    delete itemOff;
}

bool RoundButton::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {

    itemOn = display->createItem(itemOnStr, color);
    itemOff = display->createItem(itemOffStr, color);

    LOGGER("Zeichne item im Round Button als Test")
    if (itemOn) itemOn->draw(sizeX, sizeY, COLOR_GREEN);

    // TODO: anpassen
    return sizeX > 50 && sizeY > 50;
}

void RoundButton::draw() {
    uint16_t d = std::min(sizeX, sizeY) * 0.9;
    LOGGER_PATTERN("Zeichne Runden Button(state=_) mit d=_, d*0.1=_", value, d, d*0.1)
    LOGGER_PATTERN("Color: _, BorderColor: _, SecColor: _, SecRand: _", color.toString(), color.getBorderColor().toString(), color.getSecondaryColor().toString(), color.getSecondaryBorderColor().toString())
 
    if (value){
        display->circle(posX + sizeX/2, posY + sizeY/2, d, 8, color.getBorderColor(), color);
        // display->text_center(posX + sizeX/2, posY + sizeY/2, d*0.04, textOn, colorBorderOn);
        if (!itemOn) LOGGER("itemOn ist nullptr")
        if ( itemOn) LOGGER("itemOn ist gültig")
        // itemOn->draw(posX + sizeX/2, posY + sizeY/2);
        Item* icon = display->createItem("text:Hello_World size:2");
        display->drawItem(posX + sizeX/2, posY + sizeY/2, icon, COLOR_BLACK);
        // display->text_center(posX + sizeX/2, posY + sizeY/2, 2, "ON", COLOR_BLACK);
    } else {
        display->circle(posX + sizeX/2, posY + sizeY/2, d, 8, color.getSecondaryBorderColor(), color.getSecondaryColor());
        // display->text_center(posX + sizeX/2, posY + sizeY/2, d*0.04, textOff, colorBorderOff);
        // display->text(posX, posY, sizeX, sizeY, textOff, colorBorderOff);
        if (!itemOn) LOGGER("itemOff ist nullptr")
        if ( itemOn) LOGGER("itemOff ist gültig")
        // itemOff->draw(posX + sizeX/2, posY + sizeY/2);
        Item* icon = display->createItem("icon:arrow_right");
        display->drawItem(posX + sizeX/2, posY + sizeY/2, icon, COLOR_BLACK);
    }
}

uint16_t RoundButton::getHeight(){
    return sizeX;
}

uint16_t RoundButton::getWidth(){
    return sizeY;
}
