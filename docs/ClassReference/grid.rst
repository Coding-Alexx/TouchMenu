.. _grid:

GridScreen
+++++++++++

Beschreibung
=============
GridScreens sind :ref:`Screens <screen>`, bei denen :ref:`Elemente <element>` in einem Raster mit Zeilen und Spalten eingeordnet werden können.
Die Anzahl an Zeilen und Spalten kann angepasst werden.


Funktionen
=============
.. csv-table:: 
    :widths: 100 1000

    , ":ref:`GridScreen <gridgridscreenconstructor>` (const uint8_t col, const uint8_t row, const Color& background)"
    , ":ref:`Destructor <griddestructor>` ()"
    bool, ":ref:`add <gridadd>` (Element* element, const uint16_t posX, const uint16_t posY, const uint16_t sizeX, const uint16_t sizeY)"
    bool, ":ref:`add <gridaddelement>` (const AddElement& element)"
    GridScreen&, ":ref:`operator<gridoperator>` <<(const AddElement& element)"
    void, ":ref:`loop <gridloop>` (Inputs& input)"
    void, ":ref:`draw <griddraw>` () override"
    void, ":ref:`setResolution <gridsetresolution>` (int16_t height, int16_t width)"
    uint8_t, ":ref:`getRow <gridgetrow>` () const"
    uint8_t, ":ref:`getCol <gridgetcol>` () const"
    , ":ref:`AddElement <addelement>`"


Variablen und Konstanten
==========================
.. csv-table:: 
    :widths: 100 1000

    const :ref:`Color <color>` , ":ref:`color_background <gridvcolor_background>`"
    uint8_t, ":ref:`row <gridvrow>`"
    uint8_t, ":ref:`col <gridvcol>`"
    std::vector<std::unique_ptr<Element>> , ":ref:`elements <gridvelements>`"
    std::vector<uint8_t>, ":ref:`matrix <gridvmatrix>`"


Macros
=============
.. csv-table:: 
    :widths: 100 1000

    , ":ref:`CREATE_GRID_SCREEN <gridmcreate_grid_screen>` (TML, screenID, col, row, color, ...)"
    , ":ref:`CREATE_GRID_SCREEN_WITH_SIDEBAR <gridmcreate_grid_screen_with_sidebar>` (TML, screenID, sitebarID, col, row, color, ...)"
    , ":ref:`CREATE_GRID_SCREEN_SIDEBAR <gridmcreate_grid_screen_sidebar>` (TML, sitebarID, size, side, col, row, color, ...)"


Funktionen Beschreibung
=========================


.. _gridGridScreenConstructor:

GridScreen(const uint8_t col, const uint8_t row, const Color& background)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 5-13
    :linenos:

Der Konstruktor wird bei der Erzeugung eines neuen Objekts der ``GridScreen`` Klasse aufgerufen. Als Parameter nimmt der Konstruktor die Anzahl an Spalten (``col``) und Zeilen (``row``), die der GridScreen haben soll, sowie die Hintergrundfarbe
(``background``), die der GridScreen haben soll. In der Initialisierungsliste wird die Variable ":ref:`color_background <gridvcolor_background>`" nach dem ":ref:`Color <color>`" Funktionsaufruf von ``background`` mit diesem initalisiert.
":ref:`row <gridvrow>`" und ":ref:`col <gridvcol>`" werden mit den korrespondierenden Parametern initialisiert. Außerdem erfolgt die Initialisierung von ":ref:`elements <gridvelements>`" und von ":ref:`matrix <gridvmatrix>`". 
Bei letzterem erfolgt die Multiplikation der Spalten- und Reihenanzahl, um die Anzahl an Felder innerhalb des Grids zu speichern, sowie die Angabe von ``UINT8_MAX``, welches später nützlich ist, um feststellen zu können, ob ein Feld bereits belegt ist.

.. _gridDestructor:

virtual ~GridScreen()
~~~~~~~~~~~~~~~~~~~~~~


.. _gridAdd:

bool add(Element* element, const uint16_t posX, const uint16_t posY, const uint16_t sizeX, const uint16_t sizeY)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 15-48
    :linenos:

Diese Funktion ist für das Hinzufügen von neuen :ref:`Elementen <element>` auf dem Display zuständig. Als Parameter nimmt sie das hinzuzufügende Element (``element``), 
die X- und Y-Koordinaten ( ``posX`` und ``posY``), bei denen das Element platziert werden soll, sowie die Größe in X- und Y-Richtung (``sizeX`` und ``sizeY``) bzw. die Höhe und Breite des Elements.
Dabei beziehen sich die Angaben zu X- und Y-Koordinaten nicht etwa auf z.B. die Pixel des physischen Displays, sondern auf die Felder auf dem GridScreen. So hätte bei einem GridScreen mit 3x3 Feldern das linke obere Feld die X-Koordinate 0 und Y-Koordinate 0, das mittlere obere Feld
die X-Koordinate 1 und die Y-Koordinate 0 usw.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 17-20

Sollte :ref:`grid <screenvdisplay>` auf den ``nullptr`` zeigen, wird ``false`` zurückgegeben, da der aktuellen Screen noch keinem :ref:`TouchMenuLib <touchmenulib>` Objekt zugewiesen wurde.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 22-25

Sollte der übergebene übergebene Zeiger auf kein Element zeigen, wird ``false`` zurückgegeben, da kein Element auf das Display hinzugefügt werden kann.    

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 27-31

Sollte ``col == 0`` oder ``row == 0`` gelten, wird ebenfalls ``false`` zurückgegeben, da es keinen Platz gibt, auf dem ein Element hinzugefügt werden kann.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 33-36

Ist ``posX + sizeX > col`` oder ``posY + sizeY > row``, befindet sich das Element außerhalb des gültigen Rasters, weswegen ``false`` zurückgegeben wird.


.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 40-48

Dieser Codeblock wird genutzt, um zu testen, ob in den Feldern, in denen man ein Element hinzufügen möchte, bereits ein Element vorhanden ist. Da ein Element mehr als ein Feld belegen kann (indem ``sizeX`` oder ``sizeY`` > 1 sind),
sind hierfür zwei ``for``-Schleifen notwendig. Die äußere Schleife läuft von dem Wert der X-Koordinate, bei der das Element beginnt (``posX``) bis zum Wert der X-Koordinate, bei der das Element endet (``posX + sizeX``).
Die innere Schleife läuft von dem Wert der Y-Koordinate, bei der das Element beginnt (``posY``) bis zum Wert der Y-Koordinate, bei der das Element endet (``posY + sizeY``).
Es wird getestet, ob in der ":ref:`matrix <gridvmatrix>`" an der entsprechenden Stelle bereits ein Wert gespeichert ist. Ist dies der Fall, wird ``false`` zurückgegeben.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 50-57

| Hier werden einige Variablen definiert, die den darauffolgenden Code leserlicher machen. Zuerst werden die Maße des GridScreens berechnet:
| 
| ``columnSpacing`` gibt an, wie breit jedes Feld des Rasters ist. Dafür wird die Breite des Screens (:ref:`width <screenvwidth>`) durch die Anzahl der Spalten dividiert.  
| ``rowSpacing`` gibt an, wie hoch jedes Feld des Rasters ist. Dafür wird die Höhe des Screens (:ref:`height <screenvheight>`) durch die Anzahl der Zeilen dividiert. 
| ``x`` gibt die tatsächliche X-Koordinate auf dem (:ref:`Screen <screen>`) an.
| ``y`` gibt die tatsächliche Y-Koordinate auf dem (:ref:`Screen <screen>`) an.
| ``w`` gibt die tatsächliche Breite des Elements auf dem (:ref:`Screen <screen>`) an.
| ``h`` gibt die tatsächliche Höhe des Elements auf dem (:ref:`Screen <screen>`) an.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 61-66

Die :ref:`setSize <elementsetsize>` Funktion des ``element`` wird aufgerufen. Dabei wird neben ``w`` und ``h`` auch das Ergebnis des Funktionsaufruf von ":ref:`getRotation <displaytftespigetrotation>`" des Objektes ":ref:`display <screenvdisplay>`" übergeben.
Sollte der Funktionsaufruf ``false`` zurückgeben, lässt sich das Element nicht dem Display hinzufügen. Weswegen ``element`` gelöscht wird und stattdessen eine Fehlermeldung in Form einer 
:ref:`Textbox_blank <textboxblankconstructoritemstrcolorvalue>` ausgibt.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 67-68

Es folgt der Aufruf der ":ref:`setPosition <elementsetposition>`" Funktion, um dem Element die zuvor bestimmten X- und Y-Koordinaten zuzuweisen, auf welchen es platziert werden soll, sowie
der Funktionsaufruf von ":ref:`setDisplay <elementsetdisplay>`", um das Display festzulegen, auf welchem das Element platziert werden soll.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 72-73

Danach wird ein Smart Pointer in der Form eines ``unique_ptr's`` erstellt (``uptr``), der auf ``element`` zeigt. Dieser "besitzt" und managt den ``element`` und entsorgt diesen, wenn er out of scope geht.
Anschließend wird der ``unique_ptr`` ans Ende von ":ref:`elements <gridvelements>`" gepusht.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 75-80

Dieser Codeblock funktioniert ähnlich wie der von Zeile 22 bis 26. Nur wird hier an den betroffenen ":ref:`matrix <gridvmatrix>`" Positionen ein Wert gespeichert (die Größe von ":ref:`elements <gridvelements>`" -1), welcher kennzeichnet, dass das Feld vom ``element`` besetzt ist.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 82-83

Zum Schluss wird ``element`` ``nullptr`` zugewiesen, da ``uptr`` nun die Resource verwaltet. Die gesamte Funktion gibt nun ``true`` zurück, das Element wurde erfolgreich dem Display hinzugefügt.    


.. _gridaddElement:

bool add(const AddElement& element)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 86-88
    :linenos:

Diese Funktion nimmt als Parameter ein :ref:`AddElement& <addelement>` ``element`` und ruft die :ref:`add <gridadd>` Funktion mit den entsprechenden Werten auf.

.. _gridoperator:

GridScreen& operator<<(const AddElement& element)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 90-93
    :linenos:

Dieser Überladungsoperator nimmt als Parameter ein :ref:`AddElement& <addelement>` ``element`` und ruft die :ref:`add <gridadd>` Funktion mit den entsprechenden Werten auf und gibt anschließend eine 
Referenz auf das aktuelle ``GridScreen`` Objekt zurück.

.. _gridLoop:

void loop(Inputs& input) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 95-124
    :linenos:


Diese Funktion dient dazu, den Zustand des aktuellen Objektes zu aktualisieren, um auf Veränderungen und Benutzereingaben zu reagieren.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 96-99

Sollten :ref:`input.updateTouchPoint <inputvupdatetouchpoint>` und :ref:`input.isTouched <inputvistouched>` gelten (also sollte der Benutzer das Display an einer neuen Stelle berühren),
werden in ``x`` und ``y`` die Koordinaten der Berührung gespeichert.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 101-104

In diesem Codeabschnitt wird geprüft, ob sich der Berührungspunkt außerhalb des aktuellen ``GridScreen`` befindet. Wenn ja, wird die Verarbeitung abgebrochen.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 106-107

Anschließend werden mit ``grid_x`` und ``grid_y`` die Breite und Höhe eines Gitterfeldes bestimmt.   

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 109-112

Nun wird geprüft, ob das Gitterfeld außerhalb des ``GridScreens`` liegt. Wenn ja, wird die Verarbeitung abgebrochen.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 117-119

Nach allen Tests, können wir nun sicher sein, dass der Berührungspunkt auch innerhalb eines Feldes des ``GridScreens`` liegt.
Deshalb wird mit ``e`` das exakte Feld berechnet, in welchem der Touchinput geschieht. Wenn ``e != UINT_MAX`` gilt, wird auf :ref:`elements[e]<gridvelements>` die entsprechende
:ref:`setTouched<elementsettouch>` Funktion aufgerufen, um die Toucheingabe letztendlich zu verarbeiten.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 121-123

Nach der Verarbeitung der Berührungspunkte läuft eine ``for`` Schleife über alle :ref:`elements<gridvelements>`, um die jeweiligen :ref:`loop<elementloopinput>` Funktionen aufzurufen, um auch bei den einzelnen
Elementen auf mögliche Änderungen zu reagieren.

.. _gridDraw:

void draw() override
~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 126-154
    :linenos:

| Diese Funktion überschreibt die ":ref:`draw <screendraw>`" Funktion der ":ref:`Screen <screen>`" Klasse. 
| 
| Zuerst wird die :ref:`rect <displaytftespirectinfill>` Funktion des ":ref:`display <screenvdisplay>`" Objektes aufgerufen. Dabei wird ":ref:`background_color <errorvbackground_color>`" als Argument übergeben. Dadurch wird das Display in die Hintergrundfarbe gefärbt.
| Anschließend werden zwei Variablen definiert, die den darauffolgenden Code leserlicher machen:
| 
| ``columnSpacing`` gibt an, wie breit jedes Feld des Rasters ist. Dafür wird die Breite des Screens (":ref:`width <screenvwidth>`") durch die Anzahl der Spalten dividiert.  
| ``rowSpacing`` gibt an, wie hoch jedes Feld des Rasters ist. Dafür wird die Höhe des Screens (":ref:`height <screenvheight>`") durch die Anzahl der Zeilen dividiert. 

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 137-140

In diesem Codeabschnitt werden die vertikalen Linien auf dem Display gezeichnet, sodass die gewünschte Anzahl an Spalten entstehen. 
Die ``for``-Schleife läuft genau so häufig, wie unter ":ref:`col <gridvcol>`" angegeben. Bei jedem Durchlauf wird die Variable x erstellt, in der gespeichert wird, durch welche X-Koordinate die aktuelle Linie verlaufen soll.
Die Linien sollen immer am Ende eines jeden Rasterfeldes gezogen werden.
Mit dem ":ref:`line <displaytftespiline>`" Funktionsaufruf des ":ref:`display <screenvdisplay>`" wird diese Linie letztendlich gezeichnet. Dabei wird sie zwischen den Koordinaten ``(x;0)`` bis nach ``(x;height)`` gezeichnet (also von einen Bildschirmrand zum anderen).
Dabei wird die Linie in die Komplementärfarbe des Hintergrundes (":ref:`!color_background <gridvcolor_background>`") gefärbt, um eine gute Sichtbarkeit zu gewährleisten.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 143-147

In diesem Codeabschnitt werden die horizontalen Linien auf dem Display gezeichnet, sodass die gewünschte Anzahl an Zeilen entstehen. 
Die ``for``-Schleife läuft genau so häufig, wie unter ":ref:`row <gridvrow>`" angegeben. Bei jedem Durchlauf wird die Variable y erstellt, in der gespeichert wird, durch welche Y-Koordinate die aktuelle Linie verlaufen soll.
Die Linien sollen immer am unteren Ende eines jeden Rasterfeldes gezogen werden.
Mit dem ":ref:`line <displaytftespiline>`" Funktionsaufruf des ":ref:`display <screenvdisplay>`" wird diese Linie letztendlich gezeichnet. Dabei wird sie zwischen den Koordinaten ``(0;y)`` bis nach ``(0;width)`` gezeichnet (also von einen Bildschirmrand zum anderen).
Dabei wird die Linie in die Komplementärfarbe des Hintergrundes (":ref:`!color_background <gridvcolor_background>`") gefärbt, um eine gute Sichtbarkeit zu gewährleisten.

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 149-153

Schlussendlich werden durch die ``foreach``-Schleife sämtliche Elemente aus ":ref:`elements <gridvelements>`" durch den Funktionsaufruf von ":ref:`draw <elementdraw>`" auf das Grid gezeichnet.   


.. _gridSetResolution:

void setResolution(int16_t height, int16_t width)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 156-158
    :linenos:

Die Funktion ":ref:`setResolution <screensetresolution>`" in der ":ref:`Screen <screen>`" Klasse wird aufgerufen, um die Auflösung des Displays festzulegen. Dabei werden die Höhe (``h``) und Breite (``w``) des Displays als Parameter übergeben.

.. _gridGetRow:

uint8_t getRow() const 
~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/GridScreen.h
    :lines: 93
    :linenos:

Gibt die Anzahl an Zeilen (":ref:`row <gridvrow>`") des Displays zurück.

.. _gridGetCol:

uint8_t getCol() const
~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/GridScreen.h
    :lines: 94
    :linenos:

Gibt die Anzahl an Spalten (:ref:`col <gridvcol>`) des Displays zurück.


.. _addelement:

struct AddElement
~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/GridScreen.h
    :lines: 64-73
    :linenos:

Diese Struktur wird verwendet, um Informationen über ein Element und seiner Position und Größe innerhalb eines ``GridScreens`` zu speichern.

.. literalinclude:: ../../src/Screens/GridScreen.h
    :lines: 65-69

Dabei ist ``element`` der Pointer auf das Element, welches dem ``GridScreen`` hinzugefügt werden soll, ``posX`` und ``posY`` die X- bzw. Y-Koordinate, bei welchen das Element platziert werden soll 
und ``sizeX`` und ``sizeY`` die Breite bzw. Höhe des Elements

.. literalinclude:: ../../src/Screens/GridScreen.h
    :lines: 71-72

Mit dem Konstruktor werden die oben genannten Parameter initialisiert.

Variablen und Konstanten Beschreibung
=====================================

.. _gridVColor_background:

const Color color_background
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Speichert die Hintergrundfarbe eines ``GridScreens``.

.. _gridVrow:

uint8_t row
~~~~~~~~~~~~~~

Gibt an, wie viele Reihen ein ``GridScreen`` hat.

.. _gridVcol:

uint8_t col
~~~~~~~~~~~~~

Gibt an, wie viele Spalten ein ``GridScreen`` hat.

.. _gridVelements:

std::vector<std::unique_ptr<Element>> elements
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Speichert alle ":ref:`Elemente <element>`", die sich auf einem ``GridScreen`` befinden.

.. _gridVmatrix:

std::vector<uint8_t> matrix
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Speichert, aus wie vielen Kästchen/ Feldern ein GridScreen zusammengesetzt ist.


Macro Beschreibung
===================

.. _gridMCreate_grid_screen:

CREATE_GRID_SCREEN(TML, screenID, col, row, color, ...)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Screens/GridScreen.h
    :lines: 13-32
    :linenos:

Dieses Macro vereinfacht die Erstellung eines Objektes der :ref:`GridScreen<grid>` Klasse, indem ein Raster erstellt wird.
Dabei ist ``TML`` eine Instanz der :ref:`TouchMenuLib<touchmenulib>` Klasse, ``screenID`` eine einzigarte ``UINT8_MAX`` Zahl, die zur Identifizierung des :ref:`Screens<screen>` genutzt wird,
``col`` die Anzahl der Spalten, die das Gitter haben soll, ``row`` die Anzahl der Zeilen, die das Gitter haben soll und ``color`` die Hintergrundfarbe.

.. _gridMcreate_grid_screen_with_sidebar:

CREATE_GRID_SCREEN_WITH_SITEBAR(TML, screenID, sitebarID, col, row, color, ...)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/GridScreen.h
    :lines: 29-44
    :linenos:

Dieses Macro vereinfacht die Erstellung eines Objektes der :ref:`GridScreen<grid>` Klasse, indem ein Raster mit einer Sidebar am Bildschirmrand erstellt wird.
Dabei ist ``TML`` eine Instanz der :ref:`TouchMenuLib<touchmenulib>` Klasse, ``screenID`` eine einzigarte ``UINT8_MAX`` Zahl, die zur Identifizierung des :ref:`Screens<screen>` genutzt wird,
``col`` die Anzahl der Spalten, die das Gitter haben soll, ``row`` die Anzahl der Zeilen, die das Gitter haben soll und ``color`` die Hintergrundfarbe.


.. _gridMcreate_grid_screen_sidebar:

CREATE_GRID_SCREEN_SITEBAR(TML, sitebarID, size, side, col, row, color, ...)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/GridScreen.h
    :lines: 46-62
    :linenos:

Dieses Macro vereinfacht die Erstellung eines Objektes der :ref:`GridScreen<grid>` Klasse, indem eine Sidebar erstellt wird
Dabei ist ``TML`` eine Instanz der :ref:`TouchMenuLib<touchmenulib>` Klasse, ``screenID`` eine einzigarte ``UINT8_MAX`` Zahl, die zur Identifizierung des :ref:`Screens<screen>` genutzt wird,
``col`` die Anzahl der Spalten, die das Gitter haben soll, ``row`` die Anzahl der Zeilen, die das Gitter haben soll und ``color`` die Hintergrundfarbe.

