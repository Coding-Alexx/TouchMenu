#include "CalibrateTouchScreen.h"

void CalibrateTouchScreen::draw() {
    display->fillScreen(COLOR_BLACK);
    switch (state) {
    case 0:
    case 10:
        display->point(10, 10, COLOR_WHITE);
        display->text_center(width/2, 1*height/4, 1.6, "Tipp auf Punkt oben links", COLOR_WHITE);
        LOGGER(state)
        break;
    case 1:
    case 11:
        display->point(width-10, 10, COLOR_WHITE);
        display->text_center(width/2, 1*height/4, 1.6, "Tipp auf Punkt oben rechts", COLOR_WHITE);
        LOGGER(state)
        break;
    case 2:
    case 12:
        display->point(width-10, height-10, COLOR_WHITE);
        display->text_center(width/2, 1*height/4, 1.6, "Tipp auf Punkt unten links", COLOR_WHITE);
        break;
    case 3:
    case 13:
        display->point(10, height-10, COLOR_WHITE);
        display->text_center(width/2, 1*height/4, 1.6, "Tipp auf den Punkt unten rechts", COLOR_WHITE);
        break;
    case 5:
        display->text_center(width/2, height/4, 2, "Display Kalibriert", COLOR_WHITE);
        display->text_center(width/2, height/3, 1.5, "Teste jetzt Kalibrierung", COLOR_WHITE);
        break;
    case 15:
        display->text_center(width/2, 1*height/4, 2, "Kalibrierung erfolgreich", COLOR_WHITE);
        break;
    case 16:
        display->text_center(width/2, 1*height/4, 2, "Kalibrierung Fehlgeschlagen", COLOR_WHITE);
        break;


    default:
        break;
    }
}

void CalibrateTouchScreen::loop(Inputs& input) {
    uint16_t x = 0;
    uint16_t y = 0;
    if (state < 4 && display->getTouch(&x, &y)) {
        if (millis() - timer >= 600) {
            timer = millis();
            display->getTouch(&x, &y, true);
            coordinates[(2*state)] = x;
            coordinates[(2*state+1)] = y;
            LOGGER_PATTERN("Touchpunkt: [_,_] beim state: _", x, y, state)
            state++;
            draw();
        }
    } else if (state == 4) {
        LOGGER("setze Kalibrierung")
        display->setTouchCalibration({coordinates[0], coordinates[1], coordinates[4], coordinates[5]});
        timer = millis();
        state++;
        draw();
    } else if (state == 5) {
        if (millis() - timer >= 3000) {
            LOGGER("Display Kalibriert")
            timer = millis();
            state = 10;
            timer = 0;
            draw();
        }
    } else if (state >= 10 && state <= 13 && display->getTouch(&x, &y)) {
        LOGGER("im Test State")
        if (millis() - timer >= 600) {
            timer = millis();
            testCoordinates[(2*state)] = x;
            testCoordinates[(2*state+1)] = y;
            draw();
            LOGGER_PATTERN("Test Touchpunkt: [_,_] beim state: _", x, y, state)
            state++;
            draw();
        }
    } else if (state == 14) {
        state = 15;
        for (int i = 0; i < coordinates.size(); i++) {
            if (!(coordinates[i] - 50 < testCoordinates[i] && coordinates[i] + 50 > testCoordinates[i])) {
                LOGGER_PATTERN("- [_] ist fehlgeschlagen, org=_, test=_", i, coordinates[i], testCoordinates[i])
                state = 16;
            }
        }
        draw();
    } else if (((state > 5) && state < 12) || state > 16){
        bool b = display->getTouch(&x, &y);
        LOGGER_PATTERN("unbekannter State: _, Touch ist _", state, b)
    }
}