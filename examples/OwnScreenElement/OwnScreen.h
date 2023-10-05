
// Class structure of an screen
class OwnScreen: public Screen {
public:
    // constructor
    OwnScreen (Element* element, const Color& background);
    
private:
    // update all elements, show small animations, ...
    void loop(Inputs& input) override;

    // redraw the screen
    void draw() override;

    // own variables
    Element* element;
    Color background;
};

OwnScreen::OwnScreen(Element* element, const Color& background): 
    element(element),
    background(background)
    {}

void OwnScreen::loop(Inputs& input) {
    // updateTouchPoint pauses after activation, isTouched is always active when the display is touched.
    if (input.updateTouchPoint) element->setTouch(input);

    // update all elements
    element->loop(input);
}

void OwnScreen::draw() {
    // draw background
    display->rect(offsetX, offsetY, width, height, 0, 0, COLOR_BLACK, background);

    auto w = width/4;
    auto h = height/4;

    element->setDisplay(display);
    element->setPosition(width/2-w/2, height/2-h/2);
    if (!element->setSize(w, h, 0)) LOGGER_ERROR("element Size is too small");
    element->draw();
}