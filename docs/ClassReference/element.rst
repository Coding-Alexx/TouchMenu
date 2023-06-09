.. _element:

Elements
++++++++++

Beschreibung
=============
| Elemente sind vordefinierte Funktionseinheiten, die auf einem :ref:`Screen <screen>` eingefügt werden können.
| Dazu gehören 
* :ref:`Buttons <button>`
* :ref:`Slider <slider>`

Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============
relevant für eigenes Menü

.. csv-table:: 
    :widths: 100 1000

     void, ":ref:`setPosition <elementsetpostion>` (const uint16_t posX, const uint16_t posY)"
     bool, ":ref:`setsize <elementsetsize>` (const uint16_t sizeX, const uint16_t sizeY, const uint8_t rotation)"
     void, ":ref:`setDisplay <elementsetdisplay>` (Display* const display)"



sonstige 

.. csv-table:: 
    :widths: 100 1000

    , :ref:`Element <elementelementconstructor>` ()
    virtual, :ref:`~Element <elementelementdenstructor>` ()
    virtual bool, :ref:`select <elementselect>` () = 0
    virtual void, ":ref:`loop <elementloop>` (uint16_t touchX, uint16_t touchY) = 0"
    virtual void, ":ref:`draw <elementdraw>` () = 0"
    virtual void, ":ref:`checkSize <elementchecksize>` (uint16_t sizeX, uint16_t sizeY, uint8_t rotation) = 0"

Funktionen Beschreibung
=========================


.. _elementElementConstructor:

Element ()
~~~~~~~~~~~~


.. _elementElementDenstructor:

virtual ~Element ()
~~~~~~~~~~~~~~~~~~~~~



.. _elementSelect:

virtual bool select () = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~


.. _elementLoop:

virtual void loop (uint16_t touchX, uint16_t touchY) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


.. _elementDraw:

virtual void draw () = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~


.. _elementSetPostion:

void setPosition (const uint16_t posX, const uint16_t posY)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Element.cpp
    :lines: 4-7
    :linenos:
    
Die x und y Koordinaten des Elements auf dem Bildschirm werden festgelegt.  

.. _elementSetSize:

bool setSize (const uint16_t sizeX, const uint16_t sizeY, const uint8_t rotation)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Element.cpp
    :lines: 9-17
    :linenos:

Die Funktion gibt aus, ob das Element zeichenbar ist oder nicht. Gibt sie "true" zurück lässt sich das Element zeichnen, bei "false" ist das Element zu groß bzw. zu klein zum zeichnen. 
Hierbei wird zuerst :ref:`checkSize <elementchecksize>` ausgeführt.

TODO Continue

.. _elementSetDisplay:

void setDisplay (Display* const display)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Element.cpp
    :lines: 19-21
    :linenos:

.. _elementCheckSize:

virtual bool checkSize (uint16_t sizeX, uint16_t sizeY, uint8_t rotation) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
