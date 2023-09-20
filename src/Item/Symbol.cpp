#include "Text.h"
#include "../Display.h"

static void drawError(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color) {
    display->text_center(x, y, 2, "Symbol not found", COLOR_RED);
}

static void drawTriangleUp(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color) {
    display->triangle(x, y - h/2, x + w/2, y + h/2, x - w/2, y + h/2, borderSize, color.getBorderColor(), color);
}

static void drawTriangleDown(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color) {
    display->triangle(x, y + h/2, x + w/2, y - h/2, x - w/2, y - h/2, borderSize, color.getBorderColor(), color);
}

static void drawTriangleRight(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color) {
    display->triangle(x + w/2, y, x - w/2, y - h/2, x - w/2, y + h/2, borderSize, color.getBorderColor(), color);
}

static void drawTriangleLeft(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color) {
    display->triangle(x - w/2, y, x + w/2, y - h/2, x + w/2, y + h/2, borderSize, color.getBorderColor(), color);
}

static void drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color) {
    display->rect(x - w/2, y - h/2, w, h, borderSize, 0, color.getBorderColor(), color);
}

Symbol::Symbol(const symbol_func_ptr symbol, uint16_t width, uint16_t height, const Color& color, uint8_t borderSize): 
    width(width), height(height), borderSize(borderSize), color(color), drawSymbol(symbol) {}

Symbol* Symbol::create(const std::string& symbol, uint16_t width, uint16_t height, const Color& symbolColor, uint8_t borderSize) {
    if (symbol == "TriangleUp")    return new Symbol(drawTriangleUp, width, height, symbolColor, borderSize);
    if (symbol == "TriangleDown")  return new Symbol(drawTriangleDown, width, height, symbolColor, borderSize);
    if (symbol == "TriangleRight") return new Symbol(drawTriangleRight, width, height, symbolColor, borderSize);
    if (symbol == "TriangleLeft")  return new Symbol(drawTriangleLeft, width, height, symbolColor, borderSize);
    if (symbol == "Rect")          return new Symbol(drawRect, width, height, symbolColor, borderSize);

    return new Symbol(drawError, width, height, symbolColor, borderSize);
}

void Symbol::draw(uint16_t x, uint16_t y, Display* disp, const Color& textColor) {
    drawSymbol(x, y, width, height, borderSize, disp, textColor);
}

void Symbol::draw(uint16_t x, uint16_t y, Display* disp) {
    draw(x, y, disp, color);
}

void Symbol::drawOn(uint16_t x, uint16_t y, Display* disp) {
    draw(x, y, disp, color);
}

void Symbol::drawOff(uint16_t x, uint16_t y, Display* disp) {
    draw(x, y, disp, color.getSecondaryColor());
}

// TODO mechanismus ausdenken, wie man überschreiben von selbst gesetzten Werten verfindert
void Symbol::setWith(const uint16_t _width, const bool override) {
    if (!override) width = _width;
}

void Symbol::setHeight(const uint16_t _height, const bool override) {
    if (!override) height = _height;
}

void Symbol::setSize(const uint8_t _size, const bool override) {
    if (!override) borderSize = _size;
}

uint16_t Symbol::getWith() {return width;}
uint16_t Symbol::getHeight() {return height;}
uint8_t Symbol::getSize() {return borderSize;}