.. _roundbutton:

RoundButton
++++++++++++++

Beschreibung
=============
RoundButtons sind :ref:`Buttons <button>` mit einer runden Form. Sie unterscheiden sich von anderen Buttons jediglich hinsichtlich ihres Aussehens.
 

Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    , ":ref:`RoundButton <roundButtonConstructorButton>` (const char* itemOn, const char* itemOff, const Color& color, const std::function<void()> button_callback, ExternalButtonValue* const value = nullptr)"
    , ":ref:`RoundButton <roundButtonConstructorSwitch>` (const char* itemOn, const char* itemOff, const Color& color, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value = nullptr)"
    , ":ref:`~RoundButton <roundButtondestructor>` ()"
    void, ":ref:`draw <roundbuttondraw>` () override"
    void, ":ref:`setTouch <roundbuttonsettouch>` (Inputs& input) override"
    uint16_t , ":ref:`getHeight <roundbuttongetheight>` ()"
    uint16_t , ":ref:`getWidth <roundbuttongetwidth>` ()"
    uint16_t , ":ref:`getMidX <roundbuttongetMidX>` ()"
    uint16_t , ":ref:`getMidY <roundbuttongetMidY>` ()"
    bool , ":ref:`checkSize <roundbuttonchecksize>` (uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override"


Variablen und Konstanten
==========================


.. csv-table:: 
    :widths: 100 10000

    const Color, ":ref:`color <roundButtonvcolor>`"
    ":ref:`Item* <item>`", ":ref:`itemOn <roundButtonvitemon>`"
    ":ref:`Item* <item>`", ":ref:`itemOff <roundButtonvitemoff>`"
    const, ":ref:`d<roundButtonvd>`"
    

Funktionen Beschreibung
=========================

.. _roundButtonConstructorButton:

RoundButton(const char* itemOn, const char* itemOff, const Color& color, const std::function<void()> button_callback, ExternalButtonValue* const value = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/RoundButton.cpp
    :lines: 5-6
    :linenos:

Diese Funktion ist ein Konstruktor, der einen runden Button (keinen Switch) erzeugt. Als Parameter nimmt der Konstruktor ein ":ref:`Item<item>`" für die aktivierte (``itemOn``) und deaktivierte (``itemOff``)
Form des Buttons, eine Farbe (``color``), eine Button Callback Funktion (``button_callback``), sowie dem ``value``, der angibt, ob der Button aktiviert ist oder nicht.

In der Initialisierungsliste wird zum einen dieser ":ref:`Button Konstruktor<buttonbutton>`" aufgerufen, zum anderen erfolgt die Initialisierung von ":ref:`color<roundbuttonvcolor>`" mit dem korresponiderenden Parameter. 
Für die Initialisierung von ":ref:`itemOn<roundbuttonvitemon>`" erfolgt ein Funktionsaufruf von ":ref:`createItem<displaycreateitemnocolor>`" mit ``itemON`` und für ":ref:`itemOff<roundbuttonvitemoff>`" erfolgt ebenfalls 
ein Funktionsaufruf von ":ref:`createItem<displaycreateitemnocolor>`", aber diesmal mit ``ItemOff``.

.. _roundButtonConstructorSwitch:

RoundButton(const char* itemOn, const char* itemOff, const Color& color, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/RoundButton.cpp
    :lines: 8-9
    :linenos:

Diese Funktion ist ein Konstruktor, der einen runden Switch (keinen Button) erzeugt. Als Parameter nimmt der Konstruktor Ein ":ref:`Item<item>`" für die aktivierte (``itemOn``) und deaktivierte (``itemOff``)
Form des Switches, eine Farbe (``color``), eine Switch Callback Funktion (``switch_callback``), sowie dem ``value``, der angibt, ob der Button aktiviert ist oder nicht.

In der Initialisierungsliste wird zum einen dieser ":ref:`Button Konstruktor<buttonswitch>`" aufgerufen, zum anderen erfolgt die Initialisierung von ":ref:`color<roundbuttonvcolor>`" mit dem korresponiderenden Parameter. 
Für die Initialisierung von ":ref:`itemOn<roundbuttonvitemon>`" erfolgt ein Funktionsaufruf von ":ref:`createItem<displaycreateitemnocolor>`" mit ``itemON`` und für ":ref:`itemOff<roundbuttonvitemoff>`" erfolgt ebenfalls 
ein Funktionsaufruf von ":ref:`createItem<displaycreateitemnocolor>`", aber diesmal mit ``ItemOff``.

.. _roundButtonDestructor:

~RoundButton ()
~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/RoundButton.cpp
    :lines: 11-14
    :linenos:

Der Destruktor wird bei der Zerstörung eines ``RoundButton`` Objektes aufgerufen. Mit ``delete`` wird der von Speicherplatz von ":ref:`itemOn<roundbuttonvitemon>`" und ":ref:`itemOff<roundbuttonvitemoff>`" wieder freigegeben.

.. _roundButtondraw:

void draw () override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/RoundButton.cpp
    :lines: 34-50
    :linenos:


Diese Funktion ist verantwortlich für das Zeichnen des ``RoundButton`` Objektes.   

.. literalinclude:: ../../src/ElementViews/RoundButton.cpp
    :lines: 35

Zuerst wird die Variable ``d`` definiert, die als Durchmesser des ründlichen Buttons genutzt wird.

.. literalinclude:: ../../src/ElementViews/RoundButton.cpp
    :lines: 39-42

Sollte ``value==true`` gelten, also sollte der Button aktiviert sein, wird
die ":ref:`circle <displaytftespicircleinfill>`" Funktion des ":ref:`display <elementvdisplay>`" aufgerufen, um einen Kreis zu zeichen. 
Die Parameter ``posX + sizeX/2`` und ``posY + sizeY/2`` haben sich als optimal erwiesen, um die gewünschte Form zu zeichnen (das gilt auch bei den nachfolgenden Funktionsaufrufen). Für den Durchmesser übergeben wir die oben 
definierte Variable ``d``, für die Umrandungsfarbe rufen wir die ":ref:`getBorderColor <colorgetbordercolor>`" Funktion von ":ref:`color <roundbuttonvcolor>`" und als die Füllfarbe des Buttons verwenden wir ":ref:`color <roundbuttonvcolor>`".
Falls ``itemOn==true`` gelten sollte, zeichnen wir dieses Item direkt. Dazu rufen wir die ":ref:`drawItem <displayDrawItemColor>`" Funktion auf und übergeben als Parameter u.a. besagtes Item (":ref:`itemOn <roundbuttonvitemon>`") sowie eine passende Farbe für das Item 
(":ref:`itemOn <roundbuttonvitemon>`"), welche mit ":ref:`getItemColor <colorgetitemcolor>`" bestimmt wird.

.. literalinclude:: ../../src/ElementViews/RoundButton.cpp
    :lines: 44-47

Sollte ``value==true`` gelten, also sollte der Button aktiviert sein, wird ebenso 
die ":ref:`circle <displaytftespicircleinfill>`" Funktion des ":ref:`display <elementvdisplay>`" aufgerufen, um einen Kreis zu zeichen.
Nur diesmal übergeben wir das Ergebnis der Funktionsaufrufe von ":ref:`getSecondaryBorderColor <colorgetsecondarybordercolor>`" und ":ref:`getSecondaryColor <colorgetsecondarycolor>`" für die Umrandungs- bzw- Füllfarbe.
Außerdem wird geprüft, ob ``itemOff==true`` gelten sollte. Falls dies der Fall ist, wird dieses Item gezeichnet. Die Vorgehensweise ist die selbe wie weiter oben, nur übergeben wir diesmal das ":ref:`itemOff <roundbuttonvitemon>`" und übergeben die 
Farbe, die nach dem Funktionsaufruf von ":ref:`getSecondaryBorderColor <colorgetsecondarybordercolor>`" bestimmt wird.


.. _roundButtonGetHeight:

uint16_t getHeight()
~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/RoundButton.cpp
    :lines: 52-54
    :linenos:

Diese Funktion gibt die Höhe (also die Größe in X-Richtung) des Objektes zurück.

.. _roundButtonGetWidth:

uint16_t getWidth()
~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/RoundButton.cpp
    :lines: 56-58
    :linenos:

Diese Funktion gibt die Breite (also die Größe in Y-Richtung) des Objektes zurück.

.. _roundButtonGetMidX:

uint16_t getMidX() 
~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/RoundButton.h
    :lines: 16
    :linenos:

Diese Funktion gibt den Mittelpunkt der X-Ausprägung des Objektes zurück.

.. _roundButtonGetMidY:

uint16_t getMidY()
~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/RoundButton.h
    :lines: 17
    :linenos:

Diese Funktion gibt den Mittelpunkt der Y-Ausprägung des Objektes zurück.

.. _roundButtonsettouch:

void setTouch(Inputs& input) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


.. _roundButtonchecksize:


bool checkSize (uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/RoundButton.cpp
    :lines: 16-32
    :linenos:

Diese Funktion testet, ob eine Objekt groß genug ist, um es zeichnen zu können. Um diese Bedingung zu erfüllen, um es sowohl in X- als auch Y-Richtung mindestens ``50`` Pixel groß sein.

Variablen und Konstanten Beschreibung
=====================================

.. _roundButtonvcolor:

const Color color
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _roundButtonvitemon:

Item* itemOn = nullptr
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _roundButtonvitemoff:

Item* itemOff = nullptr
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _roundButtonvd:

const uint16_t d
~~~~~~~~~~~~~~~~~~~~~~~~~~~