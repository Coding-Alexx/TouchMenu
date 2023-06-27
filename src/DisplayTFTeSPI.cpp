#include "DisplayTFTeSPI.h"
#include <string>

DisplayTFTeSPI::DisplayTFTeSPI():
    tftObj(),
    tftSprite(&tftObj),
    tft(&tftObj),
    calData({0,0,0,0,0})
{}

DisplayTFTeSPI& DisplayTFTeSPI::operator= (const DisplayTFTeSPI& other){
    //tft = other.tft;
    return *this;
}

void DisplayTFTeSPI::init() {
    tftObj.begin();
    tftObj.setRotation(1);
    tftObj.setTouch(calData.data());
    //tft.setSwapBytes(true);
    // if (!LittleFS.begin()) {
    //     Serial.println("Fehler beim Initialisieren von LittleFS");
    //     return;
    // }
}

// mit sprite.createSprite(tft.width(), tft.height()); kann man Teilaktualisierungen machen

/*-----------------------------------------------------------------------------------------*/


void DisplayTFTeSPI::rect(const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color) {
    tft->fillRoundRect(x - width / 2, y - height / 2, width, height, border_radius, colorTo565(border_color));
    tft->fillRoundRect(x - width / 2 + border_size, y - height / 2 + border_size, width - (border_size*2), height - (border_size*2), border_radius, colorTo565(infill_color));
}

void DisplayTFTeSPI::rect(const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color) {
    for (uint8_t i = 0; i < border_size; i++) {
        tft->drawRoundRect(x - width / 2 - i, y - height / 2 - i, width + 2 * i, height + 2 * i, border_radius + i, colorTo565(border_color));
    }
}

void DisplayTFTeSPI::circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color, const Color& infill_color) {
    LOGGER_PATTERN("border=_, d=_", border_size, d)
    uint16_t r = 0;
    if (d >= 2) r = d/2;

    if (border_size >= 2) tft->fillCircle(pos_x, pos_y, r, colorTo565(border_color));
    tft->fillCircle(pos_x, pos_y, r - (border_size/2), colorTo565(infill_color));
}

void DisplayTFTeSPI::circle(const uint16_t x, const uint16_t y, const uint16_t d, const uint8_t border_size, const Color& border_color) {
    tft->drawCircle(x, y, d/2, colorTo565(border_color));
}

// Automatisches Formatieren des Textes (Automatosche Größe und Zeilenumbrüche)
void DisplayTFTeSPI::text(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const char* text, const Color& text_color) {
    tft->setTextColor(colorTo565(text_color));
    tft->setCursor(pos_x, pos_y);
    tft->setTextSize(1);
    tft->println(text);
}


void DisplayTFTeSPI::text_center(const uint16_t pos_x, const uint16_t pos_y, const uint8_t text_size, const char* text, const Color& text_color) {
    uint16_t size = 1;
    if (text_size > 1 && text_size <= 10) size = text_size;
    LOGGER(size)

    tft->setTextSize(size); // Textgröße festlegen
    tft->setTextDatum(MC_DATUM); // Mittelpunkt als Bezugspunkt für den Text setzen
    //tft.setCursor(pos_x, pos_y); // Textposition festlegen
    tft->setTextColor(colorTo565(text_color)); // Textfarbe festlegen (hier: Weiß)
    tft->setTextFont(1); // Textschriftart festlegen (optional, falls gewünscht)

    tft->drawString(text, pos_x, pos_y); // Text auf dem Display zeichnen
}

void DisplayTFTeSPI::line(const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color& color) {
    tft->drawLine(x1, y1, x2, y2, colorTo565(color));
}

void DisplayTFTeSPI::point(const uint16_t x1, const uint16_t y1, const Color& color) {
    tft->drawPixel(x1, y1, colorTo565(color));
}

void DisplayTFTeSPI::fillScreen(const Color& color) {
    tft->fillScreen(colorTo565(color));
}

uint16_t DisplayTFTeSPI::colorTo565(const Color& color) {
    return colorTo565(color.getRed(), color.getGreen(), color.getBlue());
}

uint16_t DisplayTFTeSPI::colorTo565(uint8_t r, uint8_t g, uint8_t b) {
    // r = 255 - r;  // Invertierung von Rot
    // g = 255 - g;  // Invertierung von Grün
    // b = 255 - b;  // Invertierung von Blau

    return tftObj.color565(r, g, b);  // Rückgabe des Farbwerts im 565-Format
}

int16_t DisplayTFTeSPI::getHeight() {
    return tftObj.height();
}

int16_t DisplayTFTeSPI::getWigth() {
    return tftObj.width();
}

uint8_t DisplayTFTeSPI::getRotation() {
    return tftObj.getRotation();
}

int16_t DisplayTFTeSPI::getTouch(uint16_t* x, uint16_t* y) {
    if (x == nullptr || y == nullptr) LOGGER("x oder y sind ein Null Pointer")
    return tftObj.getTouch(x, y);
}

TFT_eSPI& DisplayTFTeSPI::getTFTObjekt() {
    return tftObj;
}

void DisplayTFTeSPI::startTouchCalibration(){
    uint16_t calData[5];
    tftObj.calibrateTouch(calData, colorTo565(COLOR_MAGENTA), colorTo565(COLOR_BLACK), 15);
    Serial.print("-> Kalibrierungsdaten: {");
    for (uint8_t i = 0; i < 5; i++) {
        Serial.print(calData[i]);
        if (i < 4) Serial.print(", ");
    }
    Serial.println(" }");
}

void DisplayTFTeSPI::setGroup(const uint16_t w, const uint16_t h) {
    tft = &tftSprite;
    if (!tftSprite.created()) {
        // TODO: Sprite größe so wählen, dass die meisten Elemente gut reinpassen
        tftSprite.createSprite(w, h);
    } else {
        // TODO: sprite größe anpassen
        //tftSprite.setPivot(); -> ermöglicht es den Referenzpunkt innerhalb des Sprite zu verschieben und somit zu verkleinern
        // Sprites kann man auch Skalieren
    }
    tft->fillScreen(colorTo565(COLOR_LIGHT_BLUE));
}

// Zeichne die Gruppe und setzte das Display wieder in den normalen Modus
void DisplayTFTeSPI::drawGroup(const uint16_t x, const uint16_t y) {
    tftSprite.pushSprite(x, y);
    tft = &tftObj;
}