#include <Arduino.h>
#include <unity.h>
#include <../src/TouchMenuLib.h>

#include "test_Elements.h"

GridScreen* grid_elements;
RoundButton* roundButton1_elements;
RoundButton* roundButton2_elements;
RectButtonCircle* rectButtonCircle1_elements;
RectButtonCircle* rectButtonCircle2_elements;
ToggleSwitch* toggleSwitch1_elements;
ToggleSwitch* toggleSwitch2_elements;
DisplayTFTeSPI* display_elements;
TouchMenuLib TMLTest_elements(new DisplayTFTeSPI());

void callbackTestElements (bool) {
    TMLTest_elements.back();
}
//setUp


void test_elements_setup() {
    grid_elements = new GridScreen (50, 50 , COLOR_LIGHT_CYAN);
    roundButton1_elements = new RoundButton ("", COLOR_RED,  "", COLOR_GREEN, COLOR_YELLOW, callbackTestElements);
    roundButton2_elements = new RoundButton ("", COLOR_RED,  "", COLOR_GREEN, COLOR_YELLOW, callbackTestElements);
    rectButtonCircle1_elements = new RectButtonCircle (  "ON",  COLOR_DARK_GREEN, "OFF",  COLOR_DARK_RED, COLOR_DARK_BLUE, 9, callbackTestElements);
    rectButtonCircle2_elements = new RectButtonCircle (  "ON",  COLOR_DARK_GREEN, "OFF",  COLOR_DARK_RED, COLOR_DARK_BLUE, 9, callbackTestElements);
    toggleSwitch1_elements = new ToggleSwitch ("ON", COLOR_GREEN, COLOR_BLACK, "OFF", COLOR_BLACK, COLOR_RED, COLOR_BLACK, callbackTestElements);
    toggleSwitch2_elements = new ToggleSwitch ("ON", COLOR_GREEN, COLOR_BLACK, "OFF", COLOR_BLACK, COLOR_RED, COLOR_BLACK, callbackTestElements);

    display_elements = new DisplayTFTeSPI();
    grid_elements->setDisplay(display_elements);
    grid_elements->setResolution(display_elements->getWidth(), display_elements->getHeight());
}
//tearDown
void test_elements_teardown() {
    delete display_elements;
    delete roundButton2_elements;
    delete roundButton1_elements;
    delete rectButtonCircle1_elements;
    delete rectButtonCircle2_elements;
    delete toggleSwitch1_elements;
    delete toggleSwitch2_elements;

    grid_elements = nullptr;
    delete grid_elements;
}



// Tests Elemente
void test_if_roundButton_has_minimum_size(){            
    TEST_ASSERT_FALSE(grid_elements->add(roundButton1_elements,0,0,1,1));       //add element is expected to be false,, because the grid is too big and the element would be too small
}

void test_if_roundButton_has_maximum_size(){            
    TEST_ASSERT_FALSE(grid_elements->add(roundButton1_elements,0,0,51,51));     //add element is expected to be false, because the element is bigger than the grid
}

void test_if_toggleSwitch_has_minimum_size(){            
    TEST_ASSERT_FALSE(grid_elements->add(toggleSwitch1_elements,0,0,1,1));       
}

void test_if_toggleSwitch_has_maximum_size(){            
    TEST_ASSERT_FALSE(grid_elements->add(toggleSwitch2_elements,0,0,51,51));    
}

void test_if_rectButtonCircle_has_minimum_size(){            
    TEST_ASSERT_FALSE(grid_elements->add(rectButtonCircle1_elements,0,0,1,1));       
}

void test_if_rectButtonCircle_has_maximum_size(){            
    TEST_ASSERT_FALSE(grid_elements->add(rectButtonCircle2_elements,0,0,51,51));    
}

void test_if_two_roundButtons_dont_overlap(){
    grid_elements->add(roundButton1_elements,0,0,1,1);
    TEST_ASSERT_FALSE(grid_elements->add(roundButton2_elements,0,0,1,1));
}

