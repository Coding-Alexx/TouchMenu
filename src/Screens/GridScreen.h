#include <Arduino.h>
#include <array>
#include <memory>
#include <tuple>
#include <vector>

#include "../Screen.h"
#include "../Color.h"
#include "../Element.h"

#pragma once

#define CREATE_GRID_SCREEN(TML, screenID, col, row, color, ...) \
    /* Check parameters for correctness */ \
    static_assert(std::is_integral<decltype(screenID)>::value && screenID >= 0 && screenID <= UINT8_MAX, "screenID must be of type uint8_t"); \
    static_assert(std::is_integral<decltype(col)>::value && col >= 0 && col <= UINT8_MAX, "col must be of type uint8_t"); \
    static_assert(std::is_integral<decltype(row)>::value && row >= 0 && row <= UINT8_MAX, "row must be of type uint8_t"); \
    static_assert(std::is_same<decltype(color), Color>::value, "color must be of type Color"); \
    static_assert(std::is_same<decltype(TML), TouchMenuLib>::value, "TML must be of type TouchMenuLib"); \
    /* TODO: überprüfen, ob screenID bereits genutzt wurde*/ \
    \
    GridScreen* screen##screenID = new GridScreen(col, row, color); \
    TML.add(screenID, screen##screenID); \
    std::vector<AddElement> elements##screenID {__VA_ARGS__}; \
    for (const auto& element : elements##screenID) { \
        screen##screenID->add(element); \
    }

#define CREATE_GRID_SCREEN_WITH_SITEBAR(TML, screenID, sitebarID, col, row, color, ...) \
    /* Check parameters for correctness */ \
    static_assert(std::is_integral<decltype(screenID)>::value && screenID >= 0 && screenID <= UINT8_MAX, "screenID must be of type uint8_t"); \
    static_assert(std::is_integral<decltype(sitebarID)>::value && sitebarID >= 0 && sitebarID <= UINT8_MAX, "sitebarID must be of type uint8_t"); \
    static_assert(std::is_integral<decltype(col)>::value && col >= 0 && col <= UINT8_MAX, "col must be of type uint8_t"); \
    static_assert(std::is_integral<decltype(row)>::value && row >= 0 && row <= UINT8_MAX, "row must be of type uint8_t"); \
    static_assert(std::is_same<decltype(color), Color>::value, "color must be of type Color"); \
    static_assert(std::is_same<decltype(TML), TouchMenuLib>::value, "TML must be of type TouchMenuLib"); \
    /* TODO: überprüfen, ob screenID bereits genutzt wurde*/ \
    \
    GridScreen* screen##screenID = new GridScreen(col, row, color); \
    TML.add(screenID, screen##screenID, sitebarID); \
    std::vector<AddElement> elements##screenID {__VA_ARGS__}; \
    for (const auto& element : elements##screenID) { \
        screen##screenID->add(element); \
    }

#define CREATE_GRID_SCREEN_SITEBAR(TML, sitebarID, size, side, col, row, color, ...) \
    /* Check parameters for correctness */ \
    static_assert(std::is_integral<decltype(sitebarID)>::value && sitebarID >= 0 && sitebarID <= UINT8_MAX, "sitebarID must be of type uint8_t"); \
    static_assert(std::is_integral<decltype(col)>::value && col >= 0 && col <= UINT8_MAX, "col must be of type uint8_t"); \
    static_assert(std::is_integral<decltype(row)>::value && row >= 0 && row <= UINT8_MAX, "row must be of type uint8_t"); \
    static_assert(std::is_integral<decltype(side)>::value && side >= 0 && side <= UINT8_MAX, "side must be of type uint8_t"); \
    static_assert(std::is_integral<decltype(size)>::value && size >= 0 && size <= UINT16_MAX, "size must be of type uint16_t"); \
    static_assert(std::is_same<decltype(color), Color>::value, "color must be of type Color"); \
    static_assert(std::is_same<decltype(TML), TouchMenuLib>::value, "TML must be of type TouchMenuLib"); \
    /* TODO: überprüfen, ob screenID bereits genutzt wurde*/ \
    \
    GridScreen* sitebar##sitebarID = new GridScreen(col, row, color); \
    TML.addSitebar(sitebarID, sitebar##sitebarID, size, side); \
    std::vector<AddElement> sitebar_elements##sitebarID {__VA_ARGS__}; \
    for (const auto& element : sitebar_elements##sitebarID) { \
        sitebar##sitebarID->add(element); \
    }

struct AddElement {
    Element* element;
    const uint16_t posX;
    const uint16_t posY;
    const uint16_t sizeX;
    const uint16_t sizeY;

     AddElement(Element* elem, uint16_t x, uint16_t y, uint16_t sizeX, uint16_t sizeY)
        : element(elem), posX(x), posY(y), sizeX(sizeX), sizeY(sizeY) {}
};

class GridScreen: public Screen {
public:
    GridScreen(const uint8_t col, const uint8_t raw, const Color& background);
    //GridScreen(const uint8_t col, const uint8_t raw, const Color& background, std::vector<std::tuple<Element*, const uint16_t, const uint16_t, const uint16_t, const uint16_t>> e);
    //GridScreen(uint8_t col, uint8_t raw, char* image) // später soll es auch die möglichkeit geben ein Hindergrundbild anzuzeigen
    virtual ~GridScreen() {} // virtual destructor


    bool add(Element* element, const uint16_t posX, const uint16_t posY, const uint16_t sizeX, const uint16_t sizeY);
    bool add(const AddElement& element);
    GridScreen& operator<<(const AddElement& element);
    
    // Entweder mit Template, wo alle T Kind von Element sein müssen (static_assert(std::is_base_of<Element, T>::value, "T must be a derived class of Element"); // statische Überprüfung)
    // Oder mit Macros arbeiten
    //bool add(Element& element, const uint16_t posX, const uint16_t posY, const uint16_t sizeX, const uint16_t sizeY);
    void loop(Inputs& input) override;
    void draw() override;
    void setResolution(int16_t height, int16_t width);
    uint8_t getRow() const { return row; }
    uint8_t getCol() const { return col; }

private:
    const Color color_background;
    uint8_t row;
    uint8_t col;
    std::vector<std::unique_ptr<Element>> elements; // TODO eventuell eine Map nutzen
    std::vector<uint8_t> matrix; 
};