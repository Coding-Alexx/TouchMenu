.. _numberInput:

numberInput
++++++++++++++

Beschreibung
=============

Diese Klasse ist eine Eingabemöglichkeit von Zahlen in einem Intervall. Mit ihr lassen sich z.B. Schieberegler erstellen.
Von dieser Klasse erben :ref:`Number_Slider<number_slider>` und :ref:`Number_Counter<number_counter>`.



Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    const slider_func_ptr_ptr, ":ref:`slider_callback <numberinputvslider_callback>`"
    virtual void, ":ref:`setTouch <numberinputsettouch>` (Inputs& input) = 0"
    , ":ref:`NumberInput <numberinputconstructor>` (std::function<void(int)> callback, ExternalNumberValue* const externalValue = nullptr)"
    virtual, ":ref:`~NumberInput <numberinputdestructor>` ()"
    void, ":ref:`loop <numberinputloopinputs>` (Inputs& input) override"

Variablen und Konstanten
==========================


.. csv-table:: 
    :widths: 100 10000

    ExternalNumberValue* const, ":ref:`externalValue <numberinputvexternalvalue>` = nullptr "
    int, ":ref:`value <numberinputvvalue>` = 0"
    int, ":ref:`minValue <numberinputvminvalue>` = 0"
    int, ":ref:`maxValue <numberinputvmaxvalue>` = 100"
    uint, ":ref:`steps <numberinputvsteps>` = 1"


Funktionen Beschreibung
=========================

.. _numberInputVSlider_callback:

const slider_func_ptr slider_callback
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese Funktion ist die Callback Funktion für ``NumberInput`` Objekte. Standardmäßig tut diese Funktion nichts,
sie erhält erst eine Bedeutung, wenn bei der Erstellung eines ``NumberInput`` Objektes eine Funktion als ``slider_callback`` übergeben wird, die aufgerufen wird, wenn der Slider aktiviert
wird.

.. _numberInputConstructor:

NumberInput(std::function<void(int)> callback, ExternalNumberValue* const externalValue = nullptr)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/NumberInput.cpp
    :lines: 3-6
    :linenos:

Diese Funktion ist ein Konstruktor für Objekte der Klasse ``numberInput``.
Als Parameter nimmt der Konstruktor die :ref:`Callback<numberinputvslider_callback>` Funktion ``slider_callback`` sowie einen ``externalValue``. 
:ref:`slider_callback<numberinputvslider_callback>` und :ref:`externalValue<numberinputvexternalvalue>` werden mit den korrespondierenden Parametern initialisiert.

.. _numberInputDestructor:

virtual ~NumberInput()
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/NumberInput.cpp
    :lines: 8
    :linenos:

Der Destruktor wird bei der Zerstörung eines ``numberInput`` Objektes aufgerufen.

.. _numberInputLoopInputs:

void loop(Inputs& input) override
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/NumberInput.cpp
    :lines: 14-27
    :linenos:

Diese Funktion dient dazu, den Zustand des aktuellen Objektes zu aktualisieren, falls externe Änderungen vorgenommen wurden

.. literalinclude:: ../../src/Elements/NumberInput.cpp
    :lines: 19

Liegt kein :ref:`externalValue<numberinputvexternalvalue>` vor, so bricht die Funktion ab.

.. literalinclude:: ../../src/Elements/NumberInput.cpp
    :lines: 20-23

Nun wird getestet, ob sich :ref:`value <numberinputvvalue>`, :ref:`minValue <numberinputvminvalue>`, :ref:`maxValue <numberinputvmaxvalue>` und :ref:`steps<numberinputvsteps>` des
Objektes der ``NumberInput`` Klasse von den in :ref:`externalValue<numberinputvexternalvalue>` äquivalenten Werten unterscheiden. Wenn ja, werden die entsprechenden Werte aus 
:ref:`externalValue<numberinputvexternalvalue>` in den jeweiligen Variablen des Objektes der ``NumberInput`` Klasse gespeichert.

.. literalinclude:: ../../src/Elements/NumberInput.cpp
    :lines: 24

Liegt zwar ein :ref:`externalValue<numberinputvexternalvalue>` vor, aber die Werte unterscheiden sich nicht, so bricht die Funktion ebenso ab.   

.. literalinclude:: ../../src/Elements/NumberInput.cpp
    :lines: 26

Zum Schluss wird das Objekt mit den neuen Werten mit :ref:`draw<elementdraw>` gezeichnet. 

.. _numberInputSetTouch:

virtual void setTouch(Inputs& input) = 0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Diese virtuelle Funktion muss von einer abgeleiteten Klasse überschrieben werden.
(Siehe :ref:`Number_Slider <number_slidersettouch>`, :ref:`Number_Counter <number_countersettouch>`)

.. _numberInputSelect:
 

Variablen und Konstanten Beschreibung
=====================================

.. _numberInputVExternalValue:

ExternalNumberValue* const externalValue = nullptr
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Dieser :ref:`ExternalNumberValue*<externalnumbervalue>` ermöglicht eine externe Steuerung von Objekten der ``Number_Input`` Klasse, um einzelne Variablen extern anzupassen.

.. _numberInputVValue:

uint16_t value = 0
~~~~~~~~~~~~~~~~~~~~

Speichert den aktuellen Wert des ``numberInput`` Objektes.

.. _numberInputVminValue:

int minValue = 0
~~~~~~~~~~~~~~~~~~~~

Gibt den Minimalwert an, den :ref:`value <numberinputvvalue>` annehmen darf.

.. _numberInputVMaxValue:

const uint16_t maxValue = 100
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt den Maximalwert an, den :ref:`value <numberinputvvalue>` annehmen darf.

.. _numberInputVsteps:

uint steps = 1
~~~~~~~~~~~~~~~

Gibt an, um wie viel :ref:`value <numberinputvvalue>` inkrementiert bzw. dekrementiert werden soll.