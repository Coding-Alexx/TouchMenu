#include <Arduino.h>
#include <tuple>

/*
  Simple "Hello World" for ILI9341 LCD

  https://wokwi.com/arduino/projects/308024602434470466
*/

#include "TouchMenuLib.h"

//TouchMenuLib TML(DisplayGFX(TFT_CS, TFT_DC));
TouchMenuLib TML(new DisplayTFTeSPI());

void callback (bool) {
  TML.back();
}



void setup_TML() {
  // GridScreen* screen1 = new GridScreen(3, 2, Color(0, 0, 128), {
  //   {new RoundButton(COLOR_BLUE, COLOR_GREEN, callback), 1, 1, 1, 1},
  //   {new RoundButton(COLOR_BLUE, COLOR_GREEN, callback), 1, 1, 1, 1}
  // });
  
  GridScreen* screen1 = new GridScreen(3, 2, Color(0, 0, 128 ), {
    // FRAGE: Wie kann man das besser machen (ohne make_tuple)
    std::make_tuple(new RoundButton(COLOR_BLUE, COLOR_GREEN, callback), 1, 1, 1, 1)
  });

  // GridScreen* screen2 = new GridScreen(3, 2, Color(0, 0, 128 ));
  // screen2->add(new RoundButton(COLOR_BLUE, COLOR_GREEN, callback), 1, 1, 1, 1);

  ErrorSreen* error = new ErrorSreen("Hello World", "Dies ist ein kleiner Test");

  TML.add(99, error);
  TML.add(0, screen1);
  //TML.add(1, screen2);

  TML.init();
}

void setup() {
  // tft.begin();

  // tft.fillRect(0,0,320, 240, 255255255);

  // tft.setCursor(26, 120);
  // tft.setTextColor();
  // tft.setTextSize(3);
  // tft.println("Hello, TFT!");

  // tft.setCursor(20, 160);
  // tft.setTextColor(ILI9341_GREEN);
  // tft.setTextSize(2);
  // tft.println("I can has colors?");

  Serial.begin(9600);
  Serial.println("Beginn:");

  setup_TML();

  // DisplayTFTeSPI d = DisplayTFTeSPI();
  // d.init();
  // d.fillScreen(COLOR_GREEN);
}

void loop() {
  TML.loop();
}