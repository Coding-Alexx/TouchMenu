.. _display:

Display
++++++++

Beschreibung
=============
Display ist eine abstrakte Klasse, die als Schnittstelle zwischen :ref:`Menü <touchmenulib>` und dem Ausgabegerät fungiert.

Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    virtual, ":ref:`~Display <displayDestructor>` ()" 
    virtual void, ":ref:`init <displayinit>` ()"
    virtual void, ":ref:`rect <displayrectinfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color) = 0"
    virtual void, ":ref:`rect_center <displayrectcenterinfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color) = 0"
    virtual void, ":ref:`rect <displayrectnoinfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color) = 0"
    virtual void, ":ref:`rect_center <displayrectcenternoinfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color) = 0"
    virtual void, ":ref:`circle <displaycircleinfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color, const Color& infill_color) = 0"
    virtual void, ":ref:`circle <displaycirclenoinfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color) = 0"
    virtual void, ":ref:`triangle <displaytriangleinfill>` (const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color, const Color& infill_color) = 0"
    virtual void, ":ref:`triangle <displaytrianglenoinfill>` (const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color) = 0"
    virtual void, ":ref:`text <displaytext>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const char* text, const Color& text_color) = 0"
    virtual void, ":ref:`text_center <displaytextcenter>` (const uint16_t pos_x, const uint16_t pos_y, const uint8_t text_size, const char* text, const Color& text_color) = 0"
    virtual void, ":ref:`line <displayline>` (const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color& color) = 0"
    virtual void, ":ref:`point <displaypoint>` (const uint16_t x1, const uint16_t y1, const Color& color) = 0"
    virtual void, ":ref:`fillScreen <displaypoint>` (const Color& color) = 0"
    virtual void, ":ref:`drawBitmap <displaydrawbitmapnobgcolor>` (const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor) = 0"
    virtual void, ":ref:`drawBitmap <displaydrawbitmapbgcolor>` (const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor, const Color& bgcolor) = 0"
    virtual int16_t, ":ref:`getHeight <displaygetheight>` () = 0"
    virtual int16_t, ":ref:`getWidth <displaygetwidth>` () = 0"
    virtual uint8_t, ":ref:`getRotation <displaygetrotation>` () = 0"
    virtual uint8_t, ":ref:`setRotation <displaysetrotation>`(uint8_t rotation) = 0"
    virtual bool, ":ref:`getTouch <displaygettouch>`(uint16_t* x, uint16_t* y) = 0"
    virtual bool, ":ref:`startTouchCalibration <displaystarttouchcalibration>`()"
    void, ":ref:`drawItem <displaydrawitemcolor>` (uint16_t x, uint16_t y, Item* item, const Color& color)"
    void, ":ref:`drawItem <displaydrawitemnocolor>` (uint16_t x, uint16_t y, Item* item)"
    static ":ref:`Item*<item>`", ":ref:`createItem <displaycreateitemnocolor>` (const std::string str)"
    static ":ref:`Item*<item>`", ":ref:`createItem <displaycreateitemcolor>` (const std::string str, const Color& color)"
    static ":ref:`Color<color>`", ":ref:`parseColor<displayparsecolor>` (const std::string& colorStr, const Color& color)"
    static std::string, ":ref:`processText<displayprocesstext>` (const std::string& input)"
    template <typename T> static T, ":ref:`stringToNumber<displaystringtonumber>` ((const std::string& str, const T& value))"
   


Funktionen Beschreibung
=========================


.. _displayDestructor:

virtual ~Display()
~~~~~~~~~~~~~~~~~~~~

Der Destruktor wird bei der Zerstörung eines ``Display`` Objektes aufgerufen.

.. _displayInit:

virtual void init()
~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespiinit>`")

.. _displayRectInfill:

virtual void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespiRectInfill>`")

.. _displayRectCenterInfill:

virtual void rect_center(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespirectcenterinfill>`")

.. _displayRectNoInfill:

virtual void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespiRectNoInfill>`")

.. _displayRectCenterNoInfill:

virtual void rect_center(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespirectcenternoinfill>`")

.. _displayCircleInfill:

virtual void circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color, const Color& infill_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespiCircleInfill>`")

.. _displayCircleNoInfill:

virtual void circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespicirclenoinfill>`")


.. _displayTriangleInfill:

virtual void triangle(const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color, const Color& infill_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespitriangleinfill>`")

.. _displayTriangleNoInfill:

virtual void triangle(const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespitrianglenoinfill>`")

.. _displayText:

virtual void text(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const char* text, const Color& text_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespiText>`")

.. _displayTextCenter:

virtual void text_center(const uint16_t pos_x, const uint16_t pos_y, const uint8_t text_size, const char* text, const Color& text_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespitextcenter>`")


.. _displayLine:

virtual void line(const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color& color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespiLine>`")


.. _displayPoint:

virtual void point(const uint16_t x1, const uint16_t y1, const Color& color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespiPoint>`")

.. _displayFillScreen:

virtual void fillScreen (const Color& color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespifillscreen>`")


.. _displayGetHeight:

virtual int16_t getHeight() = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displayttftespigetheight>`")



.. _displayGetWidth:

virtual int16_t getWidth() = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespigetwidth>`")



.. _displayGetRotation:

virtual uint8_t getRotation() = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespigetrotation>`")



.. _displaySetRotation:

virtual void setRotation(uint8_t rotation) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespisetrotation>`")

.. _displayGetTouch:

virtual bool getTouch(uint16_t* x, uint16_t* y) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespigettouch>`")


.. _displayStartTouchCalibration:

virtual void startTouchCalibration() {}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.h
    :lines: 57
    :linenos:

LEER

.. _displayDrawBitmapNoBgColor:

virtual void drawBitmap(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespidrawbitmapnobgcolor>`")

.. _displayDrawBitmapBgColor:

virtual void drawBitmap(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor, const Color& bgcolor) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`DisplayTFTeSPI <displaytftespidrawbitmapbgcolor>`")

.. _displayDrawItemColor:

void drawItem (uint16_t x, uint16_t y, Item* item, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.cpp
    :lines: 6-8
    :linenos:

Diese Funktion ruft die ":ref:`draw<itemdrawcolor>`" Funktion der ``Item`` Klasse auf, um ein ``Item`` Objekt in einer Farbe (``color``) auf dem aktuellen Display (``this``) bei
gewünschten X- und Y-Koordinaten zu zeichnen.

.. _displayDrawItemNoColor:

void drawItem (uint16_t x, uint16_t y, Item* item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.cpp
    :lines: 10-12
    :linenos:

Diese Funktion ruft die ":ref:`draw<itemdrawcolor>`" Funktion der ``Item`` Klasse auf, um ein ``Item`` Objekt auf dem aktuellen Display (``this``) bei
gewünschten X- und Y-Koordinaten zu zeichnen.

.. _displayCreateItemNoColor:

static Item* createItem(const std::string str)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.cpp
    :lines: 76-78
    :linenos:

.. _displayCreateItemColor:

static Item* createItem(const std::string str, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.cpp
    :lines: 80-146
    :linenos:

.. _displayParseColor:

static Color parseColor(const std::string& colorStr, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.cpp
    :lines: 14-34
    :linenos:

TODO

Im Prinzip: Gebe Farbwerte ein z.B. 255,255,255, jede Zahl wird an eine Array Position gepackt und daraus wird RGB Wert bzw Farbe gebildet

.. _displayProcessText:

static std::string processText(const std::string& input)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.cpp
    :lines: 36-59
    :linenos:

.. _displayStringToNumber:

template <typename T> static T stringToNumber(const std::string& str, const T& value)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.cpp
    :lines: 62-73
    :linenos:

