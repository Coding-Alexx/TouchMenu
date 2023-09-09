#include "Symbol.h"

Symbol::Symbol(const std::string& symbol, Display* const display, const Color& color, uint16_t height, uint16_t width)
    : Item(display), width(width), height(height), color(color) {}

void Symbol::draw(uint16_t x, uint16_t y, const Color& color) {
    // Hier sollte der Code stehen, um das Symbol zu zeichnen, abhängig vom 'symbol'.
    // Dieser Code wird in Abhängigkeit von 'symbol' entwickelt.
}

void Symbol::draw(uint16_t x, uint16_t y) {
    drawOn(x, y);
}

void Symbol::drawOn(uint16_t x, uint16_t y) {
    draw(x, y, color);
}

void Symbol::drawOff(uint16_t x, uint16_t y) {
    draw(x, y, color.getSecondaryColor());
}
