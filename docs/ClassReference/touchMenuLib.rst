.. _touchMenuLib:

TouchMenuLib
++++++++++++++

Beschreibung
=============
TouchMenuLib arbeitet als Schnittstelle, verwaltet das Menü und kommuniziert mit dem Nutzer.


Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    , ":ref:`TouchMenuLib <touchmenulibtouchmenulibconstructor>` (Display* disp)"
    , ":ref:`TouchMenuLib <touchmenulibtouchmenulibconstructorempty>` ()"
    , ":ref:`~TouchMenuLib <touchmenulibtouchmenulibdestructor>` ()"
    void, ":ref:`init <touchmenulibinit>` (uint8_t rotation = 1)"
    void, ":ref:`add <touchmenulibadd>` (uint8_t id, Screen* screen)"
    void, ":ref:`add <touchmenulibaddsidebarid>` (const uint8_t id, Screen* screen, const uint8_t sitebarID)"
    void, ":ref:`addSidebar <touchmenulibaddsidebar>` (const uint8_t id, Screen* sidebar, uint16_t size, uint8_t site = 0)"
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
    ":ref:`Display&<display>`", ":ref:`getDisplay<touchmenulibgetdisplay>` ()"
    uint8_t, ":ref:`getScreenID<touchmenulibgetscreenid>` ()"
    void, ":ref:`getScreensNumber<touchmenulibgetscreensnumber>` ()"



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
    bool, ":ref:`updateAll<touchmenulibvupdateall>` = true"
    bool, ":ref:`disableSidebarAutomatic<touchmenulibvdisablesidebarautomatic>` = false"



Funktionen Beschreibung
=========================

.. _TouchMenuLibTouchMenuLibConstructor:

TouchMenuLib (Display* disp)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 12-14
    :linenos:

Der Konstruktor wird bei der Erzeugung eines neuen Objekts der ``TouchMenuLib`` Klasse aufgerufen.
Er erhält einen Pointer ``disp`` auf ein :ref:`Display <display>` Objekt als Parameter. Das Member ``display`` wird mit dem von ``disp`` übergebenen Wert initialisiert.

.. _TouchMenuLibTouchMenuLibConstructorempty:

TouchMenuLib ()
~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 8-10
    :linenos:

Der Konstruktor ruft den :ref:`TouchMenuLib<touchmenulibtouchmenulibconstructor>` Konstruktor auf, in dem er ein neues :ref:`DisplayTFTeSPI<displaytftespi>` Objekt erstellt.

.. _TouchMenuLibTouchMenuLibDestructor:

~TouchMenuLib ()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 16-18
    :linenos:

Der Destruktor wird bei der Zerstörung eines ``TouchMenuLib`` Objektes aufgerufen. Er gibt den Speicher frei, welcher vom ``display`` belegt wurde.

.. _TouchMenuLibInit:

void init (uint8_t rotation = 1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 21-26
    :linenos:

Diese Funktion ist verantwortlich für dir Initialisierung des Displays.
Zuerst wird die :ref:`init<displayinit>` Funktion des :ref:`display<touchmenulibvdisplay>` aufgerufen, um die Initialisierung zu beginnen. Ebenso wird 
:ref:`setRotation<displaysetrotation>` aufgerufen, um die Bildschirmausrichtung (``rotation``) einzustellen.
Nach Abschluss der Initialisierung wird ``isDisplayInit`` auf ``true`` gesetzt. Dieser Flag ermöglicht es, den Status der Display-Initialisierung zu verfolgen.

.. _TouchMenuLibAdd:

void add (uint8_t id, Screen* screen)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 28-48
    :linenos:

Diese Funktion ermöglicht das Hinzufügen eines neuen :ref:`Screens <screen>` mit einer ``id`` zur eigenen Anwendung.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 30-35

Zuerst wird überprüft, ob das Display bereits initialisiert wurde (siehe :ref:`init<TouchMenuLibInit>`). Anschließend wird überprüft, 
ob der übergebene :ref:`Screens <screen>` Pointer gültig ist. Zeigt der Pointer auf keine Speicheradresse, kehrt die Funktion vorzeitig zurück.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 37

Hier wird die Funktion :ref:`setDisplay <screensetdisplay>` des übergebenen Screens aufgerufen, um das :ref:`display<touchmenulibvdisplay>` Objekt diesem Screen zuzuweisen.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 39-40

Zunächst wird ein Smart Pointer in der Form eines ``unique_ptr's`` erstellt, der auf den übergebenen Screen zeigt. Dieser "besitzt" und managt den Screen und entsorgt diesen, wenn er out of scope geht.
Anschließend wird der ``unique_ptr`` in ein Array verschoben, welches alle vorhandenen Screens speichert. Die  ``id`` dient hierbei als eine Art Schlüssel, um die Screens identifizieren zu können.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 42

Es folgt ein Funktionsaufruf von :ref:`setResolution<screensetresolution>`, um die Auflösung des hinzugefügten Bildschirms an das Display anzupassen.


.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 45-47

Bei :ref:`touchmenulibvscreenhistory` handelt es sich um einen Stack, der die tatsächliche Reihenfolge der Screens bei der Benutzung speichert. Ist dieser Stack leer, wird der erste Screen, der hinzugefügt wird zum Homescreen.
Der Homescreen erhält das ``screenHistoryLeveL`` = 1. 


.. _TouchMenuLibAddSidebarID:

void add (const uint8_t id, Screen* screen, const uint8_t sitebarID)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 50-73
    :linenos:

Mit dieser Funktion lässt sich ein neuer :ref:`Screens <screen>` (``screen``) mit ``id`` und einer Sidebar hinuzfügen.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 51

Ist ``screen`` der ``nullptr``, wird die Funktion abgebrochen, weil sich der ``screen`` nicht dem ``TouchMenuLib`` Objekt hinzufügen lässt.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 53

Anschließend wird die :ref:`add <touchmenulibadd>` Funktion aufgerufen, um den Screen hinzuzufügen.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 54-57

Hier wird geprüft, ob die Sidebar ID  existiert.    

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 59

Wenn sie existiert, wird ein Pointer auf diese ``sidebarID`` innerhalb von :ref:`sitebars<touchmenulibvsidebars>` gepseichert.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 62-65

Nun werden Breite (``w``), Höhe (``h``) des Screens sowie seine X-Koordinate (``x``) und Y-Koordinate(``y``) berechnet, sodass später nichts von der Sidebar bedeckt wird.  

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 69-70

Nun wird die Auflösung und Position des Screens mit :ref:`setResolution<screensetresolution>` bzw. :ref:`setResolution<screensetoffsetposition>` angepasst.  

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 72

Zum Schluss wird ``sidebarID`` in :ref:`sidebarConnector<touchmenulibvsidebarconnector>` gespeichert.

.. _TouchMenuLibAddSidebar:

void addSidebar (const uint8_t id, Screen* sidebar, uint16_t size, uint8_t site = 0)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 75-111
    :linenos:

Mit dieser Methode wird eine neue Sidebar einem vorhandenen Screen hinzugefügt.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 77

Dafür wird sichergestellt, dass das Display initialisiert wurde bzw. wird (:ref:`init<touchmenulibinit>`).   

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 79-82

Außerdem wird geprüft, ob die angegebene Sidebar ``sidebar`` auch existiert und nicht der ``nullptr`` ist.   

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 84

Nun wird die :ref:`setDisplay<screensetdisplay>` Funktion auf der ``sidebar`` aufgerufen, um sie dem :ref:`display<touchmenulibvdisplay>` hinzuzufügen.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 86-87

Zunächst wird ein Smart Pointer in der Form eines ``unique_ptr's`` erstellt, der auf ``sidebar`` zeigt. Dieser "besitzt" und managt die und entsorgt diesen, wenn er out of scope geht.
Anschließend wird der ``unique_ptr`` in ein Array verschoben, welches alle vorhandenen Sidebars speichert (:ref:`sidebars<touchmenulibvsidebars>`). 
Die  ``id`` dient hierbei als eine Art Schlüssel, um die Sidebars identifizieren zu können.
  
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 92-110

Nun wird bestimmt, an welcher Bildschirmseite die Sidebar erscheinen soll. Das lässt sich mit ``site`` festlegen.
Bei ``site = 0`` und allen Werten ``>3`` befindet sich diese auf der oberen Seite.
Für ``size = 1`` auf der rechten, für ``size = 2`` auf der unteren und für ``size = 3`` auf der linken Seite.

.. _TouchMenuLibLoop:

void loop ()
~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 134-168
    :linenos:

Diese Funktion dient dazu, den Zustand des Objektes zu aktualisieren.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 136-140

Zuerst wird geprüft, ob :ref:`updateAll<touchmenulibvupdateall>` ``true`` ist. Wenn ja, wird :ref:`draw<touchmenulibdraw>` aufgerufen und ausgeführt, um alle Screens neu zu zeichnen, ehe 
:ref:`updateAll<touchmenulibvupdateall>` auf ``false`` gesetzt wird

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 143-146

Sollten keine ``Screens`` existieren, wird die Funktion abgebrochen.   

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 149

Nun wird in :ref:`input<touchmenulibvinput>`:ref:`.isTouched<inputvistouched>` gespeichert, ob :ref:`display<touchmenulibvdisplay>` berührt wird. Dafür werden 
:ref:`input.touchX<inputvtouchx>` und :ref:`input.touchY<inputvtouchy>` an die :ref:`getTouch<displaygettouch>` des :ref:`display<touchmenulibvdisplay>` gegeben.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 152-156

Wenn eine Berührung stattfindet und :ref:`inputTimer<touchmenulibvinputtimer>` geringer als die seit Start vergangenen Millisekunden 
(siehe `millis() <https://www.arduino.cc/reference/en/language/functions/time/millis/>`_) sind, wird :ref:`input.updateTouchPoint<inputvupdatetouchpoint>` auf 
``true`` gesetzt und dem :ref:`inputTimer<touchmenulibvinputtimer>` wird ein neuer Wert zugewiesen. ``TOUCH_INPUT_TIMER`` ist ein Macro, welches standardmäßig ``300`` beträgt. 
Der :ref:`input.updateTouchPoint<inputvupdatetouchpoint>` wird also frühstens nach 300 Millisekunden wieder aktualisiert werden können, d.h. erst dann werden neue Eingaben registriert.
 
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 159-160

Mit diesem Codeblock wird der :ref:`screensaverTimer<touchmenulibvscreensavertimer>` nach einem gültigen Input resettet. Das ist für den nächsten Absatz relevant.    

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 163-168

Denn hier wird nach einer zu langen Inaktivitätszeit der Bildschirmschoner aufgerufen, :ref:`screensaverTimer<touchmenulibvscreensavertimer>` wird auf ``0`` gesetzt und die Funktion wird beendet.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 171-173

Sollte ein Input vorgenommen werden, während der Screensaver aktiv ist, so wird dieser wieder verlassen und der :ref:`screensaverTimer<touchmenulibvscreensavertimer>` startet erneut.    

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 176-180

Sollte :ref:`screensaverBackOnInput<touchmenulibvscreensaverbackoninput>` aktiviert sein, so wird :ref:`back<touchmenulibback>` aufgerufen und der letzte Screen vor Einsetzen des
Bildschirmschoners wird wieder angezeigt.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 183

Es erfolgt ein rekursiver Aufruf dieser ``loop`` Funktion mit dem Screen, welcher an höchster Stelle des Stacks liegt (:ref:`screenHistory.top<touchmenulibvscreenhistory>`). 
Dadurch wird der aktuelle Screen aktualisiert.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 184

Sollte :ref:`input.back<inputvback>` ``> 0`` sein, rufen wir mit :ref:`back<touchmenulibback>` den Screen mit der entsprechenden ID auf.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 185-189

Andernfalls wird überprüft, ob :ref:`input.update<inputvupdate>` ``true`` ist. Dann zeichnen wir die Änderungen und setzen :ref:`input.update<inputvupdate>` wieder auf ``false``.


.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 192-199   

Mit diesem Codeblock werden Sidebars neugezeichnet, sollten Änderungen vorliegen. 
Sollte ``currentSitebar = UINT8_MAX``, so wird die Bedingung zum zeichnen nicht erfüllt. 
``UINT8_MAX`` ist ein Platzhalter Wert, der in :ref:`draw<touchmenulibdraw>` Sidebars zugewiesen wird, denen kein Screen zugewiesen werden kann. 
Die restliche Vorgehensweise ähnelt dem vorherigen Abschnitt sehr und braucht daher keine weitere Erläuterung.


.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 201

Zum Schluss wird :ref:`input.reset<inputreset>` aufgerufen. Alle Inputs und Änderungen wurden erfolgreich verarbeitet.       

.. _TouchMenuLibDraw:

void draw()
~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 204-218
    :linenos:

Diese Funktion dient dazu, den aktuellen :ref:`Screen <screen>` (und wenn vorhanden auch Sidebars) auf dem Display anzuzeigen.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 206

Sollten (noch) keine Screens existieren (siehe :ref:`ScreenHistoryLevel <touchmenulibvscreenhistorylevel>`), wird die Funktion sofort verlassen.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 207

Andernfalls wird die :ref:`draw <screendraw>` Funktion des aktuell angezeigten :ref:`Screens <screen>` aufgerufen (dieser befindet sich an 
oberster Stelle des :ref:`screenHistory <touchmenulibvscreenhistory>` Stacks).

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 209-210

Sollte :ref:`disableSidebarAutomatic<touchmenulibvdisablesidebarautomatic>` ``false`` sein und sollte es eine Sidebar für den aktuellen Screen geben, 
so erhält :ref:`currentSidebar<touchmenulibvcurrentsidebar>` die entsprechende ID.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 212-213

Hat der aktuelle Screen jedoch keine Sidebar und :ref:`disableSidebarAutomatic<touchmenulibvdisablesidebarautomatic>` ist weiterhin ``false``, so wird 
:ref:`currentSidebar<touchmenulibvcurrentsidebar>` ``UINT8_MAX`` zugewiesen, da es für diese Sidebar keinen basenden Screen und somit keine passende ID gibt.
Das ganze ist eine Art Platzhalter Wert.  

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 216-218

Ist ref:`currentSidebar<touchmenulibvcurrentsidebar>` nicht ``UINT8_MAX``, so wird sie mit :ref:`currentSidebar<touchmenulibvcurrentsidebar>` :ref:`draw<touchmenulibdraw>` gezeichnet.

.. _TouchMenuLibBack:

void back(const uint8_t i = 1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 114-121
    :linenos:

Diese Funktion ermöglicht es, in der :ref:`screenHistory <touchmenulibvscreenhistory>` i Schritte zurückzugehen, d.h. vorher bereits aufgerufene Screens erneut aufzurufen.
Während der ``for``-Schleife wird jeweils das oberste Element des Stacks entfernt, sodass der vorherige Screen nun an der Spitze des Stacks liegt. Das 
:ref:`screenHistoryLevel <touchmenulibvscreenhistorylevel>` wird um 1 verringert, da wir uns nach dem Entfernen des obersten Screens vom Stack eine Ebene tiefer befinden, als vorher.
Nach dem i-ten Schleifendurchlauf, wird :ref:`updateAll <touchmenulibvupdateall>` auf ``true`` gesetzt.


.. _TouchMenuLibGoTo:

bool goTo (const uint8_t id, const bool toHistory = true)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 124-132
    :linenos:

Diese Funktion ermöglicht es, zu einem bestimmten Screen innerhalb der :ref:`screenHistory <touchmenulibvscreenhistory>` zu navigieren.    

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 126

Wenn die übergebene ID in :ref:`screens <touchmenulibvscreens>` nicht gefunden werden kann, existiert kein Screen mit dieser ID und die Funktion gibt ``false`` zurück.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 128

Wenn der übergebene bool ``toHistory`` auf false gesetzt ist, wird der aktuelle Screen aus der :ref:`screenHistory <touchmenulibvscreenhistory>` entfernt. Des ist nützlich, 
falls, man keinen neuen Screen auf dem screenHistory Stack speichern will.

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 129-132

Wenn der ``toHistory`` jedoch auf true gesetzt ist, wird das :ref:`screenHistoryLevel <touchmenulibvscreenhistorylevel>` um 1 erhöht, die übergebene ID auf den Stack an oberster Stelle 
gespeichert und anschließend wird :ref:`updateAll<touchmenulibvupdateall>`

.. _TouchMenuLibSetInputEnter:

void setInputEnter()
~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 220-222
    :linenos:

Diese Funktion setzt :ref:`enter <inputventer>` des :ref:`inputs <touchmenulibvinput>` auf true. 

.. _TouchMenuLibSetInputRight:

void setInputRight()
~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 223-225
    :linenos:

Diese Funktion setzt :ref:`right <inputvright>` des :ref:`inputs <touchmenulibvinput>` auf true. 

.. _TouchMenuLibSetInputLeft:

void setInputLeft()
~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 226-228
    :linenos:

Diese Funktion setzt :ref:`left <inputvleft>` des :ref:`inputs <touchmenulibvinput>` auf true. 


.. _TouchMenuLibSetInputUp:

void setInputUp()
~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 229-231
    :linenos:

Diese Funktion setzt :ref:`up <inputvup>` des :ref:`inputs <touchmenulibvinput>` auf true. 


.. _TouchMenuLibSetInputDown:

void setInputDown()
~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 232-234
    :linenos:

Diese Funktion setzt :ref:`down <inputvdown>` des :ref:`inputs <touchmenulibvinput>` auf true. 


.. _TouchMenuLibSetScreenSaver:

void setScreensaver(const uint8_t screenID, unsigned long time, bool backOnInput = true)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 241-247
    :linenos:

Mit dieser Funktion lässt sich ein Bildschirmschoner erstellen, der nach einer bestimmten Zeit (``time``) einsetzt. Dabei ist ``screenID``
die ID, mit der sich der Screensaver aufrufen lässt und mit ``backOnInput`` wird angegeben, ob nach Ende des Bildschirmschoners der zuletzt aufgerufene Screen wieder angezeigt werden soll.



.. _TouchMenuLibEnableScreenSaver:

bool enableScreenSaver ()
~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 249-252
    :linenos:

Diese Funktion setzt :ref:`isScreensaverEnable<touchmenulibvisscreensaverenable>` auf ``true``, wenn eine :ref:`ScreensaverID<touchmenulibvscreensaverid>` gesetzt wurde.

.. _TouchMenuLibDisableScreenSaver:

void disableScreenSaver ()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 254-256
    :linenos:

Diese Funktion setzt :ref:`isScreensaverEnable<touchmenulibvisscreensaverenable>` auf ``false`` und sorgt dafür, dass kein Bildschirmschoner mehr einsetzt.


.. _TouchMenuLibgetdisplay:

Display& getDisplay()
~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 236-239
    :linenos:

Diese Funktion gibt :ref:`display<touchmenulibvdisplay>` zurück. Falls dieses noch nicht initialisiert war, wird es zuerst initialisiert.

.. _TouchMenuLibgetScreenID:

uint8_t getScreenID()
~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 280-282
    :linenos:

Gibt die ID des aktuellen Screens zurück.

.. _TouchMenuLibgetscreensnumber:

uint8_t getScreensNumber()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/TouchMenuLib.cpp
    :lines: 284-286
    :linenos:

Gibt die Anzahl an Screens in :ref:`screens<touchmenulibvscreens>` zurück.




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
Der erste hier gespeicherte :ref:`Screens <screen>`, der Screen mit der ID 1, wird auch als Homescreen bezeichnet.


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

Gibt Informationen zu den Eingaben des Benutzers an, wie z.B. bei Berührungen (siehe :ref:`input<input>` )

.. _TouchMenuLibVscreensaverbackoninput:

bool screensaverBackOnInput = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob nach Ende des Bildschirmschoners (also wenn während der Bildschirmschoner aktiv ist ein Input durchgeführt wird), 
der vor Einsetzen des Bildschirmschoners aktive ``Screen`` angezeigt werden soll (``screensaverBackOnInput = true``) oder ob der Homescreen angezeigt werden soll
(``screensaverBackOnInput = false``).

.. _TouchMenuLibVisscreensaverenable:

bool isScreensaverEnable = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob ein Bildschirmschoner nach einer gewissen Zeit einsetzen soll.

.. _TouchMenuLibVscreensavertime:

unsigned long screensaverTime = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Die Zeit in Millisekunden die vergehen muss, damit der Bildschirmschoner einsetzt.

.. _TouchMenuLibVscreensavertimer:

unsigned long screensaverTimer = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Die Zeit in Millisekunden die bereits vergangen ist. Wird benötigt, um zu prüfen, wann :ref:`screensaverTime<touchmenulibvscreensavertime>` erreicht wird.

.. _TouchMenuLibVscreensaverid:

uint8_t screensaverID = UINT8_MAX
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Eine ID bzw. einzigartiger Schlüssel, um den Bildschirmschoner aufzurufen.


.. _TouchMenuLibVinputtimer:

unsigned long inputTimer = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, nach wie viele Millisekunden der letzte Input getätigt wurde. Das ist wichtig, um Eingaben besser und effizienter verarbeiten zu können.

.. _TouchMenuLibVdisablesidebarautomatic:

bool disableSidebarAutomatic = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob eine Sidebar automatisch deaktivierbar sein soll (also ob diese ohne eigenes Wirken verschwinden soll).
(Anmerkung: Derzeit ist keine Funktion implementiert, die dies könnte)

.. _TouchMenuLibVupdateall:

bool updateAll = true
~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob Änderungen vorgenommen wurden. Wenn ja, wird in :ref:`loop<touchmenulibloop>` die :ref:`draw<touchmenulibdraw>` Funktion aufgerufen, um all diese Änderungen zu zeichnen.