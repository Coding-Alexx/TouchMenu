#include "GridScreen.h"

GridScreen::GridScreen(const uint8_t col, const uint8_t row, const Color& background):
    color_background(Color(background)),
    row(row),
    col(col),
    elements(row*col)
{
    //elements.reserve(row*col);
}

bool GridScreen::add(Element* element, const uint16_t posX, const uint16_t posY, const uint16_t sizeX, const uint16_t sizeY) {

    if (!element) {
        LOGGER_ERROR("element ist NULL")
        return false;
    }

    if (col == 0 || row == 0) {
        // Fehlerbehandlung für ungültige Werte von col und row
        LOGGER_ERROR("Zeilen oder Spalten sind 0!!!")
        return false;
    }

    if (posX > col && posY > row) {
        LOGGER_ERROR("Element außerhalb des Rasters")
        return false;
    }

    // Berechne die Maße des Gridscreens

    const uint16_t columnSpacing = width / col;
    const uint16_t rowSpacing = height / row;

    uint16_t x = columnSpacing * posX;
    uint16_t y = rowSpacing * posY;
    uint16_t w = columnSpacing * sizeX;
    uint16_t h = rowSpacing * sizeY;

    if (!element->setSize(w, h, display->getRotation())) {
        return false;
    }
    element->setPosition(x, y);
    element->setDisplay(display);

    std::unique_ptr<Element> uptr (element);
    // elements.push_back(std::move(uptr));
    elements[posX*col+posY] = std::move(uptr);
    element = nullptr;  // uptr besitzt jetzt die Ressource
    return true;
}

void GridScreen::loop() {

}

void GridScreen::draw() {
    display->fillScreen(color_background);
    LOGGER(row)
    LOGGER(col)
    LOGGER(height)
    LOGGER(width)

    const uint16_t columnSpacing = width / (col);
    const uint16_t rowSpacing = height / (row);

    LOGGER(columnSpacing)
    LOGGER(rowSpacing)
    LOGGER(color_background.toString())

    #ifdef DEBUG
    // Vertikale Linien zeichnen -> Spalten
    for (int i = 1; i <= col; i++) {
        int x = i * columnSpacing;
        display->line(x, 0, x, height, !color_background);
    }

    // Horizontale Linien zeichnen -> Zeilen
    for (int j = 1; j <= row; j++) {
        int y = j * rowSpacing;
        display->line(0, y, width, y, !color_background);
    }
    #endif

    for (const auto& element : elements) {
        if (element) {
            element->draw();
        }
    }
}

void GridScreen::setResolution(int16_t h, int16_t w) {
    Screen::setResolution(h, w);
}