.. _features:

List of features
+++++++++++++++++

Allgemein
============

| Einfaches Erstellen von Menüs durch Unterteilung von Screens, Elementen und Items
|       -> Screen = Fenster auf dem Display
|       -> Element = manipulierbares/interaktives Objekt
|       -> Item ist ein Symbol, Icon oder Text, das Elementen bei der Erstellung mitgegeben werden kann
| 
| Verstecken von komplexen Features, ohne auf diese zu verzichten
|       -> dies erleichtert die Einarbeitung in die Bibliothek
|       -> macht den Code lesbarer, wenn man nur das angibt, was auch notwenig ist
|
| Einfaches Erstellen von neuen Icons mittels eines Python Scriptes
|       -> einfach Icon als SVG Datei in einen Unterordner von icon_templates legen und Skript ausführen
|       -> Unterordner dienen dabei als Icon Packete, die einzeln ein-/ausgeschaltet werden können, um Speicherplatz zu sparen
|
| Elemente sind jederzeit sicher anpassbar und manipulierbar
| 
| Unterstützung von Sidebars (bzw.zwei Screens, die auf demselben Display gleichzeitig angezeigt werden)

Elemente
=========
| Die Erklärung der Elemente erfolgt in ihren Seiten unter ``Class Reference``
| **Buttons**: in rechteckiger, runder und unsichtbarer Form
| **Switches**: in rechteckiger, runder und unsichtbarer Form (gehören ebenfalls der Klasse ``Button`` an)
| **Slider**
| **Zahlenzähler** (Number_Counter)
| **Textboxen**: in eckiger und unsichtbarer Form

Screens
=========
| Die Erklärung der Screens erfolgt in ihren Seiten unter ``Class Reference``
| **GridScreen**
| **ErrorScreen**

Farbsystem
===========

``(COLOR_LIGHT_BLUE|COLOR_DARK_CYAN|COLOR_ORANGE)   + (COLOR_LIGHT_BLUE |COLOR_LIGHT_CYAN  |COLOR_RED)``
``(Hauptfarbe      |Itemfarbe     |Randfarbe)       + (Zweitfarbe       |Zweititemfarbe    |Zweitrandfarbe)``

| Hauptfarbe: ist die zentrale Farbe. Bei einem rechteckigen oder runden Element ist das z.B. die Hindergrundfarbe, da diese immer benötigt wird. Bei einem Blank Element wird nur eine Farbe für das Item benötigt, daher wird hier dafür die Hauptfarbe genutzt.
| Itemfarbe: ist die Farbe des Textes, des Icons oder die Hauptfarbe des Symbols. Wenn nicht angegeben, wird diese auf schwarz oder weiß gesetzt, je nachdem, ob die Hauptfarbe hell oder dunkel ist 
| Randfarbe: ist die Farbe der Umrandung. Wenn nicht angegeben, wird diese auf schwarz gesetzt 
| Zweitfarbe, Zweititemfarbe, Zweitrandfarbe: ist ein vollständiges zweites Farbobjekt, dass z.B. bei Buttons den An/Aus Zustand markiert oder bei einem Number_Counter ist es die Farbe des zweite Items. Wenn nicht angegeben wird die Hauptfarbe genutzt
| Man kann also auch Parameter bei der Angabe der Farbe weglassen. ``COLOR_RED`` ist auch ein vollstäniges Farbobjekt, dass Itemfarbe und Randfarbe generiert.

Itemsystem
===========
| Allen Elementen kann man einen String übergeben, um Text anzeigen zu lassen. 
| Über diesen String können aber auch Grafiken angezeigt werden, indem Schlüsselwörter und Parameter genutzt werden.

| ``icon:name`` -> alle verfügbaren Items sind am Ende der `icon_bitmaps.h <https://github.com/Coding-Alexx/TouchMenu/blob/main/src/Item/icon_bitmaps.h#L166>`_ (in der if-Verzweigung) Datei aufgelistet.
| ``symb:name`` -> alle Symbole sind in `Symbol.cpp <https://github.com/Coding-Alexx/TouchMenu/blob/main/src/Item/Symbol.cpp#L79>`_  (in der if-Verzweigung) Datei aufgelistet.
| ``text:text`` -> schreibe einen Text mit Unterstützung für Parameter. Um Leerzeichen im Text zu auszugeben, bitte ``_`` verwenden. Um ``_`` zu auszugeben, bitte ``__`` verwenden.