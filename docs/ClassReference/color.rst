.. _color:

Color
++++++++

Beschreibung
=============
Color verwaltet alles, was in irgendeiner Form mit Farben zu tun hat.

Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    , ":ref:`Color <colorcolorconstructor>` (const uint8_t r, const uint8_t g, const uint8_t b) : red(r), green(g), blue(b)"
    uint8_t, ":ref:`getRed <colorgetred>` () const"
    uint8_t, ":ref:`getGreen <colorgetgreen>` () const"
    uint8_t, ":ref:`getBlue <colorgetblue>` () const"
    Color&, ":ref:`operator= <colorassignmentoperator>` (const Color& other) const"
    , ":ref:`Color <colorcopyconstructor>` (const Color& other) : red(other.red), green(other.green), blue(other.blue)"
    , ":ref:`~Color <colordestructor>` ()"
    


Funktionen Beschreibung
=========================

.. _colorColorConstructor:

inline Color (const uint8_t r, const uint8_t g, const uint8_t b) : red(r), green(g), blue(b)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


.. _colorGetRed:

inline uint8_t getRed () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _colorGetGreen:

inline uint8_t getGreen () const 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _colorGetBlue:

inline uint8_t getBlue () const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _colorAssignmentOperator:

inline Color& operator= (const Color& other)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _colorCopyConstructor:

inline Color(const Color& other) : red(other.red), green(other.green), blue(other.blue)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _colorDestructor:

inline virtual ~Color()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
