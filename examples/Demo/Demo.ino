/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                     *
 *                     Calculator Keyboard Interface Example                           *
 *   Description:                                                                      *
 *       In this example, you get an overview with all elements.                       *
 *       You will learn to use them to integrate the elements into your projects.      *                                                                              *
 *                                                                                     *
 *   Read our documentation for more information:                                      *
 *      https://touchmenu.readthedocs.io/de/latest/index.html                          *
 *                                                                                     *
 *   Licence:                                                                          *
 *                                                                                     *
 *                                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "TouchMenuLib.h"

TouchMenuLib TML;

ExternalTextboxValue textvalue;
ExternalNumberValue  numberValue;

void updateTitle() {
    switch (TML.getScreenID()) {
        case 1: textvalue.setValue("Buttons"); break;
        case 2: textvalue.setValue("Number Inputs"); break;
        case 3: textvalue.setValue("Text"); break;
        case 4: textvalue.setValue("Items"); break;
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

    // Initialisation of the serial interface when logging is activated
    LOGGER_BEGIN(9600)
    LOGGER("Starting Programm ...")

    // inizialise the touch menu lib
    TML.init(0);

    // create a sitebar to navigate and display the current page title
    CREATE_GRID_SCREEN_SITEBAR(TML, 0, 40, 0, 5, 1, COLOR_DARK_BLUE, 
        AddElement(new Button_Round("symb:TriangleLeft", COLOR_LIGHT_BLUE, 1, previousScreen), 0, 0, 1, 1),
        AddElement(new Textbox_Blank("", 1, COLOR_BLACK, &textvalue),                          1, 0, 3, 1),
        AddElement(new Button_Round("symb:TriangleRight", COLOR_LIGHT_BLUE, 1, nextScreen),    4, 0, 1, 1)
    )

    // normal GridScreen -> the first (non-sitebar) screen is set as the start screen
    CREATE_GRID_SCREEN(TML, 0, 1, 3, Color(200, 200, 255),
        AddElement(new Button_Rect("icon:ButtonClick", COLOR_LIGHT_BLUE, 1, 1, TML_goTo(TML, 1)), 0, 0, 1, 1),
        AddElement(new Button_Rect("icon:slider",      COLOR_LIGHT_BLUE, 1, 1, TML_goTo(TML, 2)), 0, 1, 1, 1),
        AddElement(new Button_Rect("icon:number",      COLOR_LIGHT_BLUE, 1, 1, TML_goTo(TML, 3)), 0, 2, 1, 1)
    )

    // GirdScreen with Sitebar with all button elements
    CREATE_GRID_SCREEN_WITH_SITEBAR(TML, 1, 0, 4, 3, Color(200, 200, 255),
        AddElement(new Button_Rect("icon:text", COLOR_GREEN + COLOR_RED, 2, 4, TML_empty_switch), 0, 0, 2, 2),
        AddElement(new Button_Round("icon:text", COLOR_GREEN + COLOR_RED, 4, TML_empty_button),   2, 0, 2, 2),
        AddElement(new Button_Round("icon:text", COLOR_GREEN + COLOR_RED, 4, TML_empty_button),   0, 2, 2, 1),
        AddElement(new Button_Blank("icon:text", COLOR_GREEN + COLOR_RED, TML_empty_button),      2, 2, 1, 1),
        AddElement(new Button_Rect("icon:text", COLOR_GREEN + COLOR_RED, 2, 4, TML_empty_switch), 3, 2, 1, 1)
    )

    // GirdScreen with Sitebar with all number input elements
    CREATE_GRID_SCREEN_WITH_SITEBAR(TML, 2, 0, 4, 3, Color(200, 200, 255),
        AddElement(new Number_Slider(COLOR_RED, TML_empty_slider, &numberValue), 0, 0, 1, 3),
        AddElement(new Number_Counter("symb:TriangleUp", "symb:TriangleDown", (COLOR_LIGHT_YELLOW|COLOR_ORANGE|COLOR_GRAY) + (COLOR_DARK_YELLOW|Color(10,30,10)|COLOR_LIGHT_MAGENTA), true, TML_empty_slider, &numberValue), 1, 0, 1, 2),
        AddElement(new Number_Counter("symb:TriangleLeft", "symb:TriangleRight", COLOR_YELLOW, true, TML_empty_slider, &numberValue), 2, 0, 2, 1),
        AddElement(new Number_Counter("symb:TriangleLeft", "symb:TriangleRight", COLOR_YELLOW, false, TML_empty_slider, &numberValue), 2, 1, 2, 1),
        AddElement(new Number_Slider((COLOR_RED|COLOR_LIGHT_YELLOW|COLOR_GRAY) + COLOR_DARK_GREEN, TML_empty_slider, &numberValue), 1, 2, 3, 1)
    )

    // GirdScreen with Sitebar with all textfield elements 
    CREATE_GRID_SCREEN_WITH_SITEBAR(TML, 3, 0, 2, 3, Color(200, 200, 255),
        AddElement(new Textbox_Blank("This is a Blank Textbox", 1, COLOR_DARK_GREEN), 0, 0, 2, 1),
        AddElement(new Textbox_Rect("This is a Blank Textbox", 1, COLOR_LIGHT_BLUE|COLOR_DARK_GREEN), 0, 1, 2, 1),
        AddElement(new Textbox_Blank("icon:text", COLOR_YELLOW), 0, 2, 1, 1),
        AddElement(new Textbox_Rect("icon:reload", COLOR_YELLOW), 1, 2, 1, 1),
    )

    TML.setScreensaver(0, 100 * 1000);
}

void loop() {
    TML.loop();
}