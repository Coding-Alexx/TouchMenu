.. _slider_arrow:

Slider_Arrow
++++++++++++++

Beschreibung
=============

Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    inline, ":ref:`Slider_Arrow <slider_arrowconstructor>` (const Color& infill_color, const Color& triangle_color, const Color& border_color, const bool show_number, const slider_func_ptr slider_callback, uint16_t* value=nullptr)"
    inline, ":ref:`~Slider_Arrow <slider_arrowdestructor>` ()"
    inline void, ":ref:`draw <slider_arrowdraw>` ()"
    inline void, ":ref:`setTouch <slider_arrowsettouch>` (Inputs& input) override"
    inline bool, ":ref:`checkSize <slider_arrowchecksize>` (uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override"
    inline void, ":ref:`drawItem <slider_arrowdrawitem>` ()"
    inline void, ":ref:`loop <slider_arrowdraw>` (Inputs& input) override"

Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 10000

    const ":ref:`Color <Color>`", ":ref:`colorInfill <slider_arrowvcolorinfill>`"
    const ":ref:`Color <Color>`", ":ref:`colorTriangleOn <slider_arrowvcolortriangleon>`"
    const ":ref:`Color <Color>`", ":ref:`colorTriangleOff <slider_arrowvcolortriangleoff>`"
    const ":ref:`Color <Color>`", ":ref:`colorBorder <slider_arrowvcolorborder>`"
    const bool, ":ref:`showNumber <slider_arrowvshownumber>` = false"
    const ":ref:`Color* <Color>`", ":ref:`colorTriangle1 <slider_arrowvcolortriangle1>` = &colorTriangleOff"
    const ":ref:`Color* <Color>`", ":ref:`colorTriangle2 <slider_arrowvcolortriangle2>` = &colorTriangleOff"
    const uint16_t, ":ref:`borderDistance <slider_arrowvborderdistance>` = 10"
    const uint16_t, ":ref:`borderStrength <slider_arrowvborderstrength>` = 6"
    const uint16_t, ":ref:`borderRadius <slider_arrowvborderradius>` = 6"
    const uint16_t, ":ref:`triangleDistance <slider_arrowvtriangledistance>` = 2*borderDistance + borderStrength"
    uint16_t, ":ref:`triangleHeight <slider_arrowvcolorborder>`"
    bool, ":ref:`isVertical <slider_arrowvisvertical>` = false"
    const uint16_t, ":ref:`time <slider_arrowvtime>` = 300"
    bool, ":ref:`activateAnimation <slider_arrowvactiveanimation>` = true"
    unsigned long, ":ref:`timerTriang1 <slider_arrowvtimertriang1>` = 0"
    unsigned long, ":ref:`timerTriang2 <slider_arrowvtimertriang2>` = 0"



Funktionen Beschreibung
=========================

.. _slider_arrowConstructor:

inline Slider_Arrow(const Color& infill_color, const Color& triangle_color, const Color& border_color, const bool show_number, const slider_func_ptr slider_callback, uint16_t* value=nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowDestructor:

inline ~Slider_Arrow()
~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowDraw:

inline void draw()
~~~~~~~~~~~~~~~~~~~~


.. _slider_arrowSetTouch:

inline void setTouch(Inputs& input) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowCheckSize:

inline bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowDrawItem:

inline void drawItem()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowLoop:

inline void loop (Inputs& input) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Variablen und Konstanten Beschreibung
=====================================

.. _slider_arrowvcolorinfill:

const Color colorInfill
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvcolortriangleon:

const Color colorTriangleOn
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvcolortriangleoff:

const Color colorTriangleOff
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvcolorborder:

const Color colorBorder
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvshownumber:

const bool showNumber = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvcolortriangle1:

const Color* colorTriangle1 = &colorTriangleOff
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvcolortriangle2:

const Color* colorTriangle2 = &colorTriangleOff
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvborderdistance:

const uint16_t borderDistance = 10
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvborderstrength:

const uint16_t borderStrength = 6
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvborderradius:

const uint16_t borderRadius = 6
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvtriangledistance:

const uint16_t triangleDistance = 2*borderDistance + borderStrength
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvtriangleheight: 

uint16_t triangleHight
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvisvertical:

bool isVertical = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvtime:

const uint16_t time = 300
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvactiveanimation:

bool activateAnimation = true
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvtimertriang1:

unsigned long timerTriang1 = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _slider_arrowvtimertriang2:

unsigned long timerTriang2 = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~