#include "NumberInput.h"
#include "../Config.h"

NumberInput::NumberInput(slider_func_ptr slider_callback, int16_t* const value) : slider_callback(slider_callback) {}
NumberInput::~NumberInput(){};

bool NumberInput::select() {
    return false;
}

// Auchtung: die Callback wird bei einer externen Wertänderrung nicht aufgerufen, dies kann der Entwickler selbst tun
void NumberInput::loop(){
    if (*externalValue != value) {
        value = *externalValue;

        // zeichne Element neu


        if (slider_callback && value) {
            timer = millis() + BUTTON_ON_TIME;
        }
    }

    if (timer > 0 && slider_callback && timer < millis()) {
        value = false;
        timer = 0;
    }
}

void NumberInput::loop(Inputs& input) {
    if (input.enter) {
        LOGGER("Enter")
        value = !value;
    }
}