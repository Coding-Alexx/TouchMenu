.. _button:

Button
++++++++

Beschreibung
=============
| Buttons sind :ref:`Elemente <element>`, bei denen ein einmaliger Input zum Ausführen einer bestimmten Aktivität führt.
| Vom Button erben folgende Klassen: 

* :ref:`roundButton <roundbutton>`

Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============


.. csv-table:: 
    :widths: 100 1000

    , ":ref:`Button <buttonButton>` (std::function<void()> button_callback, ExternalButtonValue* externalValue)"
    , ":ref:`Button <buttonbuttonlongpress>` (std::function<void()> button_callback, std::function<void()> longpress_callback, ExternalButtonValue* externalValue)"
    , ":ref:`Button <buttonSwitch>` (std::function<void(bool)> swich_callback, ExternalButtonValue* externalValue)"
    , ":ref:`Button <buttonSwitchlongpress>` (std::function<void(bool)> swich_callback, std::function<void()> longpress_callback, ExternalButtonValue* externalValue)"
    , ":ref:`Button <buttonconstructoreverything>` (std::function<void()> button_callback, std::function<void(bool)> swich_callback, std::function<void()> longpress_callback, const bool isButton, const bool hasLongPress, ExternalButtonValue* externalValue)"
    virtual, ":ref:`~Button <buttondestructor>` ()"
    void, ":ref:`loop<buttonLoopInput>` (Inputs& input)"
    bool, ":ref:`select<buttonSelect>` ()"
    void, ":ref:`getTouch<buttonsettouch>` (uint16_t x, uint16_t y)"
    bool, ":ref:`getValue<buttongetvalue>` ()"
    bool, ":ref:`isInsideHitbox<buttonisinsidehitbox>` (uint16_t x, uint16_t y, uint16_t posX, uint16_t posY, uint16_t sizeX, uint16_t sizeY)"
    


Variablen und Konstanten
==========================


.. csv-table:: 
    :widths: 100 10000

     const std::function<void()>, ":ref:`button_callback <buttonvbuttoncallback>` = [](){}"
     const std::function<void(bool)>, ":ref:`switch_callback <buttonvswitchcallback>` = [](bool){}"
     const std::function<void()>, ":ref:`longpress_callback <buttonvlongpresscallback>` = [](){}"
     ":ref:`ExternalButtonValue<externalbuttonvalue>`", ":ref:`externalValue <buttonvexternalvalue>` = nullptr"
     const bool, ":ref:`isButton<buttonvisbutton>`"
     const bool, ":ref:`hasLongPress<buttonvhaslongpress>` = false"
     bool, ":ref:`value<buttonvvalue>` = false"
     bool, ":ref:`blocked<buttonvblocked>` = false"
     unsigned long, ":ref:`animationTimer<buttonvanimationtimer>` = 0"
     unsigned long, ":ref:`longPressTimer<buttonvlongpresstimer>` = 0"
     


Makros
=============

.. csv-table:: 
    :widths: 100 10000

     const button_func_ptr, ":ref:`button_callback <buttonvbuttoncallback>`"

Funktionen Beschreibung
=========================

.. _buttonButton:

Button(std::function<void()> button_callback, ExternalButtonValue* externalValue = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 4-11
    :linenos:
 
ÜBERARBEITEN

Diese Funktion ist ein Konstruktor für ein Objekt der Klasse ``Button``, welcher Buttons erzeugt. Als Parameter nimmt der Konstruktor eine Button Callback Funktion 
(siehe ":ref:`button_callback <buttonvbuttoncallback>`") und ein ``externalValue``, welches den Zustand des Objektes angibt (also ob es aktiviert oder deaktiviert ist)
In der Initialisierungsliste werden ":ref:`button_callback<buttonvbuttoncallback>`" und ":ref:`externalValue<buttonvexternalvalue>`" mit den entsprechenden Parametern initialisiert. 
Hingegen wird ":ref:`switch_callback<buttonvswitchcallback>`" mit mit dem Null Pointer ``nullptr`` initialisiert, da dieser Konstruktor keinen Switch konstruieren soll.
Es wird geprüft, ob ``externalValue`` ``null`` ist. Ist dem nicht so, wird in ":ref:`value<buttonvvalue>`" der Wert von ``externalValue`` gespeichert. 
Andernfalls wird ein neuer ``bool`` erzeugt und ":ref:`externalValue<buttonvexternalvalue>`" wird auf diesen Wert gesetzt. 
Das wird getan, um zu verhindern, dass ":ref:`externalValue<buttonvexternalvalue>`" ``null`` ist.


.. _buttonButtonLongPress:

Button(std::function<void()> button_callback, std::function<void()> longpress_callback, ExternalButtonValue* externalValue = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _buttonSwitch:

Button(std::function<void(bool)> swich_callback, ExternalButtonValue* externalValue = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 13-20
    :linenos:

ÜBERARBEITEN

Diese Funktion ist ein Konstruktor für ein Objekt der Klasse ``Button``, welcher Switches erzeugt. Als Parameter nimmt der Konstruktor eine Switch Callback Funktion 
(siehe ":ref:`switch_callback <buttonvswitchcallback>`") und ein ``externalValue``, welches den Zustand des Objektes angibt (also ob es aktiviert oder deaktiviert ist)
In der Initialisierungsliste werden ":ref:`switch_callback<buttonvswitchcallback>`" und ":ref:`externalValue<buttonvexternalvalue>`" mit den entsprechenden Parametern initialisiert. 
Hingegen wird ":ref:`button_callback<buttonvbuttoncallback>`" mit mit dem Null Pointer ``nullptr`` initialisiert, da dieser Konstruktor keinen Button konstruieren soll.
Es wird geprüft, ob ``externalValue`` ``null`` ist. Ist dem nicht so, wird in ":ref:`value<buttonvvalue>`" der Wert von ``externalValue`` gespeichert. 
Andernfalls wird ein neuer ``bool`` erzeugt und ":ref:`externalValue<buttonvexternalvalue>`" wird auf diesen Wert gesetzt. 
Das wird getan, um zu verhindern, dass ":ref:`externalValue<buttonvexternalvalue>`" ``null`` ist.


.. _buttonSwitchLongPress:

Button(std::function<void(bool)> swich_callback, std::function<void()> longpress_callback, ExternalButtonValue* externalValue = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


.. _buttonconstructorEverything:

Button(std::function<void()> button_callback, std::function<void(bool)> swich_callback, std::function<void()> longpress_callback, const bool isButton, const bool hasLongPress, ExternalButtonValue* externalValue = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _buttonDestructor:

virtual ~Button()
~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Button.cpp
    :lines: 25
    :linenos:

Der Destruktor wird bei der Zerstörung eines ``Button`` Objektes aufgerufen.

.. _buttonLoopInput:

void loop(Inputs& input)
~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 58-63
    :linenos:

TODO

.. _buttonSelect:

bool select ()
~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 27-37
    :linenos:

Diese Funktion ist für den Aufruf der entsprechenden Callback Funktionen von Objekten der ``Button`` Klasse zuständig, wenn diese ihren Zustand ändern.

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 28-30

Sollte das aktuelle Objekt ein Button (und kein Switch) sein, so wird ":ref:`value<buttonvvalue>`" auf true gesetzt, wodurch der Button in seinen aktivierten Zustand übergehen soll.
Danach erfolgt ein Funktionsaufruf der ":ref:`button_callback<buttonvbuttoncallback>`" Funktion.

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 32-35

Andernfalls handelt es sich bei dem Objekt um einen Switch, so wird der in ":ref:`value<buttonvvalue>`" gespeicherte Zustand auf den anderen Zustand gewechselt.
Danach erfolgt ein Funktionsaufruf der ":ref:`switch_callback<buttonvswitchcallback>`" Funktion mit dem ":ref:`value<buttonvvalue>`".


.. _buttonSetTouch:

void setTouch(uint16_t x, uint16_t y)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 68-79
    :linenos:

Diese Funktion verarbeitet Toucheingaben auf das ":ref:`Display<display>`", um den Zustand von Objekten der ``Button`` Klasse zu ändern.

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 70

Dafür wird zuerst der ":ref:`value<buttonvvalue>`" auf den entgegengesetzten Wert gewechselt, um die Zustandsänderung vom aktivierten 
in den deaktivierten bzw. deaktivierten in den aktivierten Zustand des Objekts zu vollziehen.

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 71-74

Bei einem Button (kein Switch) wird bei ``value==true`` zudem die ":ref:`button_callback<buttonvbuttoncallback>`" Funktion aufgerufen, damit die mit dem Button verknüpften Aktionen durchgeführt werden.
Außerdem wird im ":ref:`timer<buttonvtimer>`" gespeichert, wie viele Millisekunden seit Start vergangen sind (siehe `millis() <https://www.arduino.cc/reference/en/language/functions/time/millis/>`_ ).     

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 76-78

Bei einem Switch hingegen wird die ":ref:`switch_callback<buttonvswitchcallback>`" Funktion mit dem ":ref:`value<buttonvvalue>`" aufgerufen. Anschließend werden die sich durch die neuen
Zustände ergebenen Änderungen mit ":ref:`draw<elementdraw>`" gezeichnet. 

.. _buttonGetValue:

bool getValue()
~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Button.h
    :lines: 25
    :linenos:

Gibt den ":ref:`value<buttonvvalue>`" des aktuellen Objektes zurück. 

.. _buttonisinsidehitbox:

bool isInsideHitbox(uint16_t x, uint16_t y, uint16_t posX, uint16_t posY, uint16_t sizeX, uint16_t sizeY)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Variablen und Konstanten Beschreibung
=====================================

.. _buttonVbuttoncallback:

const std::function<void()> button_callback = [](){}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TODO

.. _buttonVSwitchCallback:

const std::function<void(bool)> switch_callback = [](bool){}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TODO

.. _buttonVLongpressCallback:

const std::function<void()> longpress_callback = [](){};
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TODO

.. _buttonVValue:

bool value = false;
~~~~~~~~~~~~~~~~~~~~~~

Speichert den aktuellen Zustand des Buttons bzw. Switches. Standardmäßig befinden sie sich in einem deaktivierten Zustand.

.. _buttonVExternalValue:

ExternalButtonValue* externalValue = nullptr
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Ermöglicht eine externe Steuerung des Zustands des Buttons bzw. Switches, indem es auf einen bool-Wert zeigt, die den gewünschten Zustand repräsentiert.
TODO ÜBERARBEITEN?


.. _buttonVisButton:

const bool isButton
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _buttonVhaslongpress:

const bool hasLongPress = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _buttonVblocked:

bool blocked = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _buttonVanimationtimer:

unsigned long animationTimer = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _buttonVlongpresstimer:

unsigned long longPressTimer = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Makros Beschreibung
====================

.. _buttonMTML_goTo:

TML_goTo (tml, id) [](){tml.goTo(id);}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _buttonMTML_goTo_without_History:

TML_goTo_without_History (tml, id) [](){tml.goTo(id, false);}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _buttonMTML_back:

TML_back (tml) [](){tml.back();}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _buttonMTML_empty_button:

TML_empty_button [](){}
~~~~~~~~~~~~~~~~~~~~~~~~~

.. _buttonMTML_empty_switch:

TML_empty_switch [](bool){}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _buttonMBButton_On_Time:

BUTTON_ON_TIME 400
~~~~~~~~~~~~~~~~~~~~~~

.. _buttonMButton_Long_Time:

BUTTON_LONG_TIME 500
~~~~~~~~~~~~~~~~~~~~~~~~~

