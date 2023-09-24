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

static void drawToggleSwitch(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color) {
    uint16_t switchX = x + w/2;
    uint16_t switchHeight = h / 2;
    uint16_t switchTop = y + switchHeight*0.6;
    uint16_t switchBottom = y + switchHeight*1.4;
    uint16_t d = std::min(w, h) * 0.5;

    display->circle(switchX, switchTop, d, borderSize, color.getBorderColor(), color);
    display->circle(switchX, switchBottom, d, borderSize, color.getSecondaryBorderColor(), color.getSecondaryBorderColor());
    
    display->text_center(switchX, switchTop , switchHeight * 0.75, "ON", COLOR_BLACK);
    display->text_center(switchX, switchBottom , switchHeight * 0.75, "OFF", COLOR_BLACK);
}

static void drawPlus(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color) {
    const uint16_t tmpW = w/4;
    const uint16_t tmpH = h/4;
    const uint16_t tmpX = x - tmpW/2;
    const uint16_t tmpY = y - tmpH/2;
    
    if (borderSize > 0) {
        display->rect(tmpX, 0, tmpW, h, 0, 0, color.getBorderColor());
        display->rect(0, tmpY, w, tmpH, 0, 0, color.getBorderColor());
    }

    display->rect(tmpX + borderSize, borderSize, tmpW-borderSize, h-borderSize, 0, 0, color);
    display->rect(borderSize, tmpY + borderSize, w-borderSize, tmpH-borderSize, 0, 0, color);
}

static void drawMinus(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color) {
    const uint16_t tmpH = h/4;
    const uint16_t tmpY = y - tmpH/2;
    
    if (borderSize > 0) {
        display->rect(0, tmpY, w, tmpH, 0, 0, color.getBorderColor());
    }

    display->rect(borderSize, tmpY + borderSize, w-borderSize, tmpH-borderSize, 0, 0, color);
}


/*****************************************************************************************************************************************/

Symbol::Symbol(const symbol_func_ptr symbol, uint16_t width, uint16_t height, const Color& color, uint8_t borderSize): 
    width(width), height(height), borderSize(borderSize), color(color), drawSymbol(symbol) {}

Symbol* Symbol::create(const std::string& symbol, uint16_t width, uint16_t height, const Color& symbolColor, uint8_t borderSize, const double scale) {

    const uint16_t w = width*scale;
    const uint16_t h = width*scale;

    if (symbol == "TriangleUp")    return new Symbol(drawTriangleUp, w, h, symbolColor, borderSize);
    if (symbol == "TriangleDown")  return new Symbol(drawTriangleDown, w, h, symbolColor, borderSize);
    if (symbol == "TriangleRight") return new Symbol(drawTriangleRight, w, h, symbolColor, borderSize);
    if (symbol == "TriangleLeft")  return new Symbol(drawTriangleLeft, w, h, symbolColor, borderSize);
    if (symbol == "Rect")          return new Symbol(drawRect, w, h, symbolColor, borderSize);
    if (symbol == "toggleSwitch")  return new Symbol(drawToggleSwitch, w, h, symbolColor, borderSize);
    if (symbol == "Plus")          return new Symbol(drawPlus, w, h, symbolColor, borderSize);
    if (symbol == "Minus")         return new Symbol(drawMinus, w, h, symbolColor, borderSize);

    return new Symbol(drawError, w, h, symbolColor, borderSize);
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
    draw(x, y, disp, color.getSecondaryColor() + color);
}

// TODO mechanismus ausdenken, wie man überschreiben von selbst gesetzten Werten verfindert
void Symbol::setResolution(const uint16_t w, const uint16_t h, const bool override) {
    if (!override) {
        width = w;
        height = h;
    }
}

void Symbol::setSize(const uint8_t _size, const bool override) {
    if (!override) borderSize = _size;
}

uint16_t Symbol::getWith() {return width;}
uint16_t Symbol::getHeight() {return height;}
uint8_t Symbol::getSize() {return borderSize;}