void test_if_two_toggleSwitches_dont_overlap(){
    grid_elements->add(toggleSwitch1_elements,0,0,1,1);
    TEST_ASSERT_FALSE(grid_elements->add(toggleSwitch2_elements,0,0,2,2));
}

void test_if_two_rectButtonCircles_dont_overlap(){
    grid_elements->add(rectButtonCircle1_elements,0,0,1,1);
    TEST_ASSERT_FALSE(grid_elements->add(rectButtonCircle2_elements,0,0,2,2));
}

void test_if_roundButton_is_completly_on_screen_and_no_parts_of_it_are_outside_the_screen(){ //Höhe und Breite des Elements vs Höhe und Breite eines Gitters
    TEST_ASSERT_LESS_OR_EQUAL_UINT16(display_elements->getHeight()/ grid_elements->getRow(), roundButton1_elements->getHeight());
    TEST_ASSERT_LESS_OR_EQUAL_UINT16(display_elements->getWidth()/grid_elements->getCol(), roundButton1_elements->getWidth());
}

void test_if_toggleSwitch_is_completly_on_screen_and_no_parts_of_it_are_outside_the_screen(){ 
    TEST_ASSERT_LESS_OR_EQUAL_UINT16(display_elements->getHeight()/ grid_elements->getRow(), toggleSwitch1_elements->getHeight());
    TEST_ASSERT_LESS_OR_EQUAL_UINT16(display_elements->getWidth()/grid_elements->getCol(), toggleSwitch1_elements->getWidth());
}

void test_if_rectButtonCircle_is_completly_on_screen_and_no_parts_of_it_are_outside_the_screen(){
    TEST_ASSERT_LESS_OR_EQUAL_UINT16(display_elements->getHeight()/ grid_elements->getRow(), rectButtonCircle1_elements->getHeight());
    TEST_ASSERT_LESS_OR_EQUAL_UINT16(display_elements->getWidth()/grid_elements->getCol(), rectButtonCircle1_elements->getWidth());
}

void test_if_element_callback_is_only_called_when_the_hitbox_of_the_element_was_touched(){ //TODO
}

void run_test_elements(){
    
    test_elements_setup();
    RUN_TEST(test_if_roundButton_has_minimum_size);
    test_elements_teardown();

    test_elements_setup();
    RUN_TEST(test_if_roundButton_has_maximum_size);
    test_elements_teardown();

    test_elements_setup();
    RUN_TEST(test_if_rectButtonCircle_has_minimum_size);
    test_elements_teardown();

    test_elements_setup();
    RUN_TEST(test_if_rectButtonCircle_has_maximum_size);
    test_elements_teardown();

    test_elements_setup();
    RUN_TEST(test_if_toggleSwitch_has_minimum_size);
    test_elements_teardown();

    test_elements_setup();
    RUN_TEST(test_if_toggleSwitch_has_maximum_size);
    test_elements_teardown();

    test_elements_setup();
    RUN_TEST(test_if_two_roundButtons_dont_overlap);
    test_elements_teardown();

    test_elements_setup();
    RUN_TEST(test_if_two_rectButtonCircles_dont_overlap);
    test_elements_teardown();

    test_elements_setup();
    RUN_TEST(test_if_two_toggleSwitches_dont_overlap);
    test_elements_teardown();
/*
    test_elements_setup();
    RUN_TEST(test_if_element_callback_is_only_called_when_the_hitbox_of_the_element_was_touched);
    test_elements_teardown();
    */
    test_elements_setup();
    RUN_TEST(test_if_roundButton_is_completly_on_screen_and_no_parts_of_it_are_outside_the_screen);
    test_elements_teardown();


    test_elements_setup();
    RUN_TEST(test_if_toggleSwitch_is_completly_on_screen_and_no_parts_of_it_are_outside_the_screen);
    test_elements_teardown();


    test_elements_setup();
    RUN_TEST(test_if_rectButtonCircle_is_completly_on_screen_and_no_parts_of_it_are_outside_the_screen);
    test_elements_teardown();
}