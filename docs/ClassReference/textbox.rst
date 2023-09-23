.. _textbox:

Textbox
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

    void, ":ref:`loop <textboxloopinput>` (Inputs& input) override"
    void, ":ref:`setTouch <textboxsettouch>` (uint16_t x, uint16_t y) override"
    , ":ref:`Textbox <textboxconstructor>` (Item* item, ExternalTextboxValue* value = nullptr)"
    , ":ref:`Textbox <textboxconstructortextsize>` (Item* item, const uint8_t textsize, ExternalTextboxValue* value = nullptr)"
    virtual bool, ":ref:`checkSize <textboxchecksize>` (uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override"
    virtual, ":ref:`~Textbox <textboxdestructor>` ()"
    bool, ":ref:`select <textboxselect>` () override"

Variablen und Konstanten
==========================


.. csv-table:: 
    :widths: 100 10000

    const, ":ref:`colorInfillbotOn <textboxvtext>`"

Funktionen Beschreibung
=========================

.. _textboxLoopInput:

void loop(Inputs& input) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 16
    :linenos:

.. _textboxSetTouch:

void setTouch(uint16_t x, uint16_t y) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 18
    :linenos:

.. _textboxConstructor:

Textbox(Item* item, ExternalTextboxValue* value = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 4-5
    :linenos:


.. _textboxConstructortextsize:

Textbox(Item* item, const uint8_t textsize, ExternalTextboxValue* value = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _textboxchecksize:


virtual bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _textboxDestructor:

virtual ~Textbox()
~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 7
    :linenos:

.. _textboxSelect:


bool select() override
~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 9-11
    :linenos:

Variablen und Konstanten Beschreibung
=====================================

.. _textboxvitem:

Item* item = nullptr
~~~~~~~~~~~~~~~~~~~~~~~

.. _textboxvexternalvalue:

ExternalTextboxValue* externalValue = nullptr
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
