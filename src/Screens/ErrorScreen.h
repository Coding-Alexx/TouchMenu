#include "../Screen.h"
#include "../Element.h"

#pragma once

class ErrorSreen: public Screen {
public:
    ErrorSreen (const char* error_title, const char* error_text);
    ErrorSreen (const char* error_title, const char* error_text, const Color& background_color, const Color& text_color);
    void loop() override;
    void draw() override;

private:
    const char* error_title;
    const char* error_text;
    const Color background_color;
    const Color text_color;
};