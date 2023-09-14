#include <tuple>
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

    if (!display) {
        LOGGER_ERROR("first add this Screen to TML, befor you add an element!")
        return false;
    }

    if (!element) {
        LOGGER_ERROR("element ist NULL")
        return false;
    }

    if (col == 0 || row == 0) {
        // Fehlerbehandlung für ungültige Werte von col und row
        LOGGER_ERROR("col or wor are NULL")
        return false;
    }

    if (posX + sizeX > col || posY + sizeY > row) {
        LOGGER_ERROR("Element are outsite of the Screen")
        return false;
    }

    // Check for overlap with other elements 
    LOGGER("Prüfe ob überlappunen mit anderen Elementen auftreten")
    for (int x = posX; x < posX + sizeX; x++) {
        for (int y = posY; y < posY + sizeY; y++) {
            // If any of the cells are already occupied, we have an overlap
            if (matrix[y * col + x] != UINT8_MAX) {
                LOGGER_ERROR("Element overlapping an existing element")
                return false;
            }
        }
    }

    const uint16_t columnSpacing = width / col;
    const uint16_t rowSpacing = height / row;

    // Calculate the size and position of the element
    uint16_t x = columnSpacing * posX + offsetX;
    uint16_t y = rowSpacing * posY + offsetY;
    uint16_t w = columnSpacing * sizeX;
    uint16_t h = rowSpacing * sizeY;
    LOGGER_PATTERN("Berechnete größen: x:_, y:_, w:_, h:_, display: _", x, y, w, h, display != nullptr)

    // abort, if the size does not fit the element 
    if (!element->setSize(w, h, display->getRotation())) {
        LOGGER_ERROR("Element hat falsche größe und kann daher nicht hinzugefügt werden")
        return false;
    }
    element->setPosition(x, y);
    element->setDisplay(display);

    LOGGER_PATTERN("Füge neues Element an Stelle x=_, y=_ mit sizeX=_, sizeY=_ hinzu", posX, posY, sizeX, sizeY)

    // save the element in elements and depending on the enlarge in matrix
    std::unique_ptr<Element> uptr (element);
    elements.push_back(std::move(uptr));
    for (int x = posX; x < posX+sizeX; x++) {
        for (int y = posY; y < posY+sizeY; y++) {
            LOGGER(elements.size()-1)
            matrix[y*col + x] = elements.size() - 1;
        }
    }

    element = nullptr;  // now uptr is owning the resource 
    return true;
}

bool GridScreen::add(const AddElement& element) {
    return add (element.element, element.posX, element.posY, element.sizeX, element.sizeY);
}

GridScreen& GridScreen::operator<<(const AddElement& element) {
    add (element.element, element.posX, element.posY, element.sizeX, element.sizeY);
    return *this;
}

void GridScreen::loop(Inputs& input) {
    if (input.isTouched) {

        const uint16_t x = input.touchX;
        const uint16_t y = input.touchY;

        if (x < offsetX || y < offsetY || x > offsetX + width || y > offsetY + height) {
            LOGGER_PATTERN("Touchpunkt (_/_) liegt außerhalb dieses Gridscreens", x, y)
            return;
        }

        const uint8_t grid_x = (x-offsetX) / (width / col);
        const uint8_t grid_y = (y-offsetY) / (height / row);

        if (grid_x >= col || grid_y >= row) {
            LOGGER_PATTERN("Feld (_/_) liegt außerhalb dieses Gridscreens", grid_x, grid_y)
            return;
        }
        
        LOGGER("")
        LOGGER_PATTERN("Aktualisiere Element im Feld _/_ (Berührt bei [_,_] mit höhe _/_ und spalten: _/_)", grid_x, grid_y, (x-offsetX), (y-offsetY), width, height, col, row)

        uint8_t e = matrix[col*grid_y + grid_x];
        if (e != UINT8_MAX) elements[e]->setTouch(x, y);
    }

    for (const auto& element : elements) {
        if (element) element->loop();
    }
}

void GridScreen::draw() {
    LOGGER_PATTERN("Zeichne GridScreeen an (_, _) mit sizeX=_, sizeY_ in der Hindergrundfarbe _", offsetX, offsetY, width, height, color_background.toString())
    display->rect(offsetX, offsetY, width, height, 0, 0, Color(0,0,0), color_background);

    #ifdef DEBUG

    // Abstand zwichen den Linien
    const uint16_t columnSpacing = width / (col);
    const uint16_t rowSpacing = height / (row);
    
    // Vertikale Linien zeichnen -> Spalten
    for (int i = 1; i <= col; i++) {
        int x = offsetX + i * columnSpacing;
        display->line(x, offsetY, x, offsetY + height, !color_background);
    }

    // Horizontale Linien zeichnen -> Zeilen
    for (int j = 1; j <= row; j++) {
        int y = offsetY + j * rowSpacing;
        display->line(offsetX, y, offsetX + width, y, !color_background);
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