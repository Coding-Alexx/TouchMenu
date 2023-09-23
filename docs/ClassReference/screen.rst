.. _screen:

Screen
++++++++++++++

Beschreibung
=============
| Screens sind abstrakte Klassen, die für die Darstellungsart des Bildschirms auf dem Display des Ausgabegerätes verantwortlich sind.
| Zu den Screens gehören:

* :ref:`GridScreens <gridscreen>`
* :ref:`ErrorScreens <errorscreen>`

Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    , ":ref:`Screen <screenscreenconstructor>` ()"
    virtual void, ":ref:`loop <screenloop>` (Inputs& input) = 0"
    virtual void, ":ref:`draw <screendraw>` () = 0"
    void, ":ref:`setDisplay <screensetdisplay>` (Display* const display)"
    void, ":ref:`setResolution <screensetresolution>` (int16_t height, int16_t width)"
    const int16_t, ":ref:`getResolutionHeight <screengetresolutionheight>` ()"
    const int16_t, ":ref:`getResolutionWidth <screengetresolutionwidth>` ()"


Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 10000

    int16_t, ":ref:`height <screenvheight>` = 0"
    int16_t, ":ref:`width <screenvwidth>` = 0"
    ":ref:`Display* <display>`", ":ref:`width <screenvwidth>` = 0"


Funktionen Beschreibung
=========================

.. _ScreenScreenConstructor:

Screen ()
~~~~~~~~~
.. literalinclude:: ../../src/Screen.cpp
    :lines: 3
    :linenos:
    

nichts


.. _ScreenLoop:

virtual void loop (Inputs& input) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`ErrorScreen<errorloop>`", ":ref:`GridScreen <gridloop>`")


.. _ScreenDraw:

virtual void draw () = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`ErrorScreen<errordraw>`", ":ref:`GridScreen <griddraw>`")


.. _ScreenSetDisplay:

void setDisplay (Display* const display)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screen.cpp
    :lines: 18-20
    :linenos:

Diese Funktion weist :ref:`display <screenvdisplay>` des aktuellen ``Display`` Objekts den Wert des übergebenen ``display`` zu.


.. _ScreenSetResolution:

void setResolution (int16_t height, int16_t width)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screen.cpp
    :lines: 5-8
    :linenos:

Diese Funktion weist :ref:`height <screenvheight>` und :ref:`width <screenvwidth>` des aktuellen ``Display`` Objekts den Wert des übergebenen ``h`` bzw ``w`` zu.


.. _ScreenGetResolutionHeight:


const int16_t getResolutionHeight()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screen.cpp
    :lines: 10-12
    :linenos:

Gibt die :ref:`Höhe <screenvheight>` des Screens in Pixeln zurück.

.. _ScreenGetResolutionWidth:

const int16_t getResolutionWidth()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screen.cpp
    :lines: 14-16
    :linenos:

Gibt die :ref:`Breite <screenvheight>` des Screens in Pixeln zurück.

Variablen und Konstanten Beschreibung
=====================================

.. _screenVheight:

int16_t height = 0
~~~~~~~~~~~~~~~~~~~~~

Höhe (also Größe in Y-Richtung) des Screens in Pixeln.

.. _screenVwidth:

int16_t width = 0
~~~~~~~~~~~~~~~~~~~~~

Breite (also Größe in X-Richtung) des Screens in Pixeln.

.. _screenVdisplay:

Display* display
~~~~~~~~~~~~~~~~~~~~

Ein Pointer der ":ref:`Display<display>`" Klasse. Auf ``display`` lassen sich neben einem konkreten ``Screen`` auch diverse ":ref:`Elemente<element>`" zeichnen bzw. anzeigen. 
Somit ist ``display`` von großer Wichtigkeit für das gesamte Projekt.