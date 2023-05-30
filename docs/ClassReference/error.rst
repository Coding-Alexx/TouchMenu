ErrorScreen
+++++++++++++++

Beschreibung
=============
Was macht die Klasse


Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============

.. csv-table:: 
    :widths: 100 1000

     , ":ref:`ErrorScreen <errorerrorscreenconstructor>` (char* error_title, char* error_text, const Color& background_color)"
     void , ":ref:`loop <errorloop>` ()"
     void , ":ref:`draw <errordraw>` ()"




Funktionen Beschreibung
=========================


.. _errorErrorScreenConstructor:

ErrorScreen (char* error_title, char* error_text, const Color& background_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/ErrorScreen.cpp
    :lines: 3-7
    :linenos:

.. _errorLoop:

void loop() override
~~~~~~~~~~~~~~~~~~~~~~

.. _errorDraw:

void draw() override
~~~~~~~~~~~~~~~~~~~~~
