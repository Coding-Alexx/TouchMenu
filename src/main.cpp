#include <Arduino.h>

/*
  Simple "Hello World" for ILI9341 LCD

  https://wokwi.com/arduino/projects/308024602434470466
*/

#include "TouchMenuLib.h"

//TouchMenuLib TML(DisplayGFX(TFT_CS, TFT_DC));
//auto* disp = new DisplayTFTeSPI({383, 3445, 233, 3541, 7 }); //V1:{414, 3383, 254, 3497, 7 } V2:{383, 3445, 233, 3541, 7 } 
TouchMenuLib TML(new DisplayTFTeSPI());

void callback (bool) {
  TML.back();
}

// todo: so ändern, dass es auch mit int funktionieren würde
void callbackSlider (int16_t) {
  TML.back();
}

void setup_TML() {

  TML.init();

  // disp->startTouchCalibration();

  CREATE_GRID_SCREEN(TML, 10, 3, 3, COLOR_LIGHT_CYAN,
    // std::make_tuple(new RoundButton(  "AN", COLOR_RED,    "AUS", COLOR_GREEN,          COLOR_YELLOW,                   callback), 1, 0, 2, 2),
    std::make_tuple(new RoundButton(  "Ein",  COLOR_YELLOW, "Aus",  COLOR_DARK_GREEN,     COLOR_GRAY,      COLOR_BLACK,   callback), 0, 1, 1, 1),
    std::make_tuple(new ToggleSwitch("ON", COLOR_GREEN, COLOR_BLACK, "OFF", COLOR_BLACK, COLOR_RED, COLOR_BLACK, callback), 0 , 0 , 1 , 1 ),
    std::make_tuple(new RectButtonCircle(  "ON",  COLOR_DARK_MAGENTA, "OFF",  COLOR_BROWN,     COLOR_GRAY,      COLOR_BLACK, 7, callback), 0, 2, 1, 1),
    std::make_tuple(new Slider_Rect(COLOR_GREEN, COLOR_RED, COLOR_LIGHT_YELLOW, COLOR_BLACK, callbackSlider), 1, 2, 2, 1),
    std::make_tuple(new Slider_Rect(COLOR_GREEN, COLOR_RED, COLOR_LIGHT_YELLOW, COLOR_BLACK, callbackSlider), 1, 0, 1, 2)
  );

  //TML.goTo(30);

  TML.draw();
}

#ifndef PIO_UNIT_TESTING

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

  LOGGER_BEGIN(9600)

  setup_TML();

  // DisplayTFTeSPI d = DisplayTFTeSPI();
  // d.init();
  // d.fillScreen(COLOR_GREEN);
}

void loop() {
  TML.loop();
}

#endif
