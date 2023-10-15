#ifdef TestInPlattformIO

// #include "../examples/Calculator/Calculator.ino"
// #include "../examples/Demo/Demo.ino"

// /*
#include <Arduino.h>
#include <algorithm>

#include "TouchMenuLib.h"

TouchMenuLib TML(new DisplayTFTeSPI());

#ifndef PIO_UNIT_TESTING

void setup() {
  LOGGER_BEGIN(9600)

  TML.init(2);

  // TML.getDisplay().text(150, 100, 100, 50, "Hello!", COLOR_BROWN);
  // TML.getDisplay().text(120, 200, 200, 150, "World", COLOR_BROWN);
  // TML.getDisplay().text(150, 260, 100, 20, "dud", COLOR_BROWN);
  // TML.getDisplay().text(150, 50, 250, 100, "-12", COLOR_BROWN);

  ListScreen* screen = new ListScreen(3, COLOR_LIGHT_BLUE);
  TML.add(1, screen);
  screen->add(new Button_Rect("2", COLOR_BLUE + COLOR_DARK_BLUE, 3, 4, TML_empty_button));
  screen->add(new Button_Rect("1", COLOR_BLUE + COLOR_DARK_BLUE, 3, 4, TML_empty_button)); // bei diesem Button hier gibt es einen Farbfehler -> Grund nicht gefunden
  screen->add(new Button_Rect("3", COLOR_BLUE + COLOR_DARK_BLUE, 3, 4, TML_empty_button));
  screen->add(new Button_Rect("4", COLOR_BLUE + COLOR_DARK_BLUE, 3, 4, TML_empty_button));
  screen->add(new Button_Rect("5", COLOR_BLUE + COLOR_DARK_BLUE, 3, 4, TML_empty_button));
  screen->add(new Button_Rect("6", COLOR_BLUE + COLOR_DARK_BLUE, 3, 4, TML_empty_button));
  screen->add(new Button_Rect("7", COLOR_BLUE + COLOR_DARK_BLUE, 3, 4, TML_empty_button));
  screen->add(new Button_Rect("8", COLOR_BLUE + COLOR_DARK_BLUE, 3, 4, TML_empty_button));
  
}

void loop() {
  TML.loop();
}

#endif

// */

#endif