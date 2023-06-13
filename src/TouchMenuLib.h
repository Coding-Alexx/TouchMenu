#include <Arduino.h>
#include <map>
#include <stack>
#include <memory>
#include <tuple>

#include "debug.h"
#include "Screen.h"
#include "Input.h"
#include "Screens/GridScreen.h"
#include "Screens/ErrorScreen.h"
#include "ElementViews/RoundButton.h"

//#include "DisplayGFX.h"
#include "DisplayTFTeSPI.h"

#pragma once

class TouchMenuLib {
public:
    TouchMenuLib (Display* disp);
    ~TouchMenuLib ();

    // inizialisiere das Menü mit der gewünschten ausgabe
    void init();

    // füge neues Screen mit der Kennung id hinzu
    void add (uint8_t id, Screen* screen);

    // aktualisiere das Menü
    void loop();

    void draw();

    // gehe ein Screen in der History 1 oder mehrere shritte zurück zurück -> bei back(0) -> gehe zum zuletzt gespeicherten Screen (falls man die History zwischendurch deaktiviert hat)
    void back(size_t i = 1);

    // gehe zum Screen mit kennung id, man kann es auch deaktivieren, dass dieser Screen auf dem Stabel der Historys gelegt wird
    bool goTo(size_t id, bool toHistory = true);

    // Inputs:
    void setInputEnter();
    void setInputRight();
    void setInputLeft();
    void setInputUp();
    void setInputDown();

private:
    std::map<uint8_t, std::unique_ptr<Screen>> screens; // falls Referenzen nicht funktionieren sollten, kann man z.B. std::reference_wrapper<Screen> nutzen
    std::stack<size_t> screenHistory;

    Display* display;

    bool isDisplayInit = false;

    void setAutoResolution(Screen* screen);

    uint8_t screenHistoryLevel = 0;

    Inputs input = {};
};