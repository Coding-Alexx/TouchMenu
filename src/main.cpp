#include <Arduino.h>
#include <TFT_eSPI.h>

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

void setup_TML() {

  TML.init();

  // disp->startTouchCalibration();

  CREATE_GRID_SCREEN(TML, 10, 3, 3, COLOR_LIGHT_CYAN,
    // std::make_tuple(new RoundButton(  "AN", COLOR_RED,    "AUS", COLOR_GREEN,          COLOR_YELLOW,                   callback), 1, 0, 2, 2),
    std::make_tuple(new RoundButton(  "Ein",  COLOR_YELLOW, "Aus",  COLOR_DARK_GREEN,     COLOR_GRAY,      COLOR_BLACK,   callback), 0, 1, 1, 1),
    std::make_tuple(new ToggleSwitch("ON", COLOR_GREEN, COLOR_BLACK, "OFF", COLOR_BLACK, COLOR_RED, COLOR_BLACK, callback), 0 , 0 , 1 , 1 ),
    std::make_tuple(new RectButtonCircle(  "ON",  COLOR_DARK_MAGENTA, "OFF",  COLOR_BROWN,     COLOR_GRAY,      COLOR_BLACK, 7, callback), 0, 2, 1, 1),
    std::make_tuple(new RectButtonCircle(  "ON",  COLOR_DARK_GREEN, "OFF",  COLOR_DARK_RED, COLOR_DARK_BLUE, 9, callback), 1, 2, 2, 1)
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

  
  // TFT_eSPI tft = TFT_eSPI();
  // tft.begin();

  // unsigned long startTime = micros();
  // for (int16_t y = 0; y < tft.height(); y++) {
  //     for (int16_t x = 0; x < tft.width(); x++) {
  //         tft.drawPixel(x, y, TFT_GREEN);
  //     }
  // }
  // unsigned long endTime = micros();
  // LOGGER_PATTERN("Ausführzeit mit einzelnen Punkten: _ (_ - _)", (endTime - startTime), endTime, startTime);

  // unsigned long startTime2 = micros();
  // tft.fillRect(0, 0, tft.width(), tft.height(), TFT_BLUE);
  // unsigned long endTime2 = micros();
  // LOGGER_PATTERN("Ausführzeit mit Rechteck: _ (_ - _)", (endTime2 - startTime2), endTime2, startTime2)
  // LOGGER_PATTERN("Bessere Aufführzeit: _", (endTime - startTime) - (endTime2 - startTime2));

  // mit Punkte: 832,075ms  -> 0,8s
  // mit Rechteck: 46,719ms -> 0,04s
  // nmit 8x7 Bitmap: 1086ms -> 0,001s

  // const uint16_t bitmapWidth = tft.width();
  // const uint16_t bitmapHeight = tft.height();
  // uint16_t bitmap[bitmapWidth * bitmapHeight];
  // for (uint16_t y = 0; y < bitmapHeight; y++) {
  //   for (uint16_t x = 0; x < bitmapWidth; x++) {
  //     // Beispielhaft: Weise jedem Pixel eine zufällige Farbe zu
  //     bitmap[y * bitmapWidth + x] = tft.color565(random(256), random(256), random(256));
  //   }
  // }

  // uint16_t foregroundColor = TFT_WHITE;
  // uint16_t backgroundColor = TFT_PINK;

  // unsigned long startTime3 = micros();
  // // Zeichne die Bitmap auf dem Display
  // tft.startWrite();
  // for (int16_t row = 0; row < bitmapHeight; row++) {
  //   tft.setAddrWindow(0, 0 + row, 0 + bitmapWidth - 1, 0 + row);
  //   tft.pushColors(&bitmap[row * bitmapWidth], bitmapWidth, false);
  // }
  // tft.endWrite();
  // unsigned long endTime3 = micros();
  // LOGGER_PATTERN("Ausführzeit mit Bitmap: _ (_ - _)", (endTime3 - startTime3), endTime3, startTime3)
  
  // unsigned long startTime3 = micros();
  // for (auto i = 1; i < tft.height()/3; i += 5)
  //   tft.drawLine(0, i, tft.width()/3, i, TFT_ORANGE);
  // unsigned long endTime3 = micros();
  // LOGGER_PATTERN("Ausführzeit mit einzelnen Linien: _ (_ - _)", (endTime3 - startTime3), endTime3, startTime3)

  // unsigned long startTime4 = micros();
  // tft.fillRect(0, 0, tft.width()/3, tft.height()/3, TFT_DARKGREEN);
  // for (auto i = 1; i < tft.height()/3; i += 5)
  //   tft.drawLine(0, i, tft.width()/3, i, TFT_ORANGE);
  // unsigned long endTime4 = micros();
  // LOGGER_PATTERN("Ausführzeit mit Füllung + Linien: _ (_ - _)", (endTime4 - startTime4), endTime4, startTime4)

}

void loop() {
  TML.loop();
}