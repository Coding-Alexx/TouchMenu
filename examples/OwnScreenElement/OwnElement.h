#include <array>

// Class structure of an element
class OwnElement: public Element {
private:
    // Process touch information -> is called up when the display is touched
    void setTouch(Inputs& input) override;

    // What happens when you select the element via a button?
    bool select(Inputs& input) override;

    // redraw the element
    void draw() override;

    // can be used for updates or animations
    void loop(Inputs& input) override;

    // Check if the given size works for this element
    bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override;

    // own variables
    Color color;
    String text[4] = {"this", "is", "my", "element"};
    int i = 0;

public:
    // constructor
    OwnElement(const Color& color);
};

OwnElement::OwnElement(const Color& color):
    color(color)
    {}

bool OwnElement::select(Inputs& input){
    i = (i+1) % 4;
    draw();
    return false;
}

void OwnElement::draw(){
    // draw a rectangle -> x1, y1, x2, y2, border strength, border radius, border color, infill color 
    display->rect(posX, posY, sizeX, sizeY, 2, 3, color.getBorderColor(), color);

    // draw text inside this rectangle -> x, y, text size, text, color
    display->text_center(posX + sizeX/2, posY + sizeY/2, 1, text[i].c_str(), color.getItemColor());
}

void OwnElement::loop(Inputs& input) {}

void OwnElement::setTouch(Inputs& input) {
    // if the touch coordinates are in this element, call select
    if (input.touchX > posX && input.touchX < posX + sizeX && input.touchY > posY && input.touchY < posY + sizeY) select(input);
}

bool OwnElement::checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) {
    return true;
}