#include "../Screen.h"
#include "../Element.h"

#pragma once

class ErrorSreen: public Screen {
public:
    ErrorSreen (char* error_title, char* error_text, const Color& background_color);
    void loop() override;
    void draw() override;

private:
    char* error_title;
    char* error_text;
    const Color& background_color;
};