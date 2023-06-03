#include <Arduino.h>
#include <array>
#include <memory>
#include <tuple>

#include "../Screen.h"
#include "../Color.h"
#include "../Element.h"

#pragma once

#define CREATE_GRID_SCREEN(TML, screenID, col, row, color, ...) \
    static_assert(std::is_integral<decltype(screenID)>::value && screenID >= 0 && screenID <= UINT8_MAX, "screenID must be of type uint8_t"); \
    static_assert(std::is_integral<decltype(col)>::value && col >= 0 && col <= UINT8_MAX, "col must be of type uint8_t"); \
    static_assert(std::is_integral<decltype(row)>::value && row >= 0 && row <= UINT8_MAX, "row must be of type uint8_t"); \
    static_assert(std::is_same<decltype(color), Color>::value, "color must be of type Color"); \
    static_assert(std::is_same<decltype(TML), TouchMenuLib>::value, "TML must be of type TouchMenuLib"); \
    /* TODO: überprüfen, ob screenID bereits genutzt wurde*/ \
    \
    GridScreen* screen##screenID = new GridScreen(col, row, color); \
    std::vector<std::tuple<Element*, const uint16_t, const uint16_t, const uint16_t, const uint16_t>> elements##screenID = {__VA_ARGS__}; \
    for (const auto& elementTuple : elements##screenID) { \
        screen##screenID->add(std::get<0>(elementTuple), std::get<1>(elementTuple), \
                              std::get<2>(elementTuple), std::get<3>(elementTuple), \
                              std::get<4>(elementTuple)); \
    }\
    TML.add(screenID, screen##screenID);

class GridScreen: public Screen {
public:
    GridScreen(const uint8_t col, const uint8_t raw, const Color& background);
    //GridScreen(const uint8_t col, const uint8_t raw, const Color& background, std::vector<std::tuple<Element*, const uint16_t, const uint16_t, const uint16_t, const uint16_t>> e);
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
};