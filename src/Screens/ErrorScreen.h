#include <Arduino.h>
#include "../Screen.h"
#include "../Element.h"

#pragma once

#define CREATE_ERROR_SCREEN(TML, screenID, errorTitle, errorMessage) \
    static_assert(std::is_integral<decltype(screenID)>::value && screenID >= 0 && screenID <= UINT8_MAX, "screenID must be of type uint8_t"); \
    static_assert(std::is_same<decltype(TML), TouchMenuLib>::value, "TML must be of type TouchMenuLib"); \
    static_assert(std::is_convertible<decltype(errorMessage), const char*>::value, "errorMessage must be of type const char*"); \
    static_assert(std::is_convertible<decltype(errorTitle), const char*>::value, "errorTitle must be of type const char*"); \
    TML.add(screenID, new ErrorScreen(errorTitle, errorMessage));

#define CREATE_ERROR_SCREEN_with_Colors(TML, screenID, errorTitle, errorMessage, backgroundColor, textColor) \
    static_assert(std::is_integral<decltype(screenID)>::value && screenID >= 0 && screenID <= UINT8_MAX, "screenID must be of type uint8_t"); \
    static_assert(std::is_same<decltype(TML), TouchMenuLib>::value, "TML must be of type TouchMenuLib"); \
    static_assert(std::is_convertible<decltype(errorMessage), const char*>::value, "errorMessage must be of type const char*"); \
    static_assert(std::is_convertible<decltype(errorTitle), const char*>::value, "errorTitle must be of type const char*"); \
    static_assert(std::is_same<decltype(backgroundColor), Color>::value, "backgroundColor must be of type Color"); \
    static_assert(std::is_same<decltype(textColor), Color>::value, "textColor must be of type Color"); \
    ErrorScreen* screen##screenID = new ErrorScreen(errorTitle, errorMessage, backgroundColor, textColor); \
    TML.add(screenID, screen##screenID);

class ErrorScreen: public Screen {
public:
    ErrorScreen (const char* error_title, const char* error_text);
    ErrorScreen (const char* error_title, const char* error_text, const Color& background_color, const Color& text_color);
    void loop() override;
    void draw() override;

private:
    const char* error_title;
    const char* error_text;
    const Color background_color;
    const Color text_color;
};