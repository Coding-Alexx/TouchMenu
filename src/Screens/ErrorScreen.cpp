#include "ErrorScreen.h"

ErrorScreen::ErrorScreen (const char* error_title, const char* error_text):
        ErrorScreen(error_title, error_text, COLOR_RED, COLOR_BLACK)
    {}

ErrorScreen::ErrorScreen (const char* error_title, const char* error_text, const Color& background_color, const Color& text_color):
        error_title(error_title),
        error_text(error_text),
        background_color(background_color),
        text_color(text_color)
    {}

void ErrorScreen::draw() {
    display->fillScreen(background_color);

    // TODO: text_size automatisch anpassen (je nach Textlänge) 
    display->text_center(width/2, height/3, 3, error_title, text_color);
    display->text_center(width/2, 2*height/3, 1, error_text, text_color);
}

void ErrorScreen::loop(Inputs& input) {

}