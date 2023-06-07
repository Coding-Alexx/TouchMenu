.. _errorscreen:

ErrorScreen
+++++++++++++++

Beschreibung
=============
ErrorScreens sind :ref:`Screens <screen>`, die eine Fehlermeldung ausgeben.


Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============

.. csv-table:: 
    :widths: 100 1000

     , ":ref:`ErrorScreen <errorerrorscreenconstructor>` (const char* error_title, const char* error_text)"
     , ":ref:`ErrorScreen <errorerrorscreenconstructorcolor>` (char* error_title, char* error_text, const Color& background_color)"
     void , ":ref:`loop <errorloop>` ()"
     void , ":ref:`draw <errordraw>` ()"




Funktionen Beschreibung
=========================

.. _errorErrorScreenConstructor:

ErrorScreen (const char* error_title, const char* error_text)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/ErrorScreen.cpp
    :lines: 3-5
    :linenos:

.. _errorErrorScreenConstructorColor:

ErrorScreen (char* error_title, char* error_text, const Color& background_color)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/ErrorScreen.cpp
    :lines: 7-12
    :linenos:

.. _errorLoop:

void loop() override
~~~~~~~~~~~~~~~~~~~~~~

.. _errorDraw:

void draw() override
~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Screens/ErrorScreen.cpp
    :lines: 14-20
    :linenos:
