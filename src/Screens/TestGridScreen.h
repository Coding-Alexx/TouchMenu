#include <memory>

#include "GridScreen.h"
#include "../Color.h"
#include "../Element.h"
#include "../TouchMenuLib.h"

#pragma once

class TestGridScreenFactory {
public:
    template<typename T>
    static GridScreen* create(TouchMenuLib& tml, const uint8_t id, const Color& background, T* element) {
        static_assert(std::is_base_of<Element, T>::value, "T must be a subclass of Element");

        T* e1 = new T(*element);
        T* e2 = new T(*element);
        T* e3 = new T(*element);

        GridScreen* gridscreen = new GridScreen(3, 3, background);
        tml.add(id, gridscreen);
        gridscreen->add(e1      , 0, 0, 1, 1);  
        gridscreen->add(e2      , 1, 0, 2, 2);  
        gridscreen->add(e3      , 0, 1, 1, 2);  
        gridscreen->add(element , 1, 2, 2, 1);  

        return gridscreen;
    }
};