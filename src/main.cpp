#include <Arduino.h>

/*
  Simple "Hello World" for ILI9341 LCD

  https://wokwi.com/arduino/projects/308024602434470466
*/

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 2
#define TFT_CS 15
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

#include "TouchMenuLib.h"

void callback (bool) {}

TouchMenuLib TML(100,100);

void setup_TML() {
  TML.init();
  GridScreen* screen1 = new GridScreen(3, 2, Color(0, 0, 128 ), {
    {new RoundButton(COLOR_BLUE, COLOR_GREEN, callback), 1, 1, 1, 1},
    {new RoundButton(COLOR_BLUE, COLOR_GREEN, callback), 1, 1, 1, 1}
  });
  
  GridScreen* screen2 = new GridScreen(3, 2, Color(0, 0, 128 ));
  screen2->add(new RoundButton(COLOR_BLUE, COLOR_GREEN, callback), 1, 1, 1, 1);

  TML.add(0, screen1);
  TML.add(1, screen2);
}

void setup() {
  // tft.begin();

  // tft.fillRect(0,0,320, 240, 255255255);

  // tft.setCursor(26, 120);
  // tft.setTextColor(ILI9341_RED);
  // tft.setTextSize(3);
  // tft.println("Hello, TFT!");

  // tft.setCursor(20, 160);
  // tft.setTextColor(ILI9341_GREEN);
  // tft.setTextSize(2);
  // tft.println("I can has colors?");

  setup_TML();
}

void loop() {
  TML.loop();
}