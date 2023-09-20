#include <Arduino.h>
#include "../Element.h"

#pragma once

class NumberInput: public Element {
protected:  
    // virtual void loop() override;
    typedef void (*slider_func_ptr) (int16_t);
    
    const slider_func_ptr slider_callback;
    uint16_t* const externalValue;
    uint16_t value = 0;
    const uint16_t maxValue = 100;

private:
    // TODO: Smartpointer nutzen
    // unsigned long timer = 0; // für eine kleine Animation
    virtual void setTouch(Inputs& input) = 0;

public:
    NumberInput(slider_func_ptr slider_callback, uint16_t* externalValue = nullptr);
    virtual ~NumberInput();
    bool select() override;
    void loop(Inputs& input) override;
};