#include <Arduino.h>
#include "../Elements/Button.h"
#include "../Color.h"

#pragma once

class Button_Rect: public Button {
public:
    // button mode
    Button_Rect(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, ExternalButtonValue* const value=nullptr);
    Button_Rect(const char* item                       , const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, ExternalButtonValue* const value=nullptr);
    Button_Rect(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr);
    Button_Rect(const char* item                       , const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr);

    // switch mode
    Button_Rect(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value=nullptr);
    Button_Rect(const char* item                       , const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value=nullptr);
    Button_Rect(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr);
    Button_Rect(const char* item                       , const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr);

    ~Button_Rect();

    void draw() override;
    uint16_t getHeight();
    uint16_t getWidth();

private:
    bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override;
    const Color color;
    Item* itemOn;
    Item* itemOff;
    const uint8_t borderRadius;
    const uint8_t borderSize;

    const uint8_t t = 10;
};