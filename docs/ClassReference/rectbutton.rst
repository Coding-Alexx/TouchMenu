.. _rectbutton:

RectButton
++++++++++

Beschreibung
=============


Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============

.. csv-table:: 
    :widths: 100 1000

    , ":ref:`RectButton<rectbuttonconstructorbuttonitemonoff>` (const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, ExternalButtonValue* const value=nullptr)"
    , ":ref:`RectButton<rectbuttonconstructorbuttonitem>` (const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, ExternalButtonValue* const value=nullptr)"
    , ":ref:`RectButton<rectbuttonconstructorbuttonitemonofflongpress>` (const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr)"
    , ":ref:`RectButton<rectbuttonconstructorbuttonitemlongpress>` (const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr)"
    , ":ref:`RectButton<rectbuttonconstructorswitchitemonoff>` (const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value=nullptr)"
    , ":ref:`RectButton<rectbuttonconstructorswitchitem>` (const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value=nullptr)"
    , ":ref:`RectButton<rectbuttonconstructorswitchitemonofflongpress>` (const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr)"
    , ":ref:`RectButton<rectbuttonconstructorswitchitemlongpress>` (const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr)"
    , ":ref:`~RectButton<rectbuttondestructor>` ()"
    void, ":ref:`draw<rectbuttondraw>` () override"
    uint16_t, ":ref:`getHeight<rectbuttongetheight>` ()"
    uint16_t, ":ref:`getWidth<rectbuttongetwidth>` ()"
    bool, ":ref:`checkSize<rectbuttonchecksize>` () override"







Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 1000

    const ":ref:`Color<color>`", ":ref:`color <rectbuttonvcolor>`"
    ":ref:`Item*<item>`", ":ref:`itemOn<rectbuttonvitemon>`"
    ":ref:`Item*<item>`", ":ref:`itemOff<rectbuttonvitemoff>`"
    const uint8_t, ":ref:`borderRadius<rectbuttonvborderradius>`"
    const uint8_t, ":ref:`borderSize<rectbuttonvbordersize>`"


Funktionen Beschreibung
=========================

.. _rectbuttonconstructorbuttonitemonoff:

RectButton(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, ExternalButtonValue* const value=nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _rectbuttonconstructorbuttonitem:

RectButton(const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, ExternalButtonValue* const value=nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _rectbuttonconstructorbuttonitemonofflongpress:

RectButton(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _rectbuttonconstructorbuttonitemlongpress:

RectButton(const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void()> button_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _rectbuttonconstructorswitchitemonoff:

RectButton(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value=nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _rectbuttonconstructorswitchitem:

RectButton(const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, ExternalButtonValue* const value=nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _rectbuttonconstructorswitchitemonofflongpress:

RectButton(const char* itemOn, const char* itemOff, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _rectbuttonconstructorswitchitemlongpress:

RectButton(const char* item, const Color& color, const uint8_t borderSize, const uint8_t borderRadius, const std::function<void(bool)> switch_callback, const std::function<void()> longpress_callback, ExternalButtonValue* const value=nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _rectbuttondestructor:

~RectButton()
~~~~~~~~~~~~~~

.. _rectbuttondraw:

void draw() override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _rectbuttongetheight:

uint16_t getHeight()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _rectbuttongetwidth:

uint16_t getWidth()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _rectbuttonchecksize:

bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Variablen und Konstanten Beschreibung
=====================================

.. _rectbuttonvcolor:

const Color color
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _rectbuttonvitemon:

Item* itemOn
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _rectbuttonvitemoff:

Item* itemOff
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _rectbuttonvborderradius:

const uint8_t borderRadius
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _rectbuttonvbordersize:

const uint8_t borderSize
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
