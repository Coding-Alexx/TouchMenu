#include "GridScreen.h"

GridScreen::GridScreen(const uint8_t col, const uint8_t raw, const Color& background):
    background(background),
    height(0),
    width(0) 
{
    elements.reserve(raw*col);
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

    std::unique_ptr<Element> uptr (element);
    elements.push_back(std::move(uptr));
    element = nullptr;  // uptr besitzt jetzt die Ressource
    return true;

}

// TODO Code Wiederholung entfernen
// bool GridScreen::add(Element& element, const uint16_t posX, const uint16_t posY, const uint16_t sizeX, const uint16_t sizeY) {
//     // TODO: Berechne x, y, sx, sy und rotation nach dem Grid
//     int x = 0;
//     int y = 0;
//     int sx = 0;
//     int sy = 0;
//     int r = 0;

//     element.setPosition(x, y);
//     if (!element.setSize(sx, sy, r)) {
//         return false;
//     }

//     std::unique_ptr<Element> uptr = std::make_unique<Element>(element);
//     elements.push_back(std::move(uptr));
//     return true;
// }

// bool GridScreen::add(Element&& element, const uint16_t posX, const uint16_t posY, const uint16_t sizeX, const uint16_t sizeY) {
//     // TODO: Berechne x, y, sx, sy und rotation nach dem Grid
//     int x = 0;
//     int y = 0;
//     int sx = 0;
//     int sy = 0;
//     int r = 0;

//     element.setPosition(x, y);
//     if (!element.setSize(sx, sy, r)) {
//         return false;
//     }

//     Element* ptr = new Element(std::move(element));
//     std::unique_ptr<Element> uptr = std::make_unique<Element>(ptr);
//     elements.push_back(std::move(uptr));
//     return true;
// }

void GridScreen::loop() {

}