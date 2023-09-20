
#include <Elements/Button.h>

void button_func_test();
void switch_func_test(bool value);

class TestButton : public Button {
public:
    TestButton(button_func_ptr button_callback, bool* const value);
    TestButton(switch_func_ptr switch_callback, bool* const value);
    
    void draw() override;
    void loop(Inputs& input) override;
    void setTouch(Inputs& input) override;
    bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override;
};


#pragma once


void run_test_button();