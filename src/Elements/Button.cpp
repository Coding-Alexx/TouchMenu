#include "Button.h"
#include "../Config.h"

Button::Button(button_func_ptr button_callback, bool* const value) : 
    button_callback(button_callback), 
    switch_callback(nullptr),
    externalValue(value)
    {}
Button::Button(switch_func_ptr swich_callback, bool* const value) : button_callback(nullptr), switch_callback(swich_callback) {}
Button::~Button(){};

bool Button::select() {
    if (button_callback) {
        value = true;
        button_callback();
        timer = millis() + BUTTON_ON_TIME;    // damit der Button für 200ms als Aktiv angezeigt werden -> TODO die Animationszeit in eine Config auslagern
    } else {
        value = !value;
        switch_callback(value);
    }
    return false;
}

// Auchtung: die Callback wird bei einer externen Wertänderrung nicht aufgerufen, dies kann der Entwickler selbst tun
void Button::loop(){
    if (*externalValue != value) {
        value = externalValue;

        // zeichne Element neu


        if (button_callback && value) {
            timer = millis() + BUTTON_ON_TIME;
        }
    }

    if (timer > 0 && button_callback && timer < millis()) {
        value = false;
        timer = 0;
    }
}

void Button::loop(Inputs& input) {
    if (input.enter) {
        LOGGER("Enter")
        value = !value;
    }
}

void Button::setTouch(uint16_t x, uint16_t y) {
    LOGGER("Es wurde auf Button getippt")
    value = !value;
}