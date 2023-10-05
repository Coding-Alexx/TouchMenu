.. _externalbuttonvalue:

ExternalButtonValue
+++++++++++++++++++++



Beschreibung
=============

``ExternalButtonValue`` ermöglicht eine externe Steuerung von :ref:`Button<button>` Objekten. So kann mit ihnen z.B. ein bestimmter Zustand forciert werden.


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

Diese Funktion setzt das :ref:`itemOn<externalbuttonvaluevitemon>` auf den Wert des Parameters ``item``. 
Dafür wird zuerst der vorher von :ref:`itemOn<externalbuttonvaluevitemon>` belegte Speicherplatz freigegeben, ehe die Wertzuweisung passiert.
Außerdem wird :ref:`update<externalbuttonvaluevupdate>` auf ``true`` gesetzt, um die Änderungen später zeichnen zu können. 
Diese Funktion ist speziell für :ref:`Buttons<button>` mit zwei verschiedenen Items bei aktivierten und deaktivierten Zuständen, weswegen 
:ref:`onlyOneItem<externalbuttonvaluevonlyoneitem>` auf ``false`` gesetzt wird.

.. _externalButtonVoidSetItemChar:

void setItem (const char* item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 37
    :linenos:

Bei dieser Funktion kann man den Namen eines :ref:`Items<item>` eingeben. Aus diesem wird mit :ref:`createItem<displaycreateitemnocolor>` ein :ref:`Items<item>` erstellt, welches dann
durch :ref:`setItem<externalbuttonvoidsetitemitem>` aufgerufen wird.

.. _externalButtonVoidSetItemOnChar:

void setItemOn (const char* item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 38
    :linenos:

Bei dieser Funktion kann man den Namen eines :ref:`Items<item>` eingeben. Aus diesem wird mit :ref:`createItem<displaycreateitemnocolor>` ein :ref:`Items<item>` erstellt, welches dann
durch :ref:`setItemOn<externalbuttonvoidsetitemonitem>` aufgerufen wird.

.. _externalButtonVoidSetItemOffchar:

void setItemOff (const char* item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 39
    :linenos:

Bei dieser Funktion kann man den Namen eines :ref:`Items<item>` eingeben. Aus diesem wird mit :ref:`createItem<displaycreateitemnocolor>` ein :ref:`Items<item>` erstellt, welches dann
durch :ref:`setItemOff<externalbuttonvoidsetitemoffitem>` aufgerufen wird.

.. _externalButtonVoidSetItemOffItem:

void setItemOff (Item* item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 41-46
    :linenos:

Diese Funktion setzt das :ref:`itemOff<externalbuttonvaluevitemoff>` auf den Wert des Parameters ``item``. 
Dafür wird zuerst der vorher von :ref:`itemOff<externalbuttonvaluevitemoff>` belegte Speicherplatz freigegeben, ehe die Wertzuweisung passiert.
Außerdem wird :ref:`update<externalbuttonvaluevupdate>` auf ``true`` gesetzt, um die Änderungen später zeichnen zu können. 
Diese Funktion ist speziell für :ref:`Buttons<button>` mit zwei verschiedenen Items bei aktivierten und deaktivierten Zuständen, weswegen 
:ref:`onlyOneItem<externalbuttonvaluevonlyoneitem>` auf ``false`` gesetzt wird.

.. _externalButtonVoidSetItemItem:

void setItem (Item* item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 48-55
    :linenos:

Diese Funktion gibt den von :ref:`itemOn<externalbuttonvaluevitemon>` und :ref:`itemOff<externalbuttonvaluevitemoff>` belegten Speicherplatz frei
und weißt :ref:`itemOn<externalbuttonvaluevitemon>` auf den Wert des Parameters ``item`` und :ref:`itemOff<externalbuttonvaluevitemon>` den ``nullptr`` zu.
Da diese Funktion speziell für :ref:`Buttons<button>` mit genau einem Item bei aktivierten und deaktivierten Zustand ist, wird
:ref:`onlyOneItem<externalbuttonvaluevonlyoneitem>` auf ``true`` gesetzt wird (für Buttons mit unterschiedlichen Items bei aktivierten und deaktivierten Zustand siehe :ref:`setItemOn<externalbuttonvoidsetitemonitem>`, 
:ref:`setItemOff<externalbuttonvoidsetitemoffitem>`).
Außerdem wird :ref:`update<externalbuttonvaluevupdate>` auf ``true`` gesetzt, um die Änderungen später zeichnen zu können. 




.. _externalButtonSetValue:

void setValue (const bool _value)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 57-60
    :linenos:

Mit dieser Funktion kann die Zustandänderung eines Buttons manuell ausgelöst werden. Dafür wird :ref:`value<externalbuttonvaluevvalue>` auf den Wert
der Parameters ``_value`` gesetzt. 
Außerdem wird :ref:`update<externalbuttonvaluevupdate>` auf ``true`` gesetzt, um die Änderungen später zeichnen zu können. 

.. _externalButtonGetValue:

bool getValue () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 62
    :linenos:

Gibt :ref:`value<externalbuttonvaluevvalue>` zurück. 

.. _externalButtonGetItemOn:

Item* getItemOn () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 63
    :linenos:

Gibt :ref:`itemOn<externalbuttonvaluevitemon>` zurück. 

.. _externalButtonGetItemOff:

Item* getItemOff () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 64
    :linenos:

Gibt :ref:`itemOff<externalbuttonvaluevitemoff>` zurück, wenn :ref:`onlyOneItem<externalbuttonvaluevonlyoneitem>` ``false`` ist. Andernfalls wird :ref:`itemOn<externalbuttonvaluevitemon>`
ausgegeben.

.. _externalButtonHasItemOn:

bool hasItemOn () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 66
    :linenos:

Prüft, ob :ref:`itemOn<externalbuttonvaluevitemon>` der ``nullptr`` ist, oder ob der Pointer auf ein gespeicheres Item zeigt.


.. _externalButtonHasItemOff:

bool hasItemOff () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 67
    :linenos:

Prüft, ob entweder :ref:`onlyOneItem<externalbuttonvaluevonlyoneitem>` und :ref:`hasItemOn<externalbuttonhasitemon>` ``true`` sind 
(also ob der Button bei aktivierten und deaktivierten Zustand das gleiche :ref:`Item<item>` besitzen und dieses tatsächlich existiert) oder ob
:ref:`onlyOneItem<externalbuttonvaluevonlyoneitem>` ``false`` ist und :ref:`itemOff<externalbuttonvaluevitemoff>` der ``nullptr`` ist, oder ob der Pointer auf ein gespeicheres Item zeigt
(also ob :ref:`itemOff<externalbuttonvaluevitemoff>` existiert).

.. _externalButtonHasUpdate:

bool hasUpdate () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 68
    :linenos:

Prüft, ob Änderungen (:ref:`update<externalbuttonvaluevupdate>`) vorgenommen wurden.

.. _externalButtonResetUpdate:

void resetUpdate ()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.h
    :lines: 69
    :linenos:

Setzt :ref:`update<externalbuttonvaluevupdate>` auf ``false``, um zuzeigen, dass es keine zu tätigenden Änderungen mehr gibt. 

Variablen und Konstanten Beschreibung
=====================================

.. _externalButtonValueVitemon:

Item* itemOn = nullptr
~~~~~~~~~~~~~~~~~~~~~~~~

Das :ref:`Item<item>`, welches bei einem :ref:`Button<button>` bei aktivierten Zustand angezeigt wird. Standardmäßig ist kein :ref:`Item<item>` eingestellt.
Bei einem Button, der in aktivierter und deaktivierter Form das selbe Item anzeigen soll, muss das Item in ``itemOn`` gespeichert sein.

.. _externalButtonValueVitemoff:

Item* itemOff = nullptr
~~~~~~~~~~~~~~~~~~~~~~~~

Das :ref:`Item<item>`, welches bei einem :ref:`Button<button>` bei deaktivierten Zustand angezeigt wird. Standardmäßig ist kein :ref:`Item<item>` eingestellt.

.. _externalButtonValueVvalue:

bool value = false
~~~~~~~~~~~~~~~~~~~~~~~~

Gibt den Zustand an, den ein :ref:`Button<button>` annehmen soll. Er wird aktiviert bei ``true`` und deaktiviert bei ``false``.

Der Zustand, 

.. _externalButtonValueVupdate:

bool update = false
~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob der :ref:`Button<button>` neugezeichnet werden soll, weil sich z.B. der Zustand (siehe :ref:`value<externalbuttonvaluevvalue>`) oder das :ref:`Items<item>` 
(siehe :ref:`itemOn<externalbuttonvaluevitemon>`, :ref:`itemOff<externalbuttonvaluevitemoff>`) verändert haben.

.. _externalButtonValueVonlyoneitem:

bool onlyOneItem = false
~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob ein :ref:`Button<button>` für den deaktivierten und aktivierten Zustand zwei unterschiedliche :ref:`Items<item>` haben soll (``true``) oder ob in beiden Zuständen das selbe Item 
angezeigt werden soll (``false``).