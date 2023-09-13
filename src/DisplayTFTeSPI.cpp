#include "DisplayTFTeSPI.h"
#include <string>
#include <sstream>

DisplayTFTeSPI::DisplayTFTeSPI():
    tft(),
    calData({0,0,0,0,0})
{}

DisplayTFTeSPI& DisplayTFTeSPI::operator= (const DisplayTFTeSPI& other){
    //tft = other.tft;
    return *this;
}

void DisplayTFTeSPI::init() {
    tft.begin();
    tft.setRotation(1);
    //tft.setTouch(calData.data());
    //tft.setSwapBytes(true);
    // if (!LittleFS.begin()) {
    //     Serial.println("Fehler beim Initialisieren von LittleFS");
    //     return;
    // }
}

// mit sprite.createSprite(tft.width(), tft.height()); kann man Teilaktualisierungen machen

/*-----------------------------------------------------------------------------------------*/


void DisplayTFTeSPI::rect(const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color) {
    tft.fillRoundRect(x, y, width, height, border_radius, colorTo565(border_color));
    tft.fillRoundRect(x + border_size, y + border_size, width - (border_size*2), height - (border_size*2), border_radius, colorTo565(infill_color));
}

void DisplayTFTeSPI::rect(const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color) {
    for (uint8_t i = 0; i < border_size; i++) {
        tft.drawRoundRect(x - i, y - i, width + 2 * i, height + 2 * i, border_radius + i, colorTo565(border_color));
    }
}

void DisplayTFTeSPI::rect_center(const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color) {
    rect (x - width/2, y - height/2, width, height, border_size, border_radius, border_color, infill_color);
}

void DisplayTFTeSPI::rect_center(const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color) {
    rect (x - width/2, y - height/2, width, height, border_size, border_radius, border_color);
}

void DisplayTFTeSPI::circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color, const Color& infill_color) {
    LOGGER_PATTERN("border=_, d=_", border_size, d)
    uint16_t r = 0;
    if (d >= 2) r = d/2;

    if (border_size >= 2) tft.fillCircle(pos_x, pos_y, r, colorTo565(border_color));
    tft.fillCircle(pos_x, pos_y, r - (border_size/2), colorTo565(infill_color));
}

void DisplayTFTeSPI::circle(const uint16_t x, const uint16_t y, const uint16_t d, const uint8_t border_size, const Color& border_color) {
    tft.drawCircle(x, y, d/2, colorTo565(border_color));
}

void DisplayTFTeSPI::triangle(const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color, const Color& infill_color) {
    tft.fillTriangle(pos_x0, pos_y0, pos_x1, pos_y1, pos_x2, pos_y2, colorTo565(infill_color));
    // triangle(pos_x0, pos_y0, pos_x1, pos_y1, pos_x2, pos_y2, border_size, border_color);
}

void DisplayTFTeSPI::triangle(const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color) {
    tft.drawLine(pos_x0, pos_y0, pos_x1, pos_y1, colorTo565(border_color));
    tft.drawLine(pos_x1, pos_y1, pos_x2, pos_y2, colorTo565(border_color));
    tft.drawLine(pos_x2, pos_y2, pos_x0, pos_y0, colorTo565(border_color));
}

// Automatisches Formatieren des Textes (Automatosche Größe und Zeilenumbrüche)
void DisplayTFTeSPI::text(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const char* text, const Color& text_color) {
    tft.setTextColor(colorTo565(text_color));
    tft.setCursor(pos_x, pos_y);
    tft.setTextSize(1);
    tft.println(text);
    return;
    // // Kopie des Textes erstellen
    // std::string text_copy = text;
    
    // // Schriftgröße ermitteln
    // uint8_t text_size = 1;
    // tft.setTextSize(text_size);
    // int16_t text_width = tft.textWidth(text); // geht nicht (DS3231 Libary hat einen Bug, die den ESP32 abstürtzen lässt): https://github.com/Bodmer/TFT_eSPI/issues/275
    
    // // Text in Zeilen aufteilen
    // int16_t max_text_width = width - 2; // Breite des Rechtecks mit Rand
    // uint16_t num_lines = 1;
    // if (text_width > max_text_width) {
    //     text_size = 2;
    //     tft.setTextSize(text_size);
    //     text_width = tft.textWidth(text);
    //     num_lines = 2;
    // }
    
    // if (text_width > max_text_width) {
    //     // Versuche, den Text in drei Zeilen aufzuteilen
    //     text_size = 1;
    //     tft.setTextSize(text_size);
    //     int16_t max_line_width = max_text_width / 3;
    //     // uint16_t text_length = text_copy.length();
    //     // uint16_t line_break_index = 0;
    //     int16_t line_width = 0;
        
    //     for (uint16_t i = 0; i < text_copy.length(); i++) {
    //         char current_char = text_copy[i];
    //         int16_t char_width = tft.textWidth(&current_char, 1);
            
    //         if (line_width + char_width > max_line_width) {
    //             text_copy.insert(i, "\n"); // Zeilenumbruch einfügen
    //             line_width = 0;
    //             num_lines++;
    //         }
            
    //         line_width += char_width;
    //     }
    // }
    
    // // Text zeichnen
    // tft.setTextColor(colorTo565(text_color));
    // tft.setCursor(pos_x, pos_y + (height - (text_size * 8 * num_lines)) / 2);
    // tft.setTextSize(text_size);
    // tft.println(text_copy.c_str());
}


void DisplayTFTeSPI::text_center(const uint16_t pos_x, const uint16_t pos_y, const uint8_t text_size, const char* text, const Color& text_color) {
    uint16_t size = 1;
    if (text_size > 1 && text_size <= 10) size = text_size;
    LOGGER(size)

    tft.setTextSize(size); // Textgröße festlegen
    tft.setTextDatum(MC_DATUM); // Mittelpunkt als Bezugspunkt für den Text setzen
    //tft.setCursor(pos_x, pos_y); // Textposition festlegen
    tft.setTextColor(colorTo565(text_color)); // Textfarbe festlegen (hier: Weiß)
    tft.setTextFont(1); // Textschriftart festlegen (optional, falls gewünscht)

    tft.drawString(text, pos_x, pos_y); // Text auf dem Display zeichnen
}

void DisplayTFTeSPI::line(const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color& color) {
    tft.drawLine(x1, y1, x2, y2, colorTo565(color));
}

void DisplayTFTeSPI::point(const uint16_t x1, const uint16_t y1, const Color& color) {
    tft.drawPixel(x1, y1, colorTo565(color));
}

void DisplayTFTeSPI::fillScreen(const Color& color) {
    tft.fillScreen(colorTo565(color));
}

uint16_t DisplayTFTeSPI::colorTo565(const Color& color) {
    return colorTo565(color.getRed(), color.getGreen(), color.getBlue());
}

uint16_t DisplayTFTeSPI::colorTo565(const uint8_t r, const uint8_t g, const uint8_t b) {
    return tft.color565(r, g, b);  // Rückgabe des Farbwerts im 565-Format
}

uint16_t DisplayTFTeSPI::getHeight() {
    return tft.height();
}

uint16_t DisplayTFTeSPI::getWidth() {
    return tft.width();
}

uint8_t DisplayTFTeSPI::getRotation() {
    return tft.getRotation();
}

void DisplayTFTeSPI::setRotation(uint8_t rotation) {
    tft.setRotation(rotation);
}

bool DisplayTFTeSPI::getTouch(uint16_t* x, uint16_t* y) {
    if (!x || !y) LOGGER_ERROR("x oder y ist ein Null Pointer")
    return (tft.getTouch(x, y) != 0);
}

TFT_eSPI& DisplayTFTeSPI::getTFTObjekt() {
    return tft;
}

void DisplayTFTeSPI::startTouchCalibration(){
    uint16_t calData[5];
    tft.calibrateTouch(calData, colorTo565(COLOR_MAGENTA), colorTo565(COLOR_BLACK), 15);
    std::ostringstream stm;
    stm << "{";
    for (uint8_t i = 0; i < 5; i++) {
        // str += std::to_string(static_cast<int>(calData[i]));
        stm << (int) calData[i];
        if (i < 4) stm << ", ";
    }
    stm << "}";
    
    if (Serial.available()) {
        Serial.print("Kalibrierungsdaten:"); 
        Serial.println(stm.str().c_str());
    }

    fillScreen(COLOR_LIGHT_CYAN);
    text_center(tft.width()/2,     tft.height()/3, 1, "Kalibrierungsdaten:", COLOR_BLACK);
    text_center(tft.width()/2, 2 * tft.height()/3, 1, stm.str().c_str(), COLOR_BLACK);
}

void DisplayTFTeSPI::drawBitmap(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor){
    tft.drawBitmap(x, y, bitmap, w, h, colorTo565(fgcolor));
    
    //void TFT_eSPI::draw Bitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color)
    //void TFT_eSPI::draw Bitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t fgcolor, uint16_t bgcolor)
    //void TFT_eSPI::drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color) // Bild ist in XBM array gespeichert
    //void TFT_eSPI::drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bgcolor)
}

void DisplayTFTeSPI::drawBitmap(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor, const Color& bgcolor){
    tft.drawBitmap(x, y, bitmap, w, h, colorTo565(fgcolor), colorTo565(bgcolor));
}