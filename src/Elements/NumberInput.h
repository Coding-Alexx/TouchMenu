#include <Arduino.h>
#include "../Element.h"
#include <functional>

#pragma once

#define TML_empty_slider [](int){}

class ExternalNumberValue {
protected:
    int value = 0;
    int minValue = 0;
    int maxValue = 100;
    uint steps = 1;
    bool update = false;

public:
    void setValue(int val) {
        if (val > maxValue || val < minValue) return;
        value = val;
        update = true;
    }

    void setMinValue(int min) {
        if (min > maxValue) return;
        if (value < min) value = min;
        minValue = min;
        update = true;
    }

    void setMaxValue(int max) {
        if (max < minValue) return;
        if (value > max) value = max;
        maxValue = max;
        update = true;
    }

    void setSteps(uint step) {
        if (step < (uint)(maxValue - minValue)) return;
        steps = step;
        update = true;
    }

    int getValue    () const { return value; }
    int getMinValue () const { return minValue; }
    int getMaxValue () const { return maxValue; }
    uint getSteps   () const { return steps; }
};

class NumberInput: public Element, public ExternalNumberValue {
protected:  
    const std::function<void(int)> callback = [](int){};

    ExternalNumberValue* const externalValue = nullptr;
    // int value = 0;
    // int minValue = 0;
    // int maxValue = 100;
    // uint steps = 1;

private:
    virtual void setTouch(Inputs& input) = 0;

public:
    NumberInput(std::function<void(int)> callback, ExternalNumberValue* const externalValue = nullptr);
    virtual ~NumberInput();
    bool select(Inputs& input) override;
    void loop(Inputs& input) override;    
};