# TouchMenu

## Dokumentation

https://touchmenu.readthedocs.io/de/latest/About/introduction.html

## Features
* Einfaches erstellen von Menüs durch Unterteilung von Screens, Elementen und Items
    * ein Screen ist ein Fenster auf dem Display
    * ein Element ist Manipulierbares/Interaktives Objekt
    * ein Item ist ein Symbol, Icon oder Text, das Elementen bei der Erstellung mitgegeben werden kann
* Einfaches Erstellen von neuen Icons mittels eines Python Scriptes
    * einfach Icon als SVG Datei in einen Unterordner von icon_templates legen und Skript ausführen
    * Unterordner dienen dabei als Icon Pakete, die einzeln ein/aus geschaltet werden können, um Speicherplatz zu sparen
* Elemente sind jederzeit sicher anpassbar und manipulierbar
* Unterstützung von Sitebars (bzw. 2 Screens aus einmal)
* Bildschirmschoner (automatisches Wechseln auf einen festgelegten Screen nach einer gewissen Zeit)
* Elemente mit Callback und nachträglicher Veränderungsmöglichkeit
* Buttons mit Press und switch Modi + Lang gedrückt halten Funktion
* Eingabe einer Nummer per Counter und Slider
* Darstellung von Text

## Kurz Doku
### Erstellen eines neuen Screens
```C++
CREATE_GRID_SCREEN(TML, 0, 1, 3, Color(200, 200, 255),
    AddElement(new Button_Rect("icon:ButtonClick", COLOR_LIGHT_BLUE, 1, 1, TML_goTo(TML, 1)), 0, 0, 1, 1),
    AddElement(new Button_Rect("Item System",      COLOR_LIGHT_BLUE, 1, 1, TML_goTo(TML, 4)), 0, 1, 1, 1),
    AddElement(new Button_Rect("icon:number",      COLOR_LIGHT_BLUE, 1, 1, TML_goTo(TML, 1)), 0, 2, 1, 1)
)
```
Dies ist eine von 2 Möglichkeiten einen Screen zu erstellen. Es handelt sich dabei um ein Makro, das wie folgt aufgebaut ist:
```C++
CREATE_GRID_SCREEN(TML objekt, screenID, Spalten, Zeilen, Elemente)
```
**TML** ist die Instanz dieser Bibliothek, bzw. der Klasse TouchMenuLib
**screenID** ist eine Zahl (0-255), die den Screen representiert. Dabei muss keine Reihenfolge beim vergeben der ID eingehalten werden.
**Spalten und Zeilen** sind selbsterklärend
Elemente ist eine Liste an Elementen zusammen mit ihrer Platzierung aus dem GridScreen. Es besteht dabei aus:
```C++
AddElement(element*, x, y, w, h)
```
**element*** ist ein Pointer auf eine Klasse, die von Element erbt. Die Zuständigkeit über den Pointer wird dabei vollständig abgegeben.
**x und y** sind die Koordinaten der Zelle im GridScreen. Dabei wird von 0 an gezählt.
**w und h** sind die Größe des Elements in Anzahl an Zellen
Beachte, dass Elemente, die aus dem Screen rausragen, mit anderen Elementen Überlappen oder zu klein sind erst gar nicht gezeichnet werden. Es kommt bei aktiven LOGGING auf mindestens ERROR Level dabei jedoch ein Fehler aus der Seriellen Konsole

### Weitere Befehle:
```C++
void init(rotation = 1); // inizialisiere das Display. Setzen der Display Drehung (0=0°, 1=90°, 2=180°, 3=270°)

void add (id, screen); // hinzufügen eines Screens
void add (id, screen, sitebarID); // hinzufügen eines Screens mit sitebar
void addSitebar (id, sitear, size, site = 0); // hinzufügen einer Sitebar. size ist Beite in px, size ist der Rand, an dem die Sitebar angedockt ist (0=Oben, 1=Rechts, 2=Unten, 3=Links)

void loop(); // update Menü -> muss in loop() funktion stehen

bool goTo(screenID, toHistory=true); // toHistory gibt an, ob dieser Schritt in für ein späteres back() gespeichert werden soll. Die Funktion gibt zurück, ob der Screenwechel erfolgreich war
void back(n = 1); // gehe n Screens zurück

// setzen von tasten eingaben -> wird beim nächsten loop berücksichtigt und anschließend zurückgesetzt
void setInputEnter();
void setInputRight();
void setInputLeft();
void setInputUp();
void setInputDown();

void setScreensaver(screenID, time, backOnInput = false); // erstellt einen Bildschirmschoner, der nach time ms aktibiert wird. backOnInput gibt an, ob bei einem Input direkt zurück auf den Vorherigen Screen gewechselt werden soll
void enableScreenSaver() // aktiviert wieder den Bildschirmschoner
void disableScreenSaver() // deaktiviert den Bildschirmschoner

Display& getDisplay(); // gibt die Display Instanz zurück, um manuell etwas mit dem Display anzustellen
uint8_t getScreenID(); // ID des aktuellen Screens
uint8_t getScreensNumber(); // Gesamtanzahl an Screens
```
### Farbsystem
```C++
(COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_ORANGE) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_RED)
(Hauptfarbe|Item Farbe|Randfarbe) + zweitfarbe
```
**Hauptfarbe:** ist die zentrale Farbe. Bei einem Rechteckigen oder Runden Element ist das z.B. die Hintergrundfarbe, da diese immer benötigt wird. Bei einem Blank Element wird nur eine Farbe für das Item benötigt, daher wird hier dafür die Hauptfarbe genutzt

**Itemfarbe:** ist die Farbe des Textes, des Icons oder die Hauptfarbe des Symbols. Wenn nicht angegeben, wird diese auf Schwarz oder Weiß gesetzt, je nachdem ob die Hauptfarbe hell oder dunkel ist

**Randfarbe:** ist die Farbe des Randes. Wenn nicht angegeben, wird diese auf Schwarz gesetzt

**Zweitfarbe:** ist ein vollständiges zweites Farbobjekt, dass z.B. bei Buttons den An/Aus Zustand markiert oder bei einem Number_Counter ist es die Farbe des zweite Items. Wenn nicht angegeben wird die Hauptfarbe genutzt

man kann also auch Parameter bei der Angabe der Farbe weglassen. *COLOR_RED* oder *COLOR_GREEN|COLOR_GRAY* sind auch ein vollständige Farbobjekte, die die Fehlenden Farben automatisch setzten.

### Item System
Allen Elementen kann man einfach einen String übergeben.
Über diesen String können aber auch Grafiken angezeigt werden, indem Schlüsselwörter und Parameter genutzt werden.

* icon:name -> alle verfügbaren Items sind am Ende der src/Item/icon_templates.h aufgelistet (in der if-Verzweigung)
* symb:name -> alle Symbole sind am Ende der src/Item/Symbol.cpp aufgelistet (in der if-Verzweigung)
* text:text -> schreibe einen Text mit unterstützung für Parameter. Anstatt eines Leerzeichen muss _ genutzt werden und für _ wird ein doppeltes __ geschrieben.

wenn man das Schlüsselwort weglässt, wird der String komplett als Text interprätiert

## Erforderliche Bobliotheken:
* TFT_eSPI (getestet mit Version 2.5.30), Verfügbar per Library Manager