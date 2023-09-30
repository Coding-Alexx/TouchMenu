#include "Button_Blank.h"

// button mode
Button_Blank::Button_Blank(const char* itemStr, const Color& color, const std::function<void()> button_callback, ExternalButtonValue* const value):
    Button(button_callback, nullptr),
    item(Display::createItem(itemStr, color)) {
        // hasButtonAnimation = false;
    }

Button_Blank::Button_Blank(const char* itemStr, const Color& color, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value):
    Button(button_callback, longpress_callback, value),
    item(Display::createItem(itemStr, color)) {
        // hasButtonAnimation = false;
    }

// switch mode
Button_Blank::Button_Blank(const char* itemStr, const Color& color, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value):
    Button(switch_callback, value),
    item(Display::createItem(itemStr, color)) {
        // hasButtonAnimation = false;
    }

Button_Blank::Button_Blank(const char* itemStr, const Color& color, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value):
    Button(switch_callback, longpress_callback, value),
    item(Display::createItem(itemStr, color)) {
        // hasButtonAnimation = false;
    }

Button_Blank::~Button_Blank () {
    delete item;
}

bool Button_Blank::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {
    item->setResolution(sizeX, sizeY);
    return sizeX > item->getWith() && sizeY > item->getHeight();
}

void Button_Blank::draw() {
    if (value) item->drawOn(posX + sizeX/2, posY + sizeY/2, display);
    else item->drawOff(posX + sizeX/2, posY + sizeY/2, display);
}

void Button_Blank::loop(Inputs& input) {
    if (externalValue && externalValue->getValue() != value) input.update = true;
    Button::loop(input);
}