.. _icon:

Icon
+++++++++++++++

Beschreibung
=============


Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============

.. csv-table:: 
    :widths: 100 1000

     
     , ":ref:`Icon <iconconstructor>` (const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& color = Color(0,0,0))"
    static Icon*, ":ref:`create <iconcreate>` (const std::string str, const Color& color)"
    void, ":ref:`draw <icondrawcolor>` (uint16_t x, uint16_t y, Display* disp, const Color& color) override"
    void, ":ref:`draw <icondraw>` (uint16_t x, uint16_t y, Display* disp) override"
    void, ":ref:`drawOn <icondrawOn>` (uint16_t x, uint16_t y, Display* disp) override"
    void, ":ref:`drawOff <icondrawOff>` (uint16_t x, uint16_t y, Display* disp) override"


Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 1000

     
    const uint16_t, ":ref:`w <iconvw>`"
    const uint16_t, ":ref:`h <iconvh>`"
    const uint8_t*, ":ref:`bitmap <iconvbitmap>`"
    const ":ref:`Color <color>`", ":ref:`color <iconvcolor>`"
    const uint8_t, ":ref:`arrow_right <iconvarrow_right>` [] PROGMEN"



Funktionen Beschreibung
=========================

.. _iconConstructor:

Icon(const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& color = Color(0,0,0)))
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 38-43
    :linenos:

Der Konstruktor wird bei der Erzeugung eines neuen ``Icon`` Objektes aufgerufen. Als Parameter nimmt der Konstruktor die Breite (``w``) und Höhe (``h``), die ein Icon haben soll, eine ``Bitmap``, in der die GRafik gespeichert ist
und die Farbe, die die Bitmap erhalten soll (``color``). Diese ist standardmäßig schwarz. In der Initialisierungsliste werden die Variablen ":ref:`w<iconvw>`", ":ref:`h<iconvh>`", 
":ref:`bitmap<iconvbitmap>`" und ":ref:`color<iconvcolor>`" mit den korrespondierenden Variablen initialisiert.

.. _iconCreate:

static Icon* create(const std::string str, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 45-48
    :linenos:

Diese Funktion ist verantwortlich für das Erzeugen von neuen ``Icon`` Objekten. Als Parameter nimmt sie neben der gewünschten Farbe (``color``) einen String ``str``. Dieser String
soll den Namen der gewünschten Bitmap tragen, aus der ein neues ``Icon`` entstehen soll. Hier ist es essenziell, dass der Entwickler den Code anpasst, wenn dieser eigene GRafiken einbinden will. 
Standardmäßig existiert nur ":ref:`arrow_right<iconvarrow_right>`", weswegen die ``if`` Anweisung nach dem String ``arrow_right`` fragt, um ein neues Icon zu erstellen. Dieses soll eine Höhe und Breite von 
``60`` haben. Stimmt der angegebene String mit keiner abgefragten ``if`` Bedingung überein, 
wird stattdessen ein ``nullptr`` zurückgegeben,da der Erstellungsprozess eines Icons fehlgeschlagen ist.

.. _iconDrawColor:

void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 50-52
    :linenos:

Mit dieser Funktion wird die ":ref:`Bitmap<iconvbitmap>`" auf dem ":ref:`Display<displaytftespi>`" ``disp``Objekt gezeichnet mit der !!!!TODO FUNKTION!!!! . Dabei sind ``x`` und ``y`` die X- bzw- Y-Koordinaten auf dem Display.
Damit die Bitmap wie gewünscht an den richtigen Koordinaten angezeigt wird, erolgt ``x-w/2`` bzw. ``y-h/2``.


.. _iconDraw:

void draw(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 54-56
    :linenos:


TODO

.. _iconDrawOn:

void drawOn(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 58-60
    :linenos:

TODO

.. _iconDrawOff:

void drawOff(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 62-64
    :linenos:
    
TODO

Variablen und Konstanten Beschreibung
=====================================

.. _iconvw:

const uint16_t w
~~~~~~~~~~~~~~~~~

Speichert die Breite (also die Größe in X-Richtung) des ``Icon`` Objektes.

.. _iconvh:

const uint16_t h
~~~~~~~~~~~~~~~~~

Speichert die Höhe (also die Größe in Y-Richtung) des ``Icon`` Objektes.

.. _iconvbitmap:

const uint8_t* bitmap
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Speichert die Bitmap einer Grafik, um sie dann später zeichnen zu können. Bitmaps müssen wie ":ref:`arrow_right<iconvarrow_right>`" angegeben werden.

.. _iconvcolor:

const Color color
~~~~~~~~~~~~~~~~~

Speichert die Farbe des ``Icon`` Objektes.

.. _iconvarrow_right:

const uint8_t arrow_right [] PROGMEM
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 4-35
    :linenos:

Dieses Array repräsentiert eine Grafik eines nach rechts zeigenden Pfeils, welche in einem 16x32 Pixel Raster kodiert ist. Das ganze bezeichnet man auch als ``Bitmap``
Das dekodierte Bild sieht so aus:

.. image:: icon_example_arrow.png    

Um eigene Grafiken einfügen zu können, um sie auf dem Display anzeigen zu lassen, müssen diese also zuerst in eine Bitmap umgewandelt werden. Das geht am einfachsten mit
`einem Tool wie diesem hier <https://diyusthad.com/image2cpp>`_. Wichtig ist, dass beim ``Code output format`` ``Arduino code, single bitmap`` ausgewählt ist.
