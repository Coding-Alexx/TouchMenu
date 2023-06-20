#include "ToggleSwitch.h"
#include <algorithm>

ToggleSwitch::ToggleSwitch(const char* textOn, const Color& infilltopOn, const Color& infilltopOff, const char* textOff, const Color& infillbotOn, const Color& infillbotOff, const Color& border, const button_func_ptr button_callback, bool* const value):
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
ToggleSwitch::ToggleSwitch(const char* textOn, const Color& infilltopOn, const Color& infilltopOff, const char* textOff, const Color& infillbotOn, const Color& infillbotOff, const Color& borderOn, const Color& borderOff, const button_func_ptr button_callback, bool* const value):
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
ToggleSwitch::ToggleSwitch(const char* textOn, const Color& infilltopOn, const Color& infilltopOff, const char* textOff, const Color& infillbotOn, const Color& infillbotOff, const Color& border,const switch_func_ptr switch_callback, bool* const value):
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
ToggleSwitch::ToggleSwitch(const char* textOn, const Color& infilltopOn, const Color& infilltopOff, const char* textOff, const Color& infillbotOn, const Color& infillbotOff, const Color& borderOn, const Color& borderOff, const switch_func_ptr switch_callback, bool* const value):
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
        display->circle(switchX, switchTop , d, 5, colorBorderOn, colorInfilltopOn);
        display->circle(switchX , switchBottom , d, 5, colorBorderOn, colorInfillbotOff);
        display->text_center(switchX  , switchTop , switchHeight * 0.75, textOn, COLOR_WHITE);
    } else {
        // Draw "OFF" (bottom circle)
        display->circle(switchX , switchTop , d, 5, colorBorderOn, colorInfilltopOff);
        display->circle(switchX , switchBottom , d, 5, colorBorderOn, colorInfillbotOn);
        display->text_center(switchX, switchBottom , switchHeight * 0.75, textOff, COLOR_WHITE);
    }
  


/* if (value) {
        // Draw the "ON" state
        display->rect(posX, posY, sizeX, switchHeight, 2, colorInfillbotOn, 5, colorInfillbotOn);
        display->rect(posX, posY, sizeX, switchHeight,2, colorInfilltopOn,5, colorInfilltopOn);
        display->text_center(switchX , switchTop , switchHeight * 0.75, textOn, COLOR_BLACK);
    } else {
        // Draw the "OFF" state
        display->rect(posX, posY + switchHeight, sizeX, switchHeight,2, colorInfillbotOff,5, colorInfillbotOff);
        display->rect(posX, posY + switchHeight, sizeX, switchHeight,2, colorInfilltopOff,5, colorInfilltopOff);
        display->text_center(switchX, switchBottom  , switchHeight * 0.75, textOff, COLOR_BLACK);
    }*/
  

}