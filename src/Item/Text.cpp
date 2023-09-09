#include "Text.h"

Text::Text(const char* text, Display* const display, const Color& color, uint8_t size)
    : Item(display), size(size), color(color), text(text) {
        LOGGER(text)
    }

void Text::draw(uint16_t x, uint16_t y, const Color& textColor) {
    LOGGER_PATTERN("schreibe text '_' an der Stelle _/_in der Farbe _ und der Size: _", text, x, y, textColor.toString(), size)
    display->text_center(40, 50, 2, "text", textColor);
}

void Text::draw(uint16_t x, uint16_t y) {
    LOGGER("draw")
    drawOn(x, y);
}

void Text::drawOn(uint16_t x, uint16_t y) {
    LOGGER("drawOn")
    draw(x, y, color);
}

void Text::drawOff(uint16_t x, uint16_t y) {
    LOGGER("drawOff")
    draw(x, y, color.getSecondaryColor());
}
