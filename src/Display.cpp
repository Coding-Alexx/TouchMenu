#include "Display.h"
#include "TouchMenuLib.h"
#include <array>
#include <sstream>

// alias to item->draw(x, y, *display, color)
void Display::drawItem (uint16_t x, uint16_t y, Item* item, const Color& color) {
    item->draw(x, y, this, color);
}

// alias to item->draw(x, y, *display)
void Display::drawItem (uint16_t x, uint16_t y, Item* item) {
    item->draw(x, y, this);
}

// con'vert rgb colour values or color names into a color instance
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
    
    if (arrayPos != 0) return Color(rgb[0], rgb[1], rgb[2]);

    // else return default color
    return color;
}

// convert '_' to space and '__' to '_'
std::string Display::processText(const std::string& input) {
    std::string result = input;

    // 1. replace "__" with "#@@$~"
    size_t doubleUnderscorePos;
    while ((doubleUnderscorePos = result.find("__")) != std::string::npos) {
        result.replace(doubleUnderscorePos, 2, "#@@$~");
    }

    // 2. replace '_' with ' '
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

// Convert string to a uint16_t safely
uint16_t Display::stringToNumber(const std::string& str, const uint16_t& value) {
    if (str == "") return value;

    uint16_t result = 0;
    for (char c : str) {
        if (c >= '0' && c <= '9') {
            result *= 10;
            result += (c - '0');
        } 
        else if (c == '.') break;
        else return value;
    }

    return result;
}

// Convert string to a douple safely
double Display::stringToNumber(const std::string& str, const double& value) {
    size_t dotPos = str.find('.');

    if (dotPos == std::string::npos) {
        auto number = stringToNumber(str, static_cast<double>(UINT16_MAX));
        if (number == UINT16_MAX) return value;
        else return static_cast<double>(number);
    }
    
    uint16_t intResult = stringToNumber(str.substr(0, dotPos), static_cast<double>(UINT16_MAX));
    uint16_t decimalResult = stringToNumber(str.substr(dotPos + 1), static_cast<double>(UINT16_MAX));
    double result = 0.0;

    if (intResult == UINT16_MAX && decimalResult == UINT16_MAX) return value;
    if (intResult != UINT16_MAX) result += intResult;
    if (decimalResult != UINT16_MAX) result += static_cast<float>(decimalResult) / std::pow(10, (int) log10(decimalResult));

    return result;
}

// create an instance of an item from a string with default color black
Item* Display::createItem(const std::string str) {
    return createItem(str, Color(0,0,0));
}

// create an instance of an item from a string with specified default color
Item* Display::createItem(const std::string str, const Color& defaultColor) {
    std::string type, name;
    double size = 0.0, scale = 1;
    uint16_t width = 2, height = 2;

    Color color = Color(defaultColor);
    std::istringstream iss(str);
    std::string word;
    
    if (str == "") return new Text("", size);

    while (iss >> word) {
        size_t colonPos = word.find(':');
        if (colonPos != std::string::npos) {
            std::string key = word.substr(0, colonPos);
            std::string value = word.substr(colonPos + 1);

            // set type and his name (e.g. icon:settings)
            if (type == "" && (key == "icon" || key == "file" || key == "symb" || key == "text")) {
                type = key;
                name = (key == "text") ? processText(value) : value; 
            }


            // Find and set other parameters
            else if (key == "color") {
                color.setPrimaryColor(parseColor(value, color));
            } else if (key == "border") {
                color.setBorderColor(parseColor(value, color.getBorderColor()));
            } else if (key == "size") {
                // size = stringToNumber(value, size );
            } else if (key == "height") {
                // height = stringToNumber(value, height );
            } else if (key == "width") {
                // width = stringToNumber(value, width );
            } else if (key == "scale") {
                // scale = stringToNumber(value, scale );
            }
        }
        
        // if no type was defined at the beginning, set type to text and end search for other parameters 
        if (type == "") {
            type = "text";
            name = str;
            break;
        }
    }

    if (name == "") return new Text("No Name", size, COLOR_RED);
    else if (type == "") return new Text("No type", size, COLOR_RED);

    else if (type == "text") 
        return new Text(name.c_str(), size, color);

    else if (type=="icon") {
        auto* icon = Icon::create(name, scale, color);
        if (icon) return icon;
        else return new Text("NOT FOUND", size, COLOR_RED);

    // } else if (type == "file") { // TODO: implement loading and displaying bitmaps from memory
        	
    } else if (type == "symb") {
        return Symbol::create(name, (uint16_t) height, (uint16_t) width, color, size, scale);
    }
    
    return new Text("ERR", 2, COLOR_RED);
}