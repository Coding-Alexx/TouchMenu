#include "Button.h"
#include "../Config.h"

Button::Button(button_func_ptr button_callback, bool* externalValue) : 
    button_callback(button_callback), 
    switch_callback(nullptr),
    externalValue(externalValue)
    {
        if (externalValue) value = *externalValue;
        else externalValue = new bool;
    }

Button::Button(switch_func_ptr swich_callback, bool* externalValue) : 
    button_callback(nullptr), 
    switch_callback(swich_callback),
    externalValue(externalValue) 
    {
        if (externalValue) value = *externalValue;
        else externalValue = new bool;
    }

Button::~Button(){};

bool Button::select() {
    if (button_callback) {
        value = true;
        button_callback();
        // timer = millis() + BUTTON_ON_TIME;    // damit der Button für 200ms als Aktiv angezeigt werden -> TODO die Animationszeit in eine Config auslagern
    } else {
        value = !value;
        switch_callback(value);
    }
    return false;
}

// Auchtung: die Callback wird bei einer externen Wertänderrung nicht aufgerufen, dies kann der Entwickler selbst tun
void Button::loop(){
    if (externalValue && *externalValue != value) {
        value = externalValue;
        draw();

        if (button_callback && value) {
            timer = millis() + BUTTON_ON_TIME;
            LOGGER(timer)
        }
    }

    if (timer > 0 && button_callback && timer < millis() + BUTTON_ON_TIME) {
        LOGGER("Timer weg")
        timer = 0;
        if (value) {
            value = false;
            draw();
        }
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
    if (button_callback && value) {
            button_callback();
            timer = millis();
    }

    if (switch_callback) switch_callback(value);

    draw();
}