#include "Text.h"
#include "../Display.h"

Text::Text(const std::string text, uint8_t size, const Color& color)
    : size(size), color(color), text(text) {}

void Text::draw(uint16_t x, uint16_t y, Display* disp, const Color& textColor) {
    LOGGER_PATTERN("schreibe text '_' an der Stelle _/_ in der Farbe _ und der Size: _", text.c_str(), x, y, textColor.toString(), size)
    disp->text_center(x, y, 2, text.c_str(), textColor);
}

void Text::draw(uint16_t x, uint16_t y, Display* disp) {
    draw(x, y, disp, color);
}

void Text::drawOn(uint16_t x, uint16_t y, Display* disp) {
    draw(x, y, disp, color);
}

void Text::drawOff(uint16_t x, uint16_t y, Display* disp) {
    draw(x, y, disp, color.getSecondaryColor());
}