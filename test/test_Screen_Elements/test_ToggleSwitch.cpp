#include "Arduino.h"
#include "unity.h"
#include "TouchMenuLib.h"

//TouchMenuLib TML(DisplayGFX(TFT_CS, TFT_DC));
auto* disp2 = new DisplayTFTeSPI({383, 3445, 233, 3541, 7 }); //V1:{414, 3383, 254, 3497, 7 } V2:{383, 3445, 233, 3541, 7 } 
TouchMenuLib TML2(disp2);

void callback2 (bool) {
  TML2.back();
}
void test_ToggleSwitch_min_size(){
    auto* toggle = new ToggleSwitch("ON", COLOR_RED, COLOR_BLACK, "OFF", COLOR_BLUE, COLOR_BLACK, COLOR_BLACK, callback2);
    TEST_ASSERT_FALSE(toggle->checkSize(49,50,0));  // sizeX is less than 50
    TEST_ASSERT_FALSE(toggle->checkSize(50, 49, 0));  // sizeY is less than 50
    TEST_ASSERT_FALSE(toggle->checkSize(49, 49, 0));  // sizeX and sizeY are less than 50
    TEST_ASSERT_TRUE(toggle->checkSize(50, 50,0));   // sizeX and sizeY are equal to 50
    TEST_ASSERT_TRUE(toggle->checkSize(51, 50,0));   // sizeX is greater than 50
    TEST_ASSERT_TRUE(toggle->checkSize(50, 51,0));   // sizeY is greater than 50
    TEST_ASSERT_TRUE(toggle->checkSize(51, 51,0));   // sizeX and sizeY are greater than 50
  
}
// Running all tests
void run_all_toggleSwitch_tests() {
    RUN_TEST(test_ToggleSwitch_min_size);
}
