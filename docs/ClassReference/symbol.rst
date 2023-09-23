.. _symbol:

Symbol
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

    static Symbol*, ":ref:`create<symboldraw>` (const std::string& symbol, uint16_t width, uint16_t height, const Color& color = Color(0, 0, 0), uint8_t borderSize = 0)"
     , ":ref:`Symbol <symbolconstructor>` (const symbol_func_ptr symbol, uint16_t width, uint16_t height, const Color& color = Color(0, 0, 0), uint8_t borderSize = 0)"
    virtual void, ":ref:`draw <symboldrawcolor>` (uint16_t x, uint16_t y, Display* disp, const Color& color) override"
    virtual void, ":ref:`draw <symboldraw>` (uint16_t x, uint16_t y, Display* disp) override"
    virtual void, ":ref:`drawOn <symboldrawon>` (uint16_t x, uint16_t y, Display* disp) override"
    virtual void, ":ref:`drawOff <symboldrawoff>` (uint16_t x, uint16_t y, Display* disp) = 0"
    virtual void, ":ref:`setWidth <symbolsetwidth>` (const uint16_t width, const bool override = false) override"
    virtual void, ":ref:`setHeight <symbolsetheight>` (const uint16_t height, const bool override = false) override"
    virtual void, ":ref:`setSize <symbolsetsize>` (const uint16_t size, const bool override = false) override"
    virtual uint16_t, ":ref:`getWidth <symbolgetwidth>` () override"
    virtual uint16_t, ":ref:`getHeight <symbolgetheight>` () override"
    virtual uint8_t, ":ref:`getSize <symbolgetsize>` () override"
    static void, ":ref:`drawError <symboldrawerror>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"
    static void, ":ref:`drawTriangleUp <symboldrawtriangleup>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"
    static void, ":ref:`drawTriangleDown <symboldrawtriangledown>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"
    static void, ":ref:`drawTriangleRight <symboldrawtriangleright>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"
    static void, ":ref:`drawTriangleLeft <symboldrawtriangleleft>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"
    static void, ":ref:`drawRect <symboldrawrect>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"


Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 1000

    uint16_t, ":ref:`width<symbolvwidth>`"
    uint16_t, ":ref:`height<symbolvheight>`"
    uint8_t, ":ref:`borderSize<symbolvbordersize>`"
    ":ref:`Color<color>`", ":ref:`color<symbolvcolor>`"
    symbol_func_ptr, ":ref:`drawSymbol<symbolvdrawsymbol>`"

Funktionen Beschreibung
=========================

.. _symbolCreate:

static Symbol* create(const std::string& symbol, uint16_t width, uint16_t height, const Color& color = Color(0, 0, 0), uint8_t borderSize = 0)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 32-40
    :linenos:

Diese Funktion ist verantwortlich für das Erzeugen von neuen ``Symbol`` Objekten. Als Parameter nimmt sie neben der gewünschten Breite (``width``), Höhe (``height``) Farbe (``symbolColor``) und Umrandungsdicke (``borderSize``) einen String ``symbol``. Dieser String
soll den Namen der gewünschten Funktion tragen, aus der ein neues ``Symbol`` entstehen soll. Hier ist es essenziell, dass der Entwickler den Code anpasst, wenn dieser eigene Symbole einbinden will. 
Standardmäßig existiert nur die Funktionen ":ref:`drawTriangleUp<symboldrawtriangleup>`", ":ref:`drawTriangleDown<symboldrawtriangledown>`", ":ref:`drawTriangleRight<symboldrawtriangleright>`", 
":ref:`drawTriangleLeft<symboldrawtriangleleft>`" und ":ref:`drawRect<symboldrawrect>`", weswegen die ``if`` Anweisung nach dem String ``drawTriangleUp``, ``drawTriangleDown``, 
``drawTriangleRight``, ``drawTriangleLeft`` bzw. ``drawRect`` fragt, um ein neues Symbol zu erstellen. Stimmt der angegebene String mit keiner abgefragten ``if`` Bedingung überein, 
wird stattdessen ein ":ref:`drawError<symboldrawerror>`" Symbol erstellt, um anzuzeigen, dass der Erstellungsprozess eines Symbols fehlgeschlagen ist.


.. _symbolConstructor:

Symbol(const symbol_func_ptr symbol, uint16_t width, uint16_t height, const Color& color = Color(0, 0, 0), uint8_t borderSize = 0)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 29-30
    :linenos:

.. _symbolDrawColor:

virtual void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 42-44
    :linenos:

.. _symbolDraw:

virtual void draw(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 46-48
    :linenos:

.. _symbolDrawOn:

virtual void drawOn(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 50-52
    :linenos:

.. _symbolDrawOff:

virtual void drawOff(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 54-56
    :linenos:


.. _symbolSetWidth:

virtual void setWidth(const uint16_t width, const bool override = false) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 59-61
    :linenos:

.. _symbolSetHeight:

virtual void setHeight(const uint16_t height, const bool override = false) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 63-65
    :linenos:

.. _symbolSetSize:

virtual void setSize(const uint8_t size, const bool override = false) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 67-69
    :linenos:

.. _symbolGetWidth:

virtual uint16_t getWidth() override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 71
    :linenos:

.. _symbolGetHeight:

virtual uint16_t getHeight() override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 72
    :linenos:

.. _symbolGetSize:

virtual uint8_t getSize() override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 73
    :linenos:


.. _symbolDrawError:

static void drawError(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 4-6
    :linenos:

Diese Funktion zeichnet eine Fehlermeldung auf das ``Display``, wenn ":ref:`create<symbolcreate>`" fehlgeschlagen ist. Dafür wird die ":ref:`text_center<displaytextcenter>` Funktion des ":ref:`Display <display>`" Objektes 
aufgerufen.

.. _symbolDrawTriangleUp:

static void drawTriangleUp(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 8-10
    :linenos:

Diese Funktion zeichnet ein Dreieck, bei welchem eine Ecke nach oben zeigt und die anderen beiden Ecken sich unterhalb dieser Ecke auf der selben Höhe befinden. 
Dafür wird die ":ref:`triangle<displaytftespitriangleinfill>`" Funktion des ":ref:`Display <display>`" Objektes aufgerufen.
Die Parameter ``x`` und ``y`` stehen hierfür für die X- bzw. Y-Koordinaten, bei welchen das Dreieck gezeichnet werden soll, ``h`` steht für die gewünschte Höhe und ``w`` für die gewünschte Breite des Dreiecks.

.. _symbolDrawTriangleDown:

static void drawTriangleDown(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 12-14
    :linenos:

Diese Funktion zeichnet ein Dreieck, bei welchem eine Ecke nach unten zeigt und die anderen beiden Ecken sich oberhalb dieser Ecke auf der selben Höhe befinden. 
Dafür wird die ":ref:`triangle<displaytftespitriangleinfill>`" Funktion des ":ref:`Display <display>`" Objektes aufgerufen.
Die Parameter ``x`` und ``y`` stehen hierfür für die X- bzw. Y-Koordinaten, bei welchen das Dreieck gezeichnet werden soll, ``h`` steht für die gewünschte Höhe und ``w`` für die gewünschte Breite des Dreiecks.

.. _symbolDrawTriangleRight:

static void drawTriangleRight(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 16-18
    :linenos:

Diese Funktion zeichnet ein Dreieck, bei welchem eine Ecke nach rechts zeigt und die anderen beiden Ecken sich links dieser Ecke auf der selben Breite befinden. 
Dafür wird die ":ref:`triangle<displaytftespitriangleinfill>`" Funktion des ":ref:`Display <display>`" Objektes aufgerufen.
Die Parameter ``x`` und ``y`` stehen hierfür für die X- bzw. Y-Koordinaten, bei welchen das Dreieck gezeichnet werden soll, ``h`` steht für die gewünschte Höhe und ``w`` für die gewünschte Breite des Dreiecks.

.. _symbolDrawTriangleLeft:

static void drawTriangleLeft(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 20-22
    :linenos:

Diese Funktion zeichnet ein Dreieck, bei welchem eine Ecke nach links zeigt und die anderen beiden Ecken sich reechts dieser Ecke auf der selben Breite befinden. 
Dafür wird die ":ref:`triangle<displaytftespitriangleinfill>`" Funktion des ":ref:`Display <display>`" Objektes aufgerufen.
Die Parameter ``x`` und ``y`` stehen hierfür für die X- bzw. Y-Koordinaten, bei welchen das Dreieck gezeichnet werden soll, ``h`` steht für die gewünschte Höhe und ``w`` für die gewünschte Breite des Dreiecks.

.. _symbolDrawRect:

static void drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.cpp
    :lines: 24--27
    :linenos:

Diese Funktion zeichnet ein Rechteck. 
Dafür wird die ":ref:`rect<displayrectinfill>`" Funktion des ":ref:`Display <display>`" Objektes aufgerufen.
Die Parameter ``x`` und ``y`` stehen hierfür für die X- bzw. Y-Koordinaten, bei welchen das Rechteck gezeichnet werden soll, ``h`` steht für die gewünschte Höhe und ``w`` für die gewünschte Breite des Rechtecks.

Variablen und Konstanten Beschreibung
=====================================

.. _symbolvwidth:

uint16_t width
~~~~~~~~~~~~~~~

.. _symbolvheight:

uint16_t height
~~~~~~~~~~~~~~~

.. _symbolvbordersize:

uint8_t borderSize
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _symbolvcolor:

Color color
~~~~~~~~~~~~~~~

.. _symbolvdrawSymbol:

symbol_func_ptr drawSymbol
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.h
    :lines: 12-13
    :linenos: