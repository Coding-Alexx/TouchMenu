.. _symbol:

Symbol
+++++++++++++++


Beschreibung
=============

``Symbole`` sind geometrische Formen, die vom Entwickler eingefügt werden können, um diese auf :ref:`Elementen<element>` anzeigen zu lassen.
Die Klasse erbt von  :ref:`Item<item>`.


Funktionen
=============

.. csv-table:: 
    :widths: 100 1000

     , ":ref:`Symbol <symbolconstructor>` (const symbol_func_ptr symbol, uint16_t width, uint16_t height, const Color& color = Color(0, 0, 0), uint8_t borderSize = 0)"
    static Symbol*, ":ref:`create<symboldraw>` (const std::string& symbol, uint16_t width, uint16_t height, const Color& color = Color(0, 0, 0), uint8_t borderSize = 0, const double scale = 1)"
    void, ":ref:`draw <symboldrawcolor>` (uint16_t x, uint16_t y, Display* disp, const Color& color) override"
    void, ":ref:`draw <symboldraw>` (uint16_t x, uint16_t y, Display* disp) override"
    void, ":ref:`drawOn <symboldrawon>` (uint16_t x, uint16_t y, Display* disp) override"
    void, ":ref:`drawOff <symboldrawoff>` (uint16_t x, uint16_t y, Display* disp) = 0"
    void, ":ref:`setSize <symbolsetsize>` (const uint16_t size, const bool override = false) override"
    void, ":ref:`setResolution <symbolsetresolution>` (const uint16_t width, const uint16_t height, const bool override = false) override"
    uint16_t, ":ref:`getWidth <symbolgetwidth>` () override"
    uint16_t, ":ref:`getHeight <symbolgetheight>` () override"
    uint8_t, ":ref:`getSize <symbolgetsize>` () override"
    static void, ":ref:`drawError <symboldrawerror>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"
    static void, ":ref:`drawTriangleUp <symboldrawtriangleup>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"
    static void, ":ref:`drawTriangleDown <symboldrawtriangledown>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"
    static void, ":ref:`drawTriangleRight <symboldrawtriangleright>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"
    static void, ":ref:`drawTriangleLeft <symboldrawtriangleleft>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"
    static void, ":ref:`drawRect <symboldrawrect>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"
    static void, ":ref:`drawCrosslines <symboldrawcrosslines>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"
    static void, ":ref:`drawToggleSwitch <symboldrawtoggleswitch>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"
    static void, ":ref:`drawPlus<symboldrawtoggleswitch>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"
    static void, ":ref:`drawMinus<symboldrawtoggleswitch>` (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)"
    symbol_func_ptr, ":ref:`drawSymbol<symbolvdrawsymbol>`"

Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 1000

    uint16_t, ":ref:`width<symbolvwidth>`"
    uint16_t, ":ref:`height<symbolvheight>`"
    uint8_t, ":ref:`borderSize<symbolvbordersize>`"
    ":ref:`Color<color>`", ":ref:`color<symbolvcolor>`"
    

Funktionen Beschreibung
=========================


.. _symbolsetresolution:

void setResolution(const uint16_t width, const uint16_t height, const bool override = false) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 114-119
    :linenos:

Mit dieser Funktion wird die Auflösung von Objekten der ``Symbol`` Klasse gesetzt.
Dafür wird :ref:`width<symbolvwidth>` auf den Wert von ``w`` gesetzt und :ref:`height<symbolvheight>` auf den Wert von ``h``, solange ``override`` true ist.

.. _symbolCreate:

static Symbol* create(const std::string& symbol, uint16_t width, uint16_t height, const Color& color = Color(0, 0, 0), uint8_t borderSize = 0, const double scale = 1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 79-95
    :linenos:

Diese Funktion ist verantwortlich für das Erzeugen von neuen ``Symbol`` Objekten. Als Parameter nimmt sie neben der gewünschten Breite (``width``), Höhe (``height``) Farbe (``symbolColor``), Umrandungsdicke (``borderSize``) und Skalierungsfaktor (``scale``)
einen String ``symbol``. Dieser String soll den Namen der gewünschten Funktion tragen, aus der ein neues ``Symbol`` entstehen soll. Hier ist es essenziell, dass der Entwickler den Code anpasst, 
wenn dieser eigene Symbole einbinden will. Standardmäßig existiert nur die Funktionen :ref:`drawTriangleUp<symboldrawtriangleup>`, :ref:`drawTriangleDown<symboldrawtriangledown>`, 
:ref:`drawTriangleRight<symboldrawtriangleright>`, :ref:`drawTriangleLeft<symboldrawtriangleleft>`, :ref:`drawRect<symboldrawrect>`, :ref:`drawCrosslines<symboldrawcrosslines>`,
:ref:`drawToggleSwitch<symboldrawtoggleswitch>`, :ref:`drawPlus<symboldrawplus>`  und :ref:`drawMinus<symboldrawminus>`
weswegen die ``if`` Anweisung nach dem String ``TriangleUp``, ``TriangleDown``, 
``TriangleRight``, ``TriangleLeft``, ``Rect``, ``Crosslines``, ``ToggleSwitch``, ``Plus`` bzw. ``Minus`` 
fragt, um ein neues Symbol zu erstellen. Stimmt der angegebene String mit keiner abgefragten ``if`` Bedingung überein, 
wird stattdessen ein :ref:`drawError<symboldrawerror>` Symbol erstellt, um anzuzeigen, dass der Erstellungsprozess eines Symbols fehlgeschlagen ist.


.. _symbolConstructor:

Symbol(const symbol_func_ptr symbol, uint16_t width, uint16_t height, const Color& color = Color(0, 0, 0), uint8_t borderSize = 0)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 76-77
    :linenos:

Dieser Konstruktor hat als Parameter eine Pointe auf eine ``symbol_func_ptr`` Funktion (siehe :ref:`symbol_func_ptr drawSymbol<symbolvdrawsymbol>`), die gewünschte 
Breite und Höhe des Symbols (``width`` bzw ``height``), die Farbe des Symbols (``color``), die standardmäßig schwarz ist und eine Umrandungsdicke (``bordersize``).
In der Initialisierungsliste werden die Variablen :ref:`width<symbolvwidth>`, :ref:`heighth<symbolvheight>`, :ref:`borderSize<symbolvbordersize>`, 
:ref:`color<symbolvcolor>` und :ref:`drawSymbol<symbolvdrawsymbol>` mit den entsprechenden Parametern initialisiert.

.. _symbolDrawColor:

virtual void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 97-99
    :linenos:

Diese Funktion hat die Parameter ``x`` und ``y``, die die X- bzw. Y-Koordinaten repräsentieren, bei welchen das Symbol angezeigt werden soll, sowie die Farbe 
``textColor``, die das ``Symbol`` haben soll.
Sie ruft :ref:`drawSymbol<symbolvdrawsymbol>` auf.

.. _symbolDraw:

virtual void draw(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 101-103
    :linenos:

Ruft die :ref:`draw<symboldrawcolor>` Funktion mit :ref:`color<symbolvcolor>` als Argument auf.

.. _symbolDrawOn:

virtual void drawOn(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 105-107
    :linenos:

Ruft die :ref:`draw<symboldrawcolor>` Funktion mit :ref:`color<symbolvcolor>` als Argument auf.
Diese Funktion wird verwendet, wenn ein :ref:`Element<element>` einen aktivierten und deaktivierten Zustand hat, und ein ``Symbol`` für den aktivierten Zustand gezeichnet werden soll.

.. _symbolDrawOff:

virtual void drawOff(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 109-111
    :linenos:


Ruft die :ref:`draw<symboldrawcolor>` Funktion mit :ref:`color<symbolvcolor>`:ref:`.getSecondaryColor()<colorgetsecondarycolor>` als Argument auf.
Diese Funktion wird verwendet, wenn ein :ref:`Element<element>` einen aktivierten und deaktivierten Zustand hat, und ein ``Symbol`` für den deaktivierten Zustand gezeichnet werden soll.


.. _symbolSetSize:

virtual void setSize(const uint8_t size, const bool override = false) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 121-123
    :linenos:

Mit dieser Funktion lässt sich eine neue :ref:`borderSize<symbolvbordersize>` setzen.  

.. _symbolGetWidth:

virtual uint16_t getWidth() override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 125
    :linenos:

Gibt :ref:`width<symbolvwidth>` zurück. 

.. _symbolGetHeight:

virtual uint16_t getHeight() override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 126
    :linenos:

Gibt :ref:`height<symbolvheight>` zurück. 

.. _symbolGetSize:

virtual uint8_t getSize() override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 126
    :linenos:

Gibt :ref:`size<symbolvbordersize>` zurück. 

.. _symbolDrawError:

static void drawError(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 4-6
    :linenos:

Diese Funktion zeichnet eine Fehlermeldung auf das ``Display``, wenn ":ref:`create<symbolcreate>`" fehlgeschlagen ist. Dafür wird die ":ref:`text_center<displaytextcenter>` Funktion des ":ref:`Display <display>`" Objektes 
aufgerufen.

.. _symbolDrawTriangleUp:

static void drawTriangleUp(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 8-10
    :linenos:

Diese Funktion zeichnet ein Dreieck, bei welchem eine Ecke nach oben zeigt und die anderen beiden Ecken sich unterhalb dieser Ecke auf der selben Höhe befinden. 
Dafür wird die ":ref:`triangle<displaytftespitriangleinfill>`" Funktion des ":ref:`Display <display>`" Objektes aufgerufen.
Die Parameter ``x`` und ``y`` stehen hierfür für die X- bzw. Y-Koordinaten, bei welchen das Dreieck gezeichnet werden soll, ``h`` steht für die gewünschte Höhe und ``w`` für die gewünschte Breite des Dreiecks.

.. _symbolDrawTriangleDown:

static void drawTriangleDown(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 12-14
    :linenos:

Diese Funktion zeichnet ein Dreieck, bei welchem eine Ecke nach unten zeigt und die anderen beiden Ecken sich oberhalb dieser Ecke auf der selben Höhe befinden. 
Dafür wird die ":ref:`triangle<displaytftespitriangleinfill>`" Funktion des ":ref:`Display <display>`" Objektes aufgerufen.
Die Parameter ``x`` und ``y`` stehen hierfür für die X- bzw. Y-Koordinaten, bei welchen das Dreieck gezeichnet werden soll, ``h`` steht für die gewünschte Höhe und ``w`` für die gewünschte Breite des Dreiecks.

.. _symbolDrawTriangleRight:

static void drawTriangleRight(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 16-18
    :linenos:

Diese Funktion zeichnet ein Dreieck, bei welchem eine Ecke nach rechts zeigt und die anderen beiden Ecken sich links dieser Ecke auf der selben Breite befinden. 
Dafür wird die ":ref:`triangle<displaytftespitriangleinfill>`" Funktion des ":ref:`Display <display>`" Objektes aufgerufen.
Die Parameter ``x`` und ``y`` stehen hierfür für die X- bzw. Y-Koordinaten, bei welchen das Dreieck gezeichnet werden soll, ``h`` steht für die gewünschte Höhe und ``w`` für die gewünschte Breite des Dreiecks.

.. _symbolDrawTriangleLeft:

static void drawTriangleLeft(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 20-22
    :linenos:

Diese Funktion zeichnet ein Dreieck, bei welchem eine Ecke nach links zeigt und die anderen beiden Ecken sich reechts dieser Ecke auf der selben Breite befinden. 
Dafür wird die ":ref:`triangle<displaytftespitriangleinfill>`" Funktion des ":ref:`Display <display>`" Objektes aufgerufen.
Die Parameter ``x`` und ``y`` stehen hierfür für die X- bzw. Y-Koordinaten, bei welchen das Dreieck gezeichnet werden soll, ``h`` steht für die gewünschte Höhe und ``w`` für die gewünschte Breite des Dreiecks.

.. _symbolDrawRect:

static void drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 24-27
    :linenos:

Diese Funktion zeichnet ein Rechteck. 
Dafür wird die ":ref:`rect<displayrectinfill>`" Funktion des ":ref:`Display <display>`" Objektes aufgerufen.
Die Parameter ``x`` und ``y`` stehen hierfür für die X- bzw. Y-Koordinaten, bei welchen das Rechteck gezeichnet werden soll, ``h`` steht für die gewünschte Höhe und ``w`` für die gewünschte Breite des Rechtecks.

.. _symbolDrawCrosslines:

static void drawCrosslines(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 28-31
    :linenos:

Diese Funktion zeichnet ein zwei sich kreuzende Linien. 
Dafür werden zwei :ref:`line<displayline>` Funktionen des :ref:`Display <display>` Objektes aufgerufen.
Die Parameter ``x`` und ``y`` stehen hierfür für die X- bzw. Y-Koordinaten, bei welchen die Linien sich kreuzen sollen, ``h`` steht für die gewünschte Höhe
und ``Breite`` für die gewünschte Breite des Kreuzes.


.. _symbolDrawToggleSwitch:

static void drawToggleSwitch(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 33-45
    :linenos:

Diese Funktion zeichnet einen Schalter aus zwei teilweise überlappenden Kreisen, bei dem angeschalteter und ausgeschalteter Zustand gleichzeitig sichtbar sind.

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 34-38

Dafür werden zuerst die X-Koordinate des Switches (``switchX``), die Höhe des gesamten Switches (``switchHeight``), die Y-Koordinate der oberen Hälfte (``switchTop``) und der unteren 
Hälfte (``switchBottom``) des Switches, sowie dem Durchmesser (``d``) jeder Hälfte des Schalters.   

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 40-41

Nun wird mit :ref:`circle<displaycircleinfill>` zuerst die obere Hälfte und dann die untere Häfte gezeichnet.     

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 43-44

Anschließend werden mit :ref:`text_center<displaytextcenter>` die Texte ``ON`` und ``OFF`` auf die obere bzw. untere Hälfte gezeichnet.   

.. _symbolDrawPlus:

static void drawPlus(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 47-60
    :linenos:

Diese Funktion zeichnet ein Plus.

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 48-51

Dafür werden zuerst einige Hilfsvariable bestimmt. ``tmpW`` und ``tmpH`` geben die Breite bzw. Höhe des Symbols an, ``tmpX`` und ``tmpY`` die X- bzw. Y-Koordinaten,
bei welchen das Plus gezeichnet werden soll.

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 53-56

Sollte das Symbol einen Border haben, so werden zuerst zwei Rechtecke mit :ref:`rect<displayrectinfill>` in der Farbe der Umrandung gezeichnet (eines vertikal und das andere horizontal).

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 58-59

Danach werden zwei kleinere Rechtecke über die zuvor gezeichneten Rechtecke gezeichnet, sodass die Umrandung in der gewünschten Breite sichtbar bleibt.    

.. _symbolDrawMinus:

static void drawMinus(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t borderSize, Display* display, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 62-71
    :linenos:

Diese Funktion zeichnet ein Minus.    

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 63-64

Dafür werden zuerst zwei Hilfsvariable bestimmt. ``tmpH`` gibt die Höhe des Symbols an, ``tmpY`` die Y-Koordinaten,
bei welchen das Minus gezeichnet werden soll.

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 66-68

Sollte das Symbol einen Border haben, so wird zuerst ein Rechteck mit :ref:`rect<displayrectinfill>` in der Farbe der Umrandung gezeichnet.

.. literalinclude:: ../../src/Item/Symbol.cpp
    :lines: 70

Danach wird ein kleineres Rechteck über das zuvor gezeichnete Rechtecke gezeichnet, sodass die Umrandung in der gewünschten Breite sichtbar bleibt.    


Variablen und Konstanten Beschreibung
=====================================

.. _symbolvwidth:

uint16_t width
~~~~~~~~~~~~~~~

Die Höhe (also Größe in Y-Richtung) des ``Symbols``.

.. _symbolvheight:

uint16_t height
~~~~~~~~~~~~~~~

Die Höhe (also Größe in X-Richtung) des ``Symbols``.

.. _symbolvbordersize:

uint8_t borderSize
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Die Dicke der Umrandung des ``Symbols``.

.. _symbolvcolor:

Color color
~~~~~~~~~~~~~~~

Die Farbe des ``Symbols``.

.. _symbolvdrawSymbol:

symbol_func_ptr drawSymbol
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Symbol.h
    :lines: 12-13
    :linenos:

``drawSymbol`` ist ein Pointer, der es ermöglicht, auf die oben definierten Symbol-Funktionen
(zum zeichnen verschiedener Symbol) zu zeigen, um diese wie dort beschrieben zu zeichnen.
