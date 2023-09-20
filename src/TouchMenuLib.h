#pragma once

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
#include "ElementViews/RectButton.h"
#include "ElementViews/Slider_Rect.h"
#include "ElementViews/Slider_Arrow.h"
#include "ElementViews/Textbox_Rect.h"
#include "ElementViews/Textbox_Blank.h"

//#include "DisplayGFX.h"
#include "DisplayTFTeSPI.h"
class TouchMenuLib {
public:
    TouchMenuLib (Display* disp);
    ~TouchMenuLib ();

    // init menu and display
    void init(uint8_t rotation = 1);

    // füge neues Screen mit der Kennung id hinzu
    void add (const uint8_t id, Screen* screen);
    void add (const uint8_t id, Screen* screen, const uint8_t sitebarID);

    void addSitebar (const uint8_t id, Screen* sitear, uint16_t size, uint8_t site = 0);

    // aktualisiere das Menü
    void loop();

    void draw();

    // gehe ein Screen in der History 1 oder mehrere shritte zurück zurück -> bei back(0) -> gehe zum zuletzt gespeicherten Screen (falls man die History zwischendurch deaktiviert hat)
    void back(const uint8_t i = 1);

    // gehe zum Screen mit kennung id, man kann es auch deaktivieren, dass dieser Screen auf dem Stabel der Historys gelegt wird
    bool goTo(const uint8_t id, const bool toHistory = true);

    // Inputs:
    void setInputEnter();
    void setInputRight();
    void setInputLeft();
    void setInputUp();
    void setInputDown();

    void setScreensaver(const uint8_t screenID, unsigned long time, bool backOnInput = true);
    bool enableScreenSaver ();
    void disableScreenSaver ();
    
    bool setSitebar (const uint8_t sitebarID);                  // set Sitebar to ID, if sitebar feature is activated
    bool enableSitebar ();                                      // activate Sitebar Feature, go to default Sitebar for current screen and draw
    void disableSitebar (const bool deactivateSitebar = false); // disable Sitebar Feature

    Display& getDisplay();

    uint8_t getScreenID();

private:
    bool enableSitebar (bool);

    // storage screen
    std::map<uint8_t, std::unique_ptr<Screen>> screens;
    std::stack<uint8_t> screenHistory {};

    // storage sitebar (is also a type of screen)
    std::map<uint8_t, std::unique_ptr<Screen>> sitebars;
    std::map<uint8_t, uint8_t> sitebarConnector;
    uint8_t currentSitebar = UINT8_MAX;
    bool deactivateSitebar = false;

    Display* display;

    bool isDisplayInit = false;

    Inputs input;

    bool screensaverBackOnInput = false;
    bool isScreensaverEnable = false;
    unsigned long screensaverTime = 0;  // time to waiting for screensaver
    unsigned long screensaverTimer = 0; // time counter
    uint8_t screensaverID = UINT8_MAX;

    unsigned long inputTimer = 0;
};