#include <Arduino.h>
#include "../Screen.h"
#include "../Color.h"
#include "../Elements/GridElement.h"

class GridScreen: public Screen {
public:
    GridScreen(uint8_t col, uint8_t raw, Color background);
    //GridScreen(uint8_t col, uint8_t raw, char* image) // später soll es auch die möglichkeit geben ein Hindergrundbild anzuzeigen

    void add(GridElement element);
    void loop() override;

private:
    std::vector<GridElement> elements;
};

