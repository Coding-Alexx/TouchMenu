#include <Arduino.h>
#include "../Elements/Button.h"
#include "../Color.h"

#pragma once

class ToggleSwitch: public Button {
public:
    ToggleSwitch(const char* textOn, const Color& infillbotOn, const Color& infilltopOn, const char* textOff, const Color& infillbotOff, const Color& infilltopOff, const Color& border  , const button_func_ptr button_callback, bool* const value=nullptr);
    ToggleSwitch(const char* textOn, const Color& infillbotOn, const Color& infilltopOn, const char* textOff, const Color& infillbotOff, const Color& infilltopOff, const Color& borderOn, const Color& borderOff, const button_func_ptr button_callback, bool* const value=nullptr);
    ToggleSwitch(const char* textOn, const Color& infillbotOn, const Color& infilltopOn, const char* textOff, const Color& infillbotOff, const Color& infilltopOff, const Color& border,const switch_func_ptr switch_callback, bool* const value=nullptr);
    ToggleSwitch(const char* textOn, const Color& infillbotOn, const Color& infilltopOn, const char* textOff, const Color& infillbotOff, const Color& infilltopOff, const Color& borderOn, const Color& borderOff, const switch_func_ptr switch_callback, bool* const value=nullptr);
    void loop();
    void draw() override;
    bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) ;


private:
    //bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override;
    const Color colorInfillbotOn;
    const Color colorInfilltopOn;
    const Color colorInfillbotOff;
    const Color colorInfilltopOff;
    const Color colorBorderOn;
    const Color colorBorderOff;
    const char* textOn;
    const char* textOff;
};