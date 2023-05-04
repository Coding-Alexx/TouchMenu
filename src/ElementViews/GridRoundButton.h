#include <Arduino.h>
#include "../Elements/Button.h"
#include "../Elements/GridScreen.h"
#include "../Color.h"

class GridRoundButton: public GridElement, public Button {
public:
    GridRoundButton(Color infill, Color border);
    void loop(uint16_t touchX, uint16_t touchY) override;
    bool select() override;
private:
    Color infill;
    Color border;
};