#include "../Screen.h"

class ErrorSreen: public Screen {
public:
    ErrorSreen (int height, int width, char* error_title, char* error_text, Color background_color);
    void loop() override;

private:
    char* error_title;
    char* error_text;
    Color background_color;
};