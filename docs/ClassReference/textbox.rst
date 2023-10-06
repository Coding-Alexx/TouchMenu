.. _textbox:

Textbox
++++++++++++++

Beschreibung
=============

Diese Klasse dient dazu, Umrandungen um :ref:`Elemente<element>` zu ziehen.
Von dieser Klasse erben :ref:`Textbox_blank<textboxblank>` und :ref:`Textbox_rect<textbox_rect>`. 


Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    , ":ref:`Textbox <textboxconstructor>` (Item* item, ExternalTextboxValue* value = nullptr)"
    , ":ref:`Textbox <textboxconstructortextsize>` (Item* item, const uint8_t textsize, ExternalTextboxValue* value = nullptr)"
    void, ":ref:`loop <textboxloopinput>` (Inputs& input) override"
    void, ":ref:`setTouch <textboxsettouch>` (uint16_t x, uint16_t y) override"
    virtual bool, ":ref:`checkSize <textboxchecksize>` (uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override"
    virtual, ":ref:`~Textbox <textboxdestructor>` ()"
    bool, ":ref:`select <textboxselect>` (Inputs& input) override"

Variablen und Konstanten
==========================


.. csv-table:: 
    :widths: 100 10000

    ":ref:`Item* <item>`", ":ref:`item <textboxvitem>` = nullptr"
     ":ref:`ExternalTextboxValue* <externaltextboxvalue>`", ":ref:`externalValue <textboxvexternalvalue>`"

Funktionen Beschreibung
=========================

.. _textboxConstructor:

Textbox(Item* item, ExternalTextboxValue* value = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Textbox.cpp
    :lines: 4-5
    :linenos:

Diese Funktion ist ein Konstruktor für ein Objekt der Klasse ``Textbox``. Als Parameter nimmt der Konstruktor ein :ref:`Item<item>` (``item``) und einen 
:ref:`ExternalTextboxValue*<externaltextboxvalue>` (``value``), der den Zustand des Objekts angibt. 


.. _textboxConstructortextsize:

Textbox(Item* item, const uint8_t textsize, ExternalTextboxValue* value = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Textbox.cpp
    :lines: 7-11
    :linenos:

Diese Funktion ist ein Konstruktor für ein Objekt der Klasse ``Textbox``. Als Parameter nimmt der Konstruktor ein :ref:`Item<item>` (``item``), die Größe, die der 
anzuzeigende Text innerhalb der Textbox haben soll (``textsize``) und einen :ref:`ExternalTextboxValue*<externaltextboxvalue>` (``value``), der den Zustand des Objekts angibt. 

In der Initialisierungsliste werden :ref:`item<textboxvitem>` und :ref:`externalValue<textboxvexternalvalue>` mit den entsprechenden Parametern initialisiert.
In der Initialisierungsliste werden :ref:`item<textboxvitem>` und :ref:`externalValue<textboxvexternalvalue>` mit den entsprechenden Parametern initialisiert.
Wenn :ref:`externalValue<textboxvexternalvalue>` einen gültigen Wert hat, wird die :ref:`setup<externaltextboxvaluesetuptextsize>` Funktion mit ``textsize`` als Argument aufgerufen.
Anschließend wird :ref:`setSize<itemsetsize>` Funktion mit ``textsize`` als Argument aufgerufen.



.. _textboxLoopInput:

void loop(Inputs& input) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.cpp
    :lines: 22-27
    :linenos:

Diese Funktion dient dazu, den Zustand des aktuellen Objektes zu aktualisieren.
Wenn :ref:`externalValue <textboxvexternalvalue>` nicht ``nullptr`` ist und Änderungen besitzt, die gezeichnet werden sollen (:ref:`hasUpdate <externaltextboxvaluehasupdate>`),
soll das Objekt mit der entsprechenden :ref:`draw <elementdraw>` Funktion neu gezeichnet. Die Änderungen wurden getätigt, daher wird :ref:`resetUpdate <externaltextboxvalueresetupdate>` auf 
:ref:`externalValue <textboxvexternalvalue>` aufgerufen.


.. _textboxSetTouch:

void setTouch(uint16_t x, uint16_t y) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Textbox.cpp
    :lines: 29
    :linenos:

Bei der Berührung des Objektes passiert nicht, da es sich bei Objekten der ``Textbox`` Klasse um rein optische Elemente handelt ohne Interaktionsmöglichkeiten mit dem Benutzer.

.. _textboxchecksize:

virtual bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.cpp
    :lines: 31-35
    :linenos:

Diese Funktion überprüft, ob Objekte der ``Textbox`` Klasse zeichenbar sind, oder ob sie zu groß bzw. zu klein sind, um sie anzuzeigen.
Die Parameter der Funktion sind die Höhe (``sizeY``) und Breite des Objektes (``sizeX``).
Zuerst wird geprüft, ob :ref:`externalValue<textboxvexternalvalue>` einen gültigen Wert hat und ob der Aufruf von :ref:`getSize<externaltextboxvaluegetsize>` den Wert ``0`` ausgibt. 
Wenn ja, wird die :ref:`setup<externaltextboxvaluesetupxy>` des :ref:`externalValue<textboxvexternalvalue>` mit ``sizeX`` und ``sizeY`` als Argument aufgerufen.
Anschließend wird die :ref:`setResolution<itemsetresolution>` des :ref:`item<buttonblankvitem>` aufgerufen, um zu bestimmen, wie groß ``item`` auf dem Button angezeigt werden wird.

.. _textboxDestructor:

virtual ~Textbox()
~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Textbox.cpp
    :lines: 13
    :linenos:

Der Destruktor wird bei der Zersörung eines ``textbox`` Objektes aufgerufen.


.. _textboxSelect:

bool select(Inputs& input) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.cpp
    :lines: 15-17
    :linenos:

Gibt ``false`` zurück, da Objekte der ``Textbox`` Klasse rein optische Element sind, die nicht durch den Input eines Benutzers auf den Bildschirm beeinflusst werden.


Variablen und Konstanten Beschreibung
=====================================

.. _textboxvitem:

Item* item = nullptr
~~~~~~~~~~~~~~~~~~~~~~~

Das :ref:`Item<item>`, welches in der Textbox angezeigt weren soll.

.. _textboxvexternalvalue:

ExternalTextboxValue* externalValue = nullptr
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Ermöglicht eine externe Steuerung von ``Textbox`` Objekten.

