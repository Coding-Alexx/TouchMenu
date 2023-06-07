#include <Arduino.h>

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

  TML.init();
  CREATE_GRID_SCREEN(TML, 10, 3, 3, COLOR_GREEN,
    std::make_tuple(new RoundButton(10, COLOR_BLUE, COLOR_YELLOW, callback), 1, 1, 1, 1),
    std::make_tuple(new RoundButton(10, COLOR_BLUE, COLOR_RED, callback), 0, 0, 2, 2)
  );

  // CREATE_GRID_SCREEN(TML, 80, 0, 0, COLOR_RED,
    
  // );

  /* Problem: 
      um Display Maße für die Position der Elemente zu erhalten, muss man das Display inizialisieren
      außerdem muss man Screens erst hinzufügen und anschließend Elemente hinzufügen

    Lösung: alles umdrehen -> erst TML.init(), erst new Screen und direkt danach TML.add, erst danach Elemente anpassen
  */ 

  //ErrorScreen* error = new ErrorScreen("Hello World", "Dies ist ein kleiner Test");
  //TML.add(99, error);
  //CREATE_ERROR_SCREEN(TML, 1, "Hello World", "Dies ist ein kleiner Test")
  //CREATE_ERROR_SCREEN_with_Colors(TML, 2, "Hello World", "Dies ist ein kleiner Test", COLOR_BLACK, COLOR_BLUE)

  // TML.add(3, new ErrorScreen("Hello World", "Dies ist kein Test"));

  // So geht es nicht: -> in C++ ist es nicht definiert, in welcher Reihnfolge die Objekte erstellt werden
  // GridScreen* screen1 = new GridScreen(3, 2, Color(0, 0, 128), {
  //   {new RoundButton(COLOR_BLUE, COLOR_GREEN, callback), 1, 1, 1, 1},
  //   {new RoundButton(COLOR_BLUE, COLOR_GREEN, callback), 1, 1, 1, 1}
  // });

  //TouchMenuLib, ScreenID, col, raw, color, elements
  // CREATE_GRID_SCREEN(TML, 10, 3, 2, Color(0, 0, 128),
  //   std::make_tuple(new RoundButton(10, COLOR_BLUE, COLOR_GREEN, callback), 1, 1, 1, 1),
  //   std::make_tuple(new RectButton(10, callback), 2, 1, 2, 2)
  // );

  // CREATE_GRID_SCREEN(TML, 11, 3, 2, Color(0, 0, 128),
  //   std::make_tuple(new RoundButton(4, COLOR_BLUE, COLOR_GREEN, callback), 1, 1, 1, 1),
  //   std::make_tuple(new RoundButton(5, COLOR_BLUE, COLOR_GREEN, callback), 1, 1, 1, 1)
  // );

  // // So machen:
  // GridScreen* gridScreen = new GridScreen(3, 2, Color(0, 0, 128 ));
  // gridScreen->add(new RoundButton(3, COLOR_BLUE, COLOR_GREEN, callback), 1, 1, 1, 1);
  // gridScreen->add(new RectButton(10, callback), 2, 1, 2, 2);
  // TML.add(78, gridScreen);
  // oder Factory Pattern

  // TML.goTo(10, false);

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