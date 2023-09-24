.. _text:

Text
+++++++++++++++

Beschreibung
=============


Tutorials/ Examples
=====================

Funktionen
=============

.. csv-table:: 
    :widths: 100 1000

    , ":ref:`Text<textconstructor>` (const std::string text, uint8_t size, const Color& color = Color(0, 0, 0))"
    , ":ref:`Text<textconstructorsizexy>` (const std::string text, const uint8_t sizeX, const uint8_t sizeY, const Color& color = Color(0, 0, 0))"
    void, ":ref:`draw<textdrawcolor>` (uint16_t x, uint16_t y, Display* disp, const Color& color) override"
    void, ":ref:`draw<textdraw>` (uint16_t x, uint16_t y, Display* disp) override"
    void, ":ref:`drawOn<textdrawon>` (uint16_t x, uint16_t y, Display* disp) override"
    void, ":ref:`drawOff<textdrawoff>` (uint16_t x, uint16_t y, Display* disp) override"
    void, ":ref:`setWidth<textsetwidth>` (const uint16_t width, const bool override) override"
    void, ":ref:`setHeight<textsetheight>` (const uint16_t height, const bool override) override"
    void, ":ref:`setSize<textsetsize>` (const uint8_t borderSize, const bool override) override"

Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 1000

    const uint8_t, ":ref:`size<textvsize>`"
    const ":ref:`Color<color>`, ":ref:`color<textvcolor>`"
    const std::string, ":ref:`text<textvtext>`"
    uint16_t, ":ref:`width<textvwidth>`"
    uint16_t, ":ref:`height<textvheight>`"


Funktionen Beschreibung
=========================

.. _textconstructor:

Text(const std::string text, uint8_t size, const Color& color = Color(0, 0, 0))
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Text.cpp
    :lines: 4-5
    :linenos:

Der Konstruktor wird bei der Erzeugung eines neuen ``Text`` Objektes aufgerufen. Als Parameter nimmt der Konstruktor einen String, der den anzuzeigenden text enthält (``text``), die gewünschte Textgröße (``size``)
und die Farbe, in der der Text angezeigt werden soll (``color``). Dieser ist standardmäßig schwarz. In der Initialisierungsliste werden die Variablen ":ref:`text<textvtext>`", ":ref:`size<textvsize>`", 
und ":ref:`color<textvcolor>`" mit den korrespondierenden Variablen initialisiert.

.. _textconstructorsizexy:

Text(const std::string text, const uint8_t sizeX, const uint8_t sizeY, const Color& color = Color(0, 0, 0))
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


.. _textdrawcolor:

void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Text.cpp
    :lines: 7-10
    :linenos:

Zeichnet den Text auf das ":ref:`Display<display>`" Objekt ``disp`` mithilfe der ":ref:`text_center<displaytextcenter>`" Funktion. Dafür werden der Funktion die ``x`` und ``y`` Koordinate übergeben, 
bei welchen der Text gezeichnet werden soll, die Textgröße (":ref:`size<textvsize>`"), die Textfarbe ``textColor`` sowie der Text an sich (``text``), welcher mit ``.c_str()`` von einem String zu einem character array umgewandelt wird.

.. _textdraw:

void draw(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Text.cpp
    :lines: 12-14
    :linenos:

.. _textdrawon:

void drawOn(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Text.cpp
    :lines: 16-18
    :linenos:
    
TODO 

Diese Funktion wird verwendet, um den Text zu zeichnen, der bei angeschalteten ...
Diese Funktion ruft ":ref:`draw<textdrawcolor>`" auf und übergibt als Wert für ``color`` ":ref:`color<textvcolor>`".

.. _textdrawoff:

void drawOff(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Text.cpp
    :lines: 20-22
    :linenos:

.. _textsetwidth:

void setWidth(const uint16_t width, const bool override) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _textsetheight:

void setHeight(const uint16_t height, const bool override) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _textsetsize:

void setSize(const uint8_t borderSize, const bool override) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Variablen und Konstanten Beschreibung
=====================================

.. _textvsize:

const uint8_t size
~~~~~~~~~~~~~~~~~~~~~~~~

Die Größe des Texts.

.. _textvcolor:

const Color color
~~~~~~~~~~~~~~~~~~~~~~~~

Die Farbe des Texts.

.. _textvtext:

const std::string text
~~~~~~~~~~~~~~~~~~~~~~~~

Dieser String enthält den tatsächlichen Text, der auf dem Display angezeigt werden soll.

.. _textvwidth:

uint16_t width
~~~~~~~~~~~~~~~~~~~~~~~~

.. _textvheight:

uint16_t height
~~~~~~~~~~~~~~~~~~~~~~~~

