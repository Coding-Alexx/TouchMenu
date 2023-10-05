.. _externaltextboxvalue:

ExternalTextboxValue
++++++++++++++++++++++

Beschreibung
=============

``ExternalTextboxValue`` ermöglicht eine externe Steuerung von :ref:`Textbox<textbox>` Objekten.

Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    void, ":ref:`setItem<externaltextboxvaluesetitemitem>` (Item* item)"
    , ":ref:`~ExternalTextboxValue<externaltextboxvaluedestructor>` ()"
    ":ref:`Item*<item>`", ":ref:`getItem<externaltextboxvaluegetitem>` () const"
    const char*, ":ref:`getValue<externaltextboxvaluegetvalue>` () const"
    const ":ref:`Color&<color>`", ":ref:`getColor<externaltextboxvaluegetcolor>` () const"
    uint8_t, ":ref:`getSize<externaltextboxvaluegetsize>` () const"
    bool, ":ref:`hasValue<externaltextboxvaluehasvalue>` () const"
    bool, ":ref:`hasupdate<externaltextboxvaluehasupdate>` () const"
    void, ":ref:`resetUpdate<externaltextboxvalueresetupdate>` ()"
    void, ":ref:`draw<externaltextboxvaluedraw>` (const uint8_t x, const uint8_t y, Display* disp) const"
    void, ":ref:`setItem<externaltextboxvaluesetitemitemstr>` (char* itemStr)"
    void, ":ref:`setItem<externaltextboxvaluesetitemitemstrcolor>` (char* itemStr, const Color& color)"
    void, ":ref:`setItem<externaltextboxvaluesetitem_item>` (Item* _item)"
    void, ":ref:`setValue<externaltextboxvaluesetvalue>` (const char* _value)"
    void, ":ref:`delValue<externaltextboxvaluedelvalue>` ()"
    void, ":ref:`setColor<externaltextboxvaluesetcolor>` (const Color& _color)"
    void, ":ref:`setup<externaltextboxvaluesetupxy>` (const uint8_t _sizeX, const uint8_t _sizeY)"
    void, ":ref:`setup<externaltextboxvaluesetuptextsize>` (const uint8_t _textsize)"
    ExternalTextboxValue&, ":ref:`operator+=<externaltextboxvalueoperator>` (const char* str)"
    


Variablen und Konstanten
==========================


.. csv-table:: 
    :widths: 100 10000

    ":ref:`Item*<item>`", ":ref:`item<externaltextboxvaluevitem>` = nullptr"
    std::string, ":ref:`value<externaltextboxvaluevitem>` = "" "
    bool, ":ref:`update<externaltextboxvaluevupdate>` = false"
    bool, ":ref:`isValueSet<externaltextboxvaluevisvalueset>` = false"
    uint8_t, ":ref:`sizeX<externaltextboxvaluevsizex>` = 1"
    uint8_t, ":ref:`sizeY<externaltextboxvaluevsizey>` = 1"
    uint8_t, ":ref:`textSize<externaltextboxvaluevtextsize>` = 0"
    ":ref:`Color<color>`", ":ref:`color<externaltextboxvaluevcolor>` = Color(0,0,0)"

Funktionen Beschreibung
=========================


.. _externaltextboxvaluesetitemitem:

void setItem (Item* item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 19-22
    :linenos:

Diese Funktion löscht das :ref:`item<externaltextboxvaluevitem>` des Objektes und ersetzt es mit dem Wert des Parameters ``item``.
Anders als bei dieser :ref:`setItem<externaltextboxvaluesetitem_item>` Funktion, wird :ref:`update<externaltextboxvaluevupdate>` nicht angepasst.

.. _externaltextboxvaluedestructor:

~ExternalTextboxValue()
~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 24-27
    :linenos:

Dieser Destruktor löscht :ref:`item<externaltextboxvaluevitem>` und gibt den allokierten Speicherplatz frei. 

.. _externaltextboxvaluegetitem:

Item* getItem () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 29
    :linenos:

Gibt :ref:`item<externaltextboxvaluevitem>` aus.

.. _externaltextboxvaluegetvalue:

const char* getValue ()
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 30
    :linenos:

Gibt :ref:`value<externaltextboxvaluevvalue>` aus.

.. _externaltextboxvaluegetcolor:

const Color& getColor ()
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 31
    :linenos:


Gibt :ref:`color<externaltextboxvaluevcolor>` aus.

.. _externaltextboxvaluegetsize:

uint8_t getSize() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 33
    :linenos:

Gibt :ref:`textSize<externaltextboxvaluevtextsize>` aus.

.. _externaltextboxvaluehasvalue:

bool hasValue () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 34
    :linenos:

Gibt ``true`` zurück, falls :ref:`item<externaltextboxvaluevitem>` einen gültigen Wert besitzt oder wenn :ref:`isValueSet<externaltextboxvaluevisvalueset>` gilt.
Gibt ``false`` zurück, wenn keines von beiden der Fall ist, da :ref:`item<externaltextboxvaluevitem>` entweder der ``nullptr`` ist oder kein Wert gesetzt wurde.

.. _externaltextboxvaluehasupdate:

bool hasUpdate () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 35
    :linenos:

Prüft, ob es offene Änderungen gibt (:ref:`update<externaltextboxvaluevupdate>`) oder nicht.

.. _externaltextboxvalueresetupdate:

void resetUpdate ()
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 37
    :linenos:

Setzt :ref:`update<externaltextboxvaluevupdate>` zurück, wenn keine offenen Änderungen bestehen.

.. _externaltextboxvaluedraw:

void draw (const uint8_t x, const uint8_t y, Display* disp) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 39-44
    :linenos:

Zeichnet :ref:`item<externaltextboxvaluevitem>` und/oder :ref:`value<externaltextboxvaluevvalue>` auf das :ref:`Display<display>` ``disp``. Die Parameter ``x`` und ``y`` repräsentieren 
X- und Y- Koordinaten auf dem Display.

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 41

Falls ein :ref:`item<externaltextboxvaluevitem>` existiert, wird dieses mittels :ref:`draw<itemdraw>` Funktion auf ``disp`` an den angegebenen Koordinaten gezeichnet.

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 42

Sollte :ref:`isValueSet<externaltextboxvaluevisvalueset>` ``true`` sein und ``textSize == 0`` sein, so wird mit dem :ref:`Text<textconstructorsizexy>` Konstruktor 
ein :ref:`Text<text>` Objekt erschaffen, dessen Textgröße durch ``sizeX`` und ``sizeY`` bestimmt wird. Dieses wird mit :ref:`draw<textdraw>` auf dem ``disp`` gezeichnet.

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 43

Wurde hingegen eine ``textSize != 0`` angegeben, so wird diese beim Aufruf des :ref:`Text<textconstructor>` Konstruktor genutzt, um ein :ref:`Text<text>` Objekt zu erschaffen, welches mit
:ref:`draw<textdraw>` auf dem ``disp`` gezeichnet.       

.. _externaltextboxvaluesetitemitemstr:

void setItem (char* itemStr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 46
    :linenos:

Diese Funktion ruft die :ref:`createItem<displaycreateitemnocolor>` Funktion auf, um aus dem als Parameter angegebenen ``itemStr`` ein :ref:`Item<item>` Objekt 
zu erschaffen. Dieses Item wird beim Aufruf von :ref:`setItem<externaltextboxvaluesetitem_item>` als Argument verwendet. 

.. _externaltextboxvaluesetitemitemstrcolor:

void setItem (char* itemStr, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 47
    :linenos:

Diese Funktion ruft die :ref:`createItem<displaycreateitemcolor>` Funktion auf, um aus dem als Parameter angegebenen ``itemStr`` ein :ref:`Item<item>` Objekt in einer 
festgelegten Farbe ``color`` zu erschaffen. Dieses Item wird beim Aufruf von :ref:`setItem<externaltextboxvaluesetitem_item>` als Argument verwendet. 

.. _externaltextboxvaluesetitem_item:

void setItem (Item* _item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 48-52
    :linenos:

Diese Funktion löscht das :ref:`item<externaltextboxvaluevitem>` des Objektes und ersetzt es mit dem Wert des Parameters ``item``.
Anders als bei dieser :ref:`setItem<externaltextboxvaluesetitemitem>` Funktion, wird :ref:`update<externaltextboxvaluevupdate>` angepasst und auf ``true`` gesetzt, 
um zu vermerken, dass Änderungen vorliegen.

.. _externaltextboxvaluesetvalue:

void setValue (const char* _value)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 54-60
    :linenos:

Diese Funktion ersetzt :ref:`value<externaltextboxvaluevvalue>` mit dem Wert des Parameters ``value``, wodurch :ref:`isValueSet<externaltextboxvaluevisvalueset>` auf ``true`` gesetzt wird.
Außerdem wird das :ref:`item<externaltextboxvaluevitem>` gelöscht und der Pointer auf den ``nullptr`` gerichtet, da wir nun ein neues :ref:`value<externaltextboxvaluevvalue>` haben, welches nicht
mehr mit dem alten :ref:`item<externaltextboxvaluevitem>` zusammenhängt. Außerdem wird :ref:`update<externaltextboxvaluevupdate>` auf ``true`` gesetzt, 
um zu vermerken, dass Änderungen vorliegen.

.. _externaltextboxvaluedelvalue:

void delValue ()
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 62-66
    :linenos:

Diese Funktion löscht den Wert des :ref:`value<externaltextboxvaluevvalue>` und ersetzt ihn mit einem leeren String, wodurch :ref:`isValueSet<externaltextboxvaluevisvalueset>` auf ``false`` 
gesetzt wird. Außerdem wird :ref:`update<externaltextboxvaluevupdate>` auf ``true`` gesetzt, um zu vermerken, dass Änderungen vorliegen.

.. _externaltextboxvaluesetcolor:

void setColor (const Color& _color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 68-71
    :linenos:

Diese Funktion ersetzt :ref:`color<externaltextboxvaluevcolor>` mit dem Wert des Parameters ``color``.
Außerdem wird :ref:`update<externaltextboxvaluevupdate>` auf ``true`` gesetzt, um zu vermerken, dass Änderungen vorliegen.

.. _externaltextboxvaluesetupxy:

void setup(const uint8_t _sizeX, const uint8_t _sizeY)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 73-78
    :linenos:

Diese Funktion ersetzt :ref:`sizeX<externaltextboxvaluevsizex>` und :ref:`sizeY<externaltextboxvaluevsizey>` mit dem Wert der Parameter ``_sizeX`` bzw. ``_sizeY`` und setzt die 
:ref:`textSize<externaltextboxvaluevtextsize>` auf ``0``. Außerdem wird :ref:`update<externaltextboxvaluevupdate>` auf ``true`` gesetzt, um zu vermerken, dass Änderungen vorliegen.
Diese ``setup`` Funktion wird also verwendet, damit die ``textsize`` in der :ref:`draw<externaltextboxvaluedraw>` Funktion 
automatisch ermittelt wird.

.. _externaltextboxvaluesetuptextsize:

void setup(const uint8_t _textsize)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 80-85
    :linenos:

Diese Funktion setzt:ref:`sizeX<externaltextboxvaluevsizex>` und :ref:`sizeY<externaltextboxvaluevsizey>` auf ``0`` und ersetzt die :ref:`textSize<externaltextboxvaluevtextsize>`
mit dem Wert des Parameters ``_textsize``. 
Außerdem wird :ref:`update<externaltextboxvaluevupdate>` auf ``true`` gesetzt, um zu vermerken, dass Änderungen vorliegen.
Diese ``setup`` Funktion wird also verwendet, damit die ``textsize`` in der :ref:`draw<externaltextboxvaluedraw>` Funktion 
nicht automatisch ermittelt wird.

.. _externaltextboxvalueoperator:

ExternalTextboxValue& operator+=(const char* str)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Textbox.h
    :lines: 87-91
    :linenos:

Dieser Überladungsoperator wird genutzt, um ``str`` ``value`` anzuzufügen.
Außerdem wird :ref:`update<externaltextboxvaluevupdate>` auf ``true`` gesetzt, um zu vermerken, dass Änderungen vorliegen.


Variablen und Konstanten Beschreibung
=====================================

.. _externaltextboxvaluevitem:

Item* item = nullptr
~~~~~~~~~~~~~~~~~~~~~~~~

Gibt das :ref:`Item<item>` an, welches angezeigt werden soll.

.. _externaltextboxvaluevvalue:

std::string value = ""
~~~~~~~~~~~~~~~~~~~~~~~~

Gibt den Textinhalt an, welcher angezeigt werden soll.

.. _externaltextboxvaluevupdate:

bool update = false
~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob Änderungen vorliegen, die noch nicht gezeichnet werden (``update = true``) oder ob der auf dem Bildschirm ausgegebene Inhalt aktuell ist (``update = false``).
Standardmäßig gibt es keine nicht gezeichneten Änderungen.

.. _externaltextboxvaluevisvalueset:

bool isValueSet = false
~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob ein :ref:`value<externaltextboxvaluevvalue>` angegeben ist (``isValueSet = true``) oder nicht (``isValueSet = false``).
Standardmäßig ist :ref:`value<externaltextboxvaluevvalue>` ein leerer String ``""``, weswegen ``isValueSet = false`` gilt.

.. _externaltextboxvaluevsizex:

uint8_t sizeX = 1
~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, wie breit anzuzeigender Text sein soll.
Standardmäßig gilt ``sizeX = 1``, da dies die kleinstmögliche Breite ist.


.. _externaltextboxvaluevsizey:

uint8_t sizeY = 1
~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, wie hoch anzuzeigender Text sein soll.
Standardmäßig gilt ``sizeY = 1``, da dies die kleinstmögliche Höhe ist.

.. _externaltextboxvaluevtextsize:

uint8_t textsize = 0
~~~~~~~~~~~~~~~~~~~~~~~~

Gibt die Textgröße des anzuzeigenden Textes an.
Alternativ kann die Textgröße aus :ref:`sizeX<externaltextboxvaluevsizex>` und :ref:`sizeY<externaltextboxvaluevsizey>` bestimmt werden.

.. _externaltextboxvaluevcolor:

Color color = Color(0,0,0)
~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt die Farbe :ref:`Color<color>` des :ref:`item<externaltextboxvaluevitem>` an.