.. _input:

Input
++++++++++


Beschreibung
=============

Diese Klasse kontrolliert und speichert Benutzereingaben, z.B. das Drücken vom Touchscreen.


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

.. literalinclude:: ../../src/Input.h
    :lines: 20-30
    :linenos:

Diese Funktion setzt alle Variablen zurück auf ihren Ausgangswert.

.. _inputhasinput:

bool hasInput()
~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Input.h
    :lines: 32-34
    :linenos:

Diese Funktion prüft, ob gerade eine Eingabe durchgeführt wird. 

Variablen und Konstanten Beschreibung
=====================================

.. _inputVEnter:

bool enter = false
~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob eine Eingabe ausgeführt wird (entweder durch Drücken auf einem Touchbildschirm oder durch betätigen einer dedizierten Eingabetaste).

.. _inputVRight:

bool right = false
~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob bei einer potenziell am Display angeschlossenen physischen oder virtuellen Steuerungseinheit (wie z.B. Knöpfe oder Tasten), nach rechts gedrückt wird.


.. _inputVLeft:

bool left = false
~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob bei einer potenziell am Display angeschlossenen physischen oder virtuellen Steuerungseinheit (wie z.B. Knöpfe oder Tasten), nach links gedrückt wird.

.. _inputVUp:

bool up = false
~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob bei einer potenziell am Display angeschlossenen physischen oder virtuellen Steuerungseinheit (wie z.B. Knöpfe oder Tasten), nach oben gedrückt wird.

.. _inputVDown:

bool down = false
~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob bei einer potenziell am Display angeschlossenen physischen oder virtuellen Steuerungseinheit (wie z.B. Knöpfe oder Tasten), nach unten gedrückt wird.

.. _inputVTouchX:

uint16_t touchX = 0
~~~~~~~~~~~~~~~~~~~~~~~

Gibt die X-Koordinate an, an welcher der Benutzer das :ref:`Display<display>` zuletzt berührt hat.

.. _inputVTouchY:

uint16_t touchY = 0
~~~~~~~~~~~~~~~~~~~~~~~

Gibt die Y-Koordinate an, an welcher der Benutzer das :ref:`Display<display>` zuletzt berührt hat.

.. _inputVisTouched:

bool isTouched = false
~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob das :ref:`Display<display>` gerade gedrückt wird oder nicht.
Wenn ``isTouched`` ``false`` ist, so sind :ref:`touchX<inputvtouchx>` und :ref:`touchY<inputvtouchy>` nicht definiert.

.. _inputVUpdate:

bool update = true
~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob Änderungen bei der Eingabe vorliegen, die noch nicht durchgeführt wurden.
Wird von :ref:`Elementen<element>` auf ``true`` gesetzt, falls der :ref:`Screen<screen>` also neugezeichnet werden soll.

.. _inputVupdatetouchpoint:

bool updateTouchPoint = false
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Gibt an, ob ein neuer Punkt auf dem :ref:`Display<display>` berührt wird.
Ist nachdem es ``true`` wird für kurze Zeit außer Kraft gesetzt, damit es nicht zu Fehleingaben kommt.

.. _inputVback:

uint8_t back = 0
~~~~~~~~~~~~~~~~~

Diese Variable wird für die :ref:`loop<touchmenulibloop>` Funktion der :ref:`TouchMenuLib<touchmenulib>` Klasse benötigt und speichert, wie viele Eingaben seit einer bestimmten Eingabe 
getätigt wurden.