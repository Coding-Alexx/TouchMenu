#include "Display.h"
#include "TouchMenuLib.h"
#include <array>
#include <sstream>

void Display::drawItem (uint16_t x, uint16_t y, Item* item, const Color& color) {
    item->draw(x, y, this, color);
}

void Display::drawItem (uint16_t x, uint16_t y, Item* item) {
    item->draw(x, y, this);
}

Color Display::parseColor(const std::string& str, const Color& color) {
    
    if (str == "yellow") return Color(255, 255, 0);
    if (str == "gray") return Color(50, 50, 50);
    if (str == "red") return Color(255, 0, 50);
    
    std::stringstream ss(str);
    std::string token;
    size_t arrayPos = 0;
    std::array<uint8_t, 3> rgb;
    rgb.fill(0);
    while (std::getline(ss, token, ',')) {
        rgb[arrayPos++] = std::atoi(token.c_str());
        if (arrayPos > 3) break;
    }
    LOGGER_PATTERN("_ wird zu r:_, g:_, b:_", str.c_str(), rgb[0], rgb[1], rgb[2])
    if (arrayPos != 0) return Color(rgb[0], rgb[1], rgb[2]);

    // else return default color
    return color;
}

std::string Display::processText(const std::string& input) {
    std::string result = input;

    // 1. replace "__" with "#@@$~"
    size_t doubleUnderscorePos;
    while ((doubleUnderscorePos = result.find("__")) != std::string::npos) {
        result.replace(doubleUnderscorePos, 2, "#@@$~");
    }

    // 2. replace '_' with ' '
    // Ersetze alle verbleibenden einzelnen Unterstriche am Ende durch Leerzeichen
    size_t underscorePos;
    while ((underscorePos = result.find("_")) != std::string::npos) {
        result.replace(underscorePos, 1, " ");
    }

    // 3. replace "#@@$~" with '_'
    size_t hashPos;
    while ((hashPos = result.find("#@@$~")) != std::string::npos) {
        result.replace(hashPos, 5, "_");
    }

    return result;
}

template <typename T>
T Display::stringToNumber(const std::string& str, const T& value) {
    try {
        std::istringstream ss(str);
        T result;
        if (!(ss >> result)) {
            throw std::invalid_argument("Invalid conversion");
        }
        return result;
    } catch (const std::invalid_argument&) {
        return value;
    }
}


Item* Display::createItem(const std::string str) {
    return createItem(str, Color(0,0,0));
}

Item* Display::createItem(const std::string str, const Color& defaultColor) {
    std::string type, name;
    double size = 0.0;
    int width = 2, height = 2;

    Color color = Color(defaultColor);
    std::istringstream iss(str);
    std::string word;

    while (iss >> word) {
        size_t colonPos = word.find(':');
        if (colonPos != std::string::npos) {
            std::string key = word.substr(0, colonPos);
            std::string value = word.substr(colonPos + 1);

            LOGGER_PATTERN("String _ hat im moment key=_, value=_", str.c_str(), key.c_str(), value.c_str())

            if (type == "" && (key == "icon" || key == "file" || key == "symb" || key == "text")) {
                type = key;
                name = (key == "text") ? processText(value) : value; 

            // without a type it is a text
            }

            else if (key == "color") {
                color.setPrimaryColor(parseColor(value, color));
                LOGGER_PATTERN("edit color to _", color.toString())
            } else if (key == "border") {
                color.setBorderColor(parseColor(value, color.getBorderColor()));
                LOGGER_PATTERN("edit border color to _", color.getBorderColor().toString())
            } else if (key == "size") {
                size = stringToNumber(value, size );
            } else if (key == "height") {
                height = stringToNumber(value, height );
            } else if (key == "width") {
                width = stringToNumber(value, width );
            }
        }
        
        if (type == "") {
            type = "text";
            name = str;
            break;
        }
    }

    LOGGER_PATTERN("String _ hat type _ mit dem namen '_' und: size=_, color=_, borderColor=_, width=_, height=_", str.c_str(), type.c_str(), name.c_str(), size, color.toString(), color.getBorderColor().toString(), width, height)

    if (name == "") return new Text("No Name", size, COLOR_RED);
    else if (type == "") return new Text("No type", size, COLOR_RED);

    else if (type == "text") 
        return new Text(name.c_str(), size, color);

    else if (type=="icon") {
        auto* icon = Icon::create(name, color);
        if (icon) return icon;
        else return new Text("NOT FOUND", size, COLOR_RED);

    // } else if (type == "file") {
        	
    } else if (type == "symb") {
        return Symbol::create(name, (uint16_t) height, (uint16_t) width, color, size);
    }
    
    return new Text("ERR", 2, COLOR_RED);
}