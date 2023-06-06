.. _gridscreen:

GridScreen
+++++++++++

Beschreibung
=============
GridScreens sind :ref:`Screens <screen>`, bei denen :ref:`Elemente <element>` in einem Raster mit Zeilen und Spalten eingeordnet werden können.


Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============
.. csv-table:: 
    :widths: 100 1000

    , ":ref:`GridScreen <gridgridscreenconstructor>` (const uint8_t col, const uint8_t raw, const Color& background)"
    , ":ref:`GridScreen <gridgridscreenVectorconstructor>` (const uint8_t col, const uint8_t raw, const Color& background, std::vector<std::tuple<Element*, const uint16_t, const uint16_t, const uint16_t, const uint16_t>> e)"
    bool, ":ref:`add <gridadd>` (Element* element, const uint16_t posX, const uint16_t posY, const uint16_t sizeX, const uint16_t sizeY)"
    void, ":ref:`loop <gridloop>` ()"
    void, ":ref:`draw <griddraw>` ()"
    std::unique_ptr<Element>, ":ref:`make_unique_derived <gridmake_unique_derived>` (Element* element)"

Funktionen Beschreibung
=========================


.. _gridGridScreenConstructor:

GridScreen (const uint8_t col, const uint8_t raw, const Color& background)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 3-9
    :linenos:

.. _gridGridScreenVectorConstructor:

GridScreen (const uint8_t col, const uint8_t raw, const Color& background, std::vector<std::tuple<Element*, const uint16_t, const uint16_t, const uint16_t, const uint16_t>> e)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


.. _gridAdd:

bool add (Element* element, const uint16_t posX, const uint16_t posY, const uint16_t sizeX, const uint16_t sizeY)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
.. literalinclude:: ../../src/Screens/GridScreen.cpp
    :lines: 11-30
    :linenos:

.. _gridLoop:

void loop () override
~~~~~~~~~~~~~~~~~~~~~~~~~


.. _gridDraw:

void draw () override
~~~~~~~~~~~~~~~~~~~~~~~~

.. _gridMake_unique_derived:

std::unique_ptr<Element> make_unique_derived (Element* element);
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
