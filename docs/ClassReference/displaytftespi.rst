.. _displaytftespi:

DisplayTFTeSPI
++++++++++++++++

Beschreibung
=============
DisplayTFTeSPI erben von der Klasse :ref:`Display <display>` und nutzen für ihre Ausgabe die Bibliothek `TFTeSPI <https://github.com/Bodmer/TFT_eSPI/>`_.

Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    uint16_t, ":ref:`color565 <displaytftespicolor565color>` (const Color& color)"
    uint16_t, ":ref:`color565 <displaytftespicolor565rgb>` (uint8_t r, uint8_t g, uint8_t b)"
    , ":ref:`DisplayTFTeSPI <displaytftespiConstructor>` ()" 
    , ":ref:`DisplayTFTeSPI <displaytftespiconstructorcalibration>` (std::array<uint16_t, 5> calData)"
    , ":ref:`DisplayTFTeSPI <displaytftespiCopyConstructor>` (const DisplayTFTeSPI& other)"
    , ":ref:`DisplayTFTeSPI& operator= <displaytftespiCopyAssignmentOperator>` (const DisplayTFTeSPI& other)"
    void, ":ref:`init <displaytftespiInit>` () override"
    void, ":ref:`rect <displaytftespiRectInfill>` (const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color)" 
    void, ":ref:`rect_center <displaytftespirectcenterinfill>` (const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color)" 
    void, ":ref:`rect <displaytftespiRectNoInfill>` (const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color)" 
    void, ":ref:`rect_center <displaytftespirectcenternoinfill>` (const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color)"
    void, ":ref:`circle <displaytftespiCircleInfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color, const Color& infill_color)"
    void, ":ref:`circle <displaytftespicirclenoinfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color)"
    void, ":ref:`text <displaytftespiText>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const char* text, const Color& text_color)"
    void, ":ref:`text_center <displaytftespitextcenter>` (const uint16_t pos_x, const uint16_t pos_y, const uint8_t text_size, const char* text, const Color& text_color)"
    void, ":ref:`line <displaytftespiLine>` (const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color& color)"
    void, ":ref:`point <displaytftespiPoint>` (const uint16_t x1, const uint16_t y1, const Color& color)"
    void, ":ref:`fillScreen <displaytftespifillscreen>` (const Color& color)"
    int16_t, ":ref:`getHeight <displayttftespigetheight>` ()" 
    int16_t, ":ref:`getWidth <displaytftespigetwidth>` ()" 
    uint8_t, ":ref:`getRotation <displaytftespigetrotation>` ()" 
    bool, ":ref:`getTouch <displaytftespigettouch>` ()" 
    TFT_eSPI&, ":ref:`getTFTObjekt <displaytftespigettftobject>` ()"
    void, ":ref:`startTouchCalibration <displaytftespistarttouchcalibration>` ()"
    void, ":ref:`triangle <displaytftespitriangleinfill>` (const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color, const Color& infill_color)" 
    void, ":ref:`triangle <displaytftespitrianglenoinfill>` (const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color)"
    void, ":ref:`drawBitmap <displaytftespidrawbitmapnobgcolor>` (const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor)"
    void, ":ref:`drawBitmap <displaytftespidrawbitmapbgcolor>` (const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor, const Color& bgcolor)"


Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 10000

    TFT_eSPI, ":ref:`tft <displaytftespivtft>` "
    unit8_t, ":ref:`rotation <displaytftespivrotation>` = 0"
    "std::array<uint16_t, 5>", ":ref:`calData <displaytftespivrotation>`"


Funktionen Beschreibung
=========================

.. _displaytftespiColor565Color:

uint16_t colorTo565(const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 155-157
    :linenos:

Diese Funktion wandelt eine ":ref:`Color <color>`" vom 24 Bit RGB888-Format in das 16 Bit RGB565-Format um.




.. _displaytftespiColor565RGB:

uint16_t colorTo565(uint8_t r, uint8_t g, uint8_t b)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 159-161
    :linenos:

Diese Funktion nimmt ":ref:`Red <colorvred>`", ":ref:`Green <colorvgreen>`" und ":ref:`Blue <colorvblue>`" und erzeugt ein ":ref:`Color <color>`" Objekt im 16 Bit RGB565-Format.



.. _displaytftespiConstructor:

DisplayTFTeSPI ()
~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 4-7
    :linenos:

Der Konstruktor initiallisiert das ":ref:`tft <displaytftespivtft>`" Objekt und das ":ref:`calData <displaytftespivcaldata>`" Array.

.. _displaytftespiConstructorCalibration:

DisplayTFTeSPI(std::array<uint16_t, 5> calData)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

KEINE DEFINITION

.. _displaytftespiCopyConstructor:

DisplayTFTeSPI (const DisplayTFTeSPI& other)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

KEINE DEFINITION

.. _displaytftespiCopyAssignmentOperator:

DisplayTFTeSPI& operator= (const DisplayTFTeSPI& other)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 9-12
    :linenos:

TODO

.. _displaytftespiInit:

void init()
~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 14-23
    :linenos:

Setzt das ":ref:`tft <displaytftespivtft>`" Objekt erst zurück und initialisiert es dann. (siehe `void TFT_eSPI::begin(uint8_t tc) <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Zeile 601)
TODO

.. _displaytftespiRectInfill:

virtual void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 30-33
    :linenos:

| Diese Funktion zeichnet ein gefülltes Rechteck. Als Parameter nimmt sie die X- und Y-Koordinate (pos_x und pos_y), bei welchen das Rechteck gezeichnet werden soll und die Breite (width) und Höhe (height) des Rechtecks. Die Dicke der Umrandung (border_size) und um wie viel Grad die Ecken gekrümmt sein sollen (border_radius). Sowie die Farbe der Umrandung (border_color) und die Farbe der Rechteckfläche (infill_color). 
| 
| Für das ":ref:`tft <displaytftespivtft>`" Objekt wird zuerst die `fillRoundRect <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 2639) aufgerufen, die ein Rechteck mit abgerundeten Ecken in den Farben der Umrandung zeichnet. Dieses Rechteck wird anschließend von einem weiteren, kleineren Rechteck in der Farbe der Rechteckfläche überzeichnet, wodurch das gewünschte Rechteck samt Umrandung entsteht.



.. _displaytftespiRectCenterInfill:

virtual void rect_center(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 41-43
    :linenos:

Ruft die ":ref:`rect <displaytftespirectinfill>`" Funktion auf und übergibt anstelle der übergebenen X- und Y-Koordinaten (pos_x und pos_y) den Mittelpunkt des Screens, um das Rechteck zentral auf
dem Bildschirm zu zeichnen. Das zu zeichnende Rechteck hat sowohl eine gefärbte Umrandung als auch einen gefärbten Flächeninhalt.



.. _displaytftespiRectNoInfill:

virtual void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 35-39
    :linenos:


| Diese Funktion zeichnet ein leeres Rechteck. Als Parameter nimmt sie die X- und Y-Koordinate (pos_x und pos_y), bei welchen das Rechteck gezeichnet werden soll und die Breite (width) und Höhe (height) des Rechtecks.  Die Dicke der Umrandung (border_size) und um wie viel Grad die Ecken gekrümmt sein sollen (border_radius), sowie die Farbe der Umrandung (border_color). 
| 
| Innerhalb der for Schleife wird für das ":ref:`tft <displaytftespivtft>`" Objekt die `drawRoundRect <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 2613) aufgerufen, die  die Umrandung eines Rechtecks ohne Flächeninhalt zeichnet. Die for-Schleife lässt diese Umrandung so häufig überzeichnen, bis sie so dick ist, wie gewünscht.

.. _displaytftespiRectCenterNoInfill:

virtual void rect_center(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 45-47
    :linenos:

Ruft die ":ref:`rect <displaytftespirectnoinfill>`" Funktion auf und übergibt anstelle der übergebenen X- und Y-Koordinaten (pos_x und pos_y) den Mittelpunkt des Screens, um das Rechteck zentral auf
dem Bildschirm zu zeichnen. Das zu zeichnende Rechteck hat nur eine gefärbte Umrandung und keinen gefärbten Flächeninhalt.

.. _displaytftespiCircleInfill:

virtual void circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color, const Color& infill_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 49-56
    :linenos:

Diese Funktion zeichnet einen gefüllten Kreis. Als Parameter nimmt sie die X- und Y-Koordinate (pos_x und pos_y), bei welchen der Kreis gezeichnet werden soll und den Durchmesser (d) des Kreises.
Die Dicke der Umrandung (border_size), sowie die Farbe der Umrandung (border_color) und die Farbe der Kreisfläche (infill_color).

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 51-52

Zuerst wird die Variable r erstellt und gleich 0 gesetzt, diese repräsentiert den Radius des Kreises.
Falls der Durchmesser ``d>=2``, wird der Radius auf die Hälfte des Durchmessers gesetzt. Andernfalls wird mit dem Radius r = 0 fortgefahren.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 54

Falls ``border_size >=2`` wird für das ":ref:`tft <displaytftespivtft>`" Objekt die `fillCircle <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 2412) aufgerufen, die ein Kreis in
der Farbe der Umrandung zeichnet. Dieser Kreis wird anschließend von einem weiteren, kleineren Kreis in der Farbe der der Kreisfläche überzeichnet, 
wodurch der gewünschte Kreis samt Umrandung entsteht.
Ist ``border_size <2``, wäre die Umrandung zu dünn, um sie zu darstellen zu können.

.. _displaytftespiCircleNoInfill:

virtual void circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 58-60
    :linenos:

| Diese Funktion zeichnet einen leeren Kreis. Als Parameter nimmt sie die X- und Y-Koordinate (pos_x und pos_y), bei welchen der Kreis gezeichnet werden soll und den Durchmesser (d) des Kreises. Die Dicke der Umrandung (border_size) und sowie die Farbe der Umrandung (border_color).
| 
| Für das ":ref:`tft <displaytftespivtft>`" Objekt wird die `drawCircle <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 2274) aufgerufen, die die Umrisse eines Kreises ohne Flächeninhalte zeichnet. Dabei wird als 3. Argument der Radius in der Form ``d/2`` übergeben.


.. _displaytftespiTriangleInfill:

void triangle(const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color, const Color& infill_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
TODO

| Diese Funktion zeichnet ein gefülltes Dreieck. Als Parameter nimmt sie die jeweils drei X- und Y-Koordinaten für drei verschiedene Punkte des Dreiecks(pos_x0 und pos_y0, pos_x1 und pos_y1, pos_x2 und pos_y2), bei welchen das Dreieckk gezeichnet werden soll. Die Dicke der Umrandung (border_size), sowie die Farbe der Umrandung (border_color) und die Farbe der Dreiecksfläche (infill_color).
| 
| Für das ":ref:`tft <displaytftespivtft>`" Objekt wird die `fillTriangle <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 2680) aufgerufen, die ein 

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 62-65
    :linenos:



.. _displaytftespiTriangleNoInfill:

void triangle(const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

| Diese Funktion zeichnet ein leeres Dreieck. Als Parameter nimmt sie die jeweils drei X- und Y-Koordinaten für drei verschiedene Punkte des Dreiecks(pos_x0 und pos_y0, pos_x1 und pos_y1, pos_x2 und pos_y2), bei welchen das Dreieckk gezeichnet werden soll. Die Dicke der Umrandung (border_size) und sowie die Farbe der Umrandung (border_color).
|
| Dafür werden insgesamt drei Linien gezeichnet. Für das ":ref:`tft <displaytftespivtft>`" Objekt wird die `drawLine <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 3879) aufgerufen und dann erst eine Linie von pos_x0 und pos_y0 zu pos_x1 und pos_y1 gezogen, dann von pos_x1 und pos_y1 zu pos_x2 und pos_y2 und zum Schluss von pos_x2 und pos_y2 zurück zu pos_x0 und pos_y0.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 67-71
    :linenos:

.. _displaytftespiText:

virtual void text(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const char* text, const Color& text_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 74-126
    :linenos:

Diese Funktion zeichnet einen Text mit standardisierter Größe. Diese Funktion ist besonders für Fließtexte geeignet. Als Parameter nimmt sie die X- und Y-Koordinate (pos_x und pos_y), bei welchen der Text gezeichnet werden soll, den Text selbst (text) und die Farbe des Texts (text_color)

Für das ":ref:`tft <displaytftespivtft>`" Objekt wird die `setTextColor <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 2908) aufgerufen, die die Farbe des Textes festlegt.
Anschließend wird mit der `setCursor <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 2855) die Position des Textes auf dem Display festgelegt.
Mit `setTextSize <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ (siehe Zeile 2897) wird die Textgröße festgelegt, indem ein Größenmultiplikator (hier: ``1``) übergeben wird. ``1`` bedeutet, dass jeder Text in einer 
einheitlichen Standardgröße angezeigt wird. Um einen Text mit einer anderen Größe ausgeben zu können, muss die ":ref:`text_center <displaytftespitextcenter>`" Funktion verwendet werden. 
Zum Schluss wird der übergebene Text mit ``println`` ausgegeben.


.. _displaytftespiTextCenter:

virtual void text_center(const uint16_t pos_x, const uint16_t pos_y, const uint8_t text_size, const char* text, const Color& text_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 129-141
    :linenos:

Diese Funktion zeichnet einen zentrierten Text mit einer beliebigen Größe zentriert auf dem Display. Als Parameter nimmt sie die X- und Y-Koordinate (pos_x und pos_y), 
bei welchen der Text gezeichnet werden soll, die Textgröße (text_size), den Text selbst (text) und die Farbe des Texts (text_color).

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 130-131

Wichtig bei einem solchen Text ist, dass der Text weder zu groß noch zu klein ist, weil er sonst nicht auf dem Display richtig dargestellt wird. Deshalb wird die Variable ``size`` aus Kontroll- und 
Sicherheitsgründen eingeführt, um dies zu gewährleisten (``size = 1`` entspricht der Standardgröße eines Textes, siehe ":ref:`text <displaytftespitext>`" Funktion). Es wird überprüft, ob die übergebene ``text_size``
Werte von ``2 bis 10`` annimmst, denn nur diese können (neben dem Standardwert ``1``) sinnvoll dargestellt werden. Ist dies der Fall, wird ``size`` auf ``text_size`` gesetzt. Andernfalls wird mit dem 
Standardwert ``1`` weitergearbeitet.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 134-135

Anschließend wird für das ":ref:`tft <displaytftespivtft>`" Objekt die `setTextSize <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ (siehe Zeile 2897) Funktion aufgerufen, welche die Größe des Textes festlegt.
Mit `setTextDatum <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ (siehe Zeile 2989) wird der Bezugspunkt der Textposition festgelegt, also wo genau auf dem Display der Text angezeigt werden soll.
`MCDatum <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.h>`_ (siehe Zeile 290) steht für "Middle centre", sprich der Text wird im exakten Mittelpunkt des Displays angezeigt.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 137-138

Mit `setTextColor <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ (siehe Zeile 2908) wird der Text die übergebene Farbe annehmen und mit `setTextFont <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_   
(siehe Zeile 5903) wird die Schriftart festgelegt. ``1`` ist hier der Standardwert.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 140

Zum Schluss wird mit `drawString <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ (siehe Zeile 5493) der gewünschte ``text`` bei den gewünschten X- und Y-Koordinaten gezeichnet.

.. _displaytftespiLine:

virtual void line(const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 143-145
    :linenos:

| Diese Funktion zeichnet eine Linie. Als Parameter nimmt sie je X- und Y-Koordinaten für zwei verschiedene Punkte des Dreiecks(pos_x0 und pos_y0, pos_x1 und pos_y1), bei welchen bei welchen die Linie gezeichnet werden soll, sowie die Farbe der Linie (color)
|
| Für das ":ref:`tft <displaytftespivtft>`" Objekt wird die `drawLine <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 3879) aufgerufen und dann eine Linie von pos_x0 und pos_y0 zu pos_x1 und pos_y1 gezogen.


.. _displaytftespiPoint:

