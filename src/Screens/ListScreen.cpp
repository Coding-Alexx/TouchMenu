#include <algorithm>

#include "ListScreen.h"
#include "ElementViews/textbox_Blank.h"

ListScreen::ListScreen (const uint8_t lines, const Color& background) :
    background(background),
    lines(lines),
    elements()
    {
        scrollbar.setMinValue(0);
        scrollbar.setMaxValue(0); // changed later
        scrollbar.setSteps(1);

        LOGGER_PATTERN("Scrollbar hat Wertebreich von _ bis _ mit einer Schrittweite von _", scrollbar.getMinValue(), scrollbar.getMaxValue(), scrollbar.getSteps())
    }

bool ListScreen::add(Element* element){

    uint16_t w = getResolutionWidth() - scrollbar_width;
    uint16_t h = getResolutionHeight()/lines;

    if (!element->setSize(w, h, display->getRotation())) {
        LOGGER_ERROR("Element ist mit der aktuellen Größe icht kompatibel")
        delete element;
        element = new Textbox_Blank("symb:Crosslines", COLOR_RED);
        element->setSize(w, h, display->getRotation());
    }

    element->setDisplay(display);

    std::unique_ptr<Element> uptr (element);
    elements.push_back(std::move(uptr));

    scrollbar.setMaxValue(max((int)elements.size() - lines, 0));

    return true;
}

void ListScreen::loop(Inputs& input) {
    // Alternativ dies als Callback Funktion ausführen
    uint8_t tmp = min((uint)scrollbar.getValue(), elements.size());
    if (scroll_position != tmp) {
        scroll_position = tmp;
        draw();
    }

    if (input.updateTouchPoint) scrollbar.setTouch(input);
    scrollbar.loop(input);
    for (uint8_t i = scroll_position; i < scroll_position + lines && i < elements.size() - lines; i++) {
        if (input.updateTouchPoint) elements[i]->setTouch(input);
        elements[i]->loop(input);
    }
}

void ListScreen::draw() {
    display->rect(offsetX, offsetY, getResolutionWidth(), getResolutionHeight(), 0, 0, COLOR_BLACK, background);
    for (uint8_t i = 0; i < lines && i+scroll_position < elements.size() - lines; i++) {
        uint16_t x = 0;
        uint16_t y = getResolutionHeight()/lines * i;
        elements[i+scroll_position]->setPosition(x, y);
        elements[i+scroll_position]->draw();
        LOGGER_PATTERN("i=_, x=_, y=_, site=_, lines=_", i, x, y, scroll_position, lines)
    }
    
    scrollbar.draw();
}

void ListScreen::setDisplay(Display* const disp) {
    Screen::setDisplay(disp);
    scrollbar.setDisplay(disp);
}

void ListScreen::setResolution(uint16_t width, uint16_t height) {
    Screen::setResolution(width, height);
    scrollbar.setSize(scrollbar_width, getResolutionHeight());
    scrollbar.setPosition(offsetX + getResolutionWidth() - scrollbar_width, offsetY);
}