.. _element:

Elements
++++++++++

Beschreibung
=============
Elemente sind vordefinierte Funktionseinheiten, die auf einem :ref:`Screen <screen>` eingefügt werden können. 
Dazu gehören :ref:`Button<button>`, :ref:`Number_Input<numberinput>` und :ref:`Textbox<textbox>`.



Funktionen
=============
relevant für eigenes Menü

.. csv-table:: 
    :widths: 100 1000

     void, ":ref:`setPosition <elementsetposition>` (const uint16_t posX, const uint16_t posY, const uint8_t rotation)"
     bool, ":ref:`setsize <elementsetsize>` (const uint16_t sizeX, const uint16_t sizeY, const uint8_t rotation = 0)"
     void, ":ref:`setDisplay <elementsetdisplay>` (Display* const disp)"
     , :ref:`Element <elementelementconstructor>` ()
     virtual, :ref:`~Element <elementelementdenstructor>` ()
     virtual bool, :ref:`select <elementselect>` () = 0
     virtual void, ":ref:`loop <elementloopinput>` (Inputs& input) = 0"
     virtual void, ":ref:`draw <elementdraw>` () = 0"
     virtual void, ":ref:`checkSize <elementchecksize>` (uint16_t sizeX, uint16_t sizeY, uint8_t rotation) = 0"
     virtual void, ":ref:`setTouch <elementsettouch>` (Inputs& input) = 0"



Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 1000

     uint16_t, ":ref:`posX <elementvposx>`"
     uint16_t, ":ref:`posY <elementvposy>`"
     uint16_t, ":ref:`sizeX <elementvsizex>`"
     uint16_t, ":ref:`sizeY <elementvsizeY>`"
     uint16_t, ":ref:`rotation <elementvrotation>`"
     ":ref:`Display* <display>`", ":ref:`display <elementvdisplay>`"

Funktionen Beschreibung
=========================


.. _elementElementConstructor:

Element ()
~~~~~~~~~~~~
.. literalinclude:: ../../src/Element.cpp
    :lines: 24
    :linenos:

Der Konstruktor wird bei der Erzeugung eines neuen Objekts der ``Element`` Klasse aufgerufen.

.. _elementElementDenstructor:

virtual ~Element ()
~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Element.cpp
    :lines: 23
    :linenos:

Der Destruktor wird bei der Zerstörung eines Objekts der ``Element`` Klasse aufgerufen.


.. _elementSelect:

virtual bool select () = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Die Funktion wird aufgerufen, wenn ein ``Element`` berührt wird.
Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`Button <buttonselect>`, :ref:`NumberInput <numberinputselect>`, :ref:`Textbox <textboxselect>`)

.. _elementLoopInput:

virtual void loop(Inputs& input) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Die Funktion wird bei jedem Update aufgerufen.
Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`Button <buttonloopinput>`", ":ref:`NumberInput <numberinputloopinputs>`", ":ref:`Textbox <textboxloopinput>`")


.. _elementDraw:

virtual void draw () = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Die Funktion zeichnet das Element.
Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`Button_Round <roundbuttondraw>`, :ref:`Button_Rect <rectbuttondraw>`, :ref:`Button_Blank <buttonblankdraw>`, :ref:`Textbox_Blank <textboxblankdraw>`,  
:ref:`Textbox_Rect <textbox_rectdraw>`,  :ref:`Number_Counter <number_counterdraw>`,  :ref:`Number_Slider <number_sliderdraw>`)

.. _elementSetTouch:

virtual void setTouch(Inputs& input) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`Button <buttonsettouch>`", ":ref:`NumberInput <numberinputsettouch>`", ":ref:`Textbox <textboxsettouch>`")

.. _elementSetSize:

bool setSize(const uint16_t sizeX, const uint16_t sizeY, const uint8_t rotation = 0)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Element.cpp
    :lines: 9-17
    :linenos:

Die Funktion gibt aus, ob das Element zeichenbar ist oder nicht. Gibt sie "true" zurück lässt sich das Element zeichnen, bei "false" ist das Element zu groß bzw. zu klein zum zeichnen. 
Hierbei wird zuerst :ref:`checkSize <elementchecksize>` ausgeführt. Gibt dieser Funktionsaufruf "false" zurück, so gibt auch die ``setSize`` Funktion false zurück und das Element ist nicht zeichenbar.
Andernfalls erfolgt die Zuweisung der Werte der Parameter ``posX``, ``posY`` und ``rotation`` zu den entsprechenden Membervariablen des aktuellen Objektes. Danach gibt die Funktion ``true`` zurück, das Element lässt sich zeichnen.

.. _elementSetDisplay:

void setDisplay(Display* const dis)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Element.cpp
    :lines: 19-21
    :linenos:

Diese Funktion weist :ref:`display <elementvdisplay>` des aktuellen ``Element`` Objekts den Wert des übergebenen ``disp`` zu.
Diese Funktion sollte vor allen anderen Funktionen zuerst aufgerufen werden, um einen reibungslosen Ablauf zu gewährleisten.

.. _elementCheckSize:

virtual bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe  :ref:`Button_Round <roundbuttonchecksize>`, :ref:`Button_Rect <rectbuttonchecksize>`, :ref:`Button_Blank <buttonblankchecksize>`, :ref:`Number_Counter <number_counterchecksize>`, :ref:`Number_Slider <number_sliderchecksize>`)

.. _elementSetPosition:

void setPosition(const uint16_t posX, const uint16_t posY);
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Element.cpp
    :lines: 4-7
    :linenos:

Diese Funktion legt die Position des ``Element`` Objektes auf dem Display fest. Dafür erfolgt die Zuweisung der Werte der Parameter ``posX`` und ``posY`` zu den entsprechenden Membervariablen des aktuellen Objektes.


Variablen und Konstanten Beschreibung
=====================================
.. _elementVPosX:

uint16_t posX
~~~~~~~~~~~~~~

Gibt die X-Koordinate (in Pixeln) eines ``Element`` Objektes an.

.. _elementVPosY:

uint16_t posY
~~~~~~~~~~~~~~

Gibt die Y-Koordinate (in Pixeln) eines ``Element`` Objektes an.

.. _elementVSizeX:

uint16_t sizeX
~~~~~~~~~~~~~~

Gibt die Höhe eines ``Element`` Objektes an, bzw. die Größe des Objektes in X-Richtung (in Pixeln).

.. _elementVSizeY:

uint16_t sizeY
~~~~~~~~~~~~~~

Gibt die Breite eines ``Element`` Objektes an, bzw. die Größe des Objektes in Y-Richtung (in Pixeln).

.. _elementVRotation:

uint8_t rotation
~~~~~~~~~~~~~~~~~~

Gibt an, ob das Element hochkant oder seitwärts dargestellt werden soll. Rotation kann die Werte von 0 bis 3 annehmen, da es je zwei mögliche Darstellungsformen vom Hoch- und Querformat gibt ("normal" und auf dem Kopf).

.. _elementVDisplay:

Display* display
~~~~~~~~~~~~~~~~~~

Ein Pointer auf ein :ref:`Display <display>` Objekt. Auf ``display`` lassen sich neben einem konkreten ``Screen`` auch diverse ":ref:`Elemente<element>`" zeichnen bzw. anzeigen. 
Somit ist ``display`` von großer Wichtigkeit für das gesamte Projekt.