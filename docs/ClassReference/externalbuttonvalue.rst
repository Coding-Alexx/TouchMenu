.. _externalbuttonvalue:

ExternalButtonValue
++++++++

Beschreibung
=============
| Buttons sind :ref:`Elemente <element>`, bei denen ein einmaliger Input zum Ausführen einer bestimmten Aktivität führt.
| Vom Button erben folgende Klassen: 

* :ref:`roundButton <roundbutton>`

Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============


.. csv-table:: 
    :widths: 100 1000

    void, ":ref:`setItemOn <externalbuttonvoidsetitemonitem>` (Item* item)"
    void, ":ref:`setItem <externalbuttonvoidsetitemchar>` (const char* item)"
    void, ":ref:`setItemOn <externalbuttonvoidsetitemonchar>` (const char* item)"
    void, ":ref:`setItemOff <externalbuttonvoidsetitemoffchar>` (const char* item)"
    void, ":ref:`setItemOff <externalbuttonvoidsetitemonitem>` (Item* item)"
    void, ":ref:`setItem <externalbuttonvoidsetitemitem>` (Item* item)"
    void, ":ref:`setValue <externalbuttonsetvalue>` (const bool _value)"
    bool, ":ref:`getValue <externalbuttongetvalue>` () const"
     ":ref:` item*<item>`", ":ref:`getItemOn <externalbuttongetvalue>` () const"
     ":ref:` item*<item>`", ":ref:`getItemOff <externalbuttongetitemoff>` () const"
    bool, ":ref:`hasItemOn <externalbuttonhasitemon>` () const"
    bool, ":ref:`hasItemOff <externalbuttonhasitemoff>` () const"
    bool, ":ref:`hasUpdate <externalbuttonhasupdate>` () const"
    void, ":ref:`resetUpdate <externalbuttonresetupdate>` () const"


Variablen und Konstanten
==========================


.. csv-table:: 
    :widths: 100 10000

    ":ref:` item*<item>`", ":ref:`itemOn<externalbuttonvaluevitemon>` = nullptr"
    ":ref:` item*<item>`", ":ref:`itemOff<externalbuttonvaluevitemoff>` = nullptr"
    bool, ":ref:`value<externalbuttonvaluevvalue>` = false"
    bool, ":ref:`update<externalbuttonvaluevupdate>` = false"
    bool, ":ref:`onlyOneItem<externalbuttonvaluevonlyoneitem>` = false"


Funktionen Beschreibung
=========================

.. _externalButtonVoidSetItemOnItem:

void setItemOn (Item* item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 30-35
    :linenos:

.. _externalButtonVoidSetItemChar:

void setItem (const char* item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 37
    :linenos:

.. _externalButtonVoidSetItemOnChar:

void setItemOn (const char* item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 38
    :linenos:

.. _externalButtonVoidSetItemOffchar:

void setItemOff (const char* item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 39
    :linenos:

.. _externalButtonVoidSetItemOffItem:

void setItemOff (Item* item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 41-46
    :linenos:

.. _externalButtonVoidSetItemItem:

void setItem (Item* item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 48-55
    :linenos:

.. _externalButtonSetValue:

void setValue (const bool _value)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 57-60
    :linenos:

.. _externalButtonGetValue:

bool getValue () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 62
    :linenos:

.. _externalButtonGetItemOn:

Item* getItemOn () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 63
    :linenos:

.. _externalButtonGetItemOff:

Item* getItemOff () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 64
    :linenos:

.. _externalButtonHasItemOn:

bool hasItemOn () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 66
    :linenos:

.. _externalButtonHasItemOff:

bool hasItemOff () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 67
    :linenos:

.. _externalButtonHasUpdate:

bool hasUpdate () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 68
    :linenos:

.. _externalButtonResetUpdate:

void resetUpdate ()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 69
    :linenos:

Variablen und Konstanten Beschreibung
=====================================

.. _externalButtonValueVitemon:

Item* itemOn = nullptr
~~~~~~~~~~~~~~~~~~~~~~~~

.. _externalButtonValueVitemoff:

Item* itemOff = nullptr
~~~~~~~~~~~~~~~~~~~~~~~~

.. _externalButtonValueVvalue:

bool value = false
~~~~~~~~~~~~~~~~~~~~~~~~

.. _externalButtonValueVupdate:

bool update = false
~~~~~~~~~~~~~~~~~~~~~~~~

.. _externalButtonValueVonlyoneitem:

bool onlyOneItem = false
~~~~~~~~~~~~~~~~~~~~~~~~~~