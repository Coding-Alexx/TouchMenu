#include "Arduino.h"
#include "unity.h"
#include "TouchMenuLib.h"

//TouchMenuLib TML(DisplayGFX(TFT_CS, TFT_DC));
auto* disp = new DisplayTFTeSPI({383, 3445, 233, 3541, 7 }); //V1:{414, 3383, 254, 3497, 7 } V2:{383, 3445, 233, 3541, 7 } 
TouchMenuLib TML(disp);

void callback (bool) {
  TML.back();
}
//Test ob Elemente sich im Gridscreen überlappen

void test_GridScreen_add_no_overlap() {
 

    auto* roundButton1 = new RoundButton(  "Welt", COLOR_RED,    "Hallo", COLOR_GREEN,          COLOR_YELLOW, callback);
    auto* roundButton2 = new RoundButton(  "GO!",  COLOR_YELLOW, "Lets",  COLOR_DARK_GREEN,     COLOR_GRAY,   COLOR_BLACK, callback);

//check true adding elements without overlap 
    auto* gridScreen = new GridScreen(3, 3, COLOR_LIGHT_CYAN);
    TEST_ASSERT_TRUE(gridScreen->add(roundButton1, 0, 0, 2, 2));
    TEST_ASSERT_TRUE(gridScreen->add(roundButton2, 2, 2, 1, 1));
}

void test_GridScreen_add_with_overlap() {


    auto* roundButton1 = new RoundButton(  "Welt", COLOR_RED,    "Hallo", COLOR_GREEN,          COLOR_YELLOW, callback);
    auto* roundButton2 = new RoundButton(  "GO!",  COLOR_YELLOW, "Lets",  COLOR_DARK_GREEN,     COLOR_GRAY,   COLOR_BLACK, callback);

//check false adding element over another element
    auto* gridScreen = new GridScreen(3, 3, COLOR_LIGHT_CYAN);
    TEST_ASSERT_TRUE(gridScreen->add(roundButton1, 0, 0, 2, 2));
    TEST_ASSERT_TRUE(gridScreen->add(roundButton2, 1, 1, 1, 1));
}


void run_all_gridscreen_tests() {
    RUN_TEST(test_GridScreen_add_no_overlap);
    RUN_TEST(test_GridScreen_add_with_overlap);
}



