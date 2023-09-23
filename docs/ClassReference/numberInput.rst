.. _numberInput:

numberInput
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

    void, ":ref:`loop <numberinputloopinputs>` (Inputs& input) override"
    virtual void, ":ref:`setTouch <numberinputsettouch>` (Inputs& input) = 0"
    , ":ref:`NumberInput <numberinputconstructor>` (slider_func_ptr slider_callback, uint16_t* externalValue = nullptr)"
    virtual, ":ref:`~NumberInput <numberinputdestructor>` ()"
    bool, ":ref:`select <numberinputselect>` () override"

Variablen und Konstanten
==========================


.. csv-table:: 
    :widths: 100 10000

    const slider_func_ptr_ptr, ":ref:`slider_callback <numberinputvslider_callback>`"
    uint16_t* const, ":ref:`externalValue <numberinputvexternalvalue>`"
    uint16_t, ":ref:`value <numberinputvvalue>` = 0"
    const uint16_t, ":ref:`maxValue <numberinputvmaxvalue>` = 100"


Funktionen Beschreibung
=========================

.. _numberInputConstructor:

NumberInput(slider_func_ptr slider_callback, uint16_t* externalValue = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/NumberInput.cpp
    :lines: 3-6
    :linenos:

Diese Funktion ist ein Konstruktor für Objekte der Klasse ``numberInput``.
Als Parameter nimmt der Konstruktor die ":ref:`Callback<numberinputvslider_callback>`" Funktion ``slider_callback`` sowie einen ``externalValue``. 
":ref:`slider_callback<numberinputvslider_callback>`" und ":ref:`externalValue<numberinputvexternalvalue>`" werden mit den korrespondierenden Parametern initialisiert.
Sollte ":ref:`externalValue<numberinputvexternalvalue>`" nicht ``null`` sein, so wird der Wert, auf den ":ref:`externalValue<numberinputvexternalvalue>`" zeigt, 
":ref:`value<numberinputvvalue>`" zugewiesen. Andernfalls wird ein neuer ``uint16_t`` erzeugt und ":ref:`externalValue<numberinputvexternalvalue>`" wird auf diesen Wert gesetzt. 
Das wird getan, um zu verhindern, dass ":ref:`externalValue<numberinputvexternalvalue>`" ``null`` ist.

.. _numberInputDestructor:

virtual ~NumberInput()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/NumberInput.cpp
    :lines: 7
    :linenos:

Der Destruktor wird bei der Zerstörung eines ``numberInput`` Objektes aufgerufen.

.. _numberInputLoopInputs:

void loop(Inputs& input) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/NumberInput.cpp
    :lines: 22-25
    :linenos:

TODO
Sieht aus, als kommt da noch was

.. _numberInputLoop:

void loop() override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/NumberInput.cpp
    :lines: 13-19
    :linenos:

Zuerst wird getestet, ob ``externalValue && *externalValue != value`` gilt. Dies ist der Fall, wenn beim ":ref:`NumberInput<numberinputconstructor>`" ein neues ``uint16_t`` erzeugt werden musste.
Sollte dies ``true`` sein, wird getestet, ob ``*externalValue > maxValue``, also ob der erzeugte ``uint16_t`` Wert über dem ":ref:`maxValue<numberinputvmaxvalue>`" liegt. Wenn ja, wird 
``*externalValue = maxValue`` gesetzt, um die Richtigkeit des Codes zu gewährleisten. Anschließend erfolgt noch ``value = *externalValue``, der aktuelle ":ref:`value<numberinputvvalue>`" entspricht also dem 
":ref:`maxValue<numberinputvmaxvalue>`". Zum Schluss erfolgt der Funktionsaufruf der ":ref:`draw<sliderrectdraw>`" Funktion der ":ref:`Slider_Rect<slider_rect>`" Klasse bzw. der 
":ref:`draw<slider_arrowdraw>`" Funktion der ":ref:`Slider_Srrow<slider_arrowdraw>`" Klasse, je nach Objekttyp.

.. _numberInputSetTouch:

virtual void setTouch(Inputs& input) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe ":ref:`Slider_Arrow <slider_arrowsettouch>`", ":ref:`Slider_Rect <sliderrectsettouch>`")

.. _numberInputSelect:

bool select() override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/NumberInput.cpp
    :lines: 9-11
    :linenos:

Muss noch implementiert weredn?    

Variablen und Konstanten Beschreibung
=====================================

.. _numberInputVSlider_callback:

const slider_func_ptr slider_callback
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _numberInputVExternalValue:


uint16_t* const externalValue
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _numberInputVValue:


uint16_t value = 0
~~~~~~~~~~~~~~~~~~~~

Speichert den aktuellen Wert des ``numberInput`` Objektes.

.. _numberInputVMaxValue:


const uint16_t maxValue = 100
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt den Maximalwert an, den ":ref:`value <numberinputvvalue>`" annehmen darf.