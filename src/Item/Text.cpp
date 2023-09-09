#include "Text.h"
#include "../Display.h"

Text::Text(const std::string text, const Color& color, uint8_t size)
    : size(size), color(color), text(text) {LOGGER(text.c_str())}

inline void Text::draw(uint16_t x, uint16_t y, Display* disp, const Color& textColor) {
    LOGGER_PATTERN("schreibe text '_' an der Stelle _/_in der Farbe _ und der Size: _", text.c_str(), x, y, color.toString(), size)
    disp->text_center(x, y, 2, text.c_str(), textColor);
}

inline void Text::drawOn(uint16_t x, uint16_t y, Display* disp) {
    draw(x, y, disp, color);
}

inline void Text::drawOff(uint16_t x, uint16_t y, Display* disp) {
    draw(x, y, disp, color.getSecondaryColor());
}