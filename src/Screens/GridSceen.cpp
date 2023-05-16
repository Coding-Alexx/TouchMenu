#include "GridScreen.h"

GridScreen::GridScreen(const uint8_t col, const uint8_t raw, const Color& background):
    GridScreen(col, raw, background, {})
{}

GridScreen::GridScreen(const uint8_t col, const uint8_t raw, const Color& background, std::vector<std::tuple<Element*, const uint16_t, const uint16_t, const uint16_t, const uint16_t>> elementList):
    background(background),
    height(0),
    width(0) 
    {
        elements.reserve(raw*col);
        for(auto element: elementList) {
            Element* e = std::get<0>(element);
            auto posX = std::get<1>(element);
            auto posY = std::get<1>(element);
            auto sizeX = std::get<1>(element);
            auto sizeY = std::get<1>(element);

            add(e, posX, posY, sizeX, sizeY);
        }
    }

template <typename T>
std::unique_ptr<Element> GridScreen::make_unique_derived(Element* element) {
    return std::make_unique<T>();
}

bool GridScreen::add(Element* element, const uint16_t posX, const uint16_t posY, const uint16_t sizeX, const uint16_t sizeY) {
    int x = 0;
    int y = 0;
    int sx = 0;
    int sy = 0;
    int r = 0;

    element->setPosition(x, y);
    if (!element->setSize(sx, sy, r)) {
        return false;
    }

    element->setDisplay(display);

    std::unique_ptr<Element> uptr (element);
    elements.push_back(std::move(uptr));
    element = nullptr;  // uptr besitzt jetzt die Ressource
    return true;

}

void GridScreen::loop() {

}

void GridScreen::draw() {

}