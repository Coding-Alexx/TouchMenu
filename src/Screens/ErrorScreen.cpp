#include "ErrorScreen.h"

ErrorSreen::ErrorSreen (int height, int width, char* error_title, char* error_text, Color background_color) :
    Screen(height, width)
 {
    ErrorSreen::error_title = error_title;
    ErrorSreen::error_text = error_text;
    ErrorSreen::background_color = background_color;
}