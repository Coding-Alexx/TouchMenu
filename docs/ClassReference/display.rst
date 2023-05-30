Display
++++++++

Beschreibung
=============
Was macht die Klasse

TODO Verlinkung zu roundButton 

Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    , ":ref:`Display <displayConstructor>` (const uint8_t pin_tft_CS, const uint8_t pin_tft_DC)" 
    , :ref:`Display <displayCopyConstructor>` (const Display& other)
    , :ref:`Display& operator= <displayCopyAssignmentOperator>` (const Display& other)
    void, ":ref:`init <displayinit>` ()"
    void, ":ref:`rect <displayRectInfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius, const Color* infill_color) (const Display& other)" 
    void, ":ref:`rect <displayRectRadius>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius)" 
    void, ":ref:`rect <displayRect>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius)"
    void, ":ref:`circle <displayCircleInfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color, const Color* infill_color)"
    void, ":ref:`circle <displaycircle>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color)"
    void, ":ref:`text <displayText>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color)"
    void, ":ref:`text_center <displayText_center>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color)"
    void, ":ref:`line <displayLine>` (const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color* color)"
    void, ":ref:`point <displayPoint>` (const uint16_t x1, const uint16_t y1, const Color* color)"


Funktionen Beschreibung
=========================

.. _displayConstructor:

Display (const uint8_t pin_tft_CS, const uint8_t pin_tft_DC)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayCopyConstructor:

Display (const Display& other)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayCopyAssignmentOperator:

Display& operator= (const Display& other)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayInit:

void init()
~~~~~~~~~~~~~

.. _displayRectInfill:

void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius, const Color* infill_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayRectRadius:

void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayRect:

void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color);
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayCircleInfill:

void circle (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color, const Color* infill_color);
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayCircle:

void circle (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color);
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayText:

void text (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color);
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayText_center:

void text_center (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color);
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayLine:

void line (const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color* color);
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayPoint:

void point (const uint16_t x1, const uint16_t y1, const Color* color);
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~