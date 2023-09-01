#include "Display.h"
#include "TouchMenuLib.h"

void Display::drawItem (uint16_t x, uint16_t y, Item* item, const Color& color) {
    item->draw(x, y, this, color);
}

Item* Display::createItem(const std::string str) {
    // Standart Icons
    if (str.compare(0,5,"icon:") == 0) {
        auto name = str.substr(5);
        if (name == "") return new Text("ERR 1");
        auto* icon = Icon::create(name);
        if (icon) return icon;
        else return new Text("ERR 2");
    
    // Icons aus Dateien
    } else if (str.compare(0,5,"file:") == 0) {
        return new Text("ERR 3");
    // Text
    } else {
        return new Text(str.c_str());
    }
}