.. _errorscreen:

ErrorScreen
+++++++++++++++

Beschreibung
=============
ErrorScreens sind :ref:`Screens <screen>`, die eine Fehlermeldung ausgeben.


Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============

.. csv-table:: 
    :widths: 100 1000

     , ":ref:`ErrorScreen <errorerrorscreenconstructor>` (const char* error_title, const char* error_text)"
     , ":ref:`ErrorScreen <errorerrorscreenconstructorcolor>` (const char* error_title, const char* error_text, const Color& background_color, const Color& text_color)"
     void , ":ref:`loop <errorloop>` (Inputs& input)"
     void , ":ref:`draw <errordraw>` ()"


Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 1000

    const char*, ":ref:`error_title <errorverror_title>`"
    const char*, ":ref:`error_text <errorverror_text>`"
    const ":ref:`Color <color>`", ":ref:`background_color <errorvbackground_color>`"
    const ":ref:`Color <color>`", ":ref:`text_color <errorvtext_color>`"


Macros
=============
.. csv-table:: 
    :widths: 100 1000

     , ":ref:`CREATE_ERROR_SCREEN <errormcreate_error_screen>` (TML, screenID, errorTitle, errorMessage)"
     , ":ref:`CREATE_ERROR_SCREEN_with_Colors <errormcreate_error_screen>` (TML, screenID, errorTitle, errorMessage, backgroundColor, textColor)"



Funktionen Beschreibung
=========================

.. _errorErrorScreenConstructor:

ErrorScreen (const char* error_title, const char* error_text)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/ErrorScreen.cpp
    :lines: 3-5
    :linenos:

Der Konstruktor wird bei der Erzeugung eines neuen Objekts der ``ErrorScreen`` Klasse aufgerufen. Als Parameter nimmt der Konstruktor den Namen des Fehlers (``error_title``) und den Text, den
der bei der Fehlermeldung ausgegeben werden soll (``error_text``). Für die Initialisierung wird der andere ":ref:`ErrorScreen <errorerrorscreenconstructorcolor>`" Konstruktor aufgerufen, wobei ``COLOR_RED`` die 
Standard Hintergrundfarbe (des Displays) Rot und ``COLOR_BLACK`` die Standard Textfarbe Schwarz ist.

.. _errorErrorScreenConstructorColor:

ErrorScreen (const char* error_title, const char* error_text, const Color& background_color, const Color& text_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/ErrorScreen.cpp
    :lines: 7-12
    :linenos:

| Der Konstruktor wird bei der Erzeugung eines neuen Objekts der ``ErrorScreen`` Klasse aufgerufen. Als Parameter nimmt der Konstruktor den Namen des Fehlers (``error_title``), den der bei der Fehlermeldung ausgegeben werden soll (``error_text``), die Hintergrundfarbe (``background_color``), sowie die Textfarbe (``text_color``). Dieser Konstruktor ermöglicht es, Hintergrund- und Textfarbe individuell festzulegen, anders als bei diesem ":ref:`ErrorScreen <errorerrorscreenconstructor>`" Konstruktor. 
| 
| In der Initialisierungsliste werden die Variablen ":ref:`error_title <errorverror_title>`", ":ref:`error_text <errorverror_text>`", ":ref:`background_color <errorvbackground_color>`" und ":ref:`text_color <errorvtext_color>`" mit dem korrespondierenden Parameter initialisiert.


.. _errorLoop:

void loop(Inputs& input) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/ErrorScreen.cpp
    :lines: 22-24
    :linenos:

KEINE DEFINITION

.. _errorDraw:

void draw() override
~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Screens/ErrorScreen.cpp
    :lines: 14-20
    :linenos:

Diese Funktion überschreibt die ":ref:`draw <screendraw>`" Funktion der ":ref:`Screen <screen>`" Klasse.
Zuerst wird die ":ref:`fillScreen <displaytftespifillscreen>`" Funktion des ":ref:`display <screenvdisplay>`" Objektes aufgerufen. Dabei wird ":ref:`background_color <errorvbackground_color>`" als Parameter übergeben.
Dadurch wird das Display in die Hintergrundfarbe gefärbt. Anschließend sollen sowohl ":ref:`error_title <errorverror_title>`" und ":ref:`error_text <errorverror_text>`" auf dem Display zentriert angezeigt werden.
Zuerst erfolgt der ":ref:`text_center <displaytftespitextcenter>`" Funktionsaufruf, bei welchem durch ``width/2`` und ``height/3``":ref:`error_title <errorverror_title>`" auf dem Display im oberen Drittel in der Mitte angezeigt wird.
Im nächsten ":ref:`text_center <displaytftespitextcenter>`" Funktionsaufruf wird ":ref:`error_text <errorverror_text>`" durch ``width/2`` und ``height/3`` auf dem mittleren Drittel zentral angezeigt.

Variablen und Konstanten Beschreibung
=====================================

.. _errorVError_title:

const char* error_title
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese Variable speichert den Namen einer Fehlermeldung.

.. _errorVError_text:

const char* error_text
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese Variable speichert den Text, der bei einer Fehlermeldung ausgeben wird.

.. _errorVBackground_color:

const Color background_color
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Hier wird die Hintergrundfarbe von Fehlerbildschirmen gespeichert. Die Standard Hintergrundfarbe wird in diesem ":ref:`ErrorScreen <errorerrorscreenconstructor>`" Konstruktor festgelegt.

.. _errorVText_color:

const Color text_color
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Hier wird die Textfarbe von Fehlermeldungen gespeichert. Die Standard Textfarbe wird in diesem ":ref:`ErrorScreen <errorerrorscreenconstructor>`" Konstruktor festgelegt.

Macro Beschreibung
==========================

.. _errorMCreate_error_screen:

#define CREATE_ERROR_SCREEN(TML, screenID, errorTitle, errorMessage)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/ErrorScreen.h
    :lines: 7-12
    :linenos:

Dieses Macro erleichtert das Erstellen von Instanzen der ``ErrorScreen`` Klasse. 

.. _errorMCreate_error_screen_with_colors:

#define CREATE_ERROR_SCREEN_with_Colors(TML, screenID, errorTitle, errorMessage, backgroundColor, textColor)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Screens/ErrorScreen.h
    :lines: 14-22
    :linenos: