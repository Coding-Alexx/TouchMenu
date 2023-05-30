TouchMenuLib
++++++++++++++

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

    , ":ref:`TouchMenuLib <touchmenulibtouchmenulibconstructor>` (Display&& display)"
    , ":ref:`~TouchMenuLib <touchmenulibtouchmenulibdestructor>` ()"
    void, ":ref:`init <touchmenulibinit>` ()"
    void, ":ref:`add <touchmenulibadd>` (uint8_t id, Screen* screen)"
    void, ":ref:`loop <touchmenulibloop>` ()"
    void, ":ref:`back <touchmenulibback>` ()"
    void, ":ref:`back <touchmenulibbacksize>` ()"
    void, ":ref:`goTo <touchmenulibbacksize>` (size_t id, bool toHistory)"


Funktionen Beschreibung
=========================

.. _TouchMenuLibTouchMenuLibConstructor:

TouchMenuLib (Display&& display)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 3-5
    :linenos:

.. _TouchMenuLibTouchMenuLibDestructor:

~TouchMenuLib ()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


.. _TouchMenuLibInit:

void init ()
~~~~~~~~~~~~~~~

.. _TouchMenuLibAdd:

void add (uint8_t id, Screen* screen)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 14-25
    :linenos:

.. _TouchMenuLibLoop:

void loop ()
~~~~~~~~~~~~~~~

.. _TouchMenuLibBack:

void back ()
~~~~~~~~~~~~~~~

.. _TouchMenuLibBackSize:

void back (size_t i)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibGoTo:

bool goTo (size_t id, bool toHistory)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 34-36
    :linenos: