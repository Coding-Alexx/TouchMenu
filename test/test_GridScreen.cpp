#include <Arduino.h>
#include <unity.h>
#include <../src/TouchMenuLib.h>

GridScreen* grid;
RoundButton* roundButton1;
RoundButton* roundButton2;
DisplayTFTeSPI* display;
TouchMenuLib TMLTest(new DisplayTFTeSPI());

void callbackTest (bool) {
  TMLTest.back();
}
void setUp() {
    grid = new GridScreen (3, 3 , COLOR_LIGHT_CYAN);
    roundButton1 = new RoundButton ("", COLOR_RED,  "", COLOR_GREEN, COLOR_YELLOW, callbackTest);
    roundButton2 = new RoundButton ("", COLOR_RED,  "", COLOR_GREEN, COLOR_YELLOW, callbackTest);
    display = new DisplayTFTeSPI();
    grid->setDisplay(display);
    grid->setResolution(display->getWigth(), display->getHeight());
}

void tearDown() { 
  delete display;
  delete roundButton2;
  delete roundButton1;
  grid = nullptr;
  delete grid;
  
}

void test_if_elements_dont_overlap(){   //macht noch keinen sinn
    grid->add(roundButton1,0,0,2,2);
    TEST_ASSERT_FALSE(grid->add(roundButton2,0,0,2,2));
}

/*void test_if_gridscreen_size_is_less_equal_the_size_of_the_display_device(){
  
}
void test_if_grids_are_at_least_as_big_as_a_minium_size(){

}

void test_if_element_is_big_enough(){

}

void test_if_the_measurements_of_an_element_are_wrong_the_element_should_not_be_drawn(){

}

void test_if_the_screen_has_a_display_resolution_before_an_element_can_be_added(){

}

void test_if_three_by_three_screen_places_an_element_indended_to_be_placed_in_the_middle_of_a_screen_in_the_actual_middle_of_the_display(){

}*/


void setup()
{
  delay(2000);

  UNITY_BEGIN(); // IMPORTANT LINE!
  RUN_TEST(test_if_elements_dont_overlap);
  UNITY_END();
}
void loop()
{
}