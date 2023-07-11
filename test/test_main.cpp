#include <Arduino.h>
#include <unity.h>
#include <../src/TouchMenuLib.h>
#include "test_gridscreen.h"
#include "test_Elements.h"
#include "test_Button.h"

void setUp() {
    //  setup code...
}

void tearDown() {
    //  teardown code...
}

void setup()
{
    delay(2000);

    UNITY_BEGIN(); // IMPORTANT LINE!
    
    // Run all GridScreen tests
    run_test_gridscreen();
    run_test_elements();
    run_test_button();


    UNITY_END();
}

void loop()
{
    // Empty loop
}