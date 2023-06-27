#include <Arduino.h>
#include <unity.h>

#include "../test/test_Screen_Elements/test_GridScreen.cpp"
#include "../test/test_Screen_Elements/test_ToggleSwitch.cpp"


void setUp(void)
{
  // set stuff up here
}

void tearDown(void)
{
  // clean stuff up here
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



void setup()
{
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);

  UNITY_BEGIN(); // IMPORTANT LINE!
  RUN_TEST(test_led_builtin_pin_number);
  RUN_TEST(run_all_gridscreen_tests);
  RUN_TEST(run_all_toggleSwitch_tests);
  UNITY_END();
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop()
{
  if (i < max_blinks)
  {
    RUN_TEST(test_led_state_high);
    delay(500);
    RUN_TEST(test_led_state_low);
    delay(500);
    i++;
  }
  else if (i == max_blinks)
  {
    UNITY_END(); // stop unit testing
  }
}