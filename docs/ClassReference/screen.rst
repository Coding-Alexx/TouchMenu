Screen
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

    , ":ref:`Screen <screenscreenconstructor>` ()"
    virtual void, ":ref:`loop <screenloop>` () = 0"
    virtual void, ":ref:`draw <screendraw>` () = 0"
    void, ":ref:`setDisplay <screensetdisplay>` (Display* const display)"
    void, ":ref:`setResolution <screensetresolution>` (int16_t height, int16_t width)"
    const int16_t, ":ref:`getResolutionHeight <screengetresolutionheight>` ()"
    const int16_t, ":ref:`getResolutionWidth <screengetresolutionwidth>` ()"


Funktionen Beschreibung
=========================

.. _ScreenScreenConstructor:

Screen ()
~~~~~~~~~

.. _ScreenLoop:

virtual void loop () = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _ScreenDraw:

virtual void draw () = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _ScreenSetDisplay:

void setDisplay (Display* const display)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screen.cpp
    :lines: 18-20
    :linenos:

.. _ScreenSetResolution:

void setResolution (int16_t height, int16_t width)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screen.cpp
    :lines: 5-8
    :linenos:


.. _ScreenGetResolutionHeight:


const int16_t getResolutionHeight()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screen.cpp
    :lines: 10-12
    :linenos:

.. _ScreenGetResolutionWidth:

const int16_t getResolutionWidth()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screen.cpp
    :lines: 14-16
    :linenos: