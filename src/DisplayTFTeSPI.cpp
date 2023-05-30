#include "DisplayTFTeSPI.h"

DisplayTFTeSPI::DisplayTFTeSPI():
    tft()
{}

DisplayTFTeSPI& DisplayTFTeSPI::operator= (const DisplayTFTeSPI& other){
    //tft = other.tft;
    return *this;
}

void DisplayTFTeSPI::init() {
    tft.begin();
    tft.setRotation(1);
    //tft.setSwapBytes(true);
}

/*-----------------------------------------------------------------------------------------*/

void DisplayTFTeSPI::rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color& border_color, uint8_t radius, const Color& infill_color) {
    // tft.fillRoundRect(pos_x, pos_y, width, height, radius, uint16_t(infill_color));
    // if (border_size > 0) {
    //     tft.drawRoundRect(pos_x, pos_y, width, height, radius, uint16_t(*border_color));
    // }
}

void DisplayTFTeSPI::rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color& border_color, uint8_t radius) {
    rect(pos_x, pos_y, width, height, border_size, border_color, radius, COLOR_BLACK);
}

void DisplayTFTeSPI::rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color& border_color) {
    rect(pos_x, pos_y, width, height, border_size, border_color, 0, COLOR_BLACK);
}

void DisplayTFTeSPI::circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color, const Color& infill_color) {
    // tft.fillCircle(pos_x, pos_y, d / 2, uint16_t(*infill_color));
    // if (border_size > 0) {
    //     tft.drawCircle(pos_x, pos_y, d / 2, uint16_t(*border_color));
    // }
}

void DisplayTFTeSPI::circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color) {

}

void DisplayTFTeSPI::text(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color& text_color) {
    // Füge hier den Code zum Zeichnen des Textes ein
}

void DisplayTFTeSPI::text_center(const uint16_t pos_x, const uint16_t pos_y, const uint8_t text_size, const char* text, const Color& text_color) {
    tft.setTextSize(text_size); // Textgröße festlegen
    tft.setTextDatum(MC_DATUM); // Mittelpunkt als Bezugspunkt für den Text setzen
    //tft.setCursor(pos_x, pos_y); // Textposition festlegen
    tft.setTextColor(reverseColor565(text_color)); // Textfarbe festlegen (hier: Weiß)
    tft.setTextFont(1); // Textschriftart festlegen (optional, falls gewünscht)

    tft.drawString(text, pos_x, pos_y); // Text auf dem Display zeichnen
}

void DisplayTFTeSPI::line(const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color& color) {
    tft.drawLine(x1, y1, x2, y2, reverseColor565(color));
}

void DisplayTFTeSPI::point(const uint16_t x1, const uint16_t y1, const Color& color) {
    tft.drawPixel(x1, y1, reverseColor565(color));
}

void DisplayTFTeSPI::fillScreen(const Color& color) {
    //tft.fillScreen(tft.color565(color.getRed(), color.getGreen(), color.getBlue()));
    //tft.fillScreen(reverseColor565(0, 0, 255));
    tft.fillScreen(reverseColor565(color));
}

uint16_t DisplayTFTeSPI::reverseColor565(const Color& color) {
    return reverseColor565(color.getRed(), color.getGreen(), color.getBlue());
}

uint16_t DisplayTFTeSPI::reverseColor565(uint8_t r, uint8_t g, uint8_t b) {
    // r = 255 - r;  // Invertierung von Rot
    // g = 255 - g;  // Invertierung von Grün
    // b = 255 - b;  // Invertierung von Blau

    return tft.color565(r, g, b);  // Rückgabe des Farbwerts im 565-Format
}

int16_t DisplayTFTeSPI::getHeight() {
    return tft.height();
}

int16_t DisplayTFTeSPI::getWigth() {
    return tft.width();
}