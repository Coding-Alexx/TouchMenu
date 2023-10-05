.. _text:

Text
+++++++++++++++


Beschreibung
=============

Mit dieser Klasse lassen sich anpassbare Textinhalte erstellen.
Die Klasse erbt von  :ref:`Item<item>`.


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
    void, ":ref:`setResolution<textsetsize>` (const uint16_t width, const uint16_t height, const bool override = false) override"
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
und die Farbe, in der der Text angezeigt werden soll (``color``). Dieser ist standardmäßig schwarz. In der Initialisierungsliste werden die Variablen :ref:`text<textvtext>`, :ref:`size<textvsize>`, 
und :ref:`color<textvcolor>` mit den korrespondierenden Variablen initialisiert.

.. _textconstructorsizexy:

Text(const std::string text, const uint8_t sizeX, const uint8_t sizeY, const Color& color = Color(0, 0, 0))
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Text.cpp
    :lines: 8-10
    :linenos:

Der Konstruktor wird bei der Erzeugung eines neuen ``Text`` Objektes aufgerufen. Als Parameter nimmt der Konstruktor einen String, der den anzuzeigenden text enthält (``text``), die gewünschte Breite und Höhe des Texts (``sizeX`` bzw. ``sizeY``)
und die Farbe, in der der Text angezeigt werden soll (``color``). Dieser ist standardmäßig schwarz. In der Initialisierungsliste werden die Variablen :ref:`text<textvtext>`
und :ref:`color<textvcolor>` mit den korrespondierenden Variablen initialisiert.

.. _textdrawcolor:

void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Text.cpp
    :lines: 11-15
    :linenos:

Zeichnet den Text auf das :ref:`Display<display>` Objekt ``disp`` mithilfe der :ref:`text_center<displaytextcenter>` Funktion. Dafür werden der Funktion die ``x`` und ``y`` Koordinate übergeben, 
bei welchen der Text gezeichnet werden soll, die Textgröße (:ref:`size<textvsize>`), die Textfarbe ``textColor`` sowie der Text an sich (:ref:`text<textvtext>`), welcher mit ``.c_str()`` 
von einem String zu einem character array umgewandelt wird.

.. _textdraw:

void draw(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Text.cpp
    :lines: 12-14
    :linenos:


Ruft die :ref:`draw<textdrawcolor>` Funktion mit :ref:`color<textvcolor>` als Argument auf.


.. _textdrawon:

void drawOn(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Text.cpp
    :lines: 16-18
    :linenos:
  

Ruft die :ref:`draw<textdrawcolor>` Funktion mit :ref:`color<textvcolor>` als Argument auf.
Diese Funktion wird verwendet, wenn ein :ref:`Element<element>` einen aktivierten und deaktivierten Zustand hat, und ein ``Text`` für den aktivierten Zustand gezeichnet werden soll.

.. _textdrawoff:

void drawOff(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Text.cpp
    :lines: 20-22
    :linenos:


Ruft die :ref:`draw<textdrawcolor>` Funktion mit :ref:`color<textvcolor>`:ref:`.getSecondaryColor()<colorgetsecondarycolor>`  als Argument auf.
Diese Funktion wird verwendet, wenn ein :ref:`Element<element>` einen aktivierten und deaktivierten Zustand hat, und ein ``Text`` für den deaktivierten Zustand gezeichnet werden soll.

.. _textsetresolution:

void setResolution(const uint16_t width, const uint16_t height, const bool override = false) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Text.cpp
    :lines: 30-35
    :linenos:

Mit dieser Funktion wird die Auflösung von Objekten der ``Text`` Klasse gesetzt.
Dafür wird :ref:`width<textvwidth>` auf den Wert von ``w`` gesetzt und :ref:`height<textvheight>` auf den Wert von ``h``, solange ``override`` true ist.

.. _textsetsize:

void setSize(const uint8_t borderSize, const bool override) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Text.cpp
    :lines: 37-39
    :linenos:

Mit dieser Funktion lässt sich eine neue :ref:`size<textvsize>` setzen. 


Variablen und Konstanten Beschreibung
=====================================

.. _textvsize:

const uint8_t size
~~~~~~~~~~~~~~~~~~~~~~~~

Die Schriftgröße des ``Texts``.

.. _textvcolor:

const Color color
~~~~~~~~~~~~~~~~~~~~~~~~

Die Farbe des ``Texts``.

.. _textvtext:

const std::string text
~~~~~~~~~~~~~~~~~~~~~~~~

Dieser String enthält den tatsächlichen Textinhalt, der auf dem ``Display`` angezeigt werden soll.

.. _textvwidth:

uint16_t width
~~~~~~~~~~~~~~~~~~~~~~~~

Die Breite des ``Texts``.

.. _textvheight:

uint16_t height
~~~~~~~~~~~~~~~~~~~~~~~~

Die Höhe des ``Texts``.

