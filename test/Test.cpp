#include <Arduino.h>
#include <unity.h>
#include "TouchMenuLib.h"

void callback (bool) {
}

void setUp(void)
{
  // set stuff up here
  auto grid = new GridScreen (3, 3 , COLOR_LIGHT_CYAN);
  auto button = new RoundButton("AN", COLOR_RED, "AUS", COLOR_GREEN, COLOR_YELLOW, callback);
  auto button2 = new RoundButton(  "AN", COLOR_BLUE,"AUS", COLOR_BROWN,COLOR_YELLOW,callback);
  
  auto* display = new DisplayTFTeSPI();
  grid->setDisplay(display);
  grid->setResolution(display->getWigth(), display->getHeight());
}

void tearDown(void)
{
  // clean stuff up here
  // delete button;
  // delete button2;
  // delete grid;
}

void test_led_builtin_pin_number(void)
{
  // grid->add(button2, 1, 1, 1, 1);
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

void setup()
{
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);

  UNITY_BEGIN(); // IMPORTANT LINE!
  RUN_TEST(test_led_builtin_pin_number);
  UNITY_END();
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop()
{
  // if (i < max_blinks)
  // {
  //   RUN_TEST(test_led_state_high);
  //   delay(500);
  //   RUN_TEST(test_led_state_low);
  //   delay(500);
  //   i++;
  // }
  // else if (i == max_blinks)
  // {
  //   UNITY_END(); // stop unit testing
  // }
}