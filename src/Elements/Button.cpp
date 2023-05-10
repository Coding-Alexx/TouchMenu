#include "Button.h"
#include "../Config.h"

Button::Button(const button_func_ptr button_callback) : button_callback(button_callback), switch_callback(nullptr) {}
Button::Button(const switch_func_ptr swich_callback) : switch_callback(swich_callback), button_callback(nullptr) {}
Button::~Button(){};

void Button::setExternalValue(bool* value) {
    Button::externalValue = value;
}

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
