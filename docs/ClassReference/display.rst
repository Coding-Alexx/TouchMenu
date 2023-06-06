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

    , ":ref:`~Display <displayDestructor>` ()" 
    void, ":ref:`init <displayinit>` ()"
    void, ":ref:`rect <displayRectInfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius, const Color* infill_color) (const Display& other) = 0" 
    void, ":ref:`rect <displayRectRadius>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius) = 0" 
    void, ":ref:`rect <displayRect>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius) = 0"
    void, ":ref:`circle <displayCircleInfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color, const Color* infill_color) = 0"
    void, ":ref:`circle <displaycircle>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color) = 0"
    void, ":ref:`text <displayText>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color) = 0"
    void, ":ref:`text_center <displayText_center>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color) = 0"
    void, ":ref:`line <displayLine>` (const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color* color) = 0"
    void, ":ref:`point <displayPoint>` (const uint16_t x1, const uint16_t y1, const Color* color)"
    void, ":ref:`fillScreen <displayfillscreen>` (const Color& color) = 0" 


Funktionen Beschreibung
=========================


.. _displayDestructor:

virtual ~Display()
~~~~~~~~~~~~~~~~~~~~

.. _displayInit:

virtual void init()
~~~~~~~~~~~~~~~~~~~~

.. _displayRectInfill:

virtual void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius, const Color* infill_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayRectRadius:

virtual void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color, uint8_t radius) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayRect:

virtual void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const Color* border_color) = 0;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayCircleInfill:

virtual void circle (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color, const Color* infill_color) = 0;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayCircle:

virtual void circle (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color* border_color) = 0;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayText:

virtual void text (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color) = 0;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayText_center:

virtual void text_center (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t text_size, const Color* text_color) = 0;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayLine:

virtual void line (const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color* color) = 0;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayPoint:

virtual void point (const uint16_t x1, const uint16_t y1, const Color* color) = 0;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _displayFillScreen:

virtual void fillScreen (const Color& color) = 0;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~