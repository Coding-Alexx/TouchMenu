#include <Arduino.h>
#include <unity.h>

#include "TouchMenuLib.h"


GridScreen* grid;
RoundButton* button;
RoundButton* button2;

void callback (bool) {
}

void setUp(void)
{
  // set stuff up here
  grid = new GridScreen (3, 3 , COLOR_LIGHT_CYAN);
  button = new RoundButton("AN", COLOR_RED, "AUS", COLOR_GREEN, COLOR_YELLOW, callback);
  button2 = new RoundButton(  "AN", COLOR_BLUE,"AUS", COLOR_BROWN,COLOR_YELLOW,callback);
}

void tearDown(void)
{
  // clean stuff up here
  delete button;
  delete button2;
  grid = nullptr;

}

void test_led_builtin_pin_number(void)
{
  TEST_ASSERT_EQUAL(13, 13);
}

void test_led_state_high(void)
{
  TEST_ASSERT_EQUAL(HIGH, 1);
}

void test_led_state_low(void)
{
  TEST_ASSERT_EQUAL(LOW, 0);
}





void test_add(void)
{
  TEST_ASSERT_TRUE(grid->add(button,1,1,1,1));
}

void test_overlap(void)
{
  grid->add(button, 1 ,0,2,2);
  TEST_ASSERT_FALSE(grid->add(button2, 1 ,0 ,1 ,1));
}


void test_add_element_outside_grid(void) 
{
  TEST_ASSERT_FALSE(grid->add(button, 4, 4, 1, 1)); 
}



void setup()
{
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);

  UNITY_BEGIN(); // IMPORTANT LINE!
  RUN_TEST(test_led_builtin_pin_number);
  RUN_TEST(test_add);
  RUN_TEST(test_overlap);
  RUN_TEST(test_add_element_outside_grid);
  UNITY_END();
}



void loop()
{
  
}
