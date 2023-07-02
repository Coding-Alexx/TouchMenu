#include <Arduino.h>
#include <unity.h>
#include <../src/TouchMenuLib.h>
#include "test_gridscreen.h"

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

    UNITY_END();
}

void loop()
{
    // Empty loop
}