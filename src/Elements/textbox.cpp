#include "Textbox.h"
#include "../Config.h"

Textbox::Textbox(char* const value) 
    {}

Textbox::~Textbox(){};

bool Textbox::select() {
    return false;
}

// Auchtung: die Callback wird bei einer externen Wertänderrung nicht aufgerufen, dies kann der Entwickler selbst tun
void Textbox::loop(){}

void Textbox::loop(Inputs& input) {}

void Textbox::setTouch(uint16_t x, uint16_t y) {}