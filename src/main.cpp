#include <Arduino.h>

/*
  Simple "Hello World" for ILI9341 LCD

  https://wokwi.com/arduino/projects/308024602434470466
*/

#include "TouchMenuLib.h"

//TouchMenuLib TML(DisplayGFX(TFT_CS, TFT_DC));
auto* disp = new DisplayTFTeSPI({383, 3445, 233, 3541, 7 }); //V1:{414, 3383, 254, 3497, 7 } V2:{383, 3445, 233, 3541, 7 } 
TouchMenuLib TML(disp);

void callback (bool) {
  TML.back();
}

void setup_TML() {

  TML.init();

  // disp->startTouchCalibration();

  CREATE_GRID_SCREEN(TML, 10, 3, 3, COLOR_LIGHT_CYAN,
    std::make_tuple(new RoundButton(  "Welt", COLOR_RED,    "Hallo", COLOR_GREEN,          COLOR_YELLOW,                   callback), 1, 0, 2, 2),
    std::make_tuple(new RoundButton(  "GO!",  COLOR_YELLOW, "Lets",  COLOR_DARK_GREEN,     COLOR_GRAY,      COLOR_BLACK,   callback), 0, 1, 1, 1),
    std::make_tuple(new RectButtonCircle(  "",  COLOR_NAVY, "",  COLOR_NAVY,     COLOR_GRAY,      COLOR_BLACK, true, callback), 0, 0, 1, 1),
    std::make_tuple(new RectButtonCircle(  "",  COLOR_PURPLE, "",  COLOR_DARK_YELLOW,     COLOR_GRAY,      COLOR_BLACK, false, callback), 2, 2, 1, 1),

  );

  //TML.goTo(30);

  TML.draw();
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

  LOGGER_BEGIN(9600)

  setup_TML();

  // DisplayTFTeSPI d = DisplayTFTeSPI();
  // d.init();
  // d.fillScreen(COLOR_GREEN);
}

void loop() {
  TML.loop();
}