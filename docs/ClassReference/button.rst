.. _button:

Button
++++++++

Beschreibung
=============
Buttons sind :doc:`Elemente </ClassReference/element.rst>`, bei denen ein einmaliger Input zum Ausführen einer bestimmten Aktivität führt.
Vom Button erben folgende Klassen: roundButton(Link test)

TODO Verlinkung zu roundButton 

Tutorials/ Examples
=====================
Link dazu, wenn vorhanden
oder direkt hier einbinden

Funktionen
=============
relevant für eigenes Menü

.. csv-table:: 
    :widths: 100 1000

     , :ref:`Button <buttonButton>` (button_func_ptr button_callback)
     , :ref:`Button <buttonSwitch>` (switch_func_ptr swich_callback)


sonstige 

.. csv-table:: 
    :widths: 100 1000

    void, :ref:`loop <buttonLoop>` ()
    bool, :ref:`select <buttonSelect>` ()
    void, :ref:`setExternalValue <buttonsetexternalvalue>` (bool* value)

Funktionen Beschreibung
=========================

.. _buttonButton:

Button (button_func_ptr button_callback)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 4
    :linenos:

Erklärung

.. _buttonSwitch:

Button (switch_func_ptr swich_callback)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 5
    :linenos:

Erklärung

.. _buttonLoop:

void loop ()
~~~~~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 25-41
    :linenos:

Erklärung


.. _buttonSelect:

bool select ()
~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 12-22
    :linenos:

Erklärung

.. _buttonSetExternalValue:

void setExternalValue (bool* value)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. literalinclude:: ../../src/Elements/Button.cpp 
    :lines: 8-11
    :linenos:

Erklärung
