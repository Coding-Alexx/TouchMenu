.. _displaytftespi:

DisplayTFTeSPI
+++++++++++++++++

Beschreibung
=============
Die Klasse ``DisplayTFTeSPI`` erbt von der Klasse :ref:`Display <display>` und nutzt für ihre Ausgabe die Bibliothek `TFTeSPI <https://github.com/Bodmer/TFT_eSPI/>`_.


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
    void, ":ref:`rect <displaytftespiRectInfill>` (const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color) override" 
    void, ":ref:`rect_center <displaytftespirectcenterinfill>` (const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color) override" 
    void, ":ref:`rect <displaytftespiRectNoInfill>` (const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color) override" 
    void, ":ref:`rect_center <displaytftespirectcenternoinfill>` (const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color) override"
    void, ":ref:`circle <displaytftespiCircleInfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color, const Color& infill_color) override"
    void, ":ref:`circle <displaytftespicirclenoinfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color) override"
    void, ":ref:`triangle <displaytftespitriangleinfill>` (const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color, const Color& infill_color) override" 
    void, ":ref:`triangle <displaytftespitrianglenoinfill>` (const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color) override"
    bool, ":ref:`containsInvalidCharacters <displaytftespicontainsinvalidcharacters>` (const char* input)"
    void, ":ref:`text <displaytftespiText>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const char* text, const Color& text_color) override"
    void, ":ref:`text_center <displaytftespitextcenter>` (const uint16_t pos_x, const uint16_t pos_y, const uint8_t size, const char* text, const Color& text_color) override"
    void, ":ref:`line <displaytftespiLine>` (const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color& color) override"
    void, ":ref:`point <displaytftespiPoint>` (const uint16_t x1, const uint16_t y1, const Color& color) override"
    void, ":ref:`fillScreen <displaytftespifillscreen>` (const Color& color) override"
    void, ":ref:`drawBitmap <displaytftespidrawbitmapnobgcolor>` (const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor) override"
    void, ":ref:`drawBitmap <displaytftespidrawbitmapbgcolor>` (const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor, const Color& bgcolor) override"
    int16_t, ":ref:`getHeight <displayttftespigetheight>` () override" 
    int16_t, ":ref:`getWidth <displaytftespigetwidth>` () override" 
    uint8_t, ":ref:`getRotation <displaytftespigetrotation>` () override" 
    uint8_t, ":ref:`setRotation <displaytftespisetrotation>` () override" 
    bool, ":ref:`getTouch <displaytftespigettouch>` (uint16_t* x, uint16_t* y) override" 
    TFT_eSPI&, ":ref:`getTFTObjekt <displaytftespigettftobject>` ()"
    void, ":ref:`startTouchCalibration <displaytftespistarttouchcalibration>` () override"
    

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

Diese Funktion ruft den :ref:`colorTo565<displaytftespicolor565rgb>` Konstruktor mit den RGB-Werten (durch :ref:`getRed<colorgetred>`, :ref:`getGreen<colorgetgreen>` 
und :ref:`getBlue<colorgetBlue>`) des :ref:`Color<color>` Objekts auf, um es vom 24 Bit RGB888-Format in das 16 Bit RGB565-Format umzuwandeln.


.. _displaytftespiColor565RGB:

uint16_t colorTo565(uint8_t r, uint8_t g, uint8_t b)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 159-161
    :linenos:

Diese Funktion ruft die `color565 <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L4771>`_ Funktion des ``tft`` Objekts auf, um eine Farbe im RGB565-Format zu erzeugen.


.. _displaytftespiConstructor:

DisplayTFTeSPI ()
~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 5-8
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
    :lines: 9-13
    :linenos:

Gibt die aktuelle Instanz zurück.

.. _displaytftespiInit:

void init()
~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 14-23
    :linenos:

Setzt das ":ref:`tft <displaytftespivtft>`" Objekt erst zurück und initialisiert es dann. (siehe `begin(uint8_t tc) <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L601>`_)
Danach wird mit `setRotation <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L807>`_ die Bildschirmausrichtung angepasst.

.. _displaytftespiRectInfill:

virtual void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 31-34
    :linenos:

