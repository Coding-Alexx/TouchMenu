.. _input:

Input
++++++++++

Beschreibung
=============


Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
==========================

.. csv-table:: 
    :widths: 100 1000

     void, ":ref:`reset<inputreset>` ()"
     bool, ":ref:`hasInput<inputhasinput>` ()"

Variablen und Konstanten
==========================

.. csv-table:: 
    :widths: 100 1000

     bool, ":ref:`enter <inputventer>` = false"
     bool, ":ref:`right <inputvright>` = false"
     bool, ":ref:`left <inputvleft>` = false"
     bool, ":ref:`up <inputvup>` = false"
     bool, ":ref:`down <inputvdown>` = false"
     uint16_t, ":ref:`touchX <inputvtouchx>` = 0"
     uint16_t, ":ref:`touchY <inputvtouchy>` = 0"
     bool, ":ref:`isTouched <inputvistouched>` = false"
     bool, ":ref:`update <inputvupdate>` = true"
     bool, ":ref:`updateTouchPoint <inputvupdatetouchpoint>` = false"
     uint8_t, ":ref:`back <inputvupdatetouchpoint>` = 0"



Funktionenbeschreibung
==========================

.. _inputreset:

void reset()
~~~~~~~~~~~~~

.. _inputhasinput:

bool hasInput()
~~~~~~~~~~~~~~~~

Variablen und Konstanten Beschreibung
=====================================

.. _inputVEnter:

bool enter = false
~~~~~~~~~~~~~~~~~~~~~~~

.. _inputVRight:

bool right = false
~~~~~~~~~~~~~~~~~~~~~~~

.. _inputVLeft:

bool left = false
~~~~~~~~~~~~~~~~~~~~~~~

.. _inputVUp:

bool up = false
~~~~~~~~~~~~~~~~~~~~~~~

.. _inputVDown:

bool down = false
~~~~~~~~~~~~~~~~~~~~~~~

.. _inputVTouchX:

uint16_t touchX = 0
~~~~~~~~~~~~~~~~~~~~~~~

Gibt die X-Koordinate an, an welcher der Benutzer das Display zuletzt berührt hat.

.. _inputVTouchY:

uint16_t touchY = 0
~~~~~~~~~~~~~~~~~~~~~~~

Gibt die Y-Koordinate an, an welcher der Benutzer das Display zuletzt berührt hat.

.. _inputVisTouched:

bool isTouched = false
~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob das Display gerade gedrückt wird oder nicht.

.. _inputVUpdate:

bool update = true
~~~~~~~~~~~~~~~~~~~~~~~

.. _inputVupdatetouchpoint:

bool updateTouchPoint = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. _inputVback:

uint8_t back = 0
~~~~~~~~~~~~~~~~~