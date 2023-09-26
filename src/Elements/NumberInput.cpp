#include "NumberInput.h"

NumberInput::NumberInput(std::function<void(int)> callback, ExternalNumberValue* const externalValue) : 
    callback(callback), 
    externalValue(externalValue) 
    {}

NumberInput::~NumberInput(){};

bool NumberInput::select(Inputs& input) {
    return false;
}

void NumberInput::loop(Inputs& input) {
    if (input.enter) {
        LOGGER("Enter")
    }

    if (!externalValue) return; // if there is no external Value
    else if (externalValue->getValue() != value) value = externalValue->getValue();
    else if (externalValue->getMinValue() != minValue) minValue = externalValue->getMinValue();
    else if (externalValue->getMaxValue() != maxValue) maxValue = externalValue->getMaxValue();
    else if (externalValue->getSteps() != steps) steps = externalValue->getSteps();
    else return; // if there is no update
    
    draw();
}