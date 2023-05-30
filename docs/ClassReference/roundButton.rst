RoundButton
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

    , ":ref:`RoundButton <roundbuttonroundbuttonbutton>` (const Color& infill, const Color& border, const button_func_ptr button_callback)"
    , ":ref:`RoundButton <roundbuttonroundbuttonswitch>` (const Color& infill, const Color& border, const switch_func_ptr switch_callback)"
    void , ":ref:`loop <roundbuttonloop>` (uint16_t touchX, uint16_t touchY)"
    void , ":ref:`draw <roundbuttonloop>` ()"
    bool , ":ref:`checkSize <roundbuttonloop>` (uint16_t sizeX, uint16_t sizeY, uint8_t rotation)"


Funktionen Beschreibung
=========================

.. _roundButtonRoundButtonButton:

RoundButton (const Color& infill, const Color& border, const button_func_ptr button_callback)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/RoundButton.cpp
    :lines: 3-7
    :linenos:


.. _roundButtonRoundButtonSwitch:

RoundButton (const Color& infill, const Color& border, const switch_func_ptr switch_callback)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/ElementViews/RoundButton.cpp
    :lines: 9-13
    :linenos:

.. _roundButtonloop:

void loop (uint16_t touchX, uint16_t touchY) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _roundButtondraw:

void draw () override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _roundButtonchecksize:


bool checkSize (uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
