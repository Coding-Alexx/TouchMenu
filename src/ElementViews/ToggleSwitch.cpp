#include "ToggleSwitch.h"
#include <algorithm>

ToggleSwitch::ToggleSwitch(const char* textOn, const Color& infillbotOn, const Color& infilltopOn, const char* textOff, const Color& infillbotOff, const Color& infilltopOff, const Color& border, const button_func_ptr button_callback, bool* const value):
    Button(button_callback, value),
    colorInfillbotOn(infillbotOn),
    colorInfilltopOn(infilltopOn),
    colorInfillbotOff(infillbotOff),
    colorInfilltopOff(infilltopOff),
    colorBorderOn(border),
    colorBorderOff(border),
    textOn(textOn),
    textOff(textOff)
{}
ToggleSwitch::ToggleSwitch(const char* textOn, const Color& infillbotOn, const Color& infilltopOn, const char* textOff, const Color& infillbotOff, const Color& infilltopOff, const Color& borderOn, const Color& borderOff, const button_func_ptr button_callback, bool* const value):
    Button(button_callback, value),
    colorInfillbotOn(infillbotOn),
    colorInfilltopOn(infilltopOn),
    colorInfillbotOff(infillbotOff),
    colorInfilltopOff(infilltopOff),
    colorBorderOn(borderOn),
    colorBorderOff(borderOff),
    textOn(textOn),
    textOff(textOff)
{}
ToggleSwitch::ToggleSwitch(const char* textOn, const Color& infillbotOn, const Color& infilltopOn, const char* textOff, const Color& infillbotOff, const Color& infilltopOff, const Color& border,const switch_func_ptr switch_callback, bool* const value):
    Button(switch_callback, value),
    colorInfillbotOn(infillbotOn),
    colorInfilltopOn(infilltopOn),
    colorInfillbotOff(infillbotOff),
    colorInfilltopOff(infilltopOff),
    colorBorderOn(border),
    colorBorderOff(border),
    textOn(textOn),
    textOff(textOff)
{}
ToggleSwitch::ToggleSwitch(const char* textOn, const Color& infillbotOn, const Color& infilltopOn, const char* textOff, const Color& infillbotOff, const Color& infilltopOff, const Color& borderOn, const Color& borderOff, const switch_func_ptr switch_callback, bool* const value):
    Button(switch_callback, value),
    colorInfillbotOn(infillbotOn),
    colorInfilltopOn(infilltopOn),
    colorInfillbotOff(infillbotOff),
    colorInfilltopOff(infilltopOff),
    colorBorderOn(borderOn),
    colorBorderOff(borderOff),
    textOn(textOn),
    textOff(textOff)
{}


void ToggleSwitch::loop() {}

bool ToggleSwitch::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {
    // TODO: anpassen

    return sizeX > 50 && sizeY > 50;
}

void ToggleSwitch::draw() {
    uint16_t switchX = posX + sizeX/2;
    uint16_t switchHeight = sizeY / 2;
    uint16_t switchTop = posY + switchHeight*0.6;
    uint16_t switchBottom = posY + switchHeight*1.4;


    uint16_t d = std::min(sizeX, sizeY) * 0.5;
    LOGGER_PATTERN("Zeichne Runden Button(state=_) mit d=_, d*0.1=_", value, d, d*0.1)


    if (value) {
        // Draw "ON" (top circle)
        display->circle(switchX, switchTop , d, 5, colorBorderOn, colorInfillbotOn);
        display->circle(switchX , switchBottom , d, 5, colorBorderOn, colorInfilltopOn);
        display->text_center(switchX  , switchTop , switchHeight * 0.75, textOn, COLOR_BLACK);
    } else {
        // Draw "OFF" (bottom circle)
        display->circle(switchX , switchTop , d, 5, colorBorderOn, colorInfillbotOff);
        display->circle(switchX , switchBottom , d, 5, colorBorderOn, colorInfilltopOff);
        display->text_center(switchX, switchBottom , switchHeight * 0.75, textOff, COLOR_BLACK);
    }



/*    if (value) {
        // Draw the "ON" state
        display->rect(posX, switchTop, sizeX, switchHeight, 2, colorInfillbotOn, 5, colorInfillbotOn);
        display->rect(posX, switchBottom, sizeX, switchHeight,2, colorInfilltopOn,5, colorInfilltopOn);
        display->text_center(posX + sizeX / 2, switchTop + switchHeight / 2, switchHeight * 0.6, textOn, COLOR_GRAY);
    } else {
        // Draw the "OFF" state
        display->rect(posX, switchTop, sizeX, switchHeight,2, colorInfillbotOff,5, colorInfillbotOff);
        display->rect(posX, switchBottom, sizeX, switchHeight,2, colorInfilltopOff,5, colorInfilltopOff);
        display->text_center(posX + sizeX / 2, switchBottom + switchHeight / 2, switchHeight * 0.6, textOff, COLOR_GRAY);
    }*/

}