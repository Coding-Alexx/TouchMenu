.. _textbox:

ExternalTextboxValue
++++++++++++++

Beschreibung
=============

Tutorials/ Examples
=====================
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
    void, ":ref:`setup<externaltextboxvaluetextsize>` (const uint8_t _textsize)"
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

void setitem (Item* item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluedestructor:

~ExternalTextboxValue()
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluegetitem:

Item* getItem () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluegetvalue:

const char* getValue ()
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluegetcolor:

const Color& getColor ()
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluegetsize:

uint8_t getSize() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluehasvalue:

bool hasValue () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluehasupdate:

bool hasUpdate () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvalueresetupdate:

void resetUpdate ()
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluedraw:

void draw (const uint8_t x, const uint8_t y, Display* disp) const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluesetitemitemstr:

void setItem (char* itemStr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluesetitemitemstrcolor:

void setItem (char* itemStr, const Color& color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluesetitem_item:

void setItem (Item* _item)
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluesetvalue:

void setValue (const char* _value)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluedelvalue:

void delValue ()
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluesetcolor:

void setColor (const Color& _color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluesetupxy:

void setup(const uint8_t _sizeX, const uint8_t _sizeY)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluetextsize:

void setup(const uint8_t _textsize)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvalueoperator:

ExternalTextboxValue& operator+=(const char* str)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~





Variablen und Konstanten Beschreibung
=====================================

.. _externaltextboxvaluevitem:

Item* item = nullptr
~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluevvalue:

std::string value = ""
~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluevupdate:

bool update = false
~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluevisvalueset:

bool isValueSet = false
~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluevsizex:

uint8_t sizeX = 1
~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluevsizey:

uint8_t sizeY = 1
~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluevtextsize:

uint8_t textsize = 0
~~~~~~~~~~~~~~~~~~~~~~~~

.. _externaltextboxvaluevcolor:

Color color = Color(0,0,0)
~~~~~~~~~~~~~~~~~~~~~~~~~~~