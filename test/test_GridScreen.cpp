#include <Arduino.h>
#include <unity.h>
#include <../src/TouchMenuLib.h>

#include "test_gridscreen.h"

GridScreen* grid;
RoundButton* roundButton1;
RoundButton* roundButton2;
DisplayTFTeSPI* display;
TouchMenuLib TMLTest(new DisplayTFTeSPI());

void callbackTest (bool) {
    TMLTest.back();
}
//setUp
void test_gridscreen_setup() {
    grid = new GridScreen (3, 3 , COLOR_LIGHT_CYAN);
    roundButton1 = new RoundButton ("", COLOR_RED,  "", COLOR_GREEN, COLOR_YELLOW, callbackTest);
    roundButton2 = new RoundButton ("", COLOR_RED,  "", COLOR_GREEN, COLOR_YELLOW, callbackTest);
    display = new DisplayTFTeSPI();
    grid->setDisplay(display);
    grid->setResolution(display->getWidth(), display->getHeight());
}
//tearDown
void test_gridscreen_teardown() {
    delete display;
    delete roundButton2;
    delete roundButton1;
    grid = nullptr;
    delete grid;
}
// Tests für Gridscreen
//todo (wahrscheinlich in eher in Tests für die Elemente selber) 1. Es können nur Elemente hinzugefügt haben, die eine bestimmte Größe an Platz haben ,2. Wenn ein Element meint, dass die Maße ihm nicht passen, so darf es nicht hinzugefügt werden

void test_add() {
    TEST_ASSERT_TRUE(grid->add(roundButton1,1,1,1,1));
}

void test_if_elements_dont_overlap() {
    grid->add(roundButton1,0,0,2,2);
    TEST_ASSERT_FALSE(grid->add(roundButton2,0,0,2,2));
}

void test_add_element_outside_grid() {
    TEST_ASSERT_FALSE(grid->add(roundButton1, grid->getCol() + 1, grid->getRow() + 1, 1, 1)); 
}

void test_gridscreen_not_larger_than_display() {
    TEST_ASSERT_LESS_OR_EQUAL(display->getWidth(), grid->getResolutionHeight());
    TEST_ASSERT_LESS_OR_EQUAL(display->getHeight(), grid->getResolutionWidth());
}

// minimum 10x10 Pixel pro Grid
void test_grids_have_minimum_size() {
    TEST_ASSERT_GREATER_OR_EQUAL(10, grid->getResolutionWidth()/grid->getCol());
    TEST_ASSERT_GREATER_OR_EQUAL(10, grid->getResolutionHeight()/grid->getRow());
}

// prüft ob mittleres Element in einem 3x3 Grid auch in der Mitte des Displays ist
void test_3x3_grid_places_middle_element_in_middlecoordinates() {
    grid->add(roundButton1, 1, 1, 1, 1);
    // +-1 wegen Rundungen
    TEST_ASSERT_INT_WITHIN(1, grid->getResolutionWidth()/2, roundButton1->getMidX());
    TEST_ASSERT_INT_WITHIN(1, grid->getResolutionHeight()/2, roundButton1->getMidY());
}

void run_test_gridscreen() {
    test_gridscreen_setup();
    RUN_TEST(test_add);
    test_gridscreen_teardown();

    test_gridscreen_setup();
    RUN_TEST(test_if_elements_dont_overlap);
    test_gridscreen_teardown();

    test_gridscreen_setup();
    RUN_TEST(test_add_element_outside_grid);
    test_gridscreen_teardown();

    test_gridscreen_setup();
    RUN_TEST(test_gridscreen_not_larger_than_display);
    test_gridscreen_teardown();

    test_gridscreen_setup();
    RUN_TEST(test_grids_have_minimum_size);
    test_gridscreen_teardown();

    test_gridscreen_setup();
    RUN_TEST(test_3x3_grid_places_middle_element_in_middlecoordinates);
    test_gridscreen_teardown();
}
