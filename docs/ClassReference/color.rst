.. _color:

Color
++++++++

Beschreibung
=============
Color verwaltet alles, was in irgendeiner Form mit Farben zu tun hat.

TODO auf jeden fall erklären, was border etc sind

Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

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
    :lines: 45-54
    :linenos:

Dieser Konstruktor wird genutzt, um die RGB Werte der Parameter, also der Hauptfarbe ``prim``, der Farbe des Objektes 
``item`` und der Umrandunsfarbe ``border`` zu extrahieren, und mit ihnen die entsprechenden Variablen zu initialisieren.

TODO isBorderSet???

.. _colorConstructor2:

inline Color(const uint8_t r, const uint8_t g, const uint8_t b, const bool)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 57-63
    :linenos:

Dieser Konstruktor wird genutzt, um mit den RGB übergebenen Werten nur die Variablen `r_prim <colorvr_prim>`, `g_prim <colorvg_prim>` und `b_prim <colorvb_prim>` zu initialisieren. 
Daher eignet sich der Konstruktor besonders, um ein ``Color``-Objekt ohne Item oder Border zu erstellen.

.. _colorConstructor3:

inline Color(const bool, const Color& other)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 66-72
    :linenos:

Dieser Konstruktor wird genutzt, um mit der übergebenen Farbe ``other`` nur die Variablen `r_prim <colorvr_prim>`, `g_prim <colorvg_prim>` und `b_prim <colorvb_prim>` zu initialisieren. 
Daher eignet sich der Konstruktor besonders, um von einer Farbe, die vorher auch Farbinformationen zu einem Icon oder Border gehabt hat, nur die Hauptfarbe zu extrahieren.

.. _colorsetColorOffset:

inline const Color setColorOffset(const Color& color, const int offset) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 74-82
    :linenos:

