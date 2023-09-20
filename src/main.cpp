#include "../examples/Calculator/Calculator.ino"

/*
#include <Arduino.h>
#include <algorithm>

#include "TouchMenuLib.h"
#include "Screens/TestGridScreen.h"

TouchMenuLib TML(new DisplayTFTeSPI());

// erstelle Pointer mit dem Wert 42 -> Startwert des Sliders
uint16_t* sliderValue = new uint16_t(42);

void callbackSwitch (bool) {
  
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

  TML.init(2);
  // TML.getDisplay().startTouchCalibration();
  // return;

  GridScreen* g;
  g = new GridScreen(1, 3, COLOR_LIGHT_RED);
  TML.addSitebar (1, g, TML.getDisplay().getWidth()/5); // für Doku: diese Zele muss immer vor dem hinzufügen von Elementen stehen! -> sonst gibt es einen abbruch!
  g->add(new RoundButton("Hello", "World", (COLOR_GREEN|COLOR_GRAY|COLOR_DARK_RED) + (COLOR_RED|COLOR_DARK_CYAN|COLOR_DARK_GREEN), callbackSwitch), 0, 1, 1, 1);

  // disp->startTouchCalibration();

  //GridScreen* testRoundBottonScreen = TestGridScreenFactory::create(TML, 2, COLOR_LIGHT_CYAN, new RoundButton(  "Ein",  COLOR_YELLOW, "Aus",  COLOR_DARK_GREEN,     COLOR_GRAY,      COLOR_BLACK,   callback));
  // GridScreen* testRoundBottonScreen = TestGridScreenFactory::create(TML, 3, COLOR_LIGHT_CYAN, new Textbox_Rect("Hello\n World", COLOR_BLACK, COLOR_YELLOW, COLOR_BROWN));
  LOGGER("MAIN")
  // CREATE_GRID_SCREEN(TML, 12, 2, 2, COLOR_LIGHT_CYAN,
  //   std::make_tuple(new RoundButton(  "+",  COLOR_GREEN, "+",  COLOR_DARK_GREEN,     COLOR_BLACK,      COLOR_BLACK,   callbackMinus), 0, 0, 1, 1),
  //   std::make_tuple(new RoundButton(  "-",  COLOR_RED, "-",  COLOR_DARK_RED,     COLOR_BLACK,      COLOR_BLACK,   callbackPlus), 0, 1, 1, 1),
  //   std::make_tuple(new Slider_Rect(COLOR_GREEN, COLOR_RED, COLOR_LIGHT_YELLOW, COLOR_BLACK, callbackSlider, sliderValue), 1, 0, 1, 2)
  // )

  CREATE_GRID_SCREEN(TML, 14, 4, 4, COLOR_GRAY,
    // std::make_tuple(new Slider_Arrow("symb:TriangleUp color:yellow", "symb:TriangleDown", (COLOR_LIGHT_BLUE|COLOR_GREEN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_RED), true, callbackSlider), 0, 0, 2, 4),
    // std::make_tuple(new Slider_Arrow("symb:TriangleLeft color:yellow", "symb:TriangleRight color:0,50,25", (COLOR_LIGHT_BLUE|COLOR_GREEN|Color(255, 255, 0)) + (COLOR_LIGHT_BLUE|COLOR_RED), true, callbackSlider), 2, 0, 2, 1),
    std::make_tuple(new RoundButton(  "Screensaver", "Bildschirmschoner",  (COLOR_GREEN|COLOR_GRAY|COLOR_DARK_RED) + (COLOR_RED|COLOR_DARK_CYAN|COLOR_DARK_GREEN),   callbackSwitch), 2, 2, 2, 2)
  )

  g = new GridScreen(4, 3, COLOR_LIGHT_BLUE);
  TML.add (11, g, 1);
  (*g) 
    << AddElement{new Slider_Arrow("symb:TriangleUp color:yellow", "symb:TriangleDown", (COLOR_LIGHT_BLUE|COLOR_GREEN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_RED), true, callbackSlider), 0, 0, 2, 3}
    // << AddElement{new Slider_Arrow("symb:TriangleLeft color:yellow", "symb:TriangleRight color:0,50,25", (COLOR_LIGHT_BLUE|COLOR_GREEN|Color(255, 255, 0)) + (COLOR_LIGHT_BLUE|COLOR_RED), true, callbackSlider), 2, 0, 2, 1}
    << AddElement{new RoundButton("Hello", "icon:arrow_right", (COLOR_GREEN|COLOR_GRAY|COLOR_DARK_RED) + (COLOR_RED|COLOR_DARK_CYAN|COLOR_DARK_GREEN), callbackSwitch), 2, 1, 2, 2};

  TML.goTo(11);
  TML.setScreensaver(14, 50*1000);

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

  TML.getDisplay().text(150, 100, 100, 50, "Hello!", COLOR_BROWN);
  TML.getDisplay().text(150, 200, 250, 150, "World", COLOR_BROWN);
  TML.getDisplay().text(150, 260, 100, 20, "dud", COLOR_BROWN);
  TML.getDisplay().text(150, 50, 250, 100, "-12", COLOR_BROWN);
}

#ifndef PIO_UNIT_TESTING

void setup() {
  LOGGER_BEGIN(9600)
  // setup_TML();

    TML.init(2);

    TML.getDisplay().text(150, 100, 100, 50, "Hello!", COLOR_BROWN);
    TML.getDisplay().text(120, 200, 200, 150, "World", COLOR_BROWN);
    TML.getDisplay().text(150, 260, 100, 20, "dud", COLOR_BROWN);
    TML.getDisplay().text(150, 50, 250, 100, "-12", COLOR_BROWN);

  // Item* icon1 = TML.getDisplay().createItem("symb:TriangleUp size:1 width:20 height:30");
  // TML.getDisplay().drawItem(20, 30, icon1);

  // Item* icon2 = TML.getDisplay().createItem("symb:TriangleDown size:0 width:20 height:30 color:gray");
  // TML.getDisplay().drawItem(70, 30, icon2);

  // Item* icon3 = TML.getDisplay().createItem("symb:TriangleRight width:20 height:30 color:yellow");
  // TML.getDisplay().drawItem(120, 30, icon3);

  // Item* icon4 = TML.getDisplay().createItem("symb:TriangleLeft size:2 width:20 height:30 color:red, border:0,255,255");
  // TML.getDisplay().drawItem(170, 30, icon4);
}

void loop() {
  TML.loop();
}

#endif

*/