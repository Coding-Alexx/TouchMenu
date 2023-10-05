/*
    Dieses Beispiel ist nicht Fertig!!!

    Es soll schrittweise die Funktionien dieser Bibliothek zeigen und erklären, wie all diese Funktionen in seinen Projekten umsetzen kann
    
    Tutorials:
        - Aufbau: Screens -> Elemente -> Items
        - Button modes
        - Button Callback
        - Number Input -> Slider
        - Number Input -> counter

        - Item System
            * Icons

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
        AddElement(new Button_Rect("Item System",      COLOR_LIGHT_BLUE, 1, 1, TML_goTo(TML, 4)), 0, 1, 1, 1),
        AddElement(new Button_Rect("icon:number",      COLOR_LIGHT_BLUE, 1, 1, TML_goTo(TML, 1)), 0, 2, 1, 1)
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

    // Button Modes
    CREATE_GRID_SCREEN_WITH_SITEBAR(TML, 3, 0, 4, 6, Color(200, 200, 255),
        AddElement(new Textbox_Blank("one button has 2 modes:", 1, COLOR_BLACK),                    0, 0, 4, 1),
        AddElement(new Button_Rect("Button Mode", COLOR_GREEN + COLOR_RED, 1, 1, TML_empty_button), 0, 2, 2, 1),
        AddElement(new Button_Rect("Switch Mode", COLOR_GREEN + COLOR_RED, 1, 1, TML_empty_switch), 2, 2, 2, 1)
    )

    // Item System
    CREATE_GRID_SCREEN_WITH_SITEBAR(TML, 4, 0, 4, 6, Color(200, 200, 255),
        AddElement(new Textbox_Blank("Item System", 1, COLOR_BLACK),    0, 0, 4, 1),
        
        // Icon parameter: scale: double (reduces the highest possible resolution),   color: rbg or Color name
        AddElement(new Textbox_Blank("Icons:", 1, COLOR_BLACK),               0, 1, 2, 1),  // Icons are bitmaps (pixel graphics)
        AddElement(new Textbox_Blank("icon:settings", 1, COLOR_BLACK),        2, 1, 1, 1),  // for a list of all icons see src/Item/icon_templates.h
        AddElement(new Textbox_Blank("icon:back color:red", 1, COLOR_BLACK),  3, 1, 1, 1),  // rotate overwrite the default colour of each item -> the RGB variant with colour:20,20,30 is also possible

        // Symbol parameter: scale: double,   color: rbg or Color name,     bordersize: int     borderColor: rgb or Color name      itemColor
        AddElement(new Textbox_Blank("Symbol:", 1, COLOR_BLACK),              0, 2, 2, 1),  // Symbols are created through shapes
        AddElement(new Textbox_Blank("symb:ToggleSwitch", 1, COLOR_BLACK),    2, 2, 1, 1),  // it can also be multicoloured. Currently you can only give a complete colour object in Textbox_Blank or Button_Blank.
        AddElement(new Textbox_Blank("icon:Plus scale:.75", 1, COLOR_BLACK),  3, 2, 1, 1),  // scale scales an item up or down. 1 is the normal state
        
        // Text: Parameter: size
        AddElement(new Textbox_Blank("Text:", 1, COLOR_BLACK),                0, 3, 2, 1),  // text is normal text. 
        AddElement(new Textbox_Blank("text:Hello size:1", 1, COLOR_BLACK),    2, 3, 1, 1),  // If you want to specify parameters, you have to write the keyword in front of it.
        AddElement(new Textbox_Blank("World", 1, COLOR_BLACK),                3, 3, 1, 1),  // Otherwise the whole string is displayed
    )
    
    LOGGER("T6")
    TML.setScreensaver(0, 100 * 1000);
}

void loop() {
    TML.loop();
}