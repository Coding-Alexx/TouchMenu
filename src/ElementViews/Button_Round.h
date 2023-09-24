#include <Arduino.h>
#include "../Elements/Button.h"
#include "../Color.h"

#pragma once

class Button_Round: public Button {
public:

    // button mode
    Button_Round(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const std::function<void()> button_callback, ExternalButtonValue* const value=nullptr);
    Button_Round(const char* item                       , const Color& color, const uint8_t borderSize, const std::function<void()> button_callback, ExternalButtonValue* const value=nullptr);
    Button_Round(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr);
    Button_Round(const char* item                       , const Color& color, const uint8_t borderSize, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr);

    // switch mode
    Button_Round(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value=nullptr);
    Button_Round(const char* item                       , const Color& color, const uint8_t borderSize, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value=nullptr);
    Button_Round(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr);
    Button_Round(const char* item                       , const Color& color, const uint8_t borderSize, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr);

    ~Button_Round ();

    void draw() override;
    uint16_t getHeight();
    uint16_t getWidth();
    uint16_t getMidX() const { return posX + sizeX/2; }
    uint16_t getMidY() const { return posY + sizeY/2; }

    void setTouch(Inputs& input) override;

private:
    bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override;
    const Color color;
    const uint8_t borderSize;
    // const char* itemOnStr;
    // const char* itemOffStr;
    Item* itemOn = nullptr;
    Item* itemOff = nullptr;
    uint16_t d;

    const double scale = 0.9;
};