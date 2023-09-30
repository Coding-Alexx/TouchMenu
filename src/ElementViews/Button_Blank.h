#include <Arduino.h>
#include "../Elements/Button.h"
#include "../Color.h"

#pragma once

class Button_Blank: public Button {
public:
    // button mode
    Button_Blank(const char* item, const Color& color, const std::function<void()> button_callback, ExternalButtonValue* const value=nullptr);
    Button_Blank(const char* item, const Color& color, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr);

    // switch mode
    Button_Blank(const char* item, const Color& color, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value=nullptr);
    Button_Blank(const char* item, const Color& color, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr);

    ~Button_Blank();

    void draw() override;
    uint16_t getHeight();
    uint16_t getWidth();

    void loop(Inputs& input) override;

private:
    bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override;
    Item* item;
};