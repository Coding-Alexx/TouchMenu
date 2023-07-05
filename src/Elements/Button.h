#include <Arduino.h>
#include "../Element.h"

#pragma once

class Button: public Element {
protected:
    typedef void (*button_func_ptr) ();
    typedef void (*switch_func_ptr) (bool);
    
    const button_func_ptr button_callback;
    const switch_func_ptr switch_callback;
    bool value = false;
    const bool* externalValue;

private:
    // TODO: Smartpointer nutzen
    unsigned long timer = 0; // für eine kleine Animation

    void loop(Inputs& input) override;
    void loop() override;
    void setTouch(uint16_t x, uint16_t y) override;

public:
    bool getValue() const { return value; }
    Button(button_func_ptr button_callback, bool* const value = nullptr);
    Button(switch_func_ptr swich_callback, bool* const value = nullptr);
    virtual ~Button();
    bool select() override;
};