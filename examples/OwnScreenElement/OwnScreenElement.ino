/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                     *
 *                     Calculator Keyboard Interface Example                           *
 *   Description:                                                                      *
 *       In this example you will learn how to create and                              *
 *       use your own ecreens and your own elements.                                   *
 *                                                                                     *
 *   Read our documentation for more information:                                      *
 *      https://touchmenu.readthedocs.io/de/latest/index.html                          *
 *                                                                                     *
 *   Licence:                                                                          *
 *      GNU GENERAL PUBLIC LICENSE                                                     *
 *                                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include <Arduino.h>
#include "TouchMenuLib.h"
#include "OwnElement.h"
#include "OwnScreen.h"

TouchMenuLib TML;

void setup() {
    // starting logging
    LOGGER_BEGIN(9600)
    LOGGER("Starting Programm OwnScreenElement ...")

    // inizialise TouchMenuLib and set rotation (default is 1)
    TML.init(0);

    // create an instance of your own Element element and your screen
    OwnElement* element = new OwnElement(COLOR_GREEN + COLOR_BLUE + COLOR_GRAY);
    OwnScreen* screen = new OwnScreen(element, COLOR_LIGHT_BLUE);

    // add your screen to the menu
    TML.add(1, screen);
}

void loop(){
    TML.loop();
}