#include "RectButtonCircle.h"
#include <algorithm>

RectButtonCircle::RectButtonCircle(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& border, const uint8_t borderRadius, const button_func_ptr button_callback, bool* const value):
    Button(button_callback, value),
    colorInfillOn(infillOn),
    colorInfillOff(infillOff),
    colorBorderOn(border),
    colorBorderOff(border),
    textOn(textOn),
    textOff(textOff),
    borderRadius(borderRadius)
{}
RectButtonCircle::RectButtonCircle(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& borderOn, const Color& borderOff,const uint8_t borderRadius, const button_func_ptr button_callback, bool* const value):
    Button(button_callback, value),
    colorInfillOn(infillOn),
    colorInfillOff(infillOff),
    colorBorderOn(borderOn),
    colorBorderOff(borderOff),
    textOn(textOn),
    textOff(textOff),
    borderRadius(borderRadius)
{}
RectButtonCircle::RectButtonCircle(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& border,const uint8_t borderRadius,const switch_func_ptr switch_callback, bool* const value):
    Button(switch_callback, value),
    colorInfillOn(infillOn),
    colorInfillOff(infillOff),
    colorBorderOn(border),
    colorBorderOff(border),
    textOn(textOn),
    textOff(textOff),
    borderRadius(borderRadius)
{}
RectButtonCircle::RectButtonCircle(const char* textOn, const Color& infillOn, const char* textOff, const Color& infillOff, const Color& borderOn, const Color& borderOff, const uint8_t borderRadius, const switch_func_ptr switch_callback, bool* const value):
    Button(switch_callback, value),
    colorInfillOn(infillOn),
    colorInfillOff(infillOff),
    colorBorderOn(borderOn),
    colorBorderOff(borderOff),
    textOn(textOn),
    textOff(textOff),
    borderRadius(borderRadius)
{}

void RectButtonCircle::loop() {}

bool RectButtonCircle::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {
    // TODO: anpassen

    return sizeX > 50 && sizeY > 50;
}

void RectButtonCircle::draw() {    
    const uint8_t t = 10;
    const uint8_t radius = std::min(sizeX - t, sizeY - t)/20 * borderRadius;
    const uint16_t circleSize = (sizeX+sizeY)/12;       //für das Placement eines kleinen Kreis in die obere rechte Ecke direkt an den Rand des Elements
    const uint16_t circlePosX = sizeX - t/2 - radius;
    const uint16_t circlePosY = t/2 + radius;
    
    LOGGER_PATTERN("Zeichne Rechteckigen Button mit abgerundeten Ecken und mit Kreis(state=_)", value)

    display->setGroup(sizeX, sizeY);
    if (value){
        display->rect(sizeX/2, sizeY/2, sizeX - t, sizeY - t, 5, radius, colorBorderOn, colorInfillOn);
        display->text_center(sizeX/2, sizeY/2, circleSize*0.2, textOn, colorBorderOn);
        display->circle(circlePosX, circlePosY, circleSize, 2, COLOR_BLACK ,COLOR_GREEN);
    } else {
        display->rect(sizeX/2, sizeY/2, sizeX - 5, sizeY - 5, 5, radius, colorBorderOff, colorInfillOff);
        display->text_center(sizeX/2, sizeY/2, circleSize*0.2, textOff, colorBorderOff);
        display->circle(circlePosX, circlePosY, circleSize, 2, COLOR_BLACK ,COLOR_RED);
    }
    display->drawGroup(posX, posY);
}