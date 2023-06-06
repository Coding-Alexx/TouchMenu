.. _displaytftespi:

DisplayTFTeSPI
++++++++++++++++
DisplayTFTeSPI erben von der Klasse :ref:`Display <display>` und nutzen für ihre Ausgabe die Bibliothek `TFTeSPI <https://github.com/Bodmer/TFT_eSPI/>`_.

Beschreibung
=============

Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    uint16_t, ":ref:`reverseColor565 <displaytftespireversecolor565color>` (const Color& color)"
    uint16_t, ":ref:`reverseColor565 <displaytftespireversecolor565rgb>` (uint8_t r, uint8_t g, uint8_t b)"
    , ":ref:`DisplayTFTeSPI <displaytftespiConstructor>` ()" 
    , :ref:`DisplayTFTeSPI <displaytftespiCopyConstructor>` (const DisplayTFTeSPI& other)
    , :ref:`DisplayTFTeSPI& operator= <displaytftespiCopyAssignmentOperator>` (const DisplayTFTeSPI& other)
    void, ":ref:`init <displaytftespiInit>` () override"
    void, ":ref:`rect <displaytftespiRectInfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius, const Color* infill_color) (const Display& other) override" 
    void, ":ref:`rect <displaytftespiRectRadius>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius) override" 
    void, ":ref:`rect <displaytftespiRect>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius) override"
    void, ":ref:`circle <displaytftespiCircleInfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color, const Color* infill_color) override"
    void, ":ref:`circle <displaytftespicircle>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color) override"
    void, ":ref:`text <displaytftespiText>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color) override"
    void, ":ref:`text_center <displaytftespiText_center>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color) override"
    void, ":ref:`line <displaytftespiLine>` (const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color* color) override"
    void, ":ref:`point <displaytftespiPoint>` (const uint16_t x1, const uint16_t y1, const Color* color) override"
    void, ":ref:`fillScreen <displaytftespifillscreen>` (const Color& color) override"
    int16_t, ":ref:`getHeight <displayttftespigetheight>` ()" 
    int16_t, ":ref:`getWidth <displaytftespigetwidth>` ()" 


Funktionen Beschreibung
=========================

.. _displaytftespiReverseColor565Color:

uint16_t reverseColor565 (const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displaytftespiReverseColor565RGB:

uint16_t reverseColor565 (uint8_t r, uint8_t g, uint8_t b)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



.. _displaytftespiConstructor:

DisplayTFTeSPI ()
~~~~~~~~~~~~~~~~~~~~

.. _displaytftespiCopyConstructor:

DisplayTFTeSPI (const DisplayTFTeSPI& other)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displaytftespiCopyAssignmentOperator:

DisplayTFTeSPI& operator= (const DisplayTFTeSPI& other)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displaytftespiInit:

void init() override
~~~~~~~~~~~~~~~~~~~~

.. _displaytftespiRectInfill:

void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius, const Color* infill_color) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displaytftespiRectRadius:

void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displaytftespiRect:

void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displaytftespiCircleInfill:

void circle (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color, const Color* infill_color) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displaytftespiCircle:

void circle (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displaytftespiText:

void text (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displaytftespiText_center:

void text_center (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displaytftespiLine:

void line (const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color* color) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displaytftespiPoint:


void point (const uint16_t x1, const uint16_t y1, const Color* color) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


.. _displaytftespiFillScreen:

void fillScreen (const Color& color) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayttftespiGetHeight:

int16_t getHeight()
~~~~~~~~~~~~~~~~~~~~~

.. _displaytftespiGetWidth:

int16_t getWidth()
~~~~~~~~~~~~~~~~~~~~~
