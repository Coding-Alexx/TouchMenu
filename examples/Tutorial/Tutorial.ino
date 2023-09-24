/*
    - Menü mit allen Elementen und verschiednenen Screens
    - Verschiedene Darstellungen der Elemente
    - Beispielscreens
    - Funktionsweisen auf einzelnen Screens genauer erklären
    - ...

    Tutorials:
        - Aufbau: Screens -> Elemente -> Items
        - Button modes
        - Button Callback
        - Number Input -> Slider
        - Number Input -> counter

        - Item System
            * Icons

    Idee: eine Datei, wo man seine Icons Speichern kann. Diese werden beim Kompellieren automatisch in Bitmaps umgewandelt und auf den ESP mit hochgeladen
*/

#include "TouchMenuLib.h"

TouchMenuLib TML (new DisplayTFTeSPI());

ExternalTextboxValue textvalue;


void updateTitle() {
    switch (TML.getScreenID()) {
        case 1: textvalue.setValue("structure"); break;
        case 2: 
        case 3: textvalue.setValue("Element: Button"); break;
        
        default: textvalue.setValue("structure"); break;
    }
}

// Go to the next screen in area 1-7
void nextScreen() {
    uint8_t current = TML.getScreenID();
    uint8_t total = TML.getScreensNumber() - 1;

    LOGGER_PATTERN("gehe von Screen _ nach _ von _", current, current%total+1, total)
    TML.goTo(current%total+1);
    updateTitle();
}

// Go to the previous screen in area 1-7
void previousScreen() {
    uint8_t current = TML.getScreenID();
    uint8_t total = TML.getScreensNumber() - 1;
    uint8_t to = current - 1 == 0? total : current-1;

    LOGGER_PATTERN("gehe von Screen _ nach _ von _", current, to, total)
    TML.goTo(to);
    updateTitle();
}

void setup() {

    LOGGER_BEGIN(9600)
    LOGGER("Starting Programm ...")

    TML.init(0);

    // create a sitebar to navigate and display the current page title
    CREATE_GRID_SCREEN_SITEBAR(TML, 0, 40, 0, 5, 1, COLOR_DARK_BLUE, 
        AddElement(new Button_Round("symb:TriangleLeft", COLOR_LIGHT_BLUE, 1, previousScreen), 0, 0, 1, 1),
        AddElement(new Textbox_Blank("", 1, COLOR_BLACK, &textvalue),                          1, 0, 3, 1),
        AddElement(new Button_Round("symb:TriangleRight", COLOR_LIGHT_BLUE, 1, nextScreen),    4, 0, 1, 1)
    )

    // Mian Screen
    CREATE_GRID_SCREEN(TML, 0, 1, 3, Color(200, 200, 255),
        AddElement(new Button_Rect("icon:ButtonClick", COLOR_LIGHT_BLUE, 1, 1, TML_goTo(TML, 1)), 0, 0, 1, 1),
        AddElement(new Button_Rect("icon:number",      COLOR_LIGHT_BLUE, 1, 1, TML_goTo(TML, 1)), 0, 1, 1, 1),
        AddElement(new Button_Rect("icon:text",        COLOR_LIGHT_BLUE, 1, 1, TML_goTo(TML, 1)), 0, 2, 1, 1)
    )

    // structure of this library:
    CREATE_GRID_SCREEN_WITH_SITEBAR(TML, 1, 0, 4, 6, Color(200, 200, 255),
        // TODO: Textausrichtung indigrieren
        AddElement(new Textbox_Blank("structure of this library:", 1, COLOR_BLACK),           0, 0, 4, 1),
        AddElement(new Textbox_Blank("- There are different screens", 1, COLOR_BLACK),        1, 1, 3, 1),
        AddElement(new Textbox_Blank("- each screen has different elements", 1, COLOR_BLACK), 1, 2, 3, 1),
        AddElement(new Textbox_Blank("- each element can have some items", 1, COLOR_BLACK),   1, 3, 3, 1)
        // AddElement(new Button_Rect("icon:text",        COLOR_LIGHT_BLUE, 1, 1, TML_goTo(TML, 1)), 0, 2, 1, 1)
    )

    // Button representations
    CREATE_GRID_SCREEN_WITH_SITEBAR(TML, 2, 0, 4, 7, Color(200, 200, 255),
        AddElement(new Textbox_Blank("Currently there are 3 button", 1, COLOR_BLACK), 0, 0, 4, 1),
        AddElement(new Textbox_Blank("representations", 1,              COLOR_BLACK), 0, 1, 4, 1),

        AddElement(new Textbox_Blank("Round", 1,         COLOR_LIGHT_BLUE), 0, 1, 1, 1),
        AddElement(new Button_Round("icon:text", "icon:text scale:0.5",  COLOR_LIGHT_BLUE  + COLOR_DARK_BLUE, 1, TML_empty_button), 0, 2, 1, 2),

        AddElement(new Textbox_Blank("Rect", 1,          COLOR_LIGHT_BLUE                 ), 1, 1, 1, 1),
        AddElement(new Button_Rect("icon:text",   COLOR_LIGHT_BLUE + COLOR_DARK_BLUE, 1, 1, TML_empty_button), 1, 2, 1, 2),

        AddElement(new Textbox_Blank("Blank", 1,         COLOR_LIGHT_BLUE      ), 2, 1, 1, 1),
        AddElement(new Button_Blank ("icon:text", COLOR_BLACK + COLOR_DARK_BLUE, TML_empty_button), 2, 2, 1, 2)
    )

    // Round Buttons
    CREATE_GRID_SCREEN_WITH_SITEBAR(TML, 3, 0, 4, 6, Color(200, 200, 255),
        AddElement(new Textbox_Blank("one button has 2 modes:", 1, COLOR_BLACK),                    0, 0, 4, 1),
        AddElement(new Button_Rect("Button Mode", COLOR_GREEN + COLOR_RED, 1, 1, TML_empty_button), 0, 2, 2, 1),
        AddElement(new Button_Rect("Switch Mode", COLOR_GREEN + COLOR_RED, 1, 1, TML_empty_switch), 2, 2, 2, 1)
    )
    
    LOGGER("T6")
    TML.setScreensaver(0, 100 * 1000);
}

void loop() {
    TML.loop();
}