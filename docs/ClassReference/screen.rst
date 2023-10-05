.. _screen:

Screen
++++++++++++++

Beschreibung
=============
| Screens sind abstrakte Klassen, die für die Darstellungsart des Bildschirms auf dem Display des Ausgabegerätes verantwortlich sind.
| Zu den Screens gehören: :ref:`GridScreen<grid>` und :ref:`ErrorScreen<errorscreen>`



Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    virtual void, ":ref:`loop <screenloop>` (Inputs& input) = 0"
    virtual void, ":ref:`draw <screendraw>` () = 0"
    void, ":ref:`setDisplay <screensetdisplay>` (Display* const disp)"
    void, ":ref:`setResolution <screensetresolution>` (int16_t height, int16_t width)"
    virtual void, ":ref:`setOffsetPosition <screensetoffsetposition>` (uint16_t x, uint16_t y)"
    const int16_t, ":ref:`getResolutionHeight <screengetresolutionheight>` () const"
    const int16_t, ":ref:`getResolutionWidth <screengetresolutionwidth>` () const"
    const int16_t, ":ref:`getOffsetx <screengetoffsetx>` () const"
    const int16_t, ":ref:`getOffsety <screengetoffsety>` () const"

Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 10000

    int16_t, ":ref:`height <screenvheight>` = 0"
    int16_t, ":ref:`width <screenvwidth>` = 0"
    int16_t, ":ref:`offsetX <screenvoffsetx>` = 0"
    int16_t, ":ref:`offsetY <screenvoffsety>` = 0"
    ":ref:`Display* <display>`", ":ref:`display <screenvdisplay>` = nullptr"


Funktionen Beschreibung
=========================

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
    :lines: 5-7
    :linenos:

Diese Funktion weist :ref:`display <screenvdisplay>` des aktuellen ``Display`` Objekts den Wert des ``disp`` zu.


.. _ScreenSetResolution:

void setResolution (int16_t height, int16_t width)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screen.cpp
    :lines: 9-12
    :linenos:

Diese Funktion weist :ref:`height <screenvheight>` und :ref:`width <screenvwidth>` des aktuellen ``Display`` Objekts den Wert von ``h`` bzw ``w`` zu.


.. _ScreenGetResolutionHeight:


const int16_t getResolutionHeight() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screen.cpp
    :lines: 19-21
    :linenos:

Gibt die :ref:`Höhe <screenvheight>` des Screens in Pixeln zurück.

.. _ScreenGetResolutionWidth:

const int16_t getResolutionWidth() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screen.cpp
    :lines: 23-25
    :linenos:

Gibt die :ref:`Breite <screenvheight>` des Screens in Pixeln zurück.


.. _Screensetoffsetposition:

virtual void setOffsetPosition(uint16_t x, uint16_t y)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese Funktion weist :ref:`offsetX<screenvoffsetx>` und :ref:`offsetY<screenvoffsety>` des aktuellen ``Display`` Objekts den Wert von ``x`` bzw ``y`` zu.

.. _Screengetoffsetx:

const int16_t getOffsetX() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt die :ref:`offsetX<screenvoffsetx>` zurück.

.. _Screengetoffsety:

const int16_t getOffsetY() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt die :ref:`offsetY<screenvoffsety>` zurück.

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

.. _screenVoffsetx:

int16_t offsetX = 0
~~~~~~~~~~~~~~~~~~~~

Wie weit der ``Screen`` von dem physischen Bildschirmrand in X-Richtung entfernt ist.

.. _screenVoffsety:

uint16_t offsetY = 0
~~~~~~~~~~~~~~~~~~~~~

Wie weit der ``Screen`` von dem physischen Bildschirmrand in Y-Richtung entfernt ist.

.. _screenVdisplay:

Display* display = nullptr
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Ein Pointer der ":ref:`Display<display>`" Klasse. Auf ``display`` lassen sich neben einem konkreten ``Screen`` auch diverse ":ref:`Elemente<element>`" zeichnen bzw. anzeigen. 
Somit ist ``display`` von großer Wichtigkeit für das gesamte Projekt.