| Diese Funktion zeichnet ein gefülltes Rechteck. Als Parameter nimmt sie die X- und Y-Koordinate (``pos_x`` und ``pos_y``), bei welchen das Rechteck gezeichnet werden soll und die Breite (``width``) und Höhe (``height``) des Rechtecks. Die Dicke der Umrandung (``border_size``) und um wie viel Grad die Ecken gekrümmt sein sollen (``border_radius``), sowie die Farbe der Umrandung (``border_color``) und die Farbe der Rechteckfläche (``infill_color``). 
| 
| Für das :ref:`tft <displaytftespivtft>` Objekt wird zuerst die `fillRoundRect <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L2639>`_ Funktion aufgerufen, die ein Rechteck mit abgerundeten Ecken in den Farben der Umrandung zeichnet. Dieses Rechteck wird anschließend von einem weiteren, kleineren Rechteck in der Farbe der Rechteckfläche überzeichnet, wodurch das gewünschte Rechteck samt Umrandung entsteht.



.. _displaytftespiRectCenterInfill:

virtual void rect_center(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 42-44
    :linenos:

Ruft die :ref:`rect <displaytftespirectinfill>` Funktion auf und übergibt anstelle der übergebenen X- und Y-Koordinaten (``pos_x und pos_y``) den Mittelpunkt des Screens, um das Rechteck zentral auf
dem Bildschirm zu zeichnen. Das zu zeichnende Rechteck hat sowohl eine gefärbte Umrandung als auch einen gefärbten Flächeninhalt.



.. _displaytftespiRectNoInfill:

virtual void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 36-40
    :linenos:


| Diese Funktion zeichnet ein leeres Rechteck. Als Parameter nimmt sie die X- und Y-Koordinate (``pos_x`` und ``pos_y``), bei welchen das Rechteck gezeichnet werden soll und die Breite (``width``) und Höhe (``height``) des Rechtecks.  Die Dicke der Umrandung (``border_size``) und um wie viel Grad die Ecken gekrümmt sein sollen (``border_radius``), sowie die Farbe der Umrandung (``border_color``). 
| 
| Innerhalb der for Schleife wird für das :ref:`tft <displaytftespivtft>` Objekt die `drawRoundRect <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L2613>`_ Funktion aufgerufen, die die Umrandung eines Rechtecks ohne Flächeninhalt zeichnet. Die ``for``-Schleife lässt diese Umrandung so häufig überzeichnen, bis sie so dick ist, wie gewünscht.

.. _displaytftespiRectCenterNoInfill:

virtual void rect_center(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 46-48
    :linenos:

Ruft die :ref:`rect <displaytftespirectnoinfill>` Funktion auf und übergibt anstelle der übergebenen X- und Y-Koordinaten (``pos_x`` und ``pos_y``) den Mittelpunkt des Screens, um das Rechteck zentral auf
dem Bildschirm zu zeichnen. Das zu zeichnende Rechteck hat nur eine gefärbte Umrandung und keinen gefärbten Flächeninhalt.

.. _displaytftespiCircleInfill:

virtual void circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color, const Color& infill_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 50-57
    :linenos:

Diese Funktion zeichnet einen gefüllten Kreis. Als Parameter nimmt sie die X- und Y-Koordinate (``pos_x`` und ``pos_y``), bei welchen der Kreis gezeichnet werden soll 
und den Durchmesser (``d``) des Kreises, die Dicke der Umrandung (``border_size``), sowie die Farbe der Umrandung (``border_color``) und die Farbe der Kreisfläche (``infill_color``).

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 52-53

Zuerst wird die Variable ``r`` erstellt und gleich ``0`` gesetzt, diese repräsentiert den Radius des Kreises.
Falls der Durchmesser ``d>=2``, wird der Radius auf die Hälfte des Durchmessers gesetzt. Andernfalls wird mit dem Radius ``r = 0`` fortgefahren.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 55-56

Falls ``border_size >=2`` wird für das ":ref:`tft <displaytftespivtft>`" Objekt die `fillCircle <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L2412>`_ Funktion aufgerufen, die einen Kreis in
der Farbe der Umrandung zeichnet. Dieser Kreis wird anschließend von einem weiteren, kleineren Kreis in der Farbe der der Kreisfläche überzeichnet, 
wodurch der gewünschte Kreis samt Umrandung entsteht.
Ist ``border_size <2``, wäre die Umrandung zu dünn, um sie zu darstellen zu können.

.. _displaytftespiCircleNoInfill:

virtual void circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 59-61
    :linenos:

| Diese Funktion zeichnet einen leeren Kreis. Als Parameter nimmt sie die X- und Y-Koordinate (``pos_x`` und ``pos_y``), bei welchen der Kreis gezeichnet werden soll und den Durchmesser (``d``) des Kreises. Die Dicke der Umrandung (``border_size``) und sowie die Farbe der Umrandung (``border_color``).
| 
| Für das ":ref:`tft <displaytftespivtft>`" Objekt wird die `drawCircle <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L2274>`_ Funktion aufgerufen, die die Umrisse eines Kreises ohne Flächeninhalte zeichnet. Dabei wird als 3. Argument der Radius in der Form ``d/2`` übergeben.


.. _displaytftespiTriangleInfill:

void triangle(const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color, const Color& infill_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 63-66
    :linenos:

| Diese Funktion zeichnet ein gefülltes Dreieck. Als Parameter nimmt sie die jeweils drei X- und Y-Koordinaten für drei verschiedene Punkte des Dreiecks(``pos_x0`` und ``pos_y0``, ``pos_x1`` und ``pos_y1``, ``pos_x2`` und ``pos_y2``), bei welchen das Dreieck gezeichnet werden soll, die Dicke der Umrandung (``border_size``), sowie die Farbe der Umrandung (``border_color``) und die Farbe der Dreiecksfläche (``infill_color``).
| 
| Für das :ref:`tft <displaytftespivtft>` Objekt wird die `fillTriangle <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L2680>`_ Funktion aufgerufen, die das gewünschte Dreieck zeichnet.




.. _displaytftespiTriangleNoInfill:

void triangle(const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 68-72
    :linenos:

| Diese Funktion zeichnet ein leeres Dreieck. Als Parameter nimmt sie die jeweils drei X- und Y-Koordinaten für drei verschiedene Punkte des Dreiecks(``pos_x0`` und ``pos_y0``, ``pos_x1`` und ``pos_y1``, ``pos_x2`` und ``pos_y2``), bei welchen das Dreieck gezeichnet werden soll, die Dicke der Umrandung (``border_size``), sowie die Farbe der Umrandung (``border_color``).
|
| Dafür werden insgesamt drei Linien gezeichnet. Für das :ref:`tft <displaytftespivtft>` Objekt wird die `drawLine <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L3879>`_ Funktion aufgerufen und dann erst eine Linie von ``pos_x0`` und ``pos_y0`` zu ``pos_x1`` und ``pos_y1`` gezogen, dann von ``pos_x1`` und ``pos_y1`` zu ``pos_x2`` und ``pos_y2`` und zum Schluss von ``pos_x2`` und ``pos_y2`` zurück zu ``pos_x0`` und ``pos_y0``.


.. _displaytftespicontainsinvalidcharacters:

bool containsInvalidCharacters(const char* input)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 74-84
    :linenos:

Mit dieser Funktion wird überprüft, ob in der Eingabe ungültige Zeichen/ Symbole enthalten sind. Zu diesen gehören ``.``, ``-`` und ``:``. Dafür wird Zeichen für Zeichen überprüft, ob das aktuelle Zeichen keines
dieser Symbole ist.

.. _displaytftespiText:

virtual void text(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const char* text, const Color& text_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 87-131
    :linenos:

Diese Funktion zeichnet einen Text, der automatisch formatiert wird. Als Parameter nimmt sie die X- und Y-Koordinate (``pos_x`` und ``pos_y``), bei welchen der Text gezeichnet werden soll, die Breite (``width``) und Höhe (``height``) der Fläche, auf welchen der Text gezeichnet werden soll, den Text selbst (``text``) und die Farbe des Texts (``text_color``)

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 88

Für das :ref:`tft <displaytftespivtft>` Objekt wird die `setTextColor <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L2908>`_ Funktion aufgerufen, 
die die Farbe des Textes festlegt, indem ``text_color`` mit Hilfe von :ref:`colorTo565<displaytftespicolor565color>` in das richtige farb-Format umgewandelt wird.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 90-93

Nun werden drei Arrays festgelegt, in denen ``num``-verschiedene Kombinationen von Multipliyern (``size``), Schriftarten (``fonts``) und die tatsächliche Schriftgröße, die sich aus den Schriftarten und Multiplyern ergeben
(``fonzSize``). Das ``fontSize`` Array wird später relevant, um festzustellen, wie groß der angezeigte text auf der festgelegten Fläche maximal sein kann. Die anderen beiden werden genutzt, um diesen Text dann zu generieren.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 95-96

Wir zeichnen mit `drawRect <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L2992>`_ ein weißes Rechteck an der richtigen Position, welches als Textbox für den Text dient.
Mit `setDatum <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L2989>`_  wird der Bezugspunkt der Textposition festgelegt, also wo genau auf dem Display der Text angezeigt werden soll.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 98-104

Sollte die Höhe der Textbox kleiner sein als ``16`` (welches die minimalste ``fonzSize`` ist), wird ein Text in der kleinstmöglichen Art und Weise mittels 
`setTextFont(1) <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L5898>`_ und `setTextSize(1) <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L2897>`_ erstellt
und mit `drawString <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L5488>`_ an der gewünschten Stelle gezeichnet. 

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 106

Andernfalls wird zuerst mit :ref:`containsInvalidCharacters<displaytftespicontainsinvalidcharacters>` getestet, ob der Text ungültige Zeichen enthält (``.``, ``-`` oder ``:``). Das Ergebnis wird negiert und in 
in ``isDigit`` gespeichert. ``isDigit`` wird in einem späteren Codeabschnitt relevant.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 107

Es folgt eine ``for`` Schleife, welche so lange läuft, bis entweder mehr Durchläufe als  ``num`` groß ist geschehen oder bis der größtmöglich zeichenbare Text ermittelt wurde.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 109-122

Sollte die ``fontSize`` beim aktuellen ``i`` größer sein als die Höhe der Textbox oder sollte der Text breiter sein als die breite des Textbox, so wird der Text in der
nächstgrößten möglichen Art und Weise erstellt (mit `setTextFont <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L5898>`_ und `setTextSize <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L2897>`_) 
und mit `drawString <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L5488>`_ an der gewünschten Stelle gezeichnet. 

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 123-130

Wenn die Funktion jetzt noch weiterlaufen sollte, wird (ebenfalls wie oben) der Text in der kleinstmöglichen Art und Weise gezeichnet.



.. _displaytftespiTextCenter:

virtual void text_center(const uint16_t pos_x, const uint16_t pos_y, const uint8_t size, const char* text, const Color& text_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 133-141
    :linenos:

Diese Funktion zeichnet einen zentrierten Text mit einer beliebigen Größe zentriert auf dem Display. Als Parameter nimmt sie die X- und Y-Koordinate (``pos_x`` und ``pos_y``), 
bei welchen der Text gezeichnet werden soll, die Textgröße (``size``), den Text selbst (``text``) und die Farbe des Texts (``text_color``).


.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 134-135

Anschließend wird für das :ref:`tft <displaytftespivtft>` Objekt die `setTextSize <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L2897>`_ Funktion aufgerufen, welche die Größe des Textes festlegt.
Mit `setTextDatum <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L2989>`_  wird der Bezugspunkt der Textposition festgelegt, also wo genau auf dem Display der Text angezeigt werden soll.
`MCDatum <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.h#L290>`_  steht für "Middle centre", sprich der Text wird im exakten Mittelpunkt des Displays angezeigt.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 137-138

Mit `setTextColor <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#2908>`_ wird der Text die übergebene Farbe annehmen und mit `setTextFont <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L5903>`_   
wird die Schriftart festgelegt. ``1`` ist hier der Standardwert.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 140

Zum Schluss wird mit `drawString <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#5493>`_ der gewünschte ``text`` bei den gewünschten X- und Y-Koordinaten gezeichnet.


.. _displaytftespiLine:

virtual void line(const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 143-145
    :linenos:

| Diese Funktion zeichnet eine Linie. Als Parameter nimmt sie je X- und Y-Koordinaten für zwei verschiedene Punkte des Dreiecks(``pos_x0`` und ``pos_y0``, ``pos_x1`` und ``pos_y1``), bei welchen die Linie gezeichnet werden soll, sowie die Farbe der Linie (``color``).
|
| Für das :ref:`tft <displaytftespivtft>` Objekt wird die `drawLine <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L3879>`_ Funktion aufgerufen und dann eine Linie von ``pos_x0`` und ``pos_y0`` zu ``pos_x1`` und ``pos_y1`` gezogen.


.. _displaytftespiPoint:

virtual void point(const uint16_t x1, const uint16_t y1, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 147-149
    :linenos:

| Diese Funktion zeichnet einen Punkt. Als Parameter nimmt sie eine X- und Y-Koordinaten (``pos_x0`` und ``pos_y0``), bei welchen der Punkt gezeichnet werden soll, sowie die Farbe des Punktes (``color``).
|
| Für das :ref:`tft <displaytftespivtft>` Objekt wird die `drawPixel <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L3577>`_ Funktion aufgerufen.


.. _displaytftespiFillScreen:

virtual void fillScreen (const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 151-153
    :linenos:

| Diese Funktion färbt den gesamten Bildschirm in eine übergebene Farbe. 
| Für das :ref:`tft <displaytftespivtft>` Objekt wird die `fillScreen <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L2581>`_ Funktion aufgerufen.


.. _displayttftespiGetHeight:

int16_t getHeight()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 163-165
    :linenos:

| Diese Funktion gibt die Höhe des Displays zurück. 
| Für das :ref:`tft<displaytftespivtft>` Objekt wird die `height <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#3039>`_ Funktion aufgerufen.

.. _displaytftespiGetWidth:

int16_t getWidth()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 167-169
    :linenos:

| Diese Funktion gibt die Breite des Displays zurück. 
| Für das :ref:`tft<displaytftespivtft>` Objekt wird die `width <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L3028>`_ Funktion aufgerufen.

.. _displaytftespiGetRotation:

uint8_t getRotation()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 171-173
    :linenos:

Diese Funktion gibt die :ref:`rotation<displaytftespivrotation>` des Displays zurück.

.. _displaytftespisetRotation:

uint8_t setRotation()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 175-177
    :linenos:

Diese Funktion übergibt :ref:`rotation <displaytftespivrotation>` an `setRotation <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp#L807>`_, um das Display wie gewünscht zu drehen. 

.. _displaytftespiGetTouch:

bool getTouch(uint16_t* x, uint16_t* y)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 179-190
    :linenos:

Diese Funktion berechnet die Koordinaten, auf welchem das Display berührt, je nachdem, wie der Bildschirm durch :ref:`rotation <displaytftespivrotation>` ausgerichtet ist.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 180

Wenn ``x`` oder ``y`` der Null Pointer sind, existiert kein Berührungspunkt auf dem Bildschirm.    

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 181

In der Variable ``isTouched`` wird gespeichert, ob der Bildschirm berührt wird oder nicht.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 182

Sollte der Bildschirm nicht berührt werden, ist es auch nicht notwendig, Koordinaten zu bestimmen.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 185-189

Andernfalls werden für jede der vier möglichen Bildschirmausrichtungen die Koordinaten bestimmt. Zuerst für eine :ref:`rotation<displaytftespivrotation>` von ``0``, also der Standardausrichtung.
Dafür werden temporäre Variablen angelegt, die das Ergebnis der `map <https://github.com/espressif/arduino-esp32/blob/master/cores/esp32/WMath.cpp#L75>`_ Funktion speichert. Diese Funktion mapped für
``tmpX`` die mit :ref:`getHeight<displayttftespigetheight>` ermittelte Höhe auf die mit :ref:`getWidth<displaytftespigetwidth>` ermittelte Breite und für ``tmpY`` die Breite auf die Höhe. so werden Seitenverhältnisse beibehalten.
Nun müssen die Pointer für ``x`` und ``y`` nur noch auf die Speicheradressen der temporären Variablen zeigen.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 190-191

Da der Bildschirm bei ``rotation = 1`` auf dem Kopf steht, muss nur der Kehrwert von ``y`` bestimmt werden.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 192-196

Anders als beim vorletzten Codeabschnitt, wird hier bei der der Zuweisung von ``x`` und ``y`` nach dem Mappen der Kehrwert der temporären Variablen als neuer Wert gespeichert.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 197-199

Hier wird der Kehrwert von ``x`` bestimmt, da der Bildschirm um 270° gedreht ist.    

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
    :lines: 208-228
    :linenos:

Diese Funktion wird verwendet, um das Display zu kalibrieren, damit Eingaben auf dem Display fehlerfrei stattfinden. Außerdem werden die Kalibrierungsdaten über die serielle Schnittstelle auf dem
Bildschirm aus.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 209-210

Zuerst wird ein Array erstellt, in dem die Kalibrierungsdaten gespeichert werden sollen. Anschließend wird die `calibrateTouch <https://github.com/Bodmer/TFT_eSPI/blob/master/Extensions/Touch.cpp#L228>`_ Funktion auf dem 
:ref:`tft <displaytftespivtft>` aufgerufen, die die Kalibration durchführt. Der Text, der auf dem Display angezeigt werden wird, soll magenta sein und die Hintergrundfarbe schwarz. Mit ``15`` wird die Textgröße angegeben.
Die Ergebnisse der Kalibration werden beim Funktionsaufruf in ``calData`` gespeichert.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 211-218

Die Kalibrierungsdaten werden für die Ausgabe zusammengefügt und ``stm`` hinzugefügt. Zuerst wird mit einer geöffneten geschweiften Klammer ``{`` der Anfang der Ausgabe markiert, ehe die 
Kalibrierungsdaten einzeln eingefügt und mit einem Komma getrennt werden. Eine geschlossene geschweifte Klammer ``}`` markiert das Ende des Ausgabestrings.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 220-223

Danach wird mit `Serial.available <https://www.arduino.cc/reference/en/language/functions/communication/serial/available/>`_ überprüft, ob Daten auf der Schnittstelle verfügbar sind. Wenn ja, werden die 
Kalibrierungsdaten über diese Schnittstelle ausgegeben.

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 225-227

Andernfalls werden die Kalibrierungsdaten mit :ref:`text_center<displaytftespitextcenter>` auf einem cyanfarbenen Hintergrund auf dem Display angezeigt.    

.. _displaytftespiDrawBitmapNoBgColor:

void drawBitmap(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 230-237
    :linenos:

| Diese Funktion zeichnet ein Bild. Als Parameter nimmt sie die X- und Y-Koordinate (``x`` und ``y``), bei welchen das Dreieckk gezeichnet werden soll. Die Breite (w) und Höhe (h) des Bildes, das Bild selbst (bitmap) und eine Vordergrundfarbe (fgcolor).
| 
| Für das ":ref:`tft <displaytftespivtft>`" Objekt wird die `drawBitmap <https://github.com/Bodmer/TFT_eSPI/blob/master/TFT_eSPI.cpp>`_ Funktion (siehe Zeile 2760) aufgerufen.

.. _displaytftespiDrawBitmapbgcolor:

void drawBitmap(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor, const Color& bgcolor)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/DisplayTFTeSPI.cpp
    :lines: 239-241
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

Gibt an, wie das Bild auf dem phyischen Display angezeigt bzw. ausgerichtet wird. Bei ``rotation = 0`` wird das angezeigte Bild in der Standardausrichtung angezeigt (also bei einem waagerechten Bildschrim waagerecht und bei einem senkrechten Bildschirm senkrecht).
Bei ``rotation = 1`` wird das Bild um 90° gedreht, bei ``rotation = 2`` um 180° und bei ``rotation = 3`` um 270°.


.. _displaytftespiVCalData:

std::array<uint16_t, 5> calData
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Dieses Array speichert Kalibrierungsdaten.
