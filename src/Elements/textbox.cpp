#include "Textbox.h"
#include <cstring>

Textbox::Textbox(Item* item, ExternalTextboxValue* value):
    item(item), externalValue(value) {}

Textbox::Textbox(Item* item, const uint8_t textsize, ExternalTextboxValue* value):
    item(item), externalValue(value) {
        externalValue->setup(textsize);
        item->setSize(textsize);
    }

Textbox::~Textbox(){};

bool Textbox::select() {
    return false;
}

// Auchtung: die Callback wird bei einer externen Wertänderrung nicht aufgerufen, dies kann der Entwickler selbst tun
// void Textbox::loop(){}

void Textbox::loop(Inputs& input) {
    if (externalValue && externalValue->hasUpdate()) {
        draw();
        externalValue->resetUpdate();
    }
}

void Textbox::setTouch(Inputs& input) {}

bool Textbox::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {
    if (externalValue && externalValue->getSize() == 0) externalValue->setup(sizeX, sizeY);
    return true;
}

// void Textbox::setTextPtr(TML_textbox text_ptr, const char* text) {
//     if (text_ptr != nullptr) {
//         free(text_ptr);
//         text_ptr = nullptr;
//     }
//     text_ptr = strdup(text);
// }

// const char* Textbox::getTextPtr(TML_textbox text_ptr) {
//   return (text_ptr != nullptr) ? text_ptr : "";
// }

// void Textbox::setText(const char* new_text) {
//     if (new_text != nullptr) {
//         delete[] text;
//         size_t length = strlen(new_text);
//         char* copiedText = new char[length + 1];
//         strcpy(copiedText, new_text);
//         text = copiedText;
//     }
// }