virtual void point(const uint16_t x1, const uint16_t y1, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 147-149
    :linenos:

| Diese Funktion zeichnet einen Punkt. Als Parameter nimmt sie eine X- und Y-Koordinaten (pos_x0 und pos_y0), bei welchen bei welchen der Punkt gezeichnet werden soll, sowie die Farbe des Punktes (color)
|
| Für das ":ref:`tft <displaytftespivtft>`" Objekt wird die `drawPixel <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 3577) aufgerufen.


.. _displaytftespiFillScreen:

virtual void fillScreen (const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 151-153
    :linenos:

| Diese Funktion färbt den gesamten Bildschirm in eine übergebene Farbe. 
| Für das ":ref:`tft <displaytftespivtft>`" Objekt wird die `fillScreen <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 2581) aufgerufen.


.. _displayttftespiGetHeight:

int16_t getHeight()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 163-165
    :linenos:

| Diese Funktion gibt die Höhe des Displays zurück. 
| Für das ":ref:`tft <displaytftespivtft>`" Objekt wird die `height <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 3039) aufgerufen.

.. _displaytftespiGetWidth:

int16_t getWidth()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 167-169
    :linenos:

| Diese Funktion gibt die Breite des Displays zurück. 
| Für das ":ref:`tft <displaytftespivtft>`" Objekt wird die `width <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 3028) aufgerufen.

.. _displaytftespiGetRotation:

uint8_t getRotation()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 171-173
    :linenos:

Diese Funktion gibt die ":ref:`rotation <displaytftespivrotation>`" des Displays zurück.

.. _displaytftespiGetTouch:

bool getTouch(uint16_t* x, uint16_t* y)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 175-178
    :linenos:

| Diese Funktion gibt zurück, ob das Display berührt wurde.
| Für das ":ref:`tft <displaytftespivtft>`" Objekt wird die `getTouch <https://github.com/Bodmer/TFT_eSPI/blob/master/Extensions/Touch.cpp>`_ Funktion (siehe Zeile 169) aufgerufen. Falls das Display nicht berührt wird, wird false zurückgegeben.

.. _displaytftespiGetTFTObject:

TFT_eSPI& getTFTObjekt();
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 180-182
    :linenos:


Diese Funktion gibt das ":ref:`tft <displaytftespivtft>`" Objekt zurück.

.. _displaytftespiStartTouchCalibration:

void startTouchCalibration();
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 184-193
    :linenos:


TODO
.. _displaytftespiDrawBitmapNobgcolor:

void drawBitmap(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 195-202
    :linenos:

| Diese Funktion zeichnet ein Bild. Als Parameter nimmt sie die X- und Y-Koordinate (x und y), bei welchen das Dreieckk gezeichnet werden soll. Die Breite (w) und Höhe (h) des Bildes, das Bild selbst (bitmap) und eine Vordergrundfarbe (fgcolor).
| 
| Für das ":ref:`tft <displaytftespivtft>`" Objekt wird die `drawBitmap <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 2760) aufgerufen.

.. _displaytftespiDrawBitmapbgcolor:

void drawBitmap(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor, const Color& bgcolor)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 204-206
    :linenos:

| Diese Funktion zeichnet ein Bild. Als Parameter nimmt sie die X- und Y-Koordinate (x und y), bei welchen das Dreieckk gezeichnet werden soll. Die Breite (w) und Höhe (h) des Bildes, das Bild selbst (bitmap), eine Vordergrundfarbe (fgcolor) und eine Hintergrundfarbe (bgcolor).
| 
| Für das ":ref:`tft <displaytftespivtft>`" Objekt wird die `drawBitmap <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 2784) aufgerufen.





Variablen und Konstanten Beschreibung
=====================================

.. _displaytftespiVtft:

TFT_eSPI tft
~~~~~~~~~~~~~~

Ein Objekt der Klasse `TFT_eSPI <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.h>`_. `TFT_eSPI <https://github.com/Bodmer/TFT_eSPI>`_ ist eine 
Library mit vielen verschiedenen Grafiken speziell für Arduino IDE und wird in diesem Projekt als Grundlage für die meisten geometrischen Formen der verschiedenen 
":ref:`Elemente <element>`" genutzt.

.. _displaytftespiVRotation:

uint8_t rotation = 0
~~~~~~~~~~~~~~~~~~~~~

TODO

.. _displaytftespiVCalData:

std::array<uint16_t, 5> calData
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TODO