Mit dieser Funktion kann aus einer Farbe eine neue Farbe erstellt werden, deren RGB Werte um einen bestimmten ``offset`` verschoben ist gegenüber der Ausgangsfarbe.
Sollte kein ``offset`` angegeben werden, wird dieser `Color <colorconstructor3>` Konstruktor aufgerufen. Die neue Farbe ist äquivalent zur alten.
Andernfalls werden mithilfe des ``offset`` neue RGB Werte berechnet. Dafür wird der maximale Wert aus ``0`` und ``std::min((int) r_prim + offset, UINT8_MAX)`` bestimmt. Bei 
``std::min((int) r_prim + offset, UINT8_MAX)`` wird das Minimum aus ``((int) r_prim + offset`` und ``UINT8_MAX`` gewählt. Da wird `r_prim <colorvr_prim>` von einem ``uint8_t`` zu einem normalen ``int`` 
casten und das Ergebnis der Addition deshalb ``>255`` sein kann, ist dieses Minumum äußerst wichtig. ``UINT8_MAX`` hat einen Wert von ``255`` und wird deshalb als eine Art Sicherheitsgarantie gebraucht.
Anschließend wird dieser `Color <colorconstructor2>` Konstruktor aufgerufen, wodurch aus den neuen RGB Werten ein ``Color`` Objekt entsteht.

.. _colorCreateItemcolor:

inline const Color createItemColor(const Color& color) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 84-87
    :linenos:

Mit dieser Funktion wird automatisch eine Farbe für ein Item bestimmt. Dieses kann hier entweder weiß oder schwarz werden, je nachdem, welche Farbe sichtbarer ist.
Sollte die Summe aus `r_prim <colorvr_prim>`, `g_prim <colorvg_prim>` und `b_prim <colorvb_prim>` kleiner sein als der Referenzwert, so wird der `Color <colorconstructor2>` Konstruktor aufgerufen, um eine Farbe in Weiß zu erstellen.
Andernfalls wird derselbe Konstruktor aufgerufen, um eine Farbe in Schwarz zu erstellen. 

.. _colorCreateBorderColor:

inline const Color createBorderColor(const Color& color) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Color.h
    :lines: 89-92
    :linenos:

Mit dieser Funktion wird automatisch eine Farbe für die Umrandung bestimmt. Diese kann hier entweder weiß oder schwarz werden, je nachdem, welche Farbe sichtbarer ist.
Sollte die Summe aus `r_prim <colorvr_prim>`, `g_prim <colorvg_prim>` und `b_prim <colorvb_prim>` kleiner sein als der Referenzwert, so wird der `Color <colorconstructor2>` Konstruktor aufgerufen, um eine Farbe in Weiß zu erstellen.
Andernfalls wird derselbe Konstruktor aufgerufen, um eine Farbe in Schwarz zu erstellen. 
TODO

.. _colorConstructor4:

inline Color(const Color& other)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 95
    :linenos:

Mithilfe dieser Copy Konstruktors kann ein Objekt der ``Color`` Klasse kopiert werden.

.. _colorConstructor5:

inline Color(const Color& prim, const int offset)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 96
    :linenos:

Mithilfe dieses Konstruktors kann aus einer Farbe eine neue Farbe mit einem ``offset`` erstellt werden. Dafür erfolgt bei der Initialisierung ein Funktionsaufruf von `colorsetColorOffset <colorsetColorOffset>` mit den gegebenen Parametern.

.. _colorConstructor6:

inline Color(const Color& prim, const Color& item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 97
    :linenos:

Mithilfe dieses Konstruktors kann eine Farbe mit einer selbst festgelegten Item Farbe erstellt werden. Die Borderfarbe wird mit `colorcreatebordercolor <colorcreatebordercolor>` generiert.

.. _colorConstructor7:

inline Color(const Color& prim, const bool, const Color& border)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 98
    :linenos:

Mithilfe dieses Konstruktors kann eine Farbe mit einer selbst festgelegten Umrandungs Farbe erstellt werden. Die Item Farbe wird mit `colorcreateitemcolor <colorcreateitemcolor>` generiert.

.. _colorConstructor8:

inline Color(const Color& prim, const Color& item, const Color& border)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 99
    :linenos:

Mithilfe dieses Konstruktors kann eine Farbe mit einer selbst festgelegten Item Farbe und einer selbst festgelegten Umrandungs Farbe erstellt werden.

.. _colorConstructor9:

inline Color(const Color& prim, const bool, const bool, const Color& secondary)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 100
    :linenos:

Mithilfe dieses Konstruktors kann eine Farbe zusammen mit einer zusätzlichen Zweitfarbe (siehe `secondaryColor <_colorvsecondaryColor>`) erstellt werden. Die Item Farbe und Umrandungs Farbe werden 
mit `colorcreateitemcolor <colorcreateitemcolor>` bzw. `colorcreatebordercolor <colorcreatebordercolor>` generiert.

.. _colorConstructor10:

inline Color(const Color& prim, const bool, Color& border, const Color& secondary)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 101
    :linenos:

Mithilfe dieses Konstruktors kann eine Farbe mit einer selbst festgelegten Umrandungsfarbe zusammen mit einer zusätzlichen Zweitfarbe (siehe `secondaryColor <_colorvsecondaryColor>`) erstellt werden.
Die Item Farbe wird mit `colorcreateitemcolor <colorcreateitemcolor>` generiert.

.. _colorConstructor11:

inline Color(const Color& prim, const Color& item, const bool, const Color& secondary)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 102
    :linenos:

Mithilfe dieses Konstruktors kann eine Farbe mit einer selbst festgelegten Item Farbe zusammen mit einer zusätzlichen Zweitfarbe (siehe `secondaryColor <_colorvsecondaryColor>`) erstellt werden.
Die Umrandungs Farbe wird mit `colorcreatebordercolor <colorcreatebordercolor>` generiert.

.. _colorConstructor12:

inline Color(const Color& prim, const Color& item, const Color& border, const Color& secondary)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 103
    :linenos:

.. _colorConstructor13:

Mithilfe dieses Konstruktors kann eine Farbe mit einer selbst festgelegten Item Farbe und einer selbst festgelegten Umrandungs Farbe zusammen 
mit einer zusätzlichen Zweitfarbe (siehe `secondaryColor<_colorvsecondaryColor>`) erstellt werden.

inline Color(const uint8_t r, const uint8_t g, const uint8_t b): Color(Color(r,g,b, true), 0)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 105
    :linenos:

Mithilfe dieses Konstruktors kann man mit Angabe von RGB Werten diesen `Color<_colorconstructor5>` Konstruktor aufrufen.

.. _colorDestructor:

inline ~Color()
~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 110
    :linenos:

Der Destructor wird bei der Zerstörung eines ``Color`` Objektes aufgerufen und gibt den von `secondaryColor<_colorvsecondaryColor>` belegten Speicherplatz wieder frei.

.. _colorOperatorExcl:

inline Color operator!() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 115
    :linenos:

Diese Funktion invertiert die RGB Werte einer Farbe und erzeugt ruft diesen `Color<_colorconstructor13>` Konstruktor auf, um diese neue Farbe zu erstellen.

.. _colorOperatorPlus:

inline Color operator+(const Color& secondary) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 116
    :linenos:

Diese Funktion addiert eine Farbe mit einer zweiten, übergebenen Farbe. Sie gibt ein neues ``Color`` Objekt mit diesen addierten Farbwerten nach dem Konstruktoraufruf von `Color<_colorconstructor12>` zurück.

.. _colorOperatorLine:

inline Color operator|(const Color& other)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 117
    :linenos:

TODO

.. _colorOperatorEquals:

inline Color& operator=(const Color& other)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _colorGetPrimColor:

inline Color getPrimColor()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 126
    :linenos:

Diese Getter-Funktion gibt die Hauptfarbe eines ``Color`` Objektes aus.

.. _colorGetItemColor:

inline Color getItemColor()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 127
    :linenos:

Diese Getter-Funktion gibt die Item Farbe eines ``Color`` Objektes aus.

.. _colorGetBorderColor:


inline Color getBorderColor()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 128
    :linenos:

Diese Getter-Funktion gibt die Umrandungs Farbe eines ``Color`` Objektes aus.

.. _colorGetSecondaryItemColor:

inline Color getSecondaryItemColor()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 129
    :linenos:

Diese Getter-Funktion gibt die Item Farbe der Zweitfarbe eines ``Color`` Objektes aus.

.. _colorGetSecondaryBorderColor:

inline Color getSecondaryBorderColor()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 130
    :linenos:

Diese Getter-Funktion gibt die Umrandungs Farbe der Zweitfarbe eines ``Color`` Objektes aus.

.. _colorGetSecondaryColor:

inline Color getSecondaryColor()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 131-134
    :linenos:

Diese Getter-Funktion gibt die Zweitfarbe eines ``Color`` Objektes aus. Wenn ein Objekt keine Zweifarbe besitzt, wird stattdessen das ``Color`` Objekt zurückgegeben.
.. _colorGetRed:

inline uint8_t getRed()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 136
    :linenos:

Gibt den Rotanteil einer Farbe (":ref:`r_prim<colorvr_prim>`") zurück.

.. _colorGetGreen:

inline uint8_t getGreen()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 137
    :linenos:

Gibt den Grünanteil einer Farbe (":ref:`g_prim<colorvg_prim>`") zurück.

.. _colorGetBlue:

inline uint8_t getBlue()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 138
    :linenos:

Gibt den Blauanteil einer Farbe (":ref:`b_prim<colorvb_prim>`") zurück.


.. _colorhassecondarycolor:

inline bool hasSecondaryColor() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 140
    :linenos:

Diese Funktion gibt ``true`` zurück, wenn ein ``Color`` Objekt eine Zweitfarbe (":ref:`secondaryColor<colorvsecondarycolor>`") besitzt, und ``false`` falls es keine besitzt.

.. _colorColorSetPrimaryColor:

inline Color setPrimaryColor(const Color& color) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 145
    :linenos:

Mit dieser Funktion lässt sich die Hauptfarbe eines ``Color`` Objektes setzen. Die Funktion gibt ein neues Objekt zurück.


.. _colorColorSetItemColor:

inline Color setItemColor(const Color& color) const 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 146
    :linenos:

Mit dieser Funktion lässt sich die Item Farbe eines ``Color`` Objektes setzen. Die Funktion gibt ein neues Objekt zurück.


.. _colorColorSetBorderColor:

inline Color setBorderColor(const Color& color) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 147
    :linenos:

Mit dieser Funktion lässt sich die Umrandungs Farbe eines ``Color`` Objektes setzen. Die Funktion gibt ein neues Objekt zurück.


.. _colorColorSetSecondaryColor:

inline Color setSecondaryColor(const Color& color) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 148
    :linenos:
 
Mit dieser Funktion lässt sich die Zweitfarbe eines ``Color`` Objektes setzen. Die Funktion gibt ein neues Objekt zurück.


.. _colorColorSetSecondaryItemColor:

inline Color setSecondaryItemColor(const Color& color) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 149
    :linenos:

Mit dieser Funktion lässt sich die Item Farbe der Zweitfarbe eines ``Color`` Objektes setzen. Die Funktion gibt ein neues Objekt zurück.


.. _colorColorSetSecondaryBorderColor:

inline Color setSecondaryBorderColor(const Color& color) const 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 150
    :linenos:

Mit dieser Funktion lässt sich die Umrandungs Farbe der Zweitfarbe eines ``Color`` Objektes setzen. Die Funktion gibt ein neues Objekt zurück.

.. _colorVoidSetPrimaryColor:

inline void setPrimaryColor(const Color& color)    
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 152
    :linenos:

Mit dieser Funktion lässt sich die Hauptfarbe des aktuellen ``Color`` Objektes verändern.

.. _colorVoidSetItemColor:

inline void setItemColor(const Color& color)  
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 153
    :linenos:

Mit dieser Funktion lässt sich die Item Farbe des aktuellen ``Color`` Objektes verändern.

.. _colorVoidSetBorderColor:

inline void setBorderColor(const Color& color)     
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 154
    :linenos:

Mit dieser Funktion lässt sich die Umrandungs Farbe des aktuellen ``Color`` Objektes verändern.

.. _colorVoidSetSecondayColor:

inline void setSecondaryColor(const Color& color)  
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 155
    :linenos:

Mit dieser Funktion lässt sich die Zweitfarbe des aktuellen ``Color`` Objektes verändern.

.. _colorVoidSetSecondaryItemColor:

inline void setSecondaryItemColor(const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 156
    :linenos:

Mit dieser Funktion lässt sich die Item Farbe der Zweitfarbe des aktuellen ``Color`` Objektes verändern.

.. _colorVoidSetSecondaryBorderColor:

inline void setSecondaryBorderColor(const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 157
    :linenos:

Mit dieser Funktion lässt sich die Umrandungs Farbe der Zweitfarbe des aktuellen ``Color`` Objektes verändern.

.. _colorToString:

inline String toString() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Color.h
    :lines: 160
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

TODO