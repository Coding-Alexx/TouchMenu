.. _icon:

Icon
+++++++++++++++

Beschreibung
=============
``Icons`` sind Grafiken/ Bilder, die vom Entwickler eingefügt werden können, um diese auf :ref:`Elementen<element>` anzeigen zu lassen.
Mit dieser Klasse lassen sich diese Grafiken anzeigen und erstellen. Es existieren außerdem eine Reihe an vordefinierten Icons.
Die Klasse erbt von  :ref:`Item<item>`.


Funktionen
=============

.. csv-table:: 
    :widths: 100 1000

     
    , ":ref:`Icon <iconconstructorwh>` (const unsigned char** bitmap, const uint16_t w, const uint16_t h, const double scale = 1, const Color& color = Color(0,0,0))"
    , ":ref:`Icon <iconconstructornowh>` (const unsigned char** bitmap, const double scale = 1, const Color& color = Color(0,0,0))"
    Icon*, ":ref:`create <iconcreate>` (const std::string str, const double scale, const Color& color)"
    Icon*, ":ref:`createIcon <iconcreateicon>` (const std::string str, const double scale, const Color& color)"
    void, ":ref:`draw <icondrawcolor>` (uint16_t x, uint16_t y, Display* disp, const Color& color) override"
    void, ":ref:`draw <icondraw>` (uint16_t x, uint16_t y, Display* disp) override"
    void, ":ref:`drawOn <icondrawOn>` (uint16_t x, uint16_t y, Display* disp) override"
    void, ":ref:`drawOff <icondrawOff>` (uint16_t x, uint16_t y, Display* disp) override"
    uint16_t, ":ref:`getWidth <icongetwidth>` () override"
    uint16_t, ":ref:`getHeight <icongetheight>` () override"
    void, ":ref:`setResolution <iconsetresolution>` (const uint16_t width, const uint16_t height, const bool override = false) override"



Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 1000

     
    const unsigned char**, ":ref:`bitmap <iconvbitmap>`"
    const ":ref:`Color <color>`", ":ref:`color <iconvcolor>`"
    uint8_t, ":ref:`resolution <iconvresolution>`"
    "const std::vector<uint16_t>", ":ref:`icon_resolutions<iconvvectorresolution>` = { 8, 8, 16, 16, 24, 24, 32, 32, 40, 40, 48, 48, 56, 56, 64, 64, 72, 72, 80, 80, 88, 88, 96, 96 }"




Funktionen Beschreibung
=========================

.. _iconConstructorwh:

Icon(const unsigned char** bitmap, const uint16_t w, const uint16_t h, const double scale = 1, const Color& color = Color(0,0,0))
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 13-17
    :linenos:

Der Konstruktor wird bei der Erzeugung eines neuen ``Icon`` Objektes aufgerufen. Als Parameter nimmt der Konstruktor eine ``Bitmap`` (``bitmap``), in der die Grafik gespeichert ist, den Skalierungsfaktor
(``scale``), welcher die Größe der Grafik beeinflusst und die Farbe, die die Bitmap erhalten soll (``color``). 
In der Initialisierungsliste werden die Variablen :ref:`bitmap<iconvbitmap>` und :ref:`color<iconvcolor>` mit den korrespondierenden Variablen initialisiert, 
außerdem erfolgt der Aufruf vom :ref:`Item<itemconstructor>` Konstruktor mit ``scale`` als Argument.


.. _iconConstructornowh:

Icon(const unsigned char** bitmap, const double scale = 1, const Color& color = Color(0,0,0))
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 19-23
    :linenos:

Der Konstruktor wird bei der Erzeugung eines neuen ``Icon`` Objektes aufgerufen. Als Parameter nimmt der Konstruktor eine ``Bitmap`` (``bitmap``), in der die Grafik gespeichert ist, 
die Breite (``w``) und Höhe (``h``) der Grafik, einen Skalierungsfaktor (``scale``), welcher die Größe der Grafik beeinflusst und die Farbe, die die Bitmap erhalten soll (``color``). 
In der Initialisierungsliste werden die Variablen :ref:`bitmap<iconvbitmap>` und :ref:`color<iconvcolor>` mit den korrespondierenden Variablen initialisiert, ebenso
erfolgt der Aufruf vom :ref:`Item<itemconstructor>` Konstruktor mit ``scale`` als Argument.
Außerdem wird die :ref:`setResolution<iconsetresolution>` Funktion aufgerufen.

.. _iconCreate:

Icon* create(const std::string str, const double scale, const Color& color);
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 25-30
    :linenos:

Diese Funktion nimmt den String ``str``, welcher den Namen des Icons enthalten soll, den Skalierungsfaktor ``scale``, welcher die Größe des Icons beeinflusst und die Farbe ``color``, welche die Farbe des Icons bestimmt.
Sie ruft die :ref:`createIcon<iconcreateicon>` Funktion auf und übergibt die genannten Parameter als Argumente. Die ``create`` Funktion hat sonst keine Funktionalität, sie existiert nur, um den Code etwas übersichtlicher zu gestalten, 
da sich :ref:`createIcon<iconcreateicon>` in einer anderen Datei befindet. Dort befinden sich auch mehr Informationen zum Aufbau des ``str``.


.. _iconCreateIcon:

Icon* createIcon(const std::string str, const double scale, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/icon_bitmaps.h
    :lines: 166-184
    :linenos:

Diese Funktion ist für das Erstellen von ``Icon`` Objekten zuständig. Als Parameter nimmt sie den String ``str``, 
welcher den Namen des Icons enthalten soll, den Skalierungsfaktor ``scale``, welcher die Größe des Icons beeinflusst und die Farbe ``color``, welche die Farbe des Icons bestimmt.

.. literalinclude:: ../../src/Item/icon_bitmaps.h
    :lines: 167-176

Um zu entscheiden, welche Art von ``Icon`` erstellt werden soll, werden mit ``if`` Abfragen mögliche Strings geprüft. Diese Bibliothek stellt 
insgesamt 10 verschiedene, konfigurierte Icons bereit. Die Icons werden in Bitmaps angegeben und lassen sich in 
`icon_bitmaps.h <https://github.com/Coding-Alexx/TouchMenu/blob/main/src/Item/icon_bitmaps.h>`_ finden. 
Im Rahmen dieser Dokumentation, schauen wir uns in beispielhafter Weise das ``back`` Icon in seiner kleinsten Form genauer an.

.. literalinclude:: ../../src/Item/icon_bitmaps.h
    :lines: 12

Das Array ``_ICON_back_8_8`` speichert die Bitmap des Icons, in diesem eines Zurückpfeils ``back``. Dabei ist das Icon 8x8 Pixel groß. Wenn Sie also ein eigenes ``Icon`` mit einer eingetragenen
Grafik erstellen wollen, sollte diese Form eingehalten werden. Um Bitmaps zu erstellen, kann entweder ein Online Tool 
(wie z.B. `convertio.io <https://convertio.co/de/bmp-jpg/>`_) oder der in dieser Bibliothek bereitgestellte 
`Preprozessor <https://github.com/Coding-Alexx/TouchMenu/blob/main/scripts/convert_icons_to_code.py>`_, der aus Grafiken Code erstellt. Dafür muss ein Ordner ``icon_templates`` 
im Hauptordner erstellt werden und in diesem müssen nur noch die Bilddateien eingefügt werden.

.. literalinclude:: ../../src/Item/icon_bitmaps.h
    :lines: 24

Werden mehrere Auflösungen vom selben Icon angelegt (wie es hier der Fall ist), müssen diese in ein Array gelegt werden, damit auch zwischen ihnen ja nach gewünschter Auflösung unterschieden werden kann.  


.. _iconDrawColor:

void draw(uint16_t x, uint16_t y, Display* disp, const Color& color) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 32-37
    :linenos:

Diese Funktion hat die Parameter ``x`` und ``y``, die die X- bzw. Y-Koordinaten repräsentieren, bei welchen das Icon auf dem :ref:`Display<display>` ``disp`` angezeigt werden soll, sowie die Farbe 
``color``, die das Icon haben soll.

Zuerst werden temporäre X- und Y-Koordinaten berechnet, die (basierend auf ``x`` bzw ``y``) zusätzlich die Auflösung der Icons mit einbezieht 
(``icon_resolution`` siehe :ref:`createIcon<iconcreateicon>`). Denn je nach Auflösung verändert sich auch die tatsächliche Position auf dem :ref:`Display<display>`.
Schließlich wir mit der :ref:`drawBitmap<displaydrawbitmapnobgcolor>` das Icon gezeichnet.



.. _iconDraw:

void draw(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 39-41
    :linenos:

Ruft die :ref:`draw<icondrawcolor>` Funktion mit :ref:`color<iconvcolor>` als Argument auf.

.. _iconDrawOn:

void drawOn(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 43-45
    :linenos:

Ruft die :ref:`draw<icondrawcolor>` Funktion mit :ref:`color<iconvcolor>` als Argument auf.
Diese Funktion wird verwendet, wenn ein :ref:`Element<element>` einen aktivierten und deaktivierten Zustand hat, und ein ``Icon`` für den aktivierten Zustand gezeichnet werden soll.

.. _iconDrawOff:

void drawOff(uint16_t x, uint16_t y, Display* disp) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 47-49
    :linenos:
    
Ruft die :ref:`draw<icondrawcolor>` Funktion mit :ref:`color<iconvcolor>`:ref:`.getSecondaryColor()<colorgetsecondarycolor>` als Argument auf.
Diese Funktion wird verwendet, wenn ein :ref:`Element<element>` einen aktivierten und deaktivierten Zustand hat, und ein ``Icon`` für den deaktivierten Zustand gezeichnet werden soll.


.. _icongetwidth:

uint16_t getWidth() override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 65
    :linenos:

Gibt die Breite eines ``Icon`` Objektes aus.
Mehr dazu unter :ref:`icon_resolutions<iconvvectorresolution>`.


.. _icongetheight:

uint16_t getHeight() override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 66
    :linenos:

Gibt die Höhe eines ``Icon`` Objektes aus.
Mehr dazu unter :ref:`icon_resolutions<iconvvectorresolution>`.


.. _iconsetresolution:

void setResolution(const uint16_t width, const uint16_t height, const bool override = false) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 51-63
    :linenos:

Mit dieser Funktion wir aus einer gewünschten Breite (``width``) und einer Höhe (``height``) die Auflösung für ein Icon bestimmt.
Durch ``const bool override = false`` wird die Auflösung nur dann festgelegt, wenn eine genaue Übereinstimmung gefunden wurde.

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 52-54

Die ``for`` Schleife durchläuft das :ref:`icon_resolutions<iconvvectorresolution>` Array in Zweierschritten, da die werte dort paarweise angegeben sind. 
Dabei wird die tatsächliche ``icon_width`` und ``icon_height`` bestimmt, indem der aus dem Array gespeicherte Wert mit dem Skalierungsfaktor 
:ref:`scale<itemvscale>` multipliziert wird.

.. literalinclude:: ../../src/Item/Icon.cpp
    :lines: 56-61

Anschließend werden ``icon_width`` und ``icon_height`` mit der gewünschten ``width`` und ``height`` verglichen, ob die Werte gleich oder kleiner sind. Wenn ja,
wird getestet ob nächstgrößere Auflösung nicht mehr in das Array passt (``(i + 2 >= icon_resolutions.size()``) oder größer ist als die angegebenen Werte 
(für die breite ``icon_resolutions[i + 2] > width`` oder für die Höhe ``icon_resolutions[i + 3] > height)``). Wenn auch das der Fall ist, wird 
:ref:`resolution<iconvresolution>` auf ``i`` gesetzt und die passende Auflösung wurde gefunden.

Variablen und Konstanten Beschreibung
=====================================

.. _iconvbitmap:

const unsigned char** bitmap
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Speichert die Bitmap einer Grafik, um sie dann später zeichnen zu können. 

.. _iconvcolor:

const Color color
~~~~~~~~~~~~~~~~~

Speichert die Farbe des ``Icon`` Objektes.

.. _iconvresolution:

uint8_t resolution = 0
~~~~~~~~~~~~~~~~~~~~~~~

Angabe der Auflösung eines Icons. 
Mehr dazu unter :ref:`icon_resolutions<iconvvectorresolution>`.

.. _iconvvectorresolution:

const std::vector<uint16_t> icon_resolutions = { 8, 8, 16, 16, 24, 24, 32, 32, 40, 40, 48, 48, 56, 56, 64, 64, 72, 72, 80, 80, 88, 88, 96, 96 }
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Gibt die möglichen Auflösungen eines Icons in Pixeln an. 
Dabei wird jeder ``uint16_t`` in diesem Vektor doppelt gespeichert, da der erste Wert die Breite und zweite die Höhe des Icons repräsentiert. 
Da unsere Icons alle ein 1:1 Bildformat haben, sind beide Werte jeweils identisch.