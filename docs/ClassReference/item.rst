.. _item:

Item
+++++++++++++++


Beschreibung
=============

``items`` sind vordefinierte Funktionseinheiten, die auf einem :ref:`Elementen<element>` eingefügt werden können. 
Von dieser Klasse erben :ref:`Icon<icon>`, :ref:`Symbol<symbol>` und :ref:`Text<text>`

Funktionen
=============

.. csv-table:: 
    :widths: 100 1000

     
    , ":ref:`Item <itemdrawcolor>` (const double scale = 1)" 
    virtual void, ":ref:`draw <itemdrawcolor>` (uint16_t x, uint16_t y, Display* disp, const Color& color) = 0"
    virtual void, ":ref:`draw <itemdraw>` (uint16_t x, uint16_t y, Display* disp) = 0"
    virtual void, ":ref:`drawOn <itemdrawon>` (uint16_t x, uint16_t y, Display* disp) = 0"
    virtual void, ":ref:`drawOff <itemdrawoff>` (uint16_t x, uint16_t y, Display* disp) = 0"
    virtual, ":ref:`~item <itemdestructor>` () = default"
    virtual void, ":ref:`setResolution <itemsetresolution>` (const uint16_t width, const uint16_t height, const bool override = false)"
    virtual void, ":ref:`setSize <itemsetsize>` (const uint16_t size, const bool override = false)"
    virtual uint16_t, ":ref:`getWidth <itemgetwidth>` ()"
    virtual uint16_t, ":ref:`getHeight <itemgetheight>` ()"
    virtual uint8_t, ":ref:`getSize <itemgetsize>` ()"
    virtual uint8_t, ":ref:`getScale <itemgetscale>` ()"


Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 10000

    const double, ":ref:`scale<itemvscale>` = 1"


Funktionen Beschreibung
=========================

.. _itemconstructor:

Item(const double scale = 1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 10
    :linenos:

Dieser Konstruktor nimmt einen Skalierungsfaktor ``scale`` entgegen und initialisiert die Variable :ref:`scale <itemvscale>`.

.. _itemDrawColor:

virtual void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 12
    :linenos:

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`Icon <icondrawcolor>`, :ref:`Symbol <symboldrawcolor>`, :ref:`Text <textdrawcolor>`)

.. _itemDraw:

virtual void draw(uint16_t x, uint16_t y, Display* disp) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 13
    :linenos:

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`Icon <icondraw>`, :ref:`Symbol <symboldraw>`, :ref:`Text <textdraw>`)

.. _itemDrawOn:

virtual void drawOn(uint16_t x, uint16_t y, Display* disp) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 15
    :linenos:

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`Icon <icondrawon>`, :ref:`Symbol <symboldrawon>`, :ref:`Text <textdrawon>`)

.. _itemDrawOff:

virtual void drawOff(uint16_t x, uint16_t y, Display* disp) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 16
    :linenos:

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`Icon <icondrawoff>`, :ref:`Symbol <symboldrawoff>`, :ref:`Text <textdrawoff>`)

.. _itemDestructor:

virtual ~Item() = default
~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 17
    :linenos:

Der Destruktor wird bei der Zerstörung eines Objekts der ``Item`` Klasse aufgerufen.


.. _itemsetresolution:

virtual void setResolution(const uint16_t width, const uint16_t height, const bool override = false)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 19
    :linenos:

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`Icon <iconsetresolution>`, :ref:`Symbol <symbolsetresolution>`, :ref:`Text <textsetresolution>`)



.. _itemSetSize:

virtual void setSize(const uint8_t size, const bool override = false)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 20
    :linenos:

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`Symbol <symbolsetsize>`, :ref:`Text <textsetsize>`)

.. _itemGetWidth:

virtual uint16_t getWidth()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 22
    :linenos:

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`Icon <icongetwidth>`, :ref:`Symbol <symbolgetwidth>`)

.. _itemGetHeight:

virtual uint16_t getHeight()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 23
    :linenos:

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`Icon <icongetheight>`, :ref:`Symbol <symbolgetheight>`)

.. _itemGetSize:

virtual uint8_t getSize() 
~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 24
    :linenos:

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`Symbol <symbolgetsize>`)

.. _itemGetScale:

virtual uint8_t getScale()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/item.h
    :lines: 25
    :linenos:

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.

Variablen und Konstanten Beschreibung
=====================================

.. _itemvscale:

const double scale = 1
~~~~~~~~~~~~~~~~~~~~~~~

Gibt den Skalierungsfaktor an, mit dem die Größe eines Items multipliziert werden soll.