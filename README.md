# TouchMenu

## Features
* Einfaches erstellen von Menüs durch unterteilung von Screens, Elementen und Items
    * ein Screen ist ein Fenster auf dem Display
    * ein Element ist Manipolierbares/Interaktives Objekt
    * ein Item ist ein Symbol, Icon oder Text, das Elementen bei der Erstellung mitgegeben werden kann
* verstecken von komplexen Features ohne auf diese zu verzichten
    * dies erleichtert die einarbeitung in die Bibliothek
    * macht den Code lesbarer, wenn man nur das angibt, was auch notwenig ist
* Einfaches erstellen von neuen Icons mittels eines Python Scriptes
    * einfach Icon als SVG Datei in einen Unterordner von icon_templates legen und akript ausführen
    * Unterordner dienen dabei als Icon Packete, die einzeln ein/aus geschaltet werden können, um Speicherplatz zu sparen
* Elemente sind jederzeit sicher anpassbar und manipolierbar
* Unterstützung von Sitebars (bzw. 2 Screens aus einmal)


## Kurz Doku
### Erstellen eines neuen Screens
```C++
CREATE_GRID_SCREEN(TML, 0, 1, 3, Color(200, 200, 255),
    AddElement(new Button_Rect("icon:ButtonClick", COLOR_LIGHT_BLUE, 1, 1, TML_goTo(TML, 1)), 0, 0, 1, 1),
    AddElement(new Button_Rect("Item System",      COLOR_LIGHT_BLUE, 1, 1, TML_goTo(TML, 4)), 0, 1, 1, 1),
    AddElement(new Button_Rect("icon:number",      COLOR_LIGHT_BLUE, 1, 1, TML_goTo(TML, 1)), 0, 2, 1, 1)
)
```
Dies ist eine von 3 möglichkeiten einen Screen zu erstellen. Es handelt sich dabei um ein Makro, das wie folgt aufgebaut ist:
```C++
CREATE_GRID_SCREEN(TML objekt, screenID, Spalten, Zeilen, Elemente)
```
**TML objekt** ist die instant diese Bibliothek, bzw. der Klasse TouchMenuLib
**screenID** ist eine Zahl (0-255), die den Screen representiert. Dabei muss keine Reihenfolge beim vergeben der ID eingehalten werden.
**Spalten und Zeilen** sind selbsterklärend
Elemente ist eine Liste an Elementen zusammen mit ihrer Platzierung aus dem GridScreen. Es besteht dabei aus:
```C++
AddElement(element*, x, y, w, h)
```
**element*** ist ein Pointer auf eine Klasse, die von Element erbt. Die zuständigket über den Pointer wird dabei vollständig abgegeben.
**x und y** sind die Koordinaten der Zelle im GridScreen. Dabei wird von 0 an gezählt.
**w und h** sind die Größe des Elements in Anazhl an Zellen
Beachte, dass Elemente, die aus dem Screen rausragen, mit anderen Elementen Überlappen oder zu klein sind erst garnicht gezeichnet werden. Es kommt bei aktven LOGGING auf mindestens ERROR Level dabei jedoch ein Fehler aus der Seriellen Konsole

### Weitere Befehle:
```C++
void init(rotation = 1); // inizialisiere das Display. Setzen der Display Drehung (0=0°, 1=90°, 2=180°, 3=270°)


void add (id, screen); // hinzufügen eines Screens
void add (id, screen, sitebarID); // hinzufügen eines Screens mit sitebar
void addSitebar (id, sitear, size, site = 0); // hinzufügen einer Sitebar. size ist Beite in px, size ist der Rand, an dem die Sitebar angedockt ist (0=Oben, 1=Rechts, 2=Unten, 3=Links)

void loop(); // update Menü -> muss in loop() funktion stehen

bool goTo(screenID, toHistory=true); // toHistory gibt an, ob dieser Schritt in für ein späteres back() gespeichert werden soll. Die Funktion gibt zurück, ob der Screenwechel erfolgreich war
void back(n = 1); // gehe n Screens zurück

// setzen von tasten eingaben
void setInputEnter();
void setInputRight();
void setInputLeft();
void setInputUp();
void setInputDown();

void setScreensaver(screenID, time, backOnInput = false); // erstellt einen Bildschirmschoner, der nach time ms aktibiert wird. backOnInput gibt an, ob bei einem Input direkt zurück auf den Vorherigen Screen gewechselt werden soll
void enableScreenSaver() // aktiviert wieder den Bildschirmschoner
void disableScreenSaver() // deaktiviert den Bildschirmschoner

Display& getDisplay(); // gibt die Dispay Instanz zurück, um manuell etwas mit dem Display anzustellen
uint8_t getScreenID(); // ID des aktuellen Screens
uint8_t getScreensNumber(); // Gesamtanzahl an Screens
```
### Farbsystem
```C++
(COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_ORANGE) + (COLOR_LIGHT_BLUE|COLOR_LIGHT_CYAN|COLOR_RED)
(Hauptfarbe|Item Farbe|Randfarbe) + zweitfarbe
```
**Hauptfarbe:** ist die zentrale Farbe. Bei einem Rechteckigen oder Runden Element ist das z.B. die Hindergrundfarbe, da diese immer benötigt wird. Bei einem Blank Element wird nur eine Farbe für das Item benötigt, daher wird hier dafür die Hauptfarbe genutzt
**Itemfarbe:** ist die Farbe des Textes, des Icons oder die Hauptfarbe des Symbols. Wenn nicht angegeben, wird diese auf Schwarz oder Weiß gesetzt, jenachdem ob die Hauptfarbe hell oder dunkel ist
**Randfarbe:** ist die Farbe des Randes. Wenn nicht angegeben, wird diese auf Schwarz gesetzt
**Zweitfarbe:** ist ein vollständiges zweites Farbobjekt, dass z.B. bei Buttons den An/Aus Zustand markiert oder bei einem Number_Counter ist es die Farbe des zweite Items. Wenn nicht angegeben wird die Hauptfarbe genutzt

man kann also auch Parameter bei der Angabe der Farbe weglassen. COLOR_RED ist auch ein vollstäniges Farbobjekt, dass Itemfarbe und Randfarbe generiert.

### Itemsystem
Allen Elementen kann man einfach einen String übergeben.
Über diesen String können aber auch Grafiken angezeigt werden, indem Schlüsselwörter und parameter genutzt werden.

icon:name -> alle verfügbaren Items sind am Ende der src/Item/icon_templates.h aufgelistet (in der if-Verzweigung)
symb:name -> alle Symbole sind am Ende der src/Item/Symbol.cpp aufgelistet (in der if-Verzweigung)
text:text -> schreibe einen Text mit unterstützung für Parameter. als Leerzeichen bitte _ nutzen und _ als __ schrieben.


----



ToDo:
- Anforderungen / Features detailierter definieren und hier hinterlegen
- erste Variante der Klassenstruktur aufstellen (Hinweis: Interaktion und Rendering entkoppeln, schaut doch mal bei anderen GUI Libs, wie die das machen)
- Skizzen / Diagramme mit entsprechenden Tools in Grafiken/SVG umwandeln und hier einbinden
- denkt nochmal über eine Roadmap nach: 
  - Was ist euer Ziel? 
  - Welche Schritte müsst ihr gehen, um da hin zu kommen? 
  - Wann wollt ihr welche Zwischenziele erreicht haben?

- **Sprecht euch ab, wer welche Aufgaben hat!**

Auszug aus dem Modulkatalog:

Lernziele & erworbene Kompetenzen:
Teamarbeit (insbesondere Vergabe und Annahme von Verantwortung, Führung, Delegation und Absprache von Aufgaben,
Vereinbarung von Zusammenarbeitskriterien) Projektarbeit (insbesondere Vereinbarung von Zielen, Lasten-
und Pflichtenheft, Planung von Meilensteinen und Arbeitspaketen, Projektdurchführung, Dokumentation und
Präsentation eines Projektes und dessen Ergebnisse)Erstellung eines Software-Paketes im Team. Dieses Modul
wird durch unterschiedliche Lehrveranstaltungen implementiert. Fachliche Lehrziele sind angebotsspezifisch.


------

## Anforderungen:

**1) Hauptziele – Must have**
- Bedienung per Touchscreen und Drehknopf
    - Soll mit verschiedenen Screenarten-/größen funktionieren
    - Auch für Bildschirme ohne Touch 
- Grid-Screen
    - „Hauptscreen“ mit Einteilung in Rastern
- Elemente 
   - Button
   - Textfelder
   - Slider
   - Bilder/Icons 

**2)	Should have**

- Auf anderen Microcontrollern nutzbar sein
- Line-Screen
- Listenmenü
- Custom Screen
    - Leeres Seite auf der Nutzer selber etwas gestalten kann
- Zusätzliche Elemente:
    - Farbrad
    - Slider zur Zahleneingabe
- Bedienung mit anderen (externen) Tasten
    - z.B. Funktionen für Pfeiltasten
- Fehler geben, bei Falschen Menü Definitionen -> z.B. 2 Elemente am selben Ort

**3)	Could have**

- Gestlatungsoptionen für Elemente
- Graph-Screen
    - Diagramme darstellen 
- Virtuelle Tastatur
    - Zur Toucheingabe 
- Sidebar
    - Direkte Verknüpfungen zu verschiedenen Screens an der Seite


**4)	 Won’t have**

- Elemente haben keine eigene Funktionen 
    - Nutzer der library integriert selber Funktionen 