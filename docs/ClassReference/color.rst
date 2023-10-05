.. _color:

Color
++++++++

Beschreibung
=============
Diese Klasse verwaltet alles, was mit Farben zu tun hat. Mit dieser Klasse kann man die Farben sämtlicher :ref:`Elemente<button_blank>`, 
:ref:`Screens<screen>` etc. anpassen.



Funktionen
=============


.. csv-table:: 
    :widths: 100 1000

    inline, ":ref: `Color <colorconstructor1>` (const Color& prim, const Color& item, const Color& border, const Color* secondary, bool isBorderSet = false)"
    inline, ":ref: `Color <colorconstructor2>` (const uint8_t r, const uint8_t g, const uint8_t b, const bool)"
    inline, ":ref: `Color <colorconstructor3>` (const bool, const Color& other)"
    inline const ":ref: `Color <color>`", ":ref: `setColorOffset <colorsetColorOffset>` (const Color& color, const int offset) const"
    inline const ":ref: `Color <color>`", ":ref: `createItemColor <colorcreateitemcolor>` (const Color& color) const"
    inline const ":ref: `Color <color>`", ":ref: `createBorderColor <colorcreatebordercolor>` (const Color& color) const"
    inline, ":ref: `Color <colorconstructor4>` (const Color& other)"
    inline, ":ref: `Color <colorconstructor5>` (const Color& prim, const int offset)"
    inline, ":ref: `Color <colorconstructor6>` (const Color& prim, const Color& item)"
    inline, ":ref: `Color <colorconstructor7>` (const Color& prim, const bool, const Color& border)"
    inline, ":ref: `Color <colorconstructor8>` (const Color& prim, const Color& item, const Color& border)"
    inline, ":ref: `Color <colorconstructor9>` (const Color& prim, const bool, const bool, const Color& secondary)"
    inline, ":ref: `Color <colorconstructor10>` (const Color& prim, const bool, Color& border, const Color& secondary)"
    inline, ":ref: `Color <colorconstructor11>` (const Color& prim, const Color& item, const bool, const Color& secondary)"
    inline, ":ref: `Color <colorconstructor12>` (const Color& prim, const Color& item, const Color& border, const Color& secondary)"
    inline, ":ref: `Color <colorconstructor13>` (const uint8_t r, const uint8_t g, const uint8_t b): Color(Color(r,g,b, true), 0)"
    inline, ":ref: `~Color <colordestructor>` ()"
    inline ":ref: `Color <color>`", ":ref: `operator! <colorOperatorExcl>` () const"
    inline ":ref: `Color <color>`", ":ref: `operator+ <colorOperatorPlus>` (const Color& secondary) const"
    inline ":ref: `Color <color>`", ":ref: `operator| <colorOperatorLine>` (const Color& other)"
    inline ":ref: `Color <color>`", ":ref: `operator= <_colorOperatorEquals>` (const Color& other)"
    inline ":ref: `Color <color>`", ":ref: `getPrimColor <colorGetPrimColor>` ()"
    inline ":ref: `Color <color>`", ":ref: `getItemColor <colorGetItemColor>` ()"
    inline ":ref: `Color <color>`", ":ref: `getBorderColor <colorGetBorderColor>` ()"
    inline ":ref: `Color <color>`", ":ref: `getSecondaryItemColor <colorgetsecondaryitemColor>` ()"
    inline ":ref: `Color <color>`", ":ref: `getSecondaryBorderColor <colorGetsecondaryBorderColor>` ()"
    inline ":ref: `Color <color>`", ":ref: `getSecondaryColor <colorGetsecondaryColor>` ()"
    inline uint8_t, ":ref: `getRed <colorgetred>` ()"
    inline uint8_t, ":ref: `getGreen <colorgetgreen>` ()"
    inline uint8_t, ":ref: `getBlue <colorgetblue>` ()"
    inline bool, ":ref: `hasSecondaryColor <colorhassecondarycolor>` () const"
    inline ":ref: `Color <color>`", ":ref: `setPrimaryColor <colorcolorsetprimarycolor>` (const Color& color)"
    inline ":ref: `Color <color>`", ":ref: `setItemColor <colorcolorsetitemcolor>` (const Color& color)"
    inline ":ref: `Color <color>`", ":ref: `setBorderColor <colorcolorsetbordercolor>` (const Color& color)"
    inline ":ref: `Color <color>`", ":ref: `setSecondaryColor <colorcolorsetsecondarycolor>` (const Color& color)"
    inline ":ref: `Color <color>`", ":ref: `setSecondaryItemColor <colorcolorsetsecondaryitemcolor>` (const Color& color)"
    inline ":ref: `Color <color>`", ":ref: `setSecondaryBorderColor <colorcolorsetsecondaryBordercolor>` (const Color& color)"
    inline void, ":ref: `setPrimaryColor <colorVoidSetPrimaryColor>` (const Color& color)"
    inline void, ":ref: `setItemColour <colorVoidSetItemColour>` (const Color& color)"
    inline void, ":ref: `setBorderColour <colorVoidSetBorderColour>` (const Color& color)"
    inline void, ":ref: `setSecondaryColour <colorVoidSetsecondaryColour>` (const Color& color)"
    inline void, ":ref: `setSecondaryItemColour <colorVoidSetsecondaryitemColour>` (const Color& color)"
    inline void, ":ref: `setSecondaryBorderColour <colorVoidSetsecondaryBorderColour>` (const Color& color)"
    inline String, ":ref: `toString <colortostring>` () const"

Variablen und Konstanten
==========================


.. csv-table:: 
    :widths: 100 1000

    uint8_t, ":ref: `r_prim <_colorvr_prim>`"
    uint8_t, ":ref: `g_prim <_colorvg_prim>`"
    uint8_t, ":ref: `b_prim <_colorvb_prim>`"
    uint8_t, ":ref: `r_item<_colorvr_item>`"
    uint8_t, ":ref: `g_item<_colorvg_item>`"
    uint8_t, ":ref: `b_item<_colorvb_item>`"
    uint8_t, ":ref: `r_border<_colorvr_border>`"
    uint8_t, ":ref: `g_border<_colorvg_border>`"
    uint8_t, ":ref: `n_border<_colorvb_border>`"
    Color*, ":ref: `secondaryColor<_colorvsecondaryColor>` = nullptr"
    const bool, ":ref: `isBorderSet<_colorvisborderset>` = false"



Farbwerte
=============

Hier ist eine Übersicht aller Macros, die anstelle von der ``Color (r, g, b)`` Schreibweise verwendet werden können, um 
einfacher häufig verwendete Farben zu erstellen.

.. csv-table:: 
    :widths: 100 1000

    COLOR_RED, ":ref: `Color <colorColorConstructor>` (255,   0,   0 )"
    COLOR_GREEN, ":ref: `Color <colorColorConstructor>` (0,   255,   0 )"
    COLOR_BLUE, ":ref: `Color <colorColorConstructor>` (0,     0, 255 )"
    COLOR_BLACK, ":ref: `Color <colorColorConstructor>` (0,     0,   0 )"
    COLOR_WHITE, ":ref: `Color <colorColorConstructor>` (255, 255, 255 )"
    COLOR_YELLOW, ":ref: `Color <colorColorConstructor>` (255, 255,   0 )"
    COLOR_MAGENTA, ":ref: `Color <colorColorConstructor>` (255,   0, 255 )"
    COLOR_CYAN, ":ref: `Color <colorColorConstructor>` (0,   255, 255 )"
    COLOR_GRAY, ":ref: `Color <colorColorConstructor>` (128, 128, 128 )"
    COLOR_DARK_RED, ":ref: `Color <colorColorConstructor>` (128,   0,   0 )"
    COLOR_DARK_GREEN, ":ref: `Color <colorColorConstructor>` (0,   128,   0 )"
    COLOR_DARK_BLUE, ":ref: `Color <colorColorConstructor>` (0,     0, 128 )"
    COLOR_DARK_YELLOW, ":ref: `Color <colorColorConstructor>` (128, 128,   0 )"
    COLOR_DARK_MAGENTA, ":ref: `Color <colorColorConstructor>` (128,   0, 128 )"
    COLOR_DARK_CYAN, ":ref: `Color <colorColorConstructor>` (0,   128, 128 )"
    COLOR_LIGHT_RED, ":ref: `Color <colorColorConstructor>` (255, 128, 128 )"
    COLOR_LIGHT_GREEN, ":ref: `Color <colorColorConstructor>` (128, 255, 128 )"
    COLOR_LIGHT_BLUE, ":ref: `Color <colorColorConstructor>` (128, 128, 255 )"
    COLOR_LIGHT_YELLOW, ":ref: `Color <colorColorConstructor>` (255, 255, 128 )"
    COLOR_LIGHT_MAGENTA, ":ref: `Color <colorColorConstructor>` (255, 128, 255 )"
    COLOR_LIGHT_CYAN, ":ref: `Color <colorColorConstructor>` (128, 255, 255 )"
    COLOR_ORANGE, ":ref: `Color <colorColorConstructor>` (255, 165,   0 )"
    COLOR_PURPLE, ":ref: `Color <colorColorConstructor>` (128,   0, 128 ))"
    COLOR_PINK, ":ref: `Color <colorColorConstructor>` (255, 192, 203 )"
    COLOR_LIME, ":ref: `Color <colorColorConstructor>` (0,   255,   0 )"
    COLOR_TEAL, ":ref: `Color <colorColorConstructor>` (0,   128, 128 )"
    COLOR_BROWN, ":ref: `Color <colorColorConstructor>` (139,  69,  19 )"
    COLOR_NAVY, ":ref: `Color <colorColorConstructor>` (0,     0, 128 )"


Funktionen Beschreibung
=========================

.. _colorConstructor1:

inline Color(const Color& prim, const Color& item, const Color& border, const Color* secondary, bool isBorderSet = false)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 46-55
    :linenos:

Dieser Konstruktor wird genutzt, um die RGB Werte der Parameter, also der Hauptfarbe ``prim``, der Farbe des Objektes 
``item`` und der Umrandunsfarbe ``border`` zu extrahieren, und mit ihnen die entsprechenden Variablen zu initialisieren.
Außerdem findet eine Initialisierung von :ref:`isBorderSet<colorvisborderset>` statt.

.. _colorConstructor2:

inline Color(const uint8_t r, const uint8_t g, const uint8_t b, const bool)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 58-64
    :linenos:

Dieser Konstruktor wird genutzt, um mit den RGB übergebenen Werten nur die Variablen `r_prim<colorvr_prim>`, `g_prim<colorvg_prim>` und `b_prim<colorvb_prim>` zu initialisieren. 
Daher eignet sich der Konstruktor besonders, um ein ``Color``-Objekt ohne Item oder Border zu erstellen.

.. _colorConstructor3:

inline Color(const bool, const Color& other)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 66-73
    :linenos:

Dieser Konstruktor wird genutzt, um mit der übergebenen Farbe ``other`` nur die Variablen `r_prim<colorvr_prim>`, `g_prim<colorvg_prim>` und `b_prim<colorvb_prim>` zu initialisieren. 
Daher eignet sich der Konstruktor besonders, um von einer Farbe, die vorher auch Farbinformationen zu einem Icon oder Border gehabt hat, nur die Hauptfarbe zu extrahieren.

.. _colorsetColorOffset:

inline const Color setColorOffset(const Color& color, const int offset) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 75-90
    :linenos:

Mit dieser Funktion kann aus einer Farbe eine neue Farbe erstellt werden, deren RGB Werte um einen bestimmten ``offset`` verschoben ist gegenüber der Ausgangsfarbe.

.. literalinclude:: ../../src/Color.h
    :lines: 76

Sollte kein ``offset`` angegeben werden, wird dieser `Color<colorconstructor3>` Konstruktor aufgerufen. Die neue Farbe ist äquivalent zur alten.

.. literalinclude:: ../../src/Color.h
    :lines: 81

Besonders dunkle Farben sollen nur heller und nicht noch dunkler werden, deshalb wird hier geprüft, ob die Summe von
`r_prim<colorvr_prim>`, `g_prim<colorvg_prim>` und `b_prim<colorvb_prim>` kleinergleich ``0`` ist. Wenn ja, wird der `Color<colorconstructor3>` mit ``std::abs(offset)`` aufgerufen, um aus einer negativen Zahl
eine positive zu erhalten.

.. literalinclude:: ../../src/Color.h
    :lines: 83-89

Andernfalls werden mithilfe des ``offset`` neue RGB Werte berechnet. Dafür wird der maximale Wert aus ``0`` und ``static_cast<int>(color.r_prim) + offset`` bestimmt, also dem Wert für
auf einen ``int`` gecasteten Wert für `r_prim<colorvr_prim>` addiert mit dem ``offset``. Anschließend vergleichen wir das gerade ermittelte Maximum mit ``255`` und weisen ``r`` dem Wert des daraus
resultierenden Minumums zu. Da wir :ref:`r_prim<colorvr_prim>` von einem ``uint8_t`` zu einem normalen ``int`` casten und das Ergebnis der Addition deshalb ``>255`` sein kann, ist dieses Minumum äußerst wichtig. 
Mit den Variablen ``g`` und ``b`` wird genauso verfahren.
Anschließend wird dieser `Color<colorconstructor2>` Konstruktor aufgerufen, wodurch aus den neuen RGB Werten ein ``Color`` Objekt entsteht.

.. _colorCreateItemcolor:

inline const Color createItemColor(const Color& color) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 92-95
    :linenos:

Mit dieser Funktion wird automatisch eine Farbe für ein Item bestimmt. Dieses kann hier entweder weiß oder schwarz werden, je nachdem, welche Farbe sichtbarer ist.
Sollte die Summe aus `r_prim<colorvr_prim>`, `g_prim<colorvg_prim>` und `b_prim<colorvb_prim>` kleiner sein als der Referenzwert, so wird der `Color<colorconstructor2>` Konstruktor aufgerufen, um eine Farbe in Weiß zu erstellen.
Andernfalls wird derselbe Konstruktor aufgerufen, um eine Farbe in Schwarz zu erstellen. 

.. _colorCreateBorderColor:

inline const Color createBorderColor(const Color& color) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Color.h
    :lines: 97-99
    :linenos:

Mit dieser Funktion wird automatisch eine Farbe für die Umrandung bestimmt. Diese kann hier entweder weiß oder schwarz werden, je nachdem, welche Farbe sichtbarer ist.
Sollte die Summe aus `r_prim<colorvr_prim>`, `g_prim<colorvg_prim>` und `b_prim<colorvb_prim>` kleiner sein als der Referenzwert, so wird der `Color<colorconstructor2>` Konstruktor aufgerufen, um eine Farbe in Weiß zu erstellen.
Andernfalls wird derselbe Konstruktor aufgerufen, um eine Farbe in Schwarz zu erstellen. 
TODO

.. _colorConstructor4:

inline Color(const Color& other)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 103
    :linenos:

Mithilfe dieser Copy Konstruktors kann ein Objekt der ``Color`` Klasse kopiert werden.

.. _colorConstructor5:

inline Color(const Color& prim, const int offset)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 104
    :linenos:

Mithilfe dieses Konstruktors kann aus einer Farbe eine neue Farbe mit einem ``offset`` erstellt werden. Dafür erfolgt bei der Initialisierung ein Funktionsaufruf von `colorsetColorOffset<colorsetColorOffset>` mit den gegebenen Parametern.

.. _colorConstructor6:

inline Color(const Color& prim, const Color& item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 105
    :linenos:

Mithilfe dieses Konstruktors kann eine Farbe mit einer selbst festgelegten Item Farbe erstellt werden. Die Borderfarbe wird mit `colorcreatebordercolor<colorcreatebordercolor>` generiert.

.. _colorConstructor7:

inline Color(const Color& prim, const bool, const Color& border)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 106
    :linenos:

Mithilfe dieses Konstruktors kann eine Farbe mit einer selbst festgelegten Umrandungs Farbe erstellt werden. Die Item Farbe wird mit `colorcreateitemcolor<colorcreateitemcolor>` generiert.

.. _colorConstructor8:

inline Color(const Color& prim, const Color& item, const Color& border)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 107
    :linenos:

Mithilfe dieses Konstruktors kann eine Farbe mit einer selbst festgelegten Item Farbe und einer selbst festgelegten Umrandungs Farbe erstellt werden.

.. _colorConstructor9:

inline Color(const Color& prim, const bool, const bool, const Color& secondary)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 108
    :linenos:

Mithilfe dieses Konstruktors kann eine Farbe zusammen mit einer zusätzlichen Zweitfarbe (siehe `secondaryColor<_colorvsecondaryColor>`) erstellt werden. Die Item Farbe und Umrandungs Farbe werden 
mit `colorcreateitemcolor<colorcreateitemcolor>` bzw. `colorcreatebordercolor<colorcreatebordercolor>` generiert.

.. _colorConstructor10:

inline Color(const Color& prim, const bool, Color& border, const Color& secondary)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 109
    :linenos:

Mithilfe dieses Konstruktors kann eine Farbe mit einer selbst festgelegten Umrandungsfarbe zusammen mit einer zusätzlichen Zweitfarbe (siehe `secondaryColor <colorvsecondaryColor>`) erstellt werden.
Die Item Farbe wird mit `colorcreateitemcolor <colorcreateitemcolor>` generiert.

.. _colorConstructor11:

inline Color(const Color& prim, const Color& item, const bool, const Color& secondary)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 110
    :linenos:

Mithilfe dieses Konstruktors kann eine Farbe mit einer selbst festgelegten Item Farbe zusammen mit einer zusätzlichen Zweitfarbe (siehe `secondaryColor <colorvsecondaryColor>`) erstellt werden.
Die Umrandungs Farbe wird mit `colorcreatebordercolor <colorcreatebordercolor>` generiert.

.. _colorConstructor12:

inline Color(const Color& prim, const Color& item, const Color& border, const Color& secondary)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 111
    :linenos:

.. _colorConstructor13:

Mithilfe dieses Konstruktors kann eine Farbe mit einer selbst festgelegten Item Farbe und einer selbst festgelegten Umrandungs Farbe zusammen 
mit einer zusätzlichen Zweitfarbe (siehe `secondaryColor<colorvsecondaryColor>`) erstellt werden.

inline Color(const uint8_t r, const uint8_t g, const uint8_t b): Color(Color(r,g,b, true), 0)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 113
    :linenos:

Mithilfe dieses Konstruktors kann man mit Angabe von RGB Werten diesen `Color<colorconstructor5>` Konstruktor aufrufen.

.. _colorDestructor:

inline ~Color()
~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 118
    :linenos:

Der Destructor wird bei der Zerstörung eines ``Color`` Objektes aufgerufen und gibt den von `secondaryColor<colorvsecondaryColor>` belegten Speicherplatz wieder frei.

.. _colorOperatorExcl:

inline Color operator!() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 123
    :linenos:

Diese Funktion invertiert die RGB Werte einer Farbe und erzeugt ruft diesen `Color<colorconstructor13>` Konstruktor auf, um diese neue Farbe zu erstellen.

.. _colorOperatorPlus:

inline Color operator+(const Color& secondary) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 124
    :linenos:

Diese Funktion addiert eine Farbe mit einer zweiten, übergebenen Farbe. Sie gibt ein neues ``Color`` Objekt mit diesen addierten Farbwerten nach dem Konstruktoraufruf von `Color<colorconstructor12>` zurück.

.. _colorOperatorLine:

inline Color operator|(const Color& other)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 125-129
    :linenos:

Diese Funktion nimmt eine Farbe ``other`` und benutzt diese Farbe als Hauptfarbe für eine neues ``Color`` Objekt, wenn bereits eine Umrandungsfarbe festgelegt ist (`isBorderSet<colorvisborderset>`). 
Dafür wird dieser `Color<colorconstructor1>` Konstruktor aufgerufen. Dabei wird mithilfe von `getBorderColor<colorGetBorderColor>` die Umrandunsfarbe übergeben. Desweiteren übergeben wir ``true`` an den 
Konstruktor, da dieses Objekt eine Umrandungsfarbe besitzt.
Ist noch keine Umrandungsfarbe festgelet, wird ``other`` stattdessen als Umrandunsfarbe für ein neues Objekt verwendet und es wird ebenso dieser `Color<colorconstructor1>` Konstruktor aufgerufen.
Mithilfe von `getItemColor<colorGetItemColor>` wird die Farbe des Items als Hauptfarbe übermittelt.

.. _colorOperatorEquals:

inline Color& operator=(const Color& other)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 130-143
    :linenos:

Diese Funktion überschreibt die Farbwerte von einem Objekt mit den Farbwerten eines anderen Objekts.
Um eine Selbstzuweisung zu verhindern, wird mit ``this != &other`` sichergestellt, dass tatsächlich zwei verschiedene Objekte betrachtet werden.
Anschließend werden `r_prim<colorvr_prim>`, `g_prim<colorvg_prim>`, `b_prim<colorvb_prim>`, `r_item<colorvr_item>`, `g_item<colorvg_item>`, `b_item<colorvb_item>`,
`r_border<colorvr_border>`, `g_border<colorvg_border>` und `b_border<colorvb_border>` mit den entsprechenden Werten der anderen Farbe ``other`` überschrieben.
Schließlich wird `secondaryColor<colorvsecondaryColor>` gelöscht und der Speicherplatz freigegeben. Sollte ``other`` hingegen eine `secondaryColor<colorvsecondaryColor>` besitzen, 
so wird für das aktuelle Objekt eine neue `secondaryColor<colorvsecondaryColor>` erstellt, die auf den Speicherplatz der anderen zeigt. 

.. _colorGetPrimColor:

inline Color getPrimColor()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 147
    :linenos:

Diese Getter-Funktion gibt die Hauptfarbe eines ``Color`` Objektes aus.

.. _colorGetItemColor:

inline Color getItemColor()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 148
    :linenos:

Diese Getter-Funktion gibt die Item Farbe eines ``Color`` Objektes aus.

.. _colorGetBorderColor:


inline Color getBorderColor()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 149
    :linenos:

Diese Getter-Funktion gibt die Umrandungs Farbe eines ``Color`` Objektes aus.

.. _colorGetSecondaryItemColor:

inline Color getSecondaryItemColor()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 150
    :linenos:

Diese Getter-Funktion gibt die Item Farbe der Zweitfarbe eines ``Color`` Objektes aus.

.. _colorGetSecondaryBorderColor:

inline Color getSecondaryBorderColor()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 151
    :linenos:

Diese Getter-Funktion gibt die Umrandungs Farbe der Zweitfarbe eines ``Color`` Objektes aus.

.. _colorGetSecondaryColor:

inline Color getSecondaryColor()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 152-155
    :linenos:

Diese Getter-Funktion gibt die Zweitfarbe eines ``Color`` Objektes aus. Wenn ein Objekt keine Zweifarbe besitzt, wird stattdessen das ``Color`` Objekt zurückgegeben.

.. _colorGetRed:

inline uint8_t getRed()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 157
    :linenos:

Gibt den Rotanteil einer Farbe (":ref:`r_prim<colorvr_prim>`") zurück.

.. _colorGetGreen:

inline uint8_t getGreen()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 158
    :linenos:

Gibt den Grünanteil einer Farbe (":ref:`g_prim<colorvg_prim>`") zurück.

.. _colorGetBlue:

inline uint8_t getBlue()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 159
    :linenos:

Gibt den Blauanteil einer Farbe (":ref:`b_prim<colorvb_prim>`") zurück.


.. _colorhassecondarycolor:

inline bool hasSecondaryColor() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 161
    :linenos:

Diese Funktion gibt ``true`` zurück, wenn ein ``Color`` Objekt eine Zweitfarbe (":ref:`secondaryColor<colorvsecondarycolor>`") besitzt, und ``false`` falls es keine besitzt.

.. _colorColorSetPrimaryColor:

inline Color setPrimaryColor(const Color& color) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 166
    :linenos:

Mit dieser Funktion lässt sich die Hauptfarbe eines ``Color`` Objektes setzen. Die Funktion gibt ein neues Objekt zurück.


.. _colorColorSetItemColor:

inline Color setItemColor(const Color& color) const 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 167
    :linenos:

Mit dieser Funktion lässt sich die Item Farbe eines ``Color`` Objektes setzen. Die Funktion gibt ein neues Objekt zurück.


.. _colorColorSetBorderColor:

inline Color setBorderColor(const Color& color) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 168
    :linenos:

Mit dieser Funktion lässt sich die Umrandungs Farbe eines ``Color`` Objektes setzen. Die Funktion gibt ein neues Objekt zurück.


.. _colorColorSetSecondaryColor:

inline Color setSecondaryColor(const Color& color) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 169
    :linenos:
 
Mit dieser Funktion lässt sich die Zweitfarbe eines ``Color`` Objektes setzen. Die Funktion gibt ein neues Objekt zurück.


.. _colorColorSetSecondaryItemColor:

inline Color setSecondaryItemColor(const Color& color) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 170
    :linenos:

Mit dieser Funktion lässt sich die Item Farbe der Zweitfarbe eines ``Color`` Objektes setzen. Die Funktion gibt ein neues Objekt zurück.


.. _colorColorSetSecondaryBorderColor:

inline Color setSecondaryBorderColor(const Color& color) const 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 151
    :linenos:

Mit dieser Funktion lässt sich die Umrandungs Farbe der Zweitfarbe eines ``Color`` Objektes setzen. Die Funktion gibt ein neues Objekt zurück.

.. _colorVoidSetPrimaryColor:

inline void setPrimaryColor(const Color& color)    
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 173
    :linenos:

Mit dieser Funktion lässt sich die Hauptfarbe des aktuellen ``Color`` Objektes verändern.

.. _colorVoidSetItemColor:

inline void setItemColor(const Color& color)  
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 174
    :linenos:

Mit dieser Funktion lässt sich die Item Farbe des aktuellen ``Color`` Objektes verändern.

.. _colorVoidSetBorderColor:

inline void setBorderColor(const Color& color)     
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 175
    :linenos:

Mit dieser Funktion lässt sich die Umrandungs Farbe des aktuellen ``Color`` Objektes verändern.

.. _colorVoidSetSecondayColor:

inline void setSecondaryColor(const Color& color)  
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 176
    :linenos:

Mit dieser Funktion lässt sich die Zweitfarbe des aktuellen ``Color`` Objektes verändern.

.. _colorVoidSetSecondaryItemColor:

inline void setSecondaryItemColor(const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 177
    :linenos:

Mit dieser Funktion lässt sich die Item Farbe der Zweitfarbe des aktuellen ``Color`` Objektes verändern.

.. _colorVoidSetSecondaryBorderColor:

inline void setSecondaryBorderColor(const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 178
    :linenos:

Mit dieser Funktion lässt sich die Umrandungs Farbe der Zweitfarbe des aktuellen ``Color`` Objektes verändern.

.. _colorToString:

inline String toString() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 181-183
    :linenos:

Diese Funktion gibt einen ``String`` in der Form Color(r,g,b) zurück, 
wobei die jeweiligen Zahlenwerte an Stelle von "r","g" bzw. "b" ausgegeben werden.


Variablen Beschreibung
=======================

.. _colorvr_prim:

uint8_t r_prim
~~~~~~~~~~~~~~~~

Gibt den Rotanteil an, den eine Farbe haben kann (0 bis 255).

.. _colorvg_prim:

uint8_t g_prim 
~~~~~~~~~~~~~~~~

Gibt den Grünanteil an, den eine Farbe haben kann (0 bis 255).

.. _colorvb_prim:

uint8_t b_prim
~~~~~~~~~~~~~~~~

Gibt den Blauanteil an, den eine Farbe haben kann (0 bis 255).

.. _colorvr_item:

uint8_t r_item
~~~~~~~~~~~~~~~~

Gibt den Rotanteil an, den die Farbe eines Item haben kann (0 bis 255).

.. _colorvg_item:

uint8_t g_item
~~~~~~~~~~~~~~~~

Gibt den Grünanteil an, den die Farbe eines Item haben kann (0 bis 255).

.. _colorvb_item:

uint8_t b_item
~~~~~~~~~~~~~~~~

Gibt den Blauanteil an, den die Farbe eines Item haben kann (0 bis 255).

.. _colorvr_border:

uint8_t r_border
~~~~~~~~~~~~~~~~

Gibt den Rotanteil an, den die Farbe einer Umrandung haben kann (0 bis 255).

.. _colorvg_border:

uint8_t g_border
~~~~~~~~~~~~~~~~

Gibt den Grünanteil an, den die Farbe einer Umrandung haben kann (0 bis 255).

.. _colorvb_border:

uint8_t b_border
~~~~~~~~~~~~~~~~

Gibt den Blauanteil an, den die Farbe einer Umrandung haben kann (0 bis 255).

.. _colorvsecondaryColor:

Color* secondaryColor = nullptr
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Die ``secondaryColor`` ist eine zusätzliche (Zweit)Farbe, die im ``Color`` Objekt gespeichert werden kann, wenn der Bedarf ist. Sie ist nützlich, wenn z.B. ein Button in seiner 
aktivierten Form eine andere Farbe haben soll, als in seiner deaktivierten Form. ie aus einer anderen Farbe (bzw. einem anderen ``Color`` Objekt) erstellt werden kann. 

.. _colorvisborderset:

const bool isBorderSet = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Speichert, ob bereits eine Umrandungsfarbe für ein Objekt festgelegt ist.