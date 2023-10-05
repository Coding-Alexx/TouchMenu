.. _button:

Button
++++++++

Beschreibung
=============
Buttons sind :ref:`Elemente <element>`, bei denen ein einmaliger Input zum Ausführen einer bestimmten Aktivität führt.
Vom Button erben die Klassen :ref:`Button_Blank<button_blank>`, :ref:`Button_Rect<rectbutton>` und :ref:`Button_Round<roundbutton>`. Objekte dieser Klasse können in zwei 
verschiedenen Varianten erstellt werden: als Button oder als Switch. Dabei sind Buttons Objekte der ``Button`` Klasse, die beim Drücken ihr Aussehen bzw. nur kurz ändern oder durch
durch Drücken andere :ref:`Screens<Screen>` aufrufen können. Switches sind Objekte der ``Button`` Klasse, die nach Betätigung ihr Aussehen und Zustand so lange verändern, bis erneut auf dieses Objekt
gedrückt wird. 



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
    void, ":ref:`setTouch<buttonsettouch>` (Inputs& input) override"
    bool, ":ref:`getValue<buttongetvalue>` () const"
    bool, ":ref:`isInsideHitbox<buttonisinsidehitbox>` (uint16_t x, uint16_t y, uint16_t posX, uint16_t posY, uint16_t sizeX, uint16_t sizeY)"
    


Variablen und Konstanten
==========================


.. csv-table:: 
    :widths: 100 10000

     const std::function<void()>, ":ref:`button_callback <buttonbuttoncallback>` = [](){}"
     const std::function<void(bool)>, ":ref:`switch_callback <buttonswitchcallback>` = [](bool){}"
     const std::function<void()>, ":ref:`longpress_callback <buttonlongpresscallback>` = [](){}"
     ":ref:`ExternalButtonValue<externalbuttonvalue>`", ":ref:`externalValue <buttonvexternalvalue>` = nullptr"
     const bool, ":ref:`isButton<buttonvisbutton>`"
     const bool, ":ref:`hasLongPress<buttonvhaslongpress>` = false"
     bool, ":ref:`value<buttonvvalue>` = false"
     bool, ":ref:`blocked<buttonvblocked>` = false"
     bool, ":ref:`hasButtonAnimation<buttonvhasbuttonanimation>` = true"
     unsigned long, ":ref:`animationTimer<buttonvanimationtimer>` = 0"
     unsigned long, ":ref:`longPressTimer<buttonvlongpresstimer>` = 0"
     


Makros
=============

.. csv-table:: 
    :widths: 100 10000

    , ":ref:`TML_goTo <buttonmtml_goto>`"
    , ":ref:`TML_goTo_without_History <buttonmtml_goto_without_history>`"
    , ":ref:`TML_back <buttonmtml_back>`"
    , ":ref:`TML_empty_button <buttonmtml_empty_button>`"
    , ":ref:`TML_empty_switch <buttonmtml_empty_switch>`"
    , ":ref:`BUTTON_ON_TIME <buttonmbbutton_on_time>`"
    , ":ref:`BUTTON_LONG_TIME <buttonmbutton_long_time>`"

Funktionen Beschreibung
=========================

.. _buttonButton:

Button(std::function<void()> button_callback, ExternalButtonValue* externalValue = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 3-8
    :linenos:


Diese Funktion ist ein Konstruktor für ein Objekt der Klasse ``Button``, welcher Buttons erzeugt. Als Parameter nimmt der Konstruktor eine Button Callback Funktion 
(siehe :ref:`button_callback <buttonbuttoncallback>`) und ein ``externalValue``, welches den Zustand des Objektes angibt (also ob es aktiviert oder deaktiviert ist).

In der Initialisierungsliste werden :ref:`button_callback<buttonbuttoncallback>` und :ref:`externalValue<buttonvexternalvalue>` mit den entsprechenden Parametern initialisiert. 
Außerdem werden sowohl :ref:`isButton<buttonvisbutton>` und :ref:`value<buttonvvalue>` mit ``true`` initialisiert, weil das Objekt ein Button und kein Switch ist und standarmäßig aktiviert sein soll, sollte kein 
:ref:`externalValue<buttonvexternalvalue>` vorliegen.


.. _buttonButtonLongPress:

Button(std::function<void()> button_callback, std::function<void()> longpress_callback, ExternalButtonValue* externalValue = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 10-17
    :linenos:

Diese Funktion ist ein Konstruktor für ein Objekt der Klasse ``Button``, welcher Buttons erzeugt. Als Parameter nimmt der Konstruktor eine Button Callback Funktion 
(siehe :ref:`button_callback<buttonbuttoncallback>`), eine Longpress Callback Funktion (siehe :ref:`longpress_callback<buttonlongpresscallback>`) und ein 
``externalValue``, welches den Zustand des Objektes angibt (also ob es aktiviert oder deaktiviert ist).

In der Initialisierungsliste werden :ref:`button_callback<buttonbuttoncallback>`, `longpress_callback<buttonlongpresscallback>` und :ref:`externalValue<buttonvexternalvalue>` 
mit den entsprechenden Parametern initialisiert. 
Außerdem werden sowohl :ref:`isButton<buttonvisbutton>`, :ref:`hasLongPress<buttonvhaslongpress>` und :ref:`value<buttonvvalue>` mit ``true`` initialisiert, weil das Objekt ein Button und kein Switch ist, beim gedrückhalten eine Aktion ausführen soll 
und standarmäßig aktiviert sein soll, sollte kein :ref:`externalValue<buttonvexternalvalue>` vorliegen.


.. _buttonSwitch:

Button(std::function<void(bool)> swich_callback, ExternalButtonValue* externalValue = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 19-23
    :linenos:

Diese Funktion ist ein Konstruktor für ein Objekt der Klasse ``Button``, welcher Switches erzeugt. Als Parameter nimmt der Konstruktor eine Switch Callback Funktion 
(siehe :ref:`switch_callback <buttonswitchcallback>`) und ein ``externalValue``, welches den Zustand des Objektes angibt (also ob es aktiviert oder deaktiviert ist).

In der Initialisierungsliste werden :ref:`switch_callback<buttonswitchcallback>` und :ref:`externalValue<buttonvexternalvalue>` mit den entsprechenden Parametern initialisiert. 
Außerdem wird :ref:`isButton<buttonvisbutton>` mit ``false`` initialisiert, weil das Objekt ein Switch und kein Button ist.

.. _buttonSwitchLongPress:

Button(std::function<void(bool)> swich_callback, std::function<void()> longpress_callback, ExternalButtonValue* externalValue = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 25-31
    :linenos:

Diese Funktion ist ein Konstruktor für ein Objekt der Klasse ``Button``, welcher Switches erzeugt. Als Parameter nimmt der Konstruktor eine SwitchCallback Funktion 
(siehe :ref:`switch_callback<buttonswitchcallback>`), eine Longpress Callback Funktion (siehe :ref:`longpress_callback<buttonlongpresscallback>`) und ein 
``externalValue``, welches den Zustand des Objektes angibt (also ob es aktiviert oder deaktiviert ist).

In der Initialisierungsliste werden :ref:`switch_callback<buttonswitchcallback>`, `longpress_callback<buttonlongpresscallback>` und :ref:`externalValue<buttonvexternalvalue>` 
mit den entsprechenden Parametern initialisiert. 
Außerdem wird  :ref:`isButton<buttonvisbutton>` mit ``false`` initialisiert, weil das Objekt ein Switch und kein Button ist und :ref:`hasLongPress<buttonvhaslongpress>` mit ``true``, da das
beim gedrückhalten eine Aktion ausführen soll.

.. _buttonconstructorEverything:

Button(std::function<void()> button_callback, std::function<void(bool)> swich_callback, std::function<void()> longpress_callback, const bool isButton, const bool hasLongPress, ExternalButtonValue* externalValue = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 33-40
    :linenos:

Dieser Konstruktor unterscheidet sich von den anderen vier Konstruktoren der Klasse, da hier jede einzelne Variable per Hand festgelegt werden kann. 
Dies ermöglicht die unterschiedlichsten Objekte zu erstellen, um individuelle Bedürfnisse bei der Funktionsweise von Objekten der ``Button`` Klasse` zu erfüllen.

.. _buttonDestructor:

virtual ~Button()
~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Button.cpp
    :lines: 42
    :linenos:

Der Destruktor wird bei der Zerstörung eines ``Button`` Objektes aufgerufen.

.. _buttonLoopInput:

void loop(Inputs& input)
~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 58-63
    :linenos:

Diese Funktion dient dazu, den Zustand eines Buttons bzw. Switches zu aktualisieren, um auf Benuzereingaben zu reagieren.

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 68-71

Sollte der als Argument übergebene :ref:`Input<input>` ``input.enter==true`` gelten, so wird mit ``input`` die :ref:`setTouch<buttonsettouch>` Funktion aufgerufen.

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 73-79

Sollte :ref:`externalValue<buttonvexternalvalue>` nicht ``null`` sein und sollte der darin gespeicherte Wert nicht dem :ref:`value<buttonvvalue>` entsprechen, so übernimmt
:ref:`value<buttonvvalue>` die Referenz auf den Wert von :ref:`externalValue<buttonvexternalvalue>`. Anschließend wird das Objekt mit :ref:`draw<elementdraw>` gezeichnet.
Sollte das aktuelle Objekt ein Button (und kein Switch) sein und sollte zusätzlich :ref:`value<buttonvvalue>` nicht ``null`` sein, so wird :ref:`animationTimer<buttonvanimationtimer>` mit neuen Zeitangaben 
aktualisiert. Er speichert wie viele Millisekunden seit Start vergangen sind (siehe `millis() <https://www.arduino.cc/reference/en/language/functions/time/millis/>`_ ).

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 81-88

Sollte der :ref:`animationTimer<buttonvanimationtimer>` eines Buttons (keines Switches) im vorherigen Codeabschnitt aktualisiert worden sein und seitdem mehr Millisekunden vergangen sein, als in 
:ref:`BUTTON_ON_TIME<buttonmbbutton_on_time>`, so wird der :ref:`animationTimer<buttonvanimationtimer>` wieder zurückgesetzt und, sollte dies nicht schon der Fall sein, :ref:`value<buttonvvalue>` auf ``true`` gesetzt,
um den Button wieder in seinem aktivierten Zustand mit :ref:`draw<elementdraw>` zu zeichnen.

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 91-95

Sollten Änderungen durch den :ref:`externalValue<buttonvexternalvalue>` vorgenommen worden sein (:ref:`hasUpdate<externalbuttonhasupdate>`), so werden diese Änderungen mit 
:ref:`draw<elementdraw>` gezeichnet und :ref:`resetUpdate<externalbuttonresetupdate>` aufgerufen.

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 98-99

Sollte das Objekt nicht länger berührt werden, aber weiterhin ``blocked==true`` sein, so wird :ref:`blocked<buttonvblocked>` wieder auf ``false`` gesetzt, um den Button 
wieder freizusetzen.   

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 102-106

Dieser Codeabschnitt testet, ob das Objekt lange drückbar ist und lang genug gedrückt wurde, bereit ist und auch innerhalb der Grenzen des Buttons gedrückt wurde (:ref:`isInsideHitbox<buttonisinsidehitbox>`).
Wenn dies der Fall ist, wird der :ref:`longPressTimer<buttonvlongpresstimer>` zurückgesetzt und die :ref:`longpress_callback<buttonlongpresscallback>` Funktion aufgerufen.

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 102-106

Wenn der Touchpoint allerdings nicht mehr innerhalb der Grenzen des Objektes liegt, wird der :ref:`longPressTimer<buttonvlongpresstimer>` zurückgesetzt ohne die Callback Funktion aufzurufen.
Der Prozess wurde vom Benutzer abgebrochen.     

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 114-119

Drückt der Nutzer hingegen nicht kontinuierlich auf den Button, wird der Prozess ebenso abgebrochen und statt der Aktion, die durch langes Drücken ausgeführt wird, wird die Aktion für kurzes Drücken ausgeführt,
indem :ref:`select<buttonselect>` mit dem ``input`` aufgerufen wird.

.. _buttonSelect:

bool select ()
~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 44-60
    :linenos:

Diese Funktion ist für den Aufruf der entsprechenden Callback Funktionen von Objekten der ``Button`` Klasse zuständig, wenn diese ausgewählt werden.

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 44-51

Dieser Codeabschnitt gilt für Buttons (also nicht für Switches). Wenn Buttons eine Button Animation haben sollen (:ref:`hasButtonAnimation<buttonvhasbuttonanimation>`), dann wird der
:ref:`animationTimer<buttonvanimationtimer>` die Millisekunden seit Start speichert (siehe `millis() <https://www.arduino.cc/reference/en/language/functions/time/millis/>`_ ). Der Button wird außerdem deaktiviert (:ref:`value<buttonvvalue>`).
Es folgt der Aufruf der Callback Funktion :ref:`button_callback<buttonbuttoncallback>`. Sollte durch den :ref:`externalValue<buttonvexternalvalue>` ein gewünschter Zustand für den Button angegeben sein, so wird
:ref:`setValue<externalbuttonsetvalue>` aufgerufen.


.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 52-55

Bei einem Switch, wird der aktuelle Zustand gewechselt, also vom aktivierten in den deaktivierten und umgekehrt. Danach wird die :ref:`switch_callback<buttonswitchcallback>` Callback Funktion aufgerufen.

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 56

Das Objekt wird mit :ref:`draw<elementdraw>` sofort neugezeichnet.

.. _buttonSetTouch:

void setTouch(Inputs& input)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 122-130
    :linenos:

Diese Funktion verarbeitet Toucheingaben auf das ``Button`` Objekt auf dem ":ref:`Display<display>`".

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 123-125

Sollte es möglich sein, das Objekt länger gedrückt zu halten (:ref:`hasLongPress<buttonvhaslongpress>`), sollte noch kein :ref:`longPressTimer<buttonvlongpresstimer>` gestartet worden sein
und sollte :ref:`blocked<buttonvblocked>` ``false`` sein, so wird der :ref:`longPressTimer<buttonvlongpresstimer>` gestartet, indem dieser die Millisekunden seit Start 
(siehe `millis() <https://www.arduino.cc/reference/en/language/functions/time/millis/>`_ ) speichert.

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 126-129

Sollte man das Objekt allerdings nicht länger gedrückthalten können und sollte :ref:`blocked<buttonvblocked>` ``false`` sein, so wird lediglich
die :ref:`select<buttonselect>` Funktion aufgerufen und :ref:`blocked<buttonvblocked>` auf ``true`` gesetzt.

.. _buttonGetValue:

bool getValue()
~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Button.h
    :lines: 25
    :linenos:

Gibt den :ref:`value<buttonvvalue>` des aktuellen Objektes zurück. 

.. _buttonisinsidehitbox:

bool isInsideHitbox(uint16_t x, uint16_t y, uint16_t posX, uint16_t posY, uint16_t sizeX, uint16_t sizeY)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.cpp
    :lines: 62-64
    :linenos:

Diese Funktion testet, ob, wenn das ``Display`` berührt wird, auch das aktuelle Objekt der ``Button`` Klasse berührt wird.
Dabei sind ``x`` und ``y`` die Koordinaten, bei welchem das Display berührt wird, ``posX`` und ``posY`` die Position des Objektes und ``sizeX`` und ``sizeY`` die Breite und Höhe des Objektes.


.. _buttonbuttoncallback:

const std::function<void()> button_callback = [](){}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese Funktion ist die Callback Funktion für Buttons (für Switches siehe :ref:`switch_callback<buttonswitchcallback>`). Standardmäßig tut diese Funktion nichts,
sie erhält erst eine Bedeutung, wenn bei der Erstellung eines ``Button`` Objektes eine Funktion als ``button_callback`` übergeben wird, die aufgerufen wird, wenn der Button aktiviert
wird.

.. _buttonSwitchCallback:

const std::function<void(bool)> switch_callback = [](bool){}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese Funktion ist die Callback Funktion für Switches (für Buttons siehe :ref:`button_callback<buttonbuttoncallback>`). Standardmäßig tut diese Funktion nichts 
(akzeptiert aber ein ``bool`` Argument, da ein Switch einen aktivierten und deaktivierten Zustand hat), sie erhält erst eine Bedeutung, wenn bei der Erstellung eines ``Button`` 
Objektes eine Funktion als ``button_callback``  übergeben wird, die aufgerufen wird, wenn der Switch aktiviert wird.

.. _buttonLongpressCallback:

const std::function<void()> longpress_callback = [](){};
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese Funktion ist die Callback Funktion für Buttons und Switches, welche beim längeren Gedrückthalten auf das Objekt verwendet wird. Standardmäßig tut diese Funktion nichts,
sie erhält erst eine Bedeutung, wenn bei der Erstellung eines ``Button`` Objektes eine Funktion als ``longpress_callback`` übergeben wird, die aufgerufen wird, wenn der Button/Switch aktiviert
wird.






Variablen und Konstanten Beschreibung
=====================================


.. _buttonVValue:

bool value = false;
~~~~~~~~~~~~~~~~~~~~~~

Speichert den aktuellen Zustand des Buttons bzw. Switches. Standardmäßig befinden sie sich in einem deaktivierten Zustand.

.. _buttonVExternalValue:

ExternalButtonValue* externalValue = nullptr
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Ermöglicht eine externe Steuerung des Zustands des Buttons bzw. Switches, indem es auf einen bool-Wert zeigt, die den gewünschten Zustand repräsentiert.


.. _buttonVisButton:

const bool isButton
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob ein Objekt der ``Button`` Klasse ein Button oder ein Switch ist.

.. _buttonVhaslongpress:

const bool hasLongPress = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob bei einem Objekt der ``Button`` Klasse die :ref:`longpress_callback<buttonlongpresscallback>` Callback Funktion vorliegt, also ob man den Button/ Switch gedrückthalten kann.

.. _buttonVblocked:

bool blocked = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob der Button gerade blockiert ist, also gerade nicht ausgelöst werden kann.


.. _buttonVhasButtonAnimation:

bool hasButtonAnimation = true
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob beim Drücken des Objektes eine kleine Animation abgespielt wird.

.. _buttonVanimationtimer:

unsigned long animationTimer = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, wie lang eine Animation beim Drücken eines Buttons dauert bzw. wie lange es dauert, einen Button zu drücken.

.. _buttonVlongpresstimer:

unsigned long longPressTimer = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, wie lange ein Button gedrückt wird.


Makros Beschreibung
====================

.. _buttonMTML_goTo:

TML_goTo (tml, id) [](){tml.goTo(id);}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Mit diesem Macro lässt sich der aktuell angezeigte :ref:`Screen<screen>` schnell wechseln auf den :ref:`Screen<screen>` mit der eingetragenen ``id`` (siehe :ref:`goTo<touchmenulibgoto>` der :ref:`TouchMenuLib<touchmenulib>` Klasse). Dabei ist ``tml``
eine Instanz der :ref:`TouchMenuLib<touchmenulib>` Klasse.

.. _buttonMTML_goTo_without_History:

TML_goTo_without_History (tml, id) [](){tml.goTo(id, false);}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Mit diesem Macro lässt sich der aktuell angezeigte :ref:`Screen<screen>` schnell wechseln auf den :ref:`Screen<screen>` mit der eingetragenen ``id``. Dabei ist ``tml``
eine Instanz der :ref:`TouchMenuLib<touchmenulib>` Klasse. Beim Verwenden dieses Macros wird der aufgerufene :ref:`Screen<screen>` nicht auf 


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

Stellt die Zeit in Millisekunden dar, die beim Drücken eines Buttons vergehen.

.. _buttonMButton_Long_Time:

BUTTON_LONG_TIME 500
~~~~~~~~~~~~~~~~~~~~~~~~~

Stellt die Zeit in Millisekunden dar, die vergehen müssen, damit ein Drücken auf einem Button als Gedrückthalten gewertet wird