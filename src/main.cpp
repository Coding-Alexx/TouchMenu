#include <Arduino.h>
#include <algorithm>

/*
  Simple "Hello World" for ILI9341 LCD

  https://wokwi.com/arduino/projects/308024602434470466
*/

#include "TouchMenuLib.h"
#include "Screens/TestGridScreen.h"

TouchMenuLib TML(new DisplayTFTeSPI());

// erstelle Pointer mit dem Wert 42 -> Startwert des Sliders
uint16_t* sliderValue = new uint16_t(42);

void callback (bool) {
  
}

void callbackMinus () {
  *sliderValue -= std::min(*sliderValue, static_cast<uint16_t>(10));
  LOGGER_PATTERN("MINUS value:_", *sliderValue);
}

void callbackPlus () {
  *sliderValue += 10;
  LOGGER_PATTERN("PLUS value:_", *sliderValue);
}

// todo: so ändern, dass es auch mit int funktionieren würde
void callbackSlider (int16_t) {
  
}

void setup_TML() {

  TML.init();

  // disp->startTouchCalibration();

  //GridScreen* testRoundBottonScreen = TestGridScreenFactory::create(TML, 2, COLOR_LIGHT_CYAN, new RoundButton(  "Ein",  COLOR_YELLOW, "Aus",  COLOR_DARK_GREEN,     COLOR_GRAY,      COLOR_BLACK,   callback));
  // GridScreen* testRoundBottonScreen = TestGridScreenFactory::create(TML, 3, COLOR_LIGHT_CYAN, new Textbox_Rect("Hello\n World", COLOR_BLACK, COLOR_YELLOW, COLOR_BROWN));
  LOGGER("MAIN")
  CREATE_GRID_SCREEN(TML, 12, 2, 2, COLOR_LIGHT_CYAN,
    std::make_tuple(new RoundButton(  "+",  COLOR_GREEN, "+",  COLOR_DARK_GREEN,     COLOR_BLACK,      COLOR_BLACK,   callbackMinus), 0, 0, 1, 1),
    std::make_tuple(new RoundButton(  "-",  COLOR_RED, "-",  COLOR_DARK_RED,     COLOR_BLACK,      COLOR_BLACK,   callbackPlus), 0, 1, 1, 1),
    std::make_tuple(new Slider_Rect(COLOR_GREEN, COLOR_RED, COLOR_LIGHT_YELLOW, COLOR_BLACK, callbackSlider, sliderValue), 1, 0, 1, 2)
  )

  CREATE_GRID_SCREEN(TML, 14, 4, 4, COLOR_LIGHT_CYAN,
    std::make_tuple(new Slider_Arrow(COLOR_LIGHT_BLUE, COLOR_GREEN, COLOR_BLACK, true, callbackSlider), 0, 0, 2, 4),
    std::make_tuple(new Slider_Arrow(COLOR_LIGHT_BLUE, COLOR_GREEN, COLOR_BLACK, true, callbackSlider), 2, 0, 2, 1),
    // std::make_tuple(new RoundButton(  "+",  COLOR_GREEN, "+",  COLOR_DARK_GREEN,     COLOR_BLACK,      COLOR_BLACK,   callbackMinus), 3, 0, 1, 1)
  )
  TML.goTo(14);

  LOGGER("MAIN2")

  // ERROR: bei id 20 stürtzt es ab, bei id 30 geht es
  // CREATE_GRID_SCREEN(TML, 20, 3, 3, COLOR_LIGHT_CYAN,
    // std::make_tuple(new RoundButton(  "AN", COLOR_RED,    "AUS", COLOR_GREEN,          COLOR_YELLOW,                   callback), 1, 0, 2, 2),
    // std::make_tuple(new RoundButton(  "Ein",  COLOR_YELLOW, "Aus",  COLOR_DARK_GREEN,     COLOR_GRAY,      COLOR_BLACK,   callback), 0, 1, 1, 1),
    // std::make_tuple(new ToggleSwitch("ON", COLOR_GREEN, COLOR_BLACK, "OFF", COLOR_BLACK, COLOR_RED, COLOR_BLACK, callback), 0 , 0 , 1 , 1 ),
    // std::make_tuple(new RectButtonCircle(  "ON",  COLOR_DARK_MAGENTA, "OFF",  COLOR_BROWN,     COLOR_GRAY,      COLOR_BLACK, 7, callback), 0, 2, 1, 1),
    // std::make_tuple(new Slider_Rect(COLOR_GREEN, COLOR_RED, COLOR_LIGHT_YELLOW, COLOR_BLACK, callbackSlider), 1, 2, 2, 1),
    // std::make_tuple(new Slider_Rect(COLOR_GREEN, COLOR_RED, COLOR_LIGHT_YELLOW, COLOR_BLACK, callbackSlider), 1, 0, 1, 2)
  // );

  //TML.goTo(30);

  TML.draw();
}

#ifndef PIO_UNIT_TESTING

void setup() {
  LOGGER_BEGIN(9600)
  setup_TML();

  Item* icon = TML.getDisplay().createItem("icon:arrow_right");
  TML.getDisplay().drawItem(20, 30, icon, COLOR_BLACK);
}

void loop() {
  TML.loop();
}

#endif
