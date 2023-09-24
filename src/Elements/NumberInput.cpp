#include "NumberInput.h"

NumberInput::NumberInput(slider_func_ptr slider_callback, uint16_t* externalValue) : slider_callback(slider_callback), externalValue(externalValue) {
    if (externalValue) value = *externalValue;
    else externalValue = new uint16_t;
}
NumberInput::~NumberInput(){};

bool NumberInput::select(Inputs& input) {
    return false;
}

// void NumberInput::loop(){
//     if (externalValue && *externalValue != value) {
//         // if (*externalValue < 0) * externalValue = 0;
//         if (*externalValue > maxValue) *externalValue = maxValue;
//         value = *externalValue;
//         draw();
//     }
// }

void NumberInput::loop(Inputs& input) {
    if (input.enter) {
        LOGGER("Enter")
    }

    if (externalValue && *externalValue != value) {
        // if (*externalValue < 0) * externalValue = 0;
        if (*externalValue > maxValue) *externalValue = maxValue;
        value = *externalValue;
        draw();
    }
}