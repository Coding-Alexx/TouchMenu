.. _externalnumbervalue:

ExternalNumberValue
++++++++++++++++++++++

Beschreibung
=============

``ExternalNumberValue`` ermöglicht eine externe Steuerung von :ref:`NumberInput<numberinput>` Objekten. So kann mit ihnen z.B. ein bestimmter Wert forciert werden, welcher angezeigt werden soll.


Funktionen
=============


.. csv-table:: 
    :widths: 100 10000

    void, ":ref:`setValue <externalnumbervaluesetvalue>` (int val)"
    void, ":ref:`setMinValue <externalnumbervaluesetminvalue>` (int min)"
    void, ":ref:`setMaxValue <externalnumbervaluesetmaxvalue>` (int max)"
    void, ":ref:`setSteps<externalnumbervaluesetsteps>` (uint step)"
    int, ":ref:`getValue<externalnumbervaluegetvalue>` () const"
    int, ":ref:`getMinValue<externalnumbervaluegetminvalue>` () const"
    int, ":ref:`getMaxValue<externalnumbervaluegetmaxvalue>` () const"
    uint, ":ref:`getSteps<externalnumbervaluegetsteps>` () const"


Variablen und Konstanten
==========================


.. csv-table:: 
    :widths: 100 10000

    int, ":ref:`value <externalnumbervaluevvalue>` = 0"
    int, ":ref:`minValue <externalnumbervaluevminvalue>` = 0"
    int, ":ref:`maxValue <externalnumbervaluevmaxvalue>` = 100"
    uint, ":ref:`steps <externalnumbervaluevsteps>` = 1"
    bool, ":ref:`update <externalnumbervaluevupdate>` = false"


Funktionen Beschreibung
=========================

.. _externalnumbervaluesetvalue:

void setValue(int val)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/NumberInput.h
    :lines: 17-21
    :linenos:

Mit dieser Funktion wird ein neues :ref:`value<externalnumbervaluevvalue>` festgelegt, solange dieses sich zwischen 
:ref:`minValue<externalnumbervaluevminvalue>` und :ref:`maxValue<externalnumbervaluevmaxvalue>` befindet.
Außerdem wird :ref:`update<externalnumbervaluevupdate>` auf ``true`` gesetzt, da Änderungen vorgenommen wurden.

.. _externalnumbervaluesetminvalue:

void setMinValue(int min)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/NumberInput.h
    :lines: 23-28
    :linenos:

Mit dieser Funktion wird ein neues :ref:`minValue<externalnumbervaluevminvalue>` festgelegt, solange dieses kleiner als :ref:`maxValue<externalnumbervaluevmaxvalue>` ist.
Sollte :ref:`value<externalnumbervaluevvalue>` kleiner sein als das neue :ref:`minValue<externalnumbervaluevminvalue>`, wird :ref:`value<externalnumbervaluevvalue>` auf den Wert vom neuen 
:ref:`minValue<externalnumbervaluevminvalue>` gesetzt.
Außerdem wird :ref:`update<externalnumbervaluevupdate>` auf ``true`` gesetzt, da Änderungen vorgenommen wurden.

.. _externalnumbervaluesetmaxvalue:

void setMaxValue(int max)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/NumberInput.h
    :lines: 30-35
    :linenos:

Mit dieser Funktion wird ein neues :ref:`maxValue<externalnumbervaluevmaxvalue>` festgelegt, solange dieses größer als :ref:`minValue<externalnumbervaluevminvalue>` ist.
Sollte :ref:`value<externalnumbervaluevvalue>` größer sein als das neue :ref:`maxValue<externalnumbervaluevmaxvalue>`, wird :ref:`value<externalnumbervaluevvalue>` auf den Wert vom neuen 
:ref:`maxValue<externalnumbervaluevmaxvalue>` gesetzt.
Außerdem wird :ref:`update<externalnumbervaluevupdate>` auf ``true`` gesetzt, da Änderungen vorgenommen wurden.

.. _externalnumbervaluesetsteps:

void setSteps(uint step)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/NumberInput.h
    :lines: 37-41
    :linenos:

Mit dieser Funktion wird :ref:`steps<externalnumbervaluevsteps>` einen neuen Wert zugewiesen, solange dieser Wert nicht kleiner ist als ``minValue - maxValue``, da sonst bei jeder 
Inkrementierung bzw. Dekrementierung der :ref:`maxValue<externalnumbervaluevmaxvalue>` überschritten bzw. :ref:`minValue<externalnumbervaluevminvalue>` unterschritten werden würde.
Außerdem wird :ref:`update<externalnumbervaluevupdate>` auf ``true`` gesetzt, da Änderungen vorgenommen wurden.


.. _externalnumbervaluegetvalue:

int getValue() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/NumberInput.h
    :lines: 43
    :linenos:

Diese Funktion gibt :ref:`value<externalnumbervaluevvalue>` aus.

.. _externalnumbervaluegetminvalue:

int getMinValue() const 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/NumberInput.h
    :lines: 44
    :linenos:

Diese Funktion gibt :ref:`minValue<externalnumbervaluevminvalue>` aus.

.. _externalnumbervaluegetmaxvalue:

int getMaxValue() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/NumberInput.h
    :lines: 45
    :linenos:

Diese Funktion gibt :ref:`maxValue<externalnumbervaluevmaxvalue>` aus.

.. _externalnumbervaluegetsteps:

uint getSteps() const
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/NumberInput.h
    :lines: 46
    :linenos:

Diese Funktion gibt :ref:`steps<externalnumbervaluevsteps>` aus.

Variablen und Konstanten Beschreibung
=====================================

.. _externalnumbervaluevvalue:

int value = 0
~~~~~~~~~~~~~~~~~~~~

Speichert den aktuellen Wert.

.. _externalnumbervaluevminvalue:

int minValue = 0
~~~~~~~~~~~~~~~~~~~~

Gibt den Minimalwert an, den :ref:`value<externalnumbervaluevvalue>` annehmen darf.

.. _externalnumbervaluevmaxvalue:

int maxValue = 100
~~~~~~~~~~~~~~~~~~~~

Gibt den Maximalwert an, den :ref:`value<externalnumbervaluevvalue>` annehmen darf.

.. _externalnumbervaluevsteps:

uint steps = 1
~~~~~~~~~~~~~~~~~~~~

Gibt an, um wie viel :ref:`value<externalnumbervaluevvalue>` inkrementiert bzw. dekrementiert werden soll.

.. _externalnumbervaluevupdate:

bool update = false
~~~~~~~~~~~~~~~~~~~~

Gibt an, ob nicht getätigte Änderungen vorliegen.