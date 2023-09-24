.. _textbox:

SliderRect
++++++++++++++

Beschreibung
=============

Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    inline, ":ref:`Textbox_Rect <textbox_rectconstructoritemstr>` (char* itemStr, const Color& color, ExternalTextboxValue* value=nullptr)"
    inline, ":ref:`Textbox_Rect <textbox_rectconstructoritem>` (Item* item, const Color& color, ExternalTextboxValue* value=nullptr)"
    inline void, ":ref:`draw <textbox_rectdraw>` ()"
    Color, ":ref:`getColor <textbox_rectgetcolor>` ()"

Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 10000

    const ":ref:`Color <Color>`", ":ref:`color <textbox_rectvcolor>`"
    const uint16_t, ":ref:`t <textbox_rectvT>` = 10"
    const uint16_t, ":ref:`b <textbox_rectvB>` = 10"
    const uint16_t, ":ref:`r <textbox_rectvR>` = 6"


Funktionen Beschreibung
=========================

.. _textbox_rectConstructorItemStr:

inline Textbox_Rect(char* itemStr, const Color& color, ExternalTextboxValue* value=nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/textbox_rect.h
    :lines: 10-17
    :linenos:

Diese Funktion ist ein Konstruktor, der Objekte der ``textbox_rect`` Klasse erzeugt. Als Paramater nimmt er den Text, der angezeigt werden soll (``text``), die Farbe des Rechtecks (``color``) und dem ``value``, der angibt, in welchem Zustand sich das 
Objekt befindet. In der Initialisierungsliste erfolgt zuerst der Aufruf vom ":ref:`Textbox Konstruktor<textboxconstructor>`".
Außerdem erfolgt die Initialisierung von ":ref:`color<textbox_rectvcolor>`" und ":ref:`size<textbox_rectvsize>`" mit den entsprechenden Parametern.

.. _textbox_rectConstructorItem:

inline Textbox_Rect(char* itemStr, const Color& color, ExternalTextboxValue* value=nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _textbox_rectDraw:

inline void draw()
~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/textbox_rect.h
    :lines: 23-26
    :linenos:

Diese Funktion wird genutzt, um das Objekt zu zeichnen. Zuerst wird mit dem Funktionsaufruf von ":ref:`rect_center<displayrectcenterinfill>`" auf dem ":ref:`display<elementvdisplay>`" das REchteck gezeichnet,
auf dem der Text dargestellt werden soll. Mit ":ref:`text_center<displaytextcenter>`" wird schließlich der Text über das REchteck gezeichnet.

.. _textbox_rectGetText:

char* getText() const
~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/textbox_rect.h
    :lines: 28-30
    :linenos:

Gibt den Text zurück.

.. _textbox_rectGetColor:

Color getColor() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/textbox_rect.h
    :lines: 32-34
    :linenos:

Gibt die ":ref:`Farbe<color>`" zurück.

.. _textbox_rectGetColorInfill:

.. _textbox_rectCheckSize:

inline bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/textbox_rect.h
    :lines: 45-48
    :linenos:

nicht implementiert

Variablen und Konstanten Beschreibung
=====================================


.. _textbox_rectVColor:

const Color color
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Speichert die ":ref:`Farbe<color>`" , mit der in der ":ref:`draw<textbox_rectdraw>`" Funktion die Farbe des Textes und des Rechtecks ebstimmt wird.

.. _textbox_rectVsize:

uint8_t size = 1
~~~~~~~~~~~~~~~~~~~~~~~~~

Speichert die Schriftgröße. Standardmäßig ist diese 1.

.. _textbox_rectVT:

const uint16_t t = 10
~~~~~~~~~~~~~~~~~~~~~~~~~


TODO
Gibt den Abstand zur Umrandung an.

.. _textbox_rectVB:

const uint16_t b = 10 
~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt die Breite der Umrandung an.

.. _textbox_rectVR:

const uint16_t r = 6
~~~~~~~~~~~~~~~~~~~~~~~~


Gibt den Radius der Umrandung (bzw. den Krümmungsgrad) an.
