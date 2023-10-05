.. _quickstartguide:

Quickstart Guide
+++++++++++++++++

In diesem Guide wird ein simples Programm mithilfe dieser Library zu erstellen. Der Quickstart Guide knüpft nahtlos an der :ref:`Installation<installation>`.
Stelle sicher, dass Microcontroller und Bildschirm an den PC angeschlossen sind.

Schritt 1: Dateien anlegen
=========================================
| 1. Lege innerhalb vom **TouchMenuLib** Ordner einen Ordner **Tutorial** an. Minimiere dafür alle Untermenüs und drücke mit der rechten Maustaste auf eine leere Stelle und wähle **New Folder...**.
| 2. Drücke mit der rechten Maustaste auf diesen Ordner und wähle **New File...**. Gib als Namen **my-program.ino** ein. Sollte in der unteren rechten Ecke eine Hinweisemeldung erscheinen, drücke auf das x und schließe sie.
| 3. Gehe in die **main.cpp** des TouchMenu. Diese befindet sich unter **src**. 
| 4. Setze vor dem angezeigten ``#include ...`` ein **//** um diese Zeile auszuklammern.
| 5. Schreibe anschließend **#include "../Tutorial/my-prgram.ino"** in eine neue Zeile.
| 6. Drücke in der unteren Leiste auf **PlatformIO: Upload**. Es sollte eine Fehlermeldung ausgegeben werden, da unsere Datei noch leer ist.


Schritt 2: Grundstruktur erstellen
=========================================
| 1. Kehre zu **my-program.ino** zurück.
| 2. Füge **#include "TouchMenuLib.h"** in die Datei ein. Dadurch kann auf die Klassen und Funktionen der Bibliothek zugegriffen werden.
| 3. Erstelle folgende zwei Funktionen:

.. code-block:: 

    void setup(){
    }

    void loop(){
    }

| Diese sind die wichtigsten beiden Funktionen, um ein Programm zum laufen zu bringen. ``setup()`` wird nur direkt zu Beginn des Programmstarts aufgerufen und ausgeführt, hingegen wird ``loop()`` durchgängig während der Programmlaufzeit ausgeführt wird.

| 4. Nun erstellen wir ein :ref:`TouchMenuLib<touchmenulib>` Objekt über der ``setup()`` Funktion.

.. code-block:: 

    TouchMenuLib TML;

| 5. In ``loop()`` rufen wir die :ref:`loop<touchmenulibloop>` Funktion des ``TML`` auf. Der ganze Programmcode sieht nun wie folgt aus:

.. code-block:: 

    TouchMenuLib TML;

    void setup(){
    }

    void loop(){
        TML.loop();
    }

| 6. Drücke nun erneut auf **PlatformIO: Upload**. Der Upload sollte nun nicht mehr fehlschlagen. Auf dem Bildschirm wird jedoch weiterhin der zu letzt angezeigt Screen angezeigt (wenn zuvor etwas auf dem Screen angezeigt wurden war). Jedoch kann mit diesem nicht mehr interagiert werden.

Schritt 3: GridScreen erstellen
=========================================
| 1. Wir wollen nun einen leeren :ref:`GridScreen<grid>` erstellen. Dieser soll jeweils vier Spalten und drei Zeilen haben. Außerdem müssen wir das ``TML`` Objekt noch initialisieren. Dafür verändern wir die ``setup()`` Funktion wie folgt:

.. code-block:: 

    void setup(){
        TML.init(0)
        CREATE_GRID_SCREEN(TML, 0, 4, 3, Color(0,0,0)
        )
    }

| Dabei ist ``CREATE_GRID_SCREEN`` ein Makro, welches für die Erstellung eines :ref:`GridScreen<grid>` zuständig ist. Dabei ist es wie folgt aufgebaut:
| ``CREATE_GRID_SCREEN(TML objekt, screenID, Spalten, Zeilen, Farbe)``
| Die ``ScreenID`` repräsentiert den Screen und ist nützlich, wenn Screens gewechselt werden sollen und ``Farbe`` ist die Hintergrundfarbe. Diese kann in der Form ``Color(r,g,b)`` angegeben werden oder durch Verwenden eines der :ref:`hier definierten<color>` Makros.
| 2. Drücke nun erneut auf **PlatformIO: Upload**. Auf dem Bildschirm sollte der gewünschte Screen angezeigt werden.
| 3. Ersetze ``Color(0,0,0)`` durch **COLOR_BLACK** und drücke erneut auf **PlatformIO: Upload**. Das Bild sollte unverändert sein.

.. code-block:: 

    void setup(){
        TML.init(0)
        CREATE_GRID_SCREEN(TML, 0, 4, 3, COLOR_BLACK
        )
    }

Schritt 4: Dem GridScreen Elemente hinzufügen
==================================================
| Wir wollen dem Screen zwei Elemente hinzufügen: Einen Slider und einen Button. Es gibt natürlich noch mehr Elemente, die sich unter :ref:`Element<element>` finden lassen. Fangen wir mit dem Slider an.
| 1. Füge ein neues Element hinzu, dieses soll von der Klasse :ref:`Number_Slider<number_slider>` sein und rot gefärbt sein.    


.. code-block:: 

    ExternalNumberValue numberValue;

    void setup(){
        TML.init(0)
        CREATE_GRID_SCREEN(TML, 0, 4, 3, COLOR_BLACK,
        AddElement(new Number_Slider(COLOR_RED, TML_empty_slider, &numberValue), 0, 0, 1, 3)
        )
    }

| Wir erstellen ein :ref:`ExternalNumberValue<externalnumbervalue>` Objekt, mit diesem lässt sich der Slider steuern.
| Mit ``AddElement()`` lässt sich ein neues Element hinzufügen. Achte darauf, dass nach ``COLOR_BLACK`` ein Komma gesetzt werden muss.
| ``TML_empty_slider`` ist ein Makro, welches bei der Erstellung von Slidern hilft.
| Die Zahlen zum Schluss geben die Koordinaten, die Breite und die Höhe des Sliders an.
| 2. Drücke nun erneut auf **PlatformIO: Upload**. Auf dem Screen sollte nun ein Slider sichtbar sein. Versuche ihn, zu bewegen. Im nächsten Schritt passen wir diesen weiter an.
| 3. Wir wollen, dass beim verschieben des Reglers eine andere Farbe angezeigt wird. Daher passen wir den Slider wie folgt an:

.. code-block:: 

    AddElement(new Number_Slider(COLOR_RED + COLOR_GREEN, TML_empty_slider, &numberValue))


| 4. Drücke nun erneut auf **PlatformIO: Upload** und ziehe ihn. Jetzt sollten Teile des Sliders grün werden. Als nächstes wollen wir einen Button hinzufügen.
| 5. Füge ein neues Element im setup hinzu, dieses soll von der Klasse :ref:`Button_Rect<rectbutton>` sein. Der Button soll eine blaue Farbe haben und beim Drücken auf ihn rot werden. Außerdem soll auf ihm ein Text ausgegeben werden.

.. code-block:: 

    void setup(){
        TML.init(0)
        CREATE_GRID_SCREEN(TML, 0, 4, 3, COLOR_BLACK,
        AddElement(new Number_Slider(COLOR_RED, TML_empty_slider, &numberValue), 0, 0, 1, 3),
        AddElement(new Button_Rect("Hello", COLOR_LIGHT_BLUE + COLOR_RED, 1, 1, TML_empty_Button), 2, 1, 1, 1),
        )
    }

| ``TML_empty_Button`` ist ein Makro, welches für Buttons verwendet werden kann, die keine spezielle Funktion haben sollen.
| 6. Drücke nun erneut auf **PlatformIO: Upload** und drücke den Button. Er wird nach wenigen Millisekunden wieder blau. Damit der Button seinen Zustand nicht automatisch wechselt, muss aus ihm ein Switch werden.
| 7. Tausche ``TML_empty_Button_`` mit ``TML_empty_Switch`` aus und drücke erneut auf **PlatformIO: Upload**. Betätige den Switch.    
| 8. Tausche ``TML_empty_Switch`` wieder mit ``TML_empty_Button_`` aus. Der gesamte Code sieht aktuell ungefähr so aus:

.. code-block:: 

    TouchMenuLib TML;
    ExternalNumberValue numberValue;

    void setup(){
        TML.init(0)
        CREATE_GRID_SCREEN(TML, 0, 4, 3, COLOR_BLACK,
        AddElement(new Number_Slider(COLOR_RED, TML_empty_slider, &numberValue), 0, 0, 1, 3),
        AddElement(new Button_Rect("Hello", COLOR_LIGHT_BLUE + COLOR_RED, 1, 1, TML_empty_Button), 2, 1, 1, 1)
        )
    }

    void loop(){
        TML.loop();
    }

Schritt 5: Mit dem Button zu einen anderen Screen wechseln.
=========================================================
Aktuell hat der Button noch keine großartige Funktion, das werden wir jetzt ändern.
| 1. Erstelle einen neuen, gelben GridScreen mit den Maßen 1x5. Dieser Screen bekommt die ID ``1``:

.. code-block:: 

    CREATE_GRID_SCREEN(TML, 0, 4, 3, COLOR_YELLOW)

| 2. Tausche beim Button ``TML_empty_Button`` mit ``TML_goTo(TML, 1)`` aus. Mit diesem Macro ruft Der Button den Screen mit der ID ``1`` auf.

.. code-block:: 

     AddElement(new Button_Rect("Hello", COLOR_LIGHT_BLUE + COLOR_RED, 1, 1, TML_goTo(TML, 1)), 2, 1, 1, 1),

| 3. Drücke nun erneut auf **PlatformIO: Upload** und drücke den Button. Du befindest dich nun in dem neu erstellten Screen. Versuche doch jetzt mal, einen eigenen Button im 2. Bildschirm zu erstellen, um zurück zum Startbildschirm zu kommen :)
| 
| Hiermit endet der Quickstart Guide. Du hast nun die ersten Grundlagen gesammelt, wie du mit der Bibliothek umgehen kannst. 
| Schau dir als nächsten am besten die beigelegten Beispielprogramme an, die sich im `examples <https://github.com/Coding-Alexx/TouchMenu/tree/main/examples>`_ Ordner befinden. Oder nutze das hier gebaute Programm, um noch ein wenig weiter herumzuexperimentieren.

