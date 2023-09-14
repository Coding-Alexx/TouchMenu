#include <Arduino.h>
#include "../Element.h"

#pragma once

class Textbox: public Element {
protected:
    char* text;
    char* value = nullptr;

private:
    void loop(Inputs& input) override;
    void loop() override;
    void setTouch(uint16_t x, uint16_t y) override;

public:
    Textbox(char* text, char* const value = nullptr);
    virtual ~Textbox();
    bool select() override;
};