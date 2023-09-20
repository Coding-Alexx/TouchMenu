/*
    - nur die Basics, die men benötigt, um ein Menü aufzubauen
    - Soll als Startvorlage dienen können
    - eventuell Liste aller Screens, Elemente und Items
*/

#include "TouchMenuLib.h"

TouchMenuLib TML(new DisplayTFTeSPI());

void callbackSlider (int16_t state) {
    Serial.print("Slider is moved to:");
    Serial.println(state);
}

void callbackButton () {
    Serial.println("Butten was pressed");
}

void callbackSwitch (bool state) {
    Serial.print("Switch is now in State ");
    Serial.println(state? "on": "off");
}

void setup() {
    
    // initiate menu and display
    // 0 - default Rotation, 1 - 90° Rotation (default), 2 - 180° Rotation, 3 - 270° Rotation
    TML.init(1);

    // the first Screen is the defauled used Screen
    // CREATE_GRID_SCREEN(TouchMenuLib instance, screen ID, columns, rows, backgroundcolor, elements)
    // the screen ID must be unique and greater than zero, otherwise it can be freely chosen
    CREATE_GRID_SCREEN(TML, 11, 3, 2, COLOR_LIGHT_CYAN,

        // Item Up/Left, Item Down/Right, Color, show number?, callback, value pointer
        AddElement(new Slider_Arrow("", "", (COLOR_LIGHT_BLUE|COLOR_GREEN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_RED), true, callbackSlider), 0, 0, 2, 4),

        // Item On, Item Off, Color, callback, value pointer
        AddElement(new RoundButton("", "", (COLOR_GREEN|COLOR_GRAY|COLOR_DARK_RED) + (COLOR_RED|COLOR_DARK_CYAN|COLOR_DARK_GREEN),   callbackButton), 2, 2, 2, 2),

        // Item On, Item Off, show circle indicator?, Color, border size, border Radius, callback, value pointer
        AddElement(new RectButton("", "",  true, (COLOR_GREEN|COLOR_GRAY|COLOR_DARK_RED) + (COLOR_RED|COLOR_DARK_CYAN|COLOR_DARK_GREEN), 2, 2,  callbackSwitch), 2, 2, 2, 2)
    )

    // a Second Screen
    CREATE_GRID_SCREEN(TML, 12, 3, 2, Color(128, 128, 128),

        // Button in go back mode
        AddElement(new RoundButton("", "", (COLOR_GREEN|COLOR_GRAY|COLOR_DARK_RED) + (COLOR_RED|COLOR_DARK_CYAN|COLOR_DARK_GREEN),   callbackButton), 2, 2, 2, 2),
    )
}

void loop() {

}