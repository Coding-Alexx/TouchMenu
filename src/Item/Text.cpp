#include "Text.h"
#include "../Display.h"

Text::Text(const std::string text, uint8_t size, const Color& color)
    : size(size), color(color), text(text) {}

// TODO: Textgröße automatisch berechnen
Text::Text(const std::string text, const uint8_t sizeX, const uint8_t sizeY, const Color& color)
    : size(1), color(color), text(text) {}

void Text::draw(uint16_t x, uint16_t y, Display* disp, const Color& textColor) {
    // LOGGER_PATTERN("schreibe text '_' an der Stelle _/_ in der Farbe _ und der Size: _", text.c_str(), x, y, textColor.toString(), size)
    // LOGGER_PATTERN("Text: '_'", text.c_str())
    disp->text_center(x, y, size, text.c_str(), textColor);
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

// TODO mechanismus ausdenken, wie man überschreiben von selbst gesetzten Werten verfindert
void Text::setWith(const uint16_t _width, const bool override) {
    if (!override) width = _width;
}

void Text::setHeight(const uint16_t _height, const bool override) {
    if (!override) height = _height;
}

void Text::setSize(const uint8_t _size, const bool override) {
    if (!override) size = _size;
}