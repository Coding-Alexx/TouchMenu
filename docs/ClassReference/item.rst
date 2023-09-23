.. _item:

Item
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

     
    virtual void, ":ref:`draw <itemdrawcolor>` (uint16_t x, uint16_t y, Display* disp, const Color& color) = 0"
    virtual void, ":ref:`draw <itemdraw>` (uint16_t x, uint16_t y, Display* disp) = 0"
    virtual void, ":ref:`drawOn <itemdrawon>` (uint16_t x, uint16_t y, Display* disp) = 0"
    virtual void, ":ref:`drawOff <itemdrawoff>` (uint16_t x, uint16_t y, Display* disp) = 0"
    virtual, ":ref:`~item <itemdestructor>` () = default"
    virtual void, ":ref:`setWidth <itemsetwidth>` (const uint16_t width, const bool override = false)"
    virtual void, ":ref:`setHeight <itemsetheight>` (const uint16_t height, const bool override = false)"
    virtual void, ":ref:`setSize <itemsetsize>` (const uint16_t size, const bool override = false)"
    virtual uint16_t, ":ref:`getWidth <itemgetwidth>` ()"
    virtual uint16_t, ":ref:`getHeight <itemgetheight>` ()"
    virtual uint8_t, ":ref:`getSize <itemgetsize>` ()"


Funktionen Beschreibung
=========================

.. _itemDrawColor:

virtual void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`Icon <icondrawcolor>`", ":ref:`Symbol <symboldrawcolor>`", ":ref:`Text <textdrawcolor>`")

.. _itemDraw:

virtual void draw(uint16_t x, uint16_t y, Display* disp) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`Icon <icondraw>`", ":ref:`Symbol <symboldraw>`", ":ref:`Text <textdraw>`")

.. _itemDrawOn:

virtual void drawOn(uint16_t x, uint16_t y, Display* disp) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`Icon <icondrawon>`", ":ref:`Symbol <symboldrawon>`", ":ref:`Text <textdrawon>`")

.. _itemDrawOff:

virtual void drawOff(uint16_t x, uint16_t y, Display* disp) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`Icon <icondrawoff>`", ":ref:`Symbol <symboldrawoff>`", ":ref:`Text <textdrawoff>`")

.. _itemDestructor:

virtual ~Item() = default
~~~~~~~~~~~~~~~~~~~~~~~~~

Der Destruktor wird bei der Zerstörung eines Objekts der ``Item`` Klasse aufgerufen.

.. _itemSetWidth:

virtual void setWidth(const uint16_t width, const bool override = false)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 17
    :linenos:

NICHT IMPLEMENTIERT

.. _itemSetHeight:

virtual void setHeight(const uint16_t height, const bool override = false)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 18
    :linenos:

NICHT IMPLEMENTIERT

.. _itemSetSize:

virtual void setSize(const uint8_t size, const bool override = false)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 19
    :linenos:

NICHT IMPLEMENTIERT

.. _itemGetWidth:

virtual uint16_t getWidth()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 21
    :linenos:

NICHT IMPLEMENTIERT

.. _itemGetHeight:

virtual uint16_t getHeight()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 22
    :linenos:

NICHT IMPLEMENTIERT

.. _itemGetSize:

virtual uint8_t getSize() 
~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 23
    :linenos:

NICHT IMPLEMENTIERT