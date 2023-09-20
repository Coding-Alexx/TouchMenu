#include "Button.h"

Button::Button(std::function<void()> button_callback, ExternalButtonValue* externalValue) : 
    button_callback(button_callback),
    externalValue(externalValue),
    isButton(true),
    value(true)
    {}

Button::Button(std::function<void()> button_callback, std::function<void()> longpress_callback, ExternalButtonValue* externalValue) :
    button_callback(button_callback),
    longpress_callback(longpress_callback),
    externalValue(externalValue),
    isButton(true),
    hasLongPress(true),
    value(true)
    {}

Button::Button(std::function<void(bool)> swich_callback, ExternalButtonValue* externalValue) : 
    switch_callback(swich_callback),
    externalValue(externalValue),
    isButton(false)
    {}

Button::Button(std::function<void(bool)> swich_callback, std::function<void()> longpress_callback, ExternalButtonValue* externalValue) :
    switch_callback(swich_callback),
    longpress_callback(longpress_callback),
    externalValue(externalValue),
    isButton(false),
    hasLongPress(true)
    {}

Button::Button(std::function<void()> button_callback, std::function<void(bool)> swich_callback, std::function<void()> longpress_callback, const bool isButton, const bool hasLongPress, ExternalButtonValue* externalValue):
    button_callback(button_callback), 
    switch_callback(swich_callback),
    longpress_callback(longpress_callback),
    externalValue(externalValue),
    isButton(isButton),
    hasLongPress(hasLongPress)
    {}

Button::~Button(){};

bool Button::select() {
    if (isButton) {
        value = false;
        button_callback();
        animationTimer = millis();
        if (externalValue) externalValue->setValue(value);
    } else {
        value = !value;
        switch_callback(value);
    }
    draw();
    return false;
}

bool isInsideHitbox(uint16_t x, uint16_t y, uint16_t posX, uint16_t posY, uint16_t sizeX, uint16_t sizeY) {
  return (x >= posX && x <= posX + sizeX && y >= posY && y <= posY + sizeY);
}

// Auchtung: die Callback wird bei einer externen Wertänderrung nicht aufgerufen, dies kann der Entwickler selbst tun
void Button::loop(Inputs& input) {
    if (input.enter) {
        LOGGER("Enter")
        Button::setTouch(input);
    }

    if (externalValue && externalValue->getValue() != value) {
        value = externalValue->getValue();
        draw();
        LOGGER("Externer Wert unterscheidet sich")

        if (isButton && value) animationTimer = millis();
    }

    if (animationTimer > 0 && isButton && millis() - animationTimer > BUTTON_ON_TIME) {
        // LOGGER("Timer ist zuende")
        animationTimer = 0;
        if (!value) {
            value = true;
            draw();
        }
    }

    // if someone has changed something via externalValue
    if (externalValue && externalValue->hasUpdate()) {
        draw();
        externalValue->resetUpdate();
        LOGGER("ExternalValue was changed")
    }

    // if released after Touch, release button again
    if (!input.isTouched && blocked) {
        blocked = false;

    // if Longpress is active and ready
    } else if (hasLongPress && input.isTouched && longPressTimer > 0 && isInsideHitbox(input.touchX, input.touchY, posX, posY, sizeX, sizeY) && millis() - longPressTimer > BUTTON_LONG_TIME) {
        LOGGER("---> LONG Press Timer ist zuende")
        longPressTimer = 0;
        longpress_callback();
        blocked = true;
    
    // if longpress is active, but touch point moved away from button
    } else if (hasLongPress && input.isTouched && longPressTimer > 0 && !isInsideHitbox(input.touchX, input.touchY, posX, posY, sizeX, sizeY)) {
        LOGGER("LONG Press Timer wurde abgebrochen, da Touchpunkt aus Hitbox raus")
        longPressTimer = 0;

    // if longpress active but aborted
    } else if (hasLongPress && !input.isTouched && longPressTimer > 0) {
        LOGGER("Short Press")
        longPressTimer = 0;
        select();
        blocked = true;
    } 
}

void Button::setTouch(Inputs& input) {
    if (hasLongPress && longPressTimer == 0 && !blocked) {
        LOGGER("Aktiviere long press timer")
        longPressTimer = millis();
    } else if (!hasLongPress && !blocked) {
        select();
        blocked = true;
    }

    // if (isButton && value) {
    //     LOGGER("Es wurde auf Button getippt")
    //     button_callback();
    //     animationTimer = millis();
    //     value = false;
    //     if (externalValue) externalValue->setValue(value);
    // }

    // if (!isButton) {
    //     LOGGER("Es wurde auf Switch getippt")
    //     value = !value;
    //     switch_callback(value);
    // }
}