#include <Arduino.h>
#include <array>
#include <memory>
#include <tuple>
#include <vector>

#include "../Screen.h"
#include "../Color.h"
#include "../Element.h"
#include "../ElementViews/Number_Slider.h"

class ListScreen: public Screen {
public:
    ListScreen (const uint8_t lines, const Color& background);
    virtual ~ListScreen() {} // virtual destructor

    bool add(Element* element);
    
    void loop(Inputs& input) override;
    void draw() override;

    void setDisplay(Display* const disp) override;
    void setResolution(uint16_t width, uint16_t height) override;

private:
    const Color background;
    uint8_t lines;
    std::vector<std::unique_ptr<Element>> elements;

    uint8_t scroll_position = 0;
    uint16_t scrollbar_width = 30;
    Number_Slider scrollbar = Number_Slider(COLOR_GRAY|COLOR_GREEN, TML_empty_slider);
};