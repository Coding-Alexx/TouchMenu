#include <Arduino.h>
#include <unity.h>
#include "test_Button.h"

void button_func_test() {}
void switch_func_test(bool value) {}

TestButton::TestButton(button_func_ptr button_callback, bool* const value) : Button(button_callback, value) {}
TestButton::TestButton(switch_func_ptr switch_callback, bool* const value) : Button(switch_callback, value) {}

void TestButton::draw() {}
void TestButton::loop(Inputs& input) {}
void TestButton::setTouch(Inputs& input) {}
bool TestButton::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) { return true; }

TestButton* button1;
TestButton* button2;

void test_button_setup() {
    bool externalVal = false;
    button1 = new TestButton(button_func_test, &externalVal);
    button2 = new TestButton(switch_func_test, &externalVal);
}

void test_button_teardown() {
    delete button1;
    delete button2;
}

void test_button_constructor() {
    TEST_ASSERT_FALSE(button1->getValue());
    TEST_ASSERT_FALSE(button2->getValue());
}

void test_button_select() {
    button1->select();
    TEST_ASSERT_TRUE(button1->getValue());
    button2->select();
    TEST_ASSERT_TRUE(button2->getValue());
    button2->select();
    TEST_ASSERT_FALSE(button2->getValue());
}

void run_test_button() {
    test_button_setup();
    RUN_TEST(test_button_constructor);
    test_button_teardown();

    test_button_setup();
    RUN_TEST(test_button_select);
    test_button_teardown();
}
