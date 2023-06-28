#include "GridScreen.h"

GridScreen::GridScreen(const uint8_t col, const uint8_t row, const Color& background):
    color_background(Color(background)),
    row(row),
    col(col),
    elements(),
    matrix(row*col, UINT8_MAX)
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

    
     for (int x = posX; x < posX + sizeX; x++) {
        for (int y = posY; y < posY + sizeY; y++) {
            // If any of the cells are already occupied, we have an overlap
            if (matrix[y * col + x] != UINT8_MAX) {
                LOGGER_ERROR("Element would overlap an existing element")
                return false;
            }
        }
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

    LOGGER_PATTERN("Füge neues Element an Stelle x=_, y=_ mit sizeX=_, sizeY=_ hinzu", posX, posY, sizeX, sizeY)

    std::unique_ptr<Element> uptr (element);
    elements.push_back(std::move(uptr));
    for (int x = posX; x < posX+sizeX; x++)
        for (int y = posY; y < posY+sizeY; y++) {
            LOGGER(elements.size()-1)
            matrix[y*col + x] = elements.size() - 1;
            }
            
    //elements[posX*col+posY] = std::move(uptr);
    element = nullptr;  // uptr besitzt jetzt die Ressource
    return true;
}

void GridScreen::loop(Inputs& input) {
    if (input.isTouched) {

        uint16_t x = input.touchX;
        uint16_t y = input.touchY;

        uint8_t rx = x / (width / row);
        uint8_t ry = y / (height / col);

        if (rx >= row || ry >= col) LOGGER("rx oder ry sind zu groß")
        
        LOGGER("")
        LOGGER_PATTERN("Aktualisiere Element im Feld _/_ (Berührt bei [_,_])", rx, ry, x, y)

        uint8_t e = matrix[col*ry + rx];
        if (e != UINT8_MAX) elements[e]->setTouch(x, y);
    }
}

void GridScreen::draw() {
    display->fillScreen(color_background);
    LOGGER("Zeichne Neu")

    const uint16_t columnSpacing = width / (col);
    const uint16_t rowSpacing = height / (row);

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