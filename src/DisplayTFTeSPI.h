#include <Arduino.h>
#include <tft_espi.h>
#include <SPI.h>
#include <array>
// #include <LittleFS.h>

#include "Display.h"

#pragma once

class DisplayTFTeSPI: public Display {
private:
  TFT_eSPI tft;
  uint16_t colorTo565(const Color& color);
  uint16_t colorTo565(uint8_t r, uint8_t g, uint8_t b);

public:
  DisplayTFTeSPI();
  DisplayTFTeSPI(std::array<uint16_t, 5> calData);
  DisplayTFTeSPI(const DisplayTFTeSPI& other);
  DisplayTFTeSPI& operator=(const DisplayTFTeSPI& other);

  void init() override;

    /*-----------------------------------------------------------------------------------------*/

    // pos_x    pos_y  size_x   size_y  border  border_color  radius    infill_color
    void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color& border_color, uint8_t radius, const Color& infill_color) override;
    void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color& border_color, const Color& infill_color) override;
    void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color& border_color, uint8_t radius) override;
    void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color& border_color) override;
    // pos_x    pos_y   d   border  border_color    infill_color
    void circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color, const Color& infill_color) override;
    void circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color) override;

    // pos_x    pos_y  size_x   size_y  text_size
    void text(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const char* text, const Color& text_color) override;
    void text_center(const uint16_t pos_x, const uint16_t pos_y, const uint8_t text_size, const char* text, const Color& text_color) override;

    // x1   y1  x2  y2  wide    color
    void line(const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color& color) override;

    // x1   y1    color
    void point(const uint16_t x1, const uint16_t y1, const Color& color) override;

    // color
    void fillScreen(const Color& color) override;

    /*-----------------------------------------------------------------------------------------*/

    int16_t getHeight() override;
    int16_t getWigth() override;

    uint8_t getRotation() override;

    int16_t getTouch(uint16_t* x, uint16_t* y) override;

    TFT_eSPI& getTFTObjekt();
    void startTouchCalibration();

private:
    uint8_t rotation = 0;
    std::array<uint16_t, 5> calData;
};
