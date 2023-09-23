.. _slider_rect:

SliderRect
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

    inline, ":ref:`Slider_Rect <sliderrectconstructor>` (const Color& infillOn_color, const Color& infillOff_color, const Color& slider_color, const Color& border_color, const slider_func_ptr slider_callback, uint16_t* value=nullptr)"
    inline void, ":ref:`draw <sliderrectdraw>` () override"
    inline void, ":ref:`setTouch <sliderRectSetTouch>` (Inputs& input) override"
    inline bool, ":ref:`checkSize <sliderRectSetTouch>` (uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override"

Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 10000

    const ":ref:`Color <Color>`", ":ref:`colorInfillOn <sliderrectvcolorinfillon>`"
    const ":ref:`Color <Color>`", ":ref:`colorInfillOff <sliderrectvcolorinfilloff>`"
    const ":ref:`Color <Color>`", ":ref:`colorBorder <sliderrectvcolorborder>`"
    const ":ref:`Color <Color>`", ":ref:`colorSlider <sliderrectvcolorslider>`"
    bool, ":ref:`isVertical <sliderrectvisvertical>` = false"
    const uint16_t, ":ref:`t <sliderrectvT>` = 10"
    const uint16_t, ":ref:`b <sliderrectvB>` = 10"
    const uint16_t, ":ref:`r <sliderrectvR>` = 6"

Funktionen Beschreibung
=========================

.. _sliderRectConstructor:

inline Slider_Rect(const Color& infillOn_color, const Color& infillOff_color, const Color& slider_color, const Color& border_color, const slider_func_ptr slider_callback, uint16_t* value=nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/Slider_Rect.h
    :lines: 10-16
    :linenos:

Diese Funktion ist ein Konstruktor, der einen rechteckigen Slider erzeugt. 
Als Parameter nimmt der Konstruktor eine ":ref:`Farbe<color>`" für die aktivierte (``infillOn_color``) und deaktivierte (``infillOff_color``) Seite des Sliders, für den Schieberegler 
(``slider_color``) und die Umrandung (``border_color``), die ":ref:`Callback<numberinputvslider_callback>`" Funktion ``slider_callback`` und einem ``value``, der angibt, ob das Objekt aktiviert oder deaktiviert ist.


In der Initialisierungsliste erfolgt zuerst der Aufruf vom ":ref:`NumberInput Konstruktor<numberinputconstructor>`".
Außerdem erfolgt die Initialisierung von ":ref:`colorInfillOn<sliderrectvcolorinfillon>`", ":ref:`colorInfillOff<sliderrectvcolorinfilloff>`", ":ref:`coloBorder<sliderrectvcolorborder>`" und ":ref:`colorSlider<sliderrectvcolorslider>`" mit den entsprechenden Parametern.


.. _sliderRectDraw:

inline void draw();
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/Slider_Rect.h
    :lines: 18-38
    :linenos:

Diese Funktion zeichnet Objekte der ``slider_rect`` Klasse. Für den Zeichenprozess ist es relevant, ob das Objekt vertikal oder horizontal ausgerichtet 
ist (":ref:`isVertical<sliderrectvisvertical>`").

.. literalinclude:: ../../src/ElementViews/Slider_Rect.h
    :lines: 23-29

Sollte ``isVertical==true`` gelten, soll das Objekt auch vertikal gezeichnet werden. Dafür wird zuerst die Variable ``sy`` erstellt, welche den Wert der ":ref:`sizeY<elementvsizey>`" annimmt 
abzüglich der Breite der Umrandung (":ref:`b<sliderrectvb>`") und dem Abstand zur Umrandung (":ref:`t<sliderrectvt>`"). Beide werden mit ``2`` multipliziert, da sich 
die Umrandung auf beiden Seiten des Elements befindet. Mit ``sliderPos`` wird die Y-Koordinate des Schiebereglers berechnet, bei welcher sich der Regler momentan befindet.
Zuerst zeichnent wir mit dem Funktionsaufruf von ":ref:`rect_center<displayrectcenterinfill>`" auf dem ":ref:`display<elementvdisplay>`" Objekt den deaktivierten Bereich des
Sliders, um dann beim ":ref:`rect<displayrectinfill>`" Funktionsaufruf den aktivierten Bereich des Sliders über Teile des deaktivierten Bereichs überzuzeichnen.
Schließlich wird durch den folgenden ":ref:`rect_center<displayrectcenterinfill>`" Funktionsaufruf der Schieberegler zwischen dem aktivierten und deaktivierten Bereich gezeichnet.

.. literalinclude:: ../../src/ElementViews/Slider_Rect.h
    :lines: 31-36

Sollte ``isVertical==false`` gelten, soll das Objekt horizontal statt vertikal gezeichnet werden. Der prinzipielle Ablauf bleibt aber der selbe.

.. _sliderRectSetTouch:

inline void setTouch(Inputs& input) override;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/Slider_Rect.h
    :lines: 40-60
    :linenos:

Um den Schieberegler des ``slider_rect`` Objekts auch verschieben zu können, muss mit dieser Funktion ermittelt werden, ob und wo der Benutzer das Objekt berührt.
Die Parameter ``x`` und ``y`` geben an, wo ":ref:`Display<display>`" berührt wird.

.. literalinclude:: ../../src/ElementViews/Slider_Rect.h
    :lines: 43-47

| Zuerst werden einige Variablen definiert, die den Code leserlicher machen sollen:
| ``x1`` entspricht der X-Koordinate, bei dem das Objekt anfängt.
| ``xr`` entspricht der X-Koordinate, bei dem das Objekt endet.
| ``y1`` entspricht der Y-Koordinate, bei dem das Objekt anfängt.
| ``yr`` entspricht der Y-Koordinate, bei dem das Objekt endet.

.. literalinclude:: ../../src/ElementViews/Slider_Rect.h
    :lines: 49-50

Sollte sich ``y`` nicht zwischen ``y1`` und ``yr`` befinden, wird das Objekt nicht berührt und der Schieberegler wird nicht angepasst. Selbiges gilt, wenn    
``x`` sich nicht zwischen ``x1`` und ``xr`` befindet. Andernfalls wird das Objekt berührt.

.. literalinclude:: ../../src/ElementViews/Slider_Rect.h
    :lines: 51-52

Bei einem vertikalen (":ref:`isVertical<sliderrectvisvertical>`") Objekt, muss nur die Y-Koordinate des Schiebereglers beachtet werden, da dieser sich von oben nach unten bzw. umgekehrt bewegen lässt.
Dafür wird für ":ref:`value<numberinputvvalue>`" die neue Y-Koordinate des Reglerposition gespeichert.

.. literalinclude:: ../../src/ElementViews/Slider_Rect.h
    :lines: 53-55

Bei einem horizontalen (":ref:`isVertical<sliderrectvisvertical>`") Objekt, muss nur die X-Koordinate des Schiebereglers beachtet werden, da dieser sich von rechts nach links bzw. umgekehrt bewegen lässt.  
Dafür wird für ":ref:`value<numberinputvvalue>`" die neue X-Koordinate der Reglerposition gespeichert.

.. literalinclude:: ../../src/ElementViews/Slider_Rect.h
    :lines: 56-57

Sollte ":ref:`externalValue<numberinputvexternalvalue>`" nicht ``null`` sein, so wird er mit dem neuen ":ref:`value<numberinputvvalue>`" aktualisiert.
Anschließend wird die ":ref:`Callback Funktion<numberinputvslider_callback>`" aufgerufen.

.. literalinclude:: ../../src/ElementViews/Slider_Rect.h
    :lines: 60

Zum Schluss folgt ein Aufruf der ":ref:`draw<sliderrectdraw>`" Funktion, um die neue Schiebereglerposition zu zeichnen.

.. _sliderRectCheckSize:

inline bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/ElementViews/Slider_Rect.h
    :lines: 63-77
    :linenos:

Diese Funktion testet, ob die Höhe (``sizeX``) und Breite (``sizeY``) eines Objektes in einem bestimmten Größenverhältnis zueinander stehen, um das Objekt zeichnen zu können.

.. literalinclude:: ../../src/ElementViews/Slider_Rect.h
    :lines: 65-69

Wenn ein Objekt mindestens 1.5 mal so hoch ist, wie es breit ist, dann ist das Objekt ":ref:`vertikal<sliderrectvisvertical>`" und zeichenbar.

.. literalinclude:: ../../src/ElementViews/Slider_Rect.h
    :lines: 65-69

Wenn ein Objekt mindestens 1.5 mal so breit ist, wie es hoch ist, dann ist das Objekt ":ref:`horizontal<sliderrectvisvertical>`" und zeichenbar.

.. literalinclude:: ../../src/ElementViews/Slider_Rect.h
    :lines: 77

Stimmt das Verhältnis nicht, ist das Objekt weder vertikal noch horizontal.    


Variablen und Konstanten Beschreibung
=====================================

.. _sliderRectVColorInfillOn:

const Color colorInfillOn
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt die Farbe (":ref:`Color<Color>`") an, die das Objekt bei angeschalteten Zustand hat, bzw. die Farbe, die der aktivierte Teil des Objekts hat.

.. _sliderRectVColorInfillOff:

const Color colorInfillOff
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt die Farbe (":ref:`Color<Color>`") an, die das Objekt bei ausgeschalteten Zustand hat, bzw. die Farbe, die der deaktivierte Teil des Objekts hat.

.. _sliderRectVColorBorder:

const Color colorBorder
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt die Farbe (":ref:`Color<Color>`") der Umrandung des Objekts an.

.. _sliderRectVColorSlider:

const Color colorSlider
~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt die Farbe (":ref:`Color<Color>`") des Schiebereglers an.

.. _sliderRectVIsVertical:

bool isVertical = false
~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob das Objekt horizontal oder vertikal ist. Standardmäßig ist ein Objekt horizontal.

.. _sliderRectVT:

const uint16_t t = 10
~~~~~~~~~~~~~~~~~~~~~~~~~

TODO
Gibt den Abstand zur Umrandung an.

.. _sliderRectVB:

const uint16_t b = 10 
~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt die Breite der Umrandung an.


.. _sliderRectVR:

const uint16_t r = 6
~~~~~~~~~~~~~~~~~~~~~~~~

Gibt den Radius der Umrandung (bzw. den Krümmungsgrad) an.
