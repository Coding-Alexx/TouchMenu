.. _touchMenuLib:

TouchMenuLib
++++++++++++++

Beschreibung
=============
TouchMenuLib arbeitet als Schnittstelle und verwaltet das Menü und kommuniziert mit dem Nutzer.

Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    , ":ref:`TouchMenuLib <touchmenulibtouchmenulibconstructor>` (Display* disp)"
    , ":ref:`~TouchMenuLib <touchmenulibtouchmenulibdestructor>` ()"
    void, ":ref:`init <touchmenulibinit>` (uint8_t rotation = 1)"
    void, ":ref:`add <touchmenulibadd>` (uint8_t id, Screen* screen)"
    void, ":ref:`add <touchmenulibaddsidebarid>` (const uint8_t id, Screen* screen, const uint8_t sitebarID)"
    void, ":ref:`addSidebar <touchmenulibaddsidebar>` (const uint8_t id, Screen* sitear, uint16_t size, uint8_t site = 0)"
    void, ":ref:`loop <touchmenulibloop>` ()"
    void, ":ref:`draw <touchmenulibdraw>` ()"
    void, ":ref:`back <touchmenulibback>` (const uint8_t i = 1)"
    bool, ":ref:`goTo <touchmenulibgoto>` (const uint8_t id, const bool toHistory = true)"
    void, ":ref:`setInputEnter <touchmenulibsetinputenter>` ()"
    void, ":ref:`setInputRight <touchmenulibsetinputright>` ()"
    void, ":ref:`setInputLeft <touchmenulibsetinputleft>` ()"
    void, ":ref:`setInputUp <touchmenulibsetinputup>` ()"
    void, ":ref:`setInputDown <touchmenulibsetinputdown>` ()"
    void, ":ref:`setScreenSaver<touchmenulibsetscreensaver>` (const uint8_t screenID, unsigned long time, bool backOnInput = true)"
    bool, ":ref:`enableScreenSaver <touchmenulibenablescreensaver>` ()"
    void, ":ref:`disableScreenSaver<touchmenulibdisablescreensaver>` ()"
    bool, ":ref:`setSidebar<touchmenulibsetsidebar` (const uint8_t sitebarID)"
    bool, ":ref:`enableSidebar<touchmenulibenablesidebar` ()"
    bool, ":ref:`disableSidebar<touchmenulibdisablesidebar`  (const bool deactivateSitebar = false)"
    ":ref:`Display&<display>`", ":ref:`getDisplay<touchmenulibgetdisplay>` ()"
    uint8_t, ":ref:`getScreenID<touchmenulibgetscreenid>` ()"
    bool, ":ref:`enableSidebar<touchmenulibenablesidebarbool>` (bool)"



Variablen und Konstanten
==========================


.. csv-table:: 
    :widths: 100 10000

    "std::map<uint8_t, std::unique_ptr<Screen>>", ":ref:`screens <touchmenulibvscreens>`"
    std::stack<uint8_t>, ":ref:`screenHistory <touchmenulibvscreenhistory>`"
    "std::map<uint8_t, std::unique_ptr<Screen>>", ":ref:`sidebars <touchmenulibvsidebars>`"
    "std::map<uint8_t, uint8_t> ", ":ref:`sidebarConnector <touchmenulibvsidebarconnector>`"
    uint8_t, ":ref:`currentSidebar <touchmenulibvcurrentsidebar>` = UINT8_MAX"
    bool, ":ref:`deactivateSidebar<touchmenulibvdeactivatesidebar>` = false"
    :ref:`Display* <display>`, ":ref:`display <touchmenulibvdisplay>`"
    bool, ":ref:`isDisplayInit <touchmenulibvisdisplayinit>` = false"
    :ref:`Inputs <input>`, ":ref:`input <touchmenulibvinput>`"
    bool, ":ref:`screensaverBackOnInput<touchmenulibvscreensaverbackoninput>` = false"
    bool, ":ref:`isScreensaverEnable<touchmenulibvisscreensaverenable>` = false"
    unsigned long, ":ref:`screensaverTime<touchmenulibvscreensavertime>` = 0"
    unsigned long, ":ref:`screensaverTimer<touchmenulibvscreensavertimer>` = 0"
    uint8_t, ":ref:`screensaverID<touchmenulibvscreensaverid>` = UINT8_MAX"
    unsigned long, ":ref:`inputTimer<touchmenulibvinputtimer>` = 0"


Funktionen Beschreibung
=========================

.. _TouchMenuLibTouchMenuLibConstructor:

TouchMenuLib (Display* disp)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 3-7
    :linenos:

Der Konstruktor wird bei der Erzeugung eines neuen Objekts der ``TouchMenuLib`` Klasse aufgerufen.
Er erhält einen Pointer ``disp`` auf ein :ref:`Display <display>` Objekt als Parameter. Das Member ``display`` wird mit dem von ``disp`` übergebenen Wert initialisiert.
In Zeile 4 wird schließlich der ursprüngliche Pointer ``disp`` auf ``nullptr`` gesetzt. Es ist wichtig zu bedenken, dass dies keinen Einfluss auf das ``display`` Objekt hat.

.. _TouchMenuLibTouchMenuLibDestructor:

~TouchMenuLib ()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 9-11
    :linenos:

Der Destruktor wird bei der Zerstörung eines ``TouchMenuLib`` Objektes aufgerufen. Er gibt den Speicher frei, welcher vom ``display`` belegt wurde.

.. _TouchMenuLibInit:

void init (uint8_t rotation = 1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 14-17
    :linenos:

Diese Funktion ist verantwortlich für dir Initialisierung des Displays.
Zuerst wird die :ref:`init() <displayinit>` Funktion des ``display`` Objekts aufgerufen. Sie wird aufgerufen, um sicherzustellen, dass das Display betriebsbereit ist, bevor es verwendet wird.
Nach Abschluss der Initialisierung wird ``isDisplayInit`` auf ``true`` gesetzt. Dieser Flag ermöglicht es, den Status der Display-Initialisierung zu verfolgen.

.. _TouchMenuLibAdd:

void add (uint8_t id, Screen* screen)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 19-42
    :linenos:

Diese Funktion ermöglicht das Hinzufügen eines neuen :ref:`Screens <screen>` zur eigenen Anwendung.
Zuerst wird überprüft, ob das Display bereits initialisiert wurde (siehe :ref:`init() <TouchMenuLibInit>`). Anschließend wird überprüft, 
ob der übergebene :ref:`Screens <screen>` Pointer gültig ist. Zeigt der Pointer auf keine Speicheradresse, kehrt die Funktion vorzeitig zurück.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 28

Hier wird die Funktion :ref:`setDisplay <screensetdisplay>` des übergebenen Screens aufgerufen, um das ``display`` Objekt diesem Screen zuzuweisen.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 30-31

Zunächst wird ein Smart Pointer in der Form eines ``unique_ptr's`` erstellt, der auf den übergebenen Screen zeigt. Dieser "besitzt" und managt den Screen und entsorgt diesen, wenn er out of scope geht.
Anschließend wird der ``unique_ptr`` in ein Array verschoben, welches alle vorhandenen Screens speichert. Die als Parameter übergebene ``id`` dient hierbei als eine Art Schlüssel, um die Screens identifizieren zu können.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 34

Es folgt ein Funktionsaufruf von :ref:`Screens <touchmenulibsetautoresolution>`, um die Auflösung des hinzugefügten Bildschirms an das Display anzupassen.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 35

Diese Zuweisung geschieht aus Sicherheitsgründen, damit der Benutzer keinen unerwarteten Zugriff auf den Pointer hat, um keinen Schaden anrichten zu können.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 38-41

Bei ``ScreenHistory`` handelt es sich um einen Stack, der die tatsächliche Reihenfolge der Screens bei der Benutzung speichert. Ist dieser Stack leer, wird der erste Screen, der hinzugefügt wird zum Homescreen.
Der HomeScreen erhält das ``screenHistoryLeveL`` = 1. 


.. _TouchMenuLibAddSidebarID:

void add (const uint8_t id, Screen* screen, const uint8_t sitebarID)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibAddSidebar:

void addSitebar (const uint8_t id, Screen* sitear, uint16_t size, uint8_t site = 0)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibLoop:

void loop ()
~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 65-69
    :linenos:

Diese Funktion ist für die Verarbeitung von Nutzereingaben zuständig.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 66

Zuerst wird die :ref:`getTouch <displaygettouch>` Funktion von :ref:`display <touchmenulibvdisplay>` aufgerufen, um festzustellen, ob der Touchscreen berührt wurde. 
Dabei werden die X- und Y-Koordinaten der Berührung in den Variablen :ref:`input.touchX <inputvtouchx>` bzw. :ref:`input.touchY <inputvtouchy>` gespeichert. 

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 67

Anschließend wird :ref:`input.touchY <inputvtouchy>` angepasst, um sicherzustellen, dass sie in einem geeigneten Koordinatensystem liegt.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 67

Zuletzt wird die :ref:`loop <screenloop>` Funktion des aktuell angezeigten :ref:`Screens <screen>` aufgerufen (dieser befindet sich an 
oberster Stelle des :ref:`screenHistory <touchmenulibvscreenhistory>` Stacks).

.. _TouchMenuLibDraw:

void draw()
~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 71-74
    :linenos:

Diese Funktion dient dazu, den aktuellen :ref:`Screen <screen>` auf dem Display anzuzeigen.
Sollten (noch) keine Screens existieren (siehe :ref:`ScreenHistoryLevel <touchmenulibvscreenhistorylevel>`), wird die Funktion sofort verlassen.
Andernfalls wird die :ref:`draw <screendraw>` Funktion des aktuell angezeigten :ref:`Screens <screen>` aufgerufen (dieser befindet sich an 
oberster Stelle des :ref:`screenHistory <touchmenulibvscreenhistory>` Stacks).

.. _TouchMenuLibBack:

void back(const uint8_t i = 1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 45-52
    :linenos:

Diese Funktion ermöglicht es, in der :ref:`screenHistory <touchmenulibvscreenhistory>` i Schritte zurückzugehen, d.h. vorher bereits aufgerufene Screens erneut aufzurufen.
Während der for-Schleife wird jeweils das oberste Element des screenHistory Stacks entfernt, sodass der vorherige Screen nun an der Spitze des Stacks liegt. Das 
:ref:`screenHistoryLevel <touchmenulibvscreenhistorylevel>` wird um 1 verringert, da wir uns nach dem Entfernen des obersten Screens vom Stack eine Ebene tiefer befinden, als vorher.
Nach dem i-ten Schleifendurchlauf, wird die :ref:`draw <touchmenulibdraw>` Funktion aufgerufen, wodurch der oberste Screen des Stacks egzeichnet wird.


.. _TouchMenuLibGoTo:

bool goTo (const uint8_t id, const bool toHistory = true)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 55-63
    :linenos:

Diese Funktion ermöglicht es, zu einem bestimmten Screen innerhalb der :ref:`screenHistory <touchmenulibvscreenhistory>` zu navigieren.    

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 56

Wenn die übergebene ID in :ref:`screens <touchmenulibvscreens>` nicht gefunden werden kann, existiert kein Screen mit dieser ID und die Funktion gibt false zurück.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 58

Wenn der übergebene bool toHistory auf false gesetzt ist, wird der aktuelle Screen aus der :ref:`screenHistory <touchmenulibvscreenhistory>` entfernt. Des ist nützlich, 
falls, man keinen neuen Screen auf dem screenHistory Stack speichern will.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 59-62

Wenn der übergebene bool toHistory jedoch auf true gesetzt ist, wird das :ref:`screenHistoryLevel <touchmenulibvscreenhistorylevel>` um 1 erhöht, die übergebene ID auf den Stack an oberster Stelle 
gespeichert und anschließend wird die :ref:`draw <touchmenulibdraw>` Funktion aufgerufen. 

.. _TouchMenuLibSetInputEnter:

void setInputEnter()
~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 85-87
    :linenos:

Diese Funktion setzt :ref:`enter <inputventer>` des :ref:`inputs <touchmenulibvinput>` auf true. 

.. _TouchMenuLibSetInputRight:

void setInputRight()
~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 88-90
    :linenos:

Diese Funktion setzt :ref:`right <inputvright>` des :ref:`inputs <touchmenulibvinput>` auf true. 

.. _TouchMenuLibSetInputLeft:

void setInputLeft()
~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 91-93
    :linenos:

Diese Funktion setzt :ref:`left <inputvleft>` des :ref:`inputs <touchmenulibvinput>` auf true. 


.. _TouchMenuLibSetInputUp:

void setInputUp()
~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 94-96
    :linenos:

Diese Funktion setzt :ref:`up <inputvup>` des :ref:`inputs <touchmenulibvinput>` auf true. 


.. _TouchMenuLibSetInputDown:

void setInputDown()
~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 97-99
    :linenos:

Diese Funktion setzt :ref:`down <inputvdown>` des :ref:`inputs <touchmenulibvinput>` auf true. 


.. _TouchMenuLibSetScreenSaver:


void setScreensaver(const uint8_t screenID, unsigned long time, bool backOnInput = true)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibEnableScreenSaver:

bool enableScreenSaver ()
~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibDisableScreenSaver:

void disableScreenSaver ()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibsetSidebar:

bool setSitebar (const uint8_t sitebarID)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibenablesidebar:

bool enableSitebar ()    
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibSetdisablesidebar:

void disableSitebar (const bool deactivateSitebar = false) 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibgetdisplay:

Display& getDisplay()
~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibgetScreenID:

uint8_t getScreenID()
~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibenablesidebarbool:

bool enableSitebar (bool)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~






Variablen und Konstanten Beschreibung
=====================================

.. _TouchMenuLibVScreens:

std::map<uint8_t, std::unique_ptr<Screen>> screens
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Hierbei handelt es sich um eine Map, die :ref:`Screens <screen>` mit einer eindeutigen ID verknüpft.

.. _TouchMenuLibVScreenHistory:

std::stack<uint8_t> screenHistory;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

In diesem Stack werden die IDs der :ref:`Screens <screen>` in ihrer Anzeigereihenfolge gespeichert.


.. _TouchMenuLibVsidebars:

std::map<uint8_t, std::unique_ptr<Screen>> sitebars
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibVsidebarconnector:

std::map<uint8_t, uint8_t> sitebarConnector
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibVcurrentsidebar:

uint8_t currentSitebar = UINT8_MAX
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibVdeactivatesidebar:

bool deactivateSitebar = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



.. _TouchMenuLibVDisplay:

Display* display
~~~~~~~~~~~~~~~~~~

Ein Pointer auf ein :ref:`Display <display>` Objekt.

.. _TouchMenuLibVIsDisplayInit:

bool isDisplayInit = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob das :ref:`Display <display>` bereits :ref:`initialisiert <touchmenulibinit>` wurde. Standardmäßig ist dies nicht der Fall.

.. _TouchMenuLibVScreenHistoryLevel:

uint8_t screenHistoryLevel = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, in welcher Ebene der :ref:`screenHistory <touchmenulibvscreenhistory>` wir uns befinden. Standardmäßig befinden wir uns in der 0. Ebene, weil noch keine Screens existieren.

.. _TouchMenuLibVinput:

Inputs input;
~~~~~~~~~~~~~~~~~~

Gibt Informationen zu den Eingaben des Benutzers an, wie z.B. bei Berührungen.


.. _TouchMenuLibVscreensaverbackoninput:

bool screensaverBackOnInput = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibVisscreensaverenable:

bool isScreensaverEnable = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibVscreensavertime:

unsigned long screensaverTime = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibVscreensavertimer:

unsigned long screensaverTimer = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibVscreensaverid:

uint8_t screensaverID = UINT8_MAX
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _TouchMenuLibVinputtimer:

unsigned long inputTimer = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

