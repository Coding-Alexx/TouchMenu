
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                     *
 *                     Calculator Keyboard Interface Example                           *
 *   Description:                                                                      *
 *       Here you can see an example of a calculator. Since it is about the menu,      *
 *       the calculator function has not been implemented. You are welcome to do so ;) *
 *       To keep everything readable, templates were used for the callback methods.    *
 *       The sitebar is used to display the equation.                                  *
 *       There is also a second screen to save and load the current equation.          *
 *       A short tap loads an equation, a long press saves one.                        *
 *                                                                                     *
 *       In order for the library to function well, you should refrain from delay      *
 *       or other time-consuming operations!                                           *
 *                                                                                     *
 *   To learn:                                                                         *
 *     - using templates as callback methods                                           *
 *     - use external values to manipulate elements                                    *
 *     - misuse of the sitebar                                                         *
 *     - long press buttons feature                                                    *
 *                                                                                     *
 *   Read our documentation for more information:                                      *
 *      https://touchmenu.readthedocs.io/de/latest/index.html                          *
 *                                                                                     *
 *   Licence:                                                                          *
 *                                                                                     *
 *                                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "TouchMenuLib.h"

#include <Arduino.h>

// Initialise touch menu lib as TML
TouchMenuLib TML(new DisplayTFTeSPI());

// external values for textbox and Buttons
ExternalTextboxValue textvalue;
ExternalButtonValue saveButton [4];

// Other variables
String formula;
String savedFormulas [4];

// callback method to add a char -> call with addChar< char >
template<char c>
void addChar () {
    formula += c;

    // set the text Value for the textbox
    textvalue.setValue(formula.c_str());
}

// callback method to save a formula at the i. position -> call with saveFormula< int >
template<int i>
void saveFormula () {

    // set a new item/text for the button
    saveButton[i].setItem(("text:" + formula + " size:2").c_str());
    
    // The better way is to directly hand over the appropriate item
    //saveButton[i].setItem(new Text(formula.c_str(), 2));

    savedFormulas[i] = formula;
}

// callback method to load a formula from the i. position -> call with loadFormula< int >
template<int i>
void loadFormula () {
    if (saveButton[i].hasItemOn()) {

        formula = savedFormulas[i];

        // set the Text for the Textbox
        textvalue.setValue(formula.c_str());
    }
}

// here the equation would be calculated
void calculate () {

    // add other values to the logging message at the '_' -> use sparingly, as it is very unperformant
    LOGGER_PATTERN("Formula is: _", formula)

}

void deleteLast () {
    formula = formula.substring(0, formula.length()-1);
    textvalue.setValue(formula.c_str());
}

// Switch between screens -> the (bool) indicates that the element should be a switch
void switchScreen(bool) {

    // go to an other Screen
    TML.goTo(TML.getScreenID() == 1? 2:1);
    
}

void setup() {

    // initialise the serial interface -> can also be done manually by you
    LOGGER_BEGIN(9600)

    String test = "hello world";

    // Log something via the serial interface if the DEBUG flag is set and DEBBUG_LEVEL is set to INFO
    LOGGER("Starting Programm ...")

    // inizialise the touch menu lib
    TML.init(0);

    
    
    // First possibility to create a screen: using the macro
    CREATE_GRID_SCREEN_SITEBAR(TML, 1, 60, 0, 4, 1, COLOR_DARK_BLUE, 
        AddElement(new Textbox_Blank("GLEICHUNG", 2, COLOR_BLACK, &textvalue), 0, 0, 3, 1),
        AddElement(new RoundButton("<-", "->", COLOR_RED, switchScreen), 3, 0, 1, 1)
    )

    // for a sitebar GridScreen the macro is called: CREATE_GRID_SCREEN_SITEBAR (TML, id, size, site, col, row, elements...)
    // for a normal GridScreen the macro is called:  CREATE_GRID_SCREEN (TML, id, col, row, elements...)
    //                             or with sitebar:  CREATE_GRID_SCREEN_WITH_SITEBAR (TML, id, sitebarID, col, row, elements...)


    // create a GridScreen pointer for the second and third way 
    GridScreen* g;

    // second way to create a GridScreen: use the << operator
    g = new GridScreen(4, 5, COLOR_LIGHT_CYAN);
    TML.add(1, g, 1); // Attention: always add the GridScreen first before adding elements!
    (*g)
        << AddElement(new RectButton("text:7 size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_ORANGE) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_RED), 2, 3,  addChar<'7'>), 0, 0, 1, 1)
        << AddElement(new RectButton("text:8 size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_ORANGE) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_RED), 2, 3,  addChar<'8'>), 1, 0, 1, 1)
        << AddElement(new RectButton("text:9 size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_ORANGE) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_RED), 2, 3,  addChar<'9'>), 2, 0, 1, 1)
        << AddElement(new RectButton("text:+ size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_GRAY), 2, 3,  addChar<'+'>), 3, 0, 1, 1)
        << AddElement(new RectButton("text:4 size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_ORANGE) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_RED), 2, 3,  addChar<'4'>), 0, 1, 1, 1)
        << AddElement(new RectButton("text:5 size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_ORANGE) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_RED), 2, 3,  addChar<'5'>), 1, 1, 1, 1)
        << AddElement(new RectButton("text:6 size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_ORANGE) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_RED), 2, 3,  addChar<'6'>), 2, 1, 1, 1)
        << AddElement(new RectButton("text:- size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_GRAY), 2, 3,  addChar<'-'>), 3, 1, 1, 1)
        << AddElement(new RectButton("text:1 size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_ORANGE) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_RED), 2, 3,  addChar<'1'>), 0, 2, 1, 1)
        << AddElement(new RectButton("text:2 size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_ORANGE) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_RED), 2, 3,  addChar<'2'>), 1, 2, 1, 1)
        << AddElement(new RectButton("text:3 size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_ORANGE) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_RED), 2, 3,  addChar<'3'>), 2, 2, 1, 1)
        << AddElement(new RectButton("text:* size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_GRAY), 2, 3,  addChar<'*'>), 3, 2, 1, 1)
        << AddElement(new RectButton("text:. size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_GRAY), 2, 3,  addChar<'.'>), 0, 3, 1, 1)
        << AddElement(new RectButton("text:0 size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_ORANGE) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_RED), 2, 3,  addChar<'0'>), 1, 3, 1, 1)
        << AddElement(new RectButton("text:% size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_GRAY), 2, 3,  addChar<'%'>), 2, 3, 1, 1)
        << AddElement(new RectButton("text:: size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_GRAY), 2, 3,  addChar<'/'>), 3, 3, 1, 1)
        << AddElement(new RectButton("text:( size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_GRAY), 2, 3,  addChar<'('>), 0, 4, 1, 1)
        << AddElement(new RectButton("text:) size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_GRAY), 2, 3,  addChar<')'>), 1, 4, 1, 1)
        << AddElement(new RectButton("text:<- size:2", (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_GRAY), 2, 3,  deleteLast),   2, 4, 1, 1)
        << AddElement(new RectButton("text:= size:2",  (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_RED) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_DARK_RED),2, 3, calculate),    3, 4, 1, 1)
    ;


    // third way to create a GridScreen: use the add function
    g = new GridScreen(1, 4, COLOR_LIGHT_CYAN);
    TML.add(2, g, 1);
    g->add(new RectButton("text:Leer size:2", (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_GRAY), 2, 3,  loadFormula<0>, saveFormula<0>, &saveButton[0]), 0, 0, 1, 1);
    g->add(new RectButton("text:Leer size:2", (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_GRAY), 2, 3,  loadFormula<1>, saveFormula<1>, &saveButton[1]), 0, 1, 1, 1);
    g->add(new RectButton("text:Leer size:2", (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_GRAY), 2, 3,  loadFormula<2>, saveFormula<2>, &saveButton[2]), 0, 2, 1, 1);
    g->add(new RectButton("text:Leer size:2", (COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_BLACK) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_GRAY), 2, 3,  loadFormula<3>, saveFormula<3>, &saveButton[3]), 0, 3, 1, 1);

}

void loop() {
    // update the touch menu lib
    TML.loop();
}