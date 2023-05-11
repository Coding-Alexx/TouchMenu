#include <Arduino.h>
#include <array>
#include <memory>
#include <tuple>

#include "../Screen.h"
#include "../Color.h"
#include "../Element.h"

#pragma once

class GridScreen: public Screen {
public:
    GridScreen(const uint8_t col, const uint8_t raw, const Color& background);
    GridScreen(const uint8_t col, const uint8_t raw, const Color& background, std::vector<std::tuple<Element*, const uint16_t, const uint16_t, const uint16_t, const uint16_t>> e);
    //GridScreen(uint8_t col, uint8_t raw, char* image) // später soll es auch die möglichkeit geben ein Hindergrundbild anzuzeigen

    bool add(Element* element, const uint16_t posX, const uint16_t posY, const uint16_t sizeX, const uint16_t sizeY);
    
    // Entweder mit Template, wo alle T Kind von Element sein müssen (static_assert(std::is_base_of<Element, T>::value, "T must be a derived class of Element"); // statische Überprüfung)
    // Oder mit Macros arbeiten
    //bool add(Element& element, const uint16_t posX, const uint16_t posY, const uint16_t sizeX, const uint16_t sizeY);
    void loop() override;
    void draw() override;

private:
    std::vector<std::unique_ptr<Element>> elements; // TODO eventuell eine Map nutzen
    const Color& background;
    size_t height;
    size_t width;
    uint8_t raw;
    uint8_t col;

    template <typename T>
    std::unique_ptr<Element> make_unique_derived(Element* element);

    
};