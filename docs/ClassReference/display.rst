.. _display:

Display
++++++++

Beschreibung
=============
``Display`` ist eine abstrakte Klasse, die als Schnittstelle zwischen :ref:`Menü <touchmenulib>` und dem Ausgabegerät fungiert.
Von dieser Klasse erbt :ref:`DisplayTFTeSPI<displaytftespi>`


Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    virtual, ":ref:`~Display <displayDestructor>` ()" 
    virtual void, ":ref:`init <displayinit>` () = 0"
    virtual void, ":ref:`rect <displayrectinfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color) = 0"
    virtual void, ":ref:`rect_center <displayrectcenterinfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color) = 0"
    virtual void, ":ref:`rect <displayrectnoinfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color) = 0"
    virtual void, ":ref:`rect_center <displayrectcenternoinfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color) = 0"
    virtual void, ":ref:`circle <displaycircleinfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color, const Color& infill_color) = 0"
    virtual void, ":ref:`circle <displaycirclenoinfill>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color) = 0"
    virtual void, ":ref:`triangle <displaytriangleinfill>` (const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color, const Color& infill_color) = 0"
    virtual void, ":ref:`triangle <displaytrianglenoinfill>` (const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color) = 0"
    virtual void, ":ref:`text <displaytext>` (const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const char* text, const Color& text_color) = 0"
    virtual void, ":ref:`text_center <displaytextcenter>` (const uint16_t pos_x, const uint16_t pos_y, const uint8_t text_size, const char* text, const Color& text_color) = 0"
    virtual void, ":ref:`line <displayline>` (const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color& color) = 0"
    virtual void, ":ref:`point <displaypoint>` (const uint16_t x1, const uint16_t y1, const Color& color) = 0"
    virtual void, ":ref:`fillScreen <displaypoint>` (const Color& color) = 0"
    virtual void, ":ref:`drawBitmap <displaydrawbitmapnobgcolor>` (const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor) = 0"
    virtual void, ":ref:`drawBitmap <displaydrawbitmapbgcolor>` (const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor, const Color& bgcolor) = 0"
    virtual int16_t, ":ref:`getHeight <displaygetheight>` () = 0"
    virtual int16_t, ":ref:`getWidth <displaygetwidth>` () = 0"
    virtual uint8_t, ":ref:`getRotation <displaygetrotation>` () = 0"
    virtual uint8_t, ":ref:`setRotation <displaysetrotation>` (uint8_t rotation) = 0"
    virtual bool, ":ref:`getTouch <displaygettouch>` (uint16_t* x, uint16_t* y) = 0"
    virtual bool, ":ref:`startTouchCalibration <displaystarttouchcalibration>` ()"
    void, ":ref:`drawItem <displaydrawitemcolor>` (uint16_t x, uint16_t y, Item* item, const Color& color)"
    void, ":ref:`drawItem <displaydrawitemnocolor>` (uint16_t x, uint16_t y, Item* item)"
    static ":ref:`Item*<item>`", ":ref:`createItem <displaycreateitemnocolor>` (const std::string str)"
    static ":ref:`Item*<item>`", ":ref:`createItem <displaycreateitemcolor>` (const std::string str, const Color& color)"
    static ":ref:`Color<color>`", ":ref:`parseColor<displayparsecolor>` (const std::string& str, const Color& color)"
    static std::string, ":ref:`processText<displayprocesstext>` (const std::string& input)"
    static uint16_t, ":ref:`stringToNumber<displaystringtonumberuint16_t>` (const std::string& str, const uint16_t& value)"
    static double, ":ref:`stringToNumber<displaystringtonumberdouble>` (const std::string& str, const double& value)"
   


Funktionen Beschreibung
=========================


.. _displayDestructor:

virtual ~Display()
~~~~~~~~~~~~~~~~~~~~

Der Destruktor wird bei der Zerstörung eines ``Display`` Objektes aufgerufen.

.. _displayInit:

virtual void init() = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespiinit>`)

.. _displayRectInfill:

virtual void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespiRectInfill>`)

.. _displayRectCenterInfill:

virtual void rect_center(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color, const Color& infill_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespirectcenterinfill>`)

.. _displayRectNoInfill:

virtual void rect(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespiRectNoInfill>`)

.. _displayRectCenterNoInfill:

virtual void rect_center(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const uint8_t border_size, const uint8_t border_radius, const Color& border_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespirectcenternoinfill>`)

.. _displayCircleInfill:

virtual void circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color, const Color& infill_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespiCircleInfill>`)

.. _displayCircleNoInfill:

virtual void circle(const uint16_t pos_x, const uint16_t pos_y, const uint16_t d, const uint8_t border_size, const Color& border_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespicirclenoinfill>`)


.. _displayTriangleInfill:

virtual void triangle(const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color, const Color& infill_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespitriangleinfill>`)

.. _displayTriangleNoInfill:

virtual void triangle(const uint16_t pos_x0, const uint16_t pos_y0, const uint16_t pos_x1, const uint16_t pos_y1, const uint16_t pos_x2, const uint16_t pos_y2, const uint8_t border_size, const Color& border_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespitrianglenoinfill>`)

.. _displayText:

virtual void text(const uint16_t pos_x, const uint16_t pos_y, const uint16_t width, const uint16_t height, const char* text, const Color& text_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespiText>`)

.. _displayTextCenter:

virtual void text_center(const uint16_t pos_x, const uint16_t pos_y, const uint8_t text_size, const char* text, const Color& text_color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespitextcenter>`)


.. _displayLine:

virtual void line(const uint16_t x1, const uint16_t y1, const uint16_t x2, const uint16_t y2, const Color& color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespiLine>`)


.. _displayPoint:

virtual void point(const uint16_t x1, const uint16_t y1, const Color& color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespiPoint>`)

.. _displayFillScreen:

virtual void fillScreen (const Color& color) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespifillscreen>`)


.. _displayDrawBitmapNoBgColor:

virtual void drawBitmap(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespiDrawBitmapNoBgColor>`)

.. _displayDrawBitmapBgColor:

virtual void drawBitmap(const uint16_t x, const uint16_t y, const uint16_t w, const uint16_t h, const uint8_t* bitmap, const Color& fgcolor, const Color& bgcolor) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespidrawbitmapbgcolor>`)


.. _displayGetHeight:

virtual int16_t getHeight() = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displayttftespigetheight>`)


.. _displayGetWidth:

virtual int16_t getWidth() = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespigetwidth>`)



.. _displayGetRotation:

virtual uint8_t getRotation() = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespigetrotation>`)



.. _displaySetRotation:

virtual void setRotation(uint8_t rotation) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespisetrotation>`)

.. _displayGetTouch:

virtual bool getTouch(uint16_t* x, uint16_t* y) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`DisplayTFTeSPI <displaytftespigettouch>`)


.. _displayStartTouchCalibration:

virtual void startTouchCalibration() {}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.h
    :lines: 57
    :linenos:

LEER

.. _displayDrawItemColor:

void drawItem (uint16_t x, uint16_t y, Item* item, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.cpp
    :lines: 7-9
    :linenos:

Diese Funktion ruft die :ref:`draw<itemdrawcolor>` Funktion der ``Item`` Klasse auf, um ein ``Item`` Objekt in einer Farbe (``color``) auf dem aktuellen Display (``this``) bei
gewünschten X- und Y-Koordinaten zu zeichnen.

.. _displayDrawItemNoColor:

void drawItem (uint16_t x, uint16_t y, Item* item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.cpp
    :lines: 12-14
    :linenos:

Diese Funktion ruft die :ref:`draw<itemdrawcolor>` Funktion der ``Item`` Klasse auf, um ein ``Item`` Objekt auf dem aktuellen Display (``this``) bei
gewünschten X- und Y-Koordinaten zu zeichnen.

.. _displayCreateItemNoColor:

static Item* createItem(const std::string str)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.cpp
    :lines: 103-105
    :linenos:

Diese Funktion ruft die :ref:`createItem<displaycreateitemcolor>` Funktion auf, um ein :ref:`Item<item>` aus einem String in der Standardfarbe schwarz zu erstellen.
Der String muss dabei in der Form ``type:name`` angegeben werden. Für ``type`` kann u.a. zwischen ``icon`` (um ein :ref:`Icon<icon>` zu erstellen), ``symb`` (um ein :ref:`Symbol<symbol>` zu erstellen), 
``text`` (um einen :ref:`Text<text>` zu erstellen) und ``file`` entschieden werden. Für ``name`` hingegen kann ein beliebiger Name gewählt werden. Namen dürfen auch doppelt gewählt werden.

.. _displayCreateItemColor:

static Item* createItem(const std::string str, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.cpp
    :lines: 108-174
    :linenos:

Diese Funktion erstellt ein :ref:`Item<item>` aus einem String in einer spezifischen Farbe (``defaultColor``).
Der String muss dabei in der Form ``type:name`` angegeben werden. Für ``type`` kann u.a. zwischen ``icon`` (um ein :ref:`Icon<icon>` zu erstellen), ``symb`` (um ein :ref:`Symbol<symbol>` zu erstellen), 
``text`` (um einen :ref:`Text<text>` zu erstellen) und ``file`` entschieden werden. Für ``name`` hingegen kann ein beliebiger Name gewählt werden. Namen dürfen auch doppelt gewählt werden.

.. literalinclude:: ../../src/Display.cpp
    :lines: 109-111

Zuerst werden die zwei Strings ``type`` und ``name`` erstellt, in denen später der eingegebene Typ und Name gespeichert wird.
Die Variable ``size`` legt bei der späteren Erstellung eines :ref:`Icons<icon>` /:ref:`Symbols<symbol>` /:ref:`Texts<text>` die Größe, ``scale`` den Skalierungsfaktor von  :ref:`Icons<icon>` /:ref:`Symbolen<symbol>`
und ``width`` und ``height`` die Breite und Höhe von :ref:`Symbolen<symbol>` fest.

.. literalinclude:: ../../src/Display.cpp
    :lines: 113-115

Wir kopieren die ``defaultColor`` in eine neue :ref:`Color<color>` ``color`` mithilfe des :ref:`Color<colorconstructor4>` Konstruktors, um später potenziell einige Änderungen daran zu machen.
Außerdem wird mit `std::istringstream <https://cplusplus.com/reference/sstream/istringstream/>`_ der Eingabestring ``str`` verarbeitet, um die einzelnen Komponenten (also ``type``, ``:`` und ``name``)
identifizieren und aufteilen zu können. Der String ``word`` wird ebenfalls für diese Identifikation genutzt werden.

.. literalinclude:: ../../src/Display.cpp
    :lines: 117

Sollte kein String eingegeben worden sein, so wird ein leerer Text zurückgegeben.  

.. literalinclude:: ../../src/Display.cpp
    :lines: 119-123

Die ``while`` Schleife liest die einzelnen Komponenten aus ``iss`` und speichert sie in ``word``. In ``colonPos`` wird dann die Position des Doppelpunktes innerhalb von ``word`` gespeichert. Nun lässt
sich identifizieren, wo sich ``type`` und ``name`` befinden. In ``key`` wird schließlich das Schlüsselwort gespeichert, welches auf den ``type`` schließen lässt. In ``value`` wird schließlich der ``name`` identifiziert und gespeichert.

.. literalinclude:: ../../src/Display.cpp
    :lines: 126-129

Anschließend wird in ``type`` ``key`` gespeichert, solange ``key`` eine der genannten Möglichkeiten ist und solange in ``type`` nicht bereits ein anderer Wert gespeichert ist.
Sollte ``key`` den Wert ``"text"`` haben, wird ``value`` durch :ref:`processText<displayprocesstext>` verarbeitet und das Ergebnis wird in ``name`` gespeichert. ``value`` bzw. ``name``
enstspricht dann einem Text, der angezeigt werden soll (Wichtig zu beachten ist, dass Text in der Form ``text:hello_world`` und nicht ``test:hello world`` angegeben werden müssen, mehr dazu in der entsprechenden Funktion). Wenn dies nicht der Fall ist, wird ``value`` direkt in ``name`` kopiert.

.. literalinclude:: ../../src/Display.cpp
    :lines: 133-146

Mithilfe dieses Codeblocks können auch andere Parameter identifiziert und erstellt werden. So kann mit dem ``key`` ``"color"`` die Hauptfarbe von ``color``
(siehe :ref:`parseColor<displayparsecolor>`, :ref:`setPrimaryColor<colorvoidsetprimarycolor>`) oder mit ``"border"`` die Umrandungsfarbe von ``color`` 
(siehe :ref:`parseColor<displayparsecolor>`, :ref:`setBorderColor<colorvoidsetbordercolor>`) verändert werden.  

.. literalinclude:: ../../src/Display.cpp
    :lines: 149-154

Falls kein ``type`` definiert wurde, wird es standardmäßig auf ``"text"`` gesetzt und die While Schleife wird abgebrochen. 

.. literalinclude:: ../../src/Display.cpp
    :lines: 156-157

Falls kein ``name`` oder ``type`` spezifiziert wurde, wird ein Warnhinweis auf dem Display gezeichnet.  

.. literalinclude:: ../../src/Display.cpp
    :lines: 159-160

Wenn der ``type`` ``"text"`` ist, so wird mit dem :ref:`Text<textconstructor>` Konstruktor ein :ref:`Text<text>` Objekt mit ``name`` als Textinhalt erstellt. 

.. literalinclude:: ../../src/Display.cpp
    :lines: 162-165

Wenn der ``type`` ``"icon"`` ist, so wird die :ref:`create<iconcreate>` Funktion für ein neues :ref:`Icon<icon>` Objekt ``icon`` aufgerufen.

.. literalinclude:: ../../src/Display.cpp
    :lines: 162-165

Wenn der ``type`` ``"symb"`` ist, so wird die :ref:`create<symbolcreate>` Funktion ein neues :ref:`Symbol<symbol>` Objekt erstellt. 


.. literalinclude:: ../../src/Display.cpp
    :lines: 173

Sollte keines der oben genannten Objekte erstellt werden können, weil die Bedinungen nicht erfüllt sind, wird eine Fehlermeldung auf dem Display angezeigt.



.. _displayParseColor:

static Color parseColor(const std::string& str, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.cpp
    :lines: 17-37
    :linenos:

Diese Funktion wird von der :ref:`createItem<displaycreateitemcolor>` Funktion aufgerufen, um aus dem dort ermittelten ``value`` eine Farbe zu identifizieren. 
Dieser String ``str`` kann in der Form ``r,g,b`` angegeben werden, wobei jeweils natürliche Zahlen von 0 bis 255 anstelle von ``r``, ``g`` und ``b`` eingegeben werden müssen 
(z.B. ``255,255,255`` für weiß).

.. literalinclude:: ../../src/Display.cpp
    :lines: 19-21

Eine weitere Methode ist die direkte Eingabe der gewünschten Farbe, wobei standardmäßig nur die Farben Gelb, Grau und Rot implementiert sind. Bei Eingabe der entsprechenden Strings, wird 
dieser :ref:`Color<colorconstructor13>` Konstruktor aufgerufen, um die richtige Farbe zurückzugeben.

.. literalinclude:: ../../src/Display.cpp
    :lines: 23-24

Nun wird mit `std::istringstream <https://cplusplus.com/reference/sstream/istringstream/>`_ der Eingabestring ``str`` verarbeitet, um die einzelnen Komponenten (also ``r``, ``,``, ``g``, ``,``, ``b``)
identifizieren und aufteilen zu können. Der String ``token`` wird ebenfalls für diese Identifikation genutzt werden. 

.. literalinclude:: ../../src/Display.cpp
    :lines: 25-27

In dem Array ``rgb`` sollen die RGB Werte einzeln gespeichert werden.
Die Variable ``arrayPos`` wird u.a. zum iterieren dieses Arrays genutzt. Das Array wird außerdem vollständig mit ``0`` gefüllt, um Fehler zu vermeiden.

.. literalinclude:: ../../src/Display.cpp
    :lines: 28-31

In diesem Codeabschnitt werden die einzelnen Werte für ``r``, ``g`` und ``b`` in das ``rgb`` Array gelegt und das so lange, bis alle drei Werte im Array liegen.   

.. literalinclude:: ../../src/Display.cpp
    :lines: 33

Nach Durchlaufen der ``while`` Schleife wird schließlichaus mit den Werten im ``rgb`` Array durch den Aufruf des :ref:`Color<colorconstructor13>` Konstruktors ein neues ein neues :ref:`Color<color>` Objekt zurückgegeben.

.. literalinclude:: ../../src/Display.cpp
    :lines: 36

Sollte die while Schleife nicht durchlaufen worden sein, wird ``color`` genauso wiederzurückgegeben.

.. _displayProcessText:

static std::string processText(const std::string& input)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.cpp
    :lines: 40-62
    :linenos:

Diese Funktion wird von der :ref:`createItem<displaycreateitemcolor>` Funktion aufgerufen, um aus dem dort ermittelten ``value`` einen Text zu identifizieren. 
Texte müssen in der Form ``hello_world`` angegeben werden und nicht in der Form ``hello world``. Ersteres erzeugt den Output ``hello world`` während zweiteres nichts nach dem Wort ``hello`` ausgibt.

.. literalinclude:: ../../src/Display.cpp
    :lines: 44-47

Möchte man in seiner Ausgabe einen Unterstrich ``_`` mit einbauen, so muss in der Eingabe ein doppelter Unterstrich ``__`` angegeben werden. Dieser wird zunächst 
durch ein Platzhalter Symbol ``#@@$~`` ersetzt. Die Umwandlung zu einem einfachen Unterstrich ``_`` erfolgt im übernächsten Codeabschnitt.

.. literalinclude:: ../../src/Display.cpp
    :lines: 50-53

Zunächst erfolgt jedoch die Umwandlung des einfachen Unterstrichs ``_`` zu einem Leerzeichen, um eine Ausgabe wie sie im Einleitungsteil dieser Funktion beschrieben ist, zu erhalten.

.. literalinclude:: ../../src/Display.cpp
    :lines: 56-59

Schließlich erfolgt die Umwandlung des Plazhalters ``#@@$~`` zum einfachen Unterstrich ``_``.
Sollte es gewünscht sein, dass die Ausgabe einen doppelten Unterstrich enthält, muss ein vierfacher Unterstrich ``____`` in der Eingabe verwendet werden, für einen dreifachen Unterstrich ein sechsfacher etc.

.. literalinclude:: ../../src/Display.cpp
    :lines: 61

Das Ergebnis wird zurückgegeben.    

.. _displayStringToNumberuint16_t:

static uint16_t stringToNumber(const std::string& str, const uint16_t& value)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.cpp
    :lines: 65-79
    :linenos:

.. _displayStringToNumberdouble:

static double stringToNumber(const std::string& str, const double& value)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Display.cpp
    :lines: 82-100
    :linenos: