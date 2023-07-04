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
    const uint16_t circlePosX = posX + sizeX - t/2 - radius;
    const uint16_t circlePosY = posY + t/2 + radius;
    
    LOGGER_PATTERN("Zeichne Rechteckigen Button mit abgerundeten Ecken und mit Kreis(state=_)", value)

    if (value){
        display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - t, sizeY - t, 5, radius, colorBorderOn, colorInfillOn);
        display->text_center(posX + sizeX/2, posY + sizeY/2, circleSize*0.2, textOn, colorBorderOn);
        display->circle(circlePosX, circlePosY, circleSize, 2, COLOR_BLACK ,COLOR_GREEN);
    } else {
        display->rect_center(posX + sizeX/2, posY + sizeY/2, sizeX - t, sizeY - t, 5, radius, colorBorderOff, colorInfillOff);
        display->text_center(posX + sizeX/2, posY + sizeY/2, circleSize*0.2, textOff, colorBorderOff);
        display->circle(circlePosX, circlePosY, circleSize, 2, COLOR_BLACK ,COLOR_RED);
    }

        //     if(hasRoundedCorners){                  //runde Ecken
        //         LOGGER_PATTERN("Zeichne Rechteckigen Button mit abgerundeten Ecken und mit Kreis(state=_) mit d=_, d*0.1=_", value, d, d*0.1)
        //         display->rect(posX, posY, sizeX, sizeY, 2, colorBorderOn, 10, colorInfillOn);
        //     }else{                                  //eckige Ecken
        //         LOGGER_PATTERN("Zeichne Rechteckigen Button mit Kreis(state=_) mit d=_, d*0.1=_", value, d, d*0.1)                           
        //         display->rect(posX, posY, sizeX, sizeY, 2, colorBorderOn, colorInfillOn);
        //     }
        //     display->circle(circlePosX, circlePosY, circleSize, 0, colorBorderOn ,COLOR_RED);
        //     display->text_center(posX + sizeX/2, posY + sizeY/2, d*0.04, textOn, colorBorderOn);
        // } else {
        //     if(hasRoundedCorners){
        //         display->rect(posX, posY, sizeX, sizeY, 2, colorBorderOff, 10, colorInfillOff);
        //     }else{
        //         display->rect(posX, posY, sizeX, sizeY, 2, colorBorderOff, colorInfillOff);
        //     }
        //     display->circle(circlePosX, circlePosY, circleSize, 0, colorBorderOff ,COLOR_GREEN);
        //     display->text_center(posX + sizeX/2, posY + sizeY/2, d*0.04, textOff, colorBorderOff);
        // }
}