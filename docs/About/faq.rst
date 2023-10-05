.. _faq:

Frequently asked questions
+++++++++++++++++++++++++++

Was kann die Library?
======================
siehe :ref:`Feature List<Features>`

Welche Microcontroller funktionieren?
======================================
Die Library wurde intensiv mit ESP32 und ESP8266 getestet. Mit ihnen funktioniert sie auf jeden Fall.

Ich habe nur wenig Programmiererfahrung, kann ich die Library trotzdem verwenden?
========================================================================================
Ja, sehr gern sogar. Zum einen wird in :ref:`Installation<installation>` das Aufsetzen der Library erklärt und zum anderen findet sich in 
:ref:`Quickstart guide<quickstartguide>` eine Schritt-für-Schritt Anleitung, wie man ein erstes kleines Programm erstellt. Zusätzlich befinden sich einige fertige Beispiele im
`examples <https://github.com/Coding-Alexx/TouchMenu/tree/main/examples>`_ Ordner. Zussätzlich ist die Code Dokumentation so geschrieben, dass viel Code auch in 
natürliche Sprache übersetzt wurde, um es Anfängern leichter zu machen. Natürlich wird dort auch die Funktion des Codes erklärt.

Kann ich anpassen, wie viele Elemente auf mein Screen passen?
==============================================================
Bei einem GridScreen kannst du die Anzahl an Spalten und Reihen beliebig verändern und demnach auch beliebig viele Elemente auf deinen Screen legen.

Kann ich die Größe von Elementen ändern?
=========================================
Ja, das geht. Schau doch mal im :ref:`Quickstart guide<quickstartguide>` vorbei. Dort erstellst du selbst einige Elemente.

Welche Elemente kann ich auf meinen Screen legen?
==================================================
Eine Auflistung findet sich in der :ref:`Feature list<Features>`.

Was passiert, wenn ich zwei Elemente auf dem selben Punkt zeichnen will?
=========================================================================
Dann wird nur das erste Element auf dem Screen gezeichnet.

Mein Element wird nicht angezeigt, was kann ich tun?
=====================================================
Prüfe bitte, ob das Element auch wirklich auf dem Screen gezeichnet wird. Wenn ja, prüfe bitte, wie groß das Element ist. Eventuell ist es zu klein, um es anzeigen zu können.

Was ist der Unterschied zwischen Buttons und Switches?
=======================================================
Beide lassen sich mit der einer entsprechenden ``Button`` Klasse erstellen, weil sich ihre Funktion nur minimal unterscheidet. Drückt man auf einen Button, so verändert dieser kurz seinen Zustand, und wechselt dann in den Ursprungszustand zurück
(z.B. wechselt er seine Farbe von grün auf rot und dann zurück auf grün). Switches bleiben in dem gewechselten Zustand und wechseln ihn erst nach erneutem Drücken (z.B. wechselt ein Switch seine Farbe von grün auf rot und bleibt so lange rot, bis er erneut berührt wird).

Kann ich auf meinen Elementen irgendwelche Bilder oder ähnliches anzeigen lassen?
==================================================================================
Ja, das geht mit ``Items``. Schau dich mal hier :ref:`Feature list<Features>` oder hier :ref:`Items<item>` um.

Mein Text wird auf dem Element abgehackt, was kann ich tun?
==============================================================
Wenn du in deinem Text ein Leerzeichen verwendest, tausche es durch einen Unterstrich aus ``_``.

Kann ich meine eigenen Icons hochladen?
========================================
Ja, eine Kurzbeschreibung findet sich in der :ref:`Feature list<Features>` und der :ref:`createIcon()<iconCreateIcon>` Funktion.

Die Standard Icons sind weg, was tun?
========================================
Wenn man alle Abhängigkeiten Installiert hat und den Ordner ``icon_templates`` mit seinen eigenen neuen, in Unterordnen befindlichen Icons erstellt, dann werden alle Icons, 
die sonst mit der Lib mitgeliefert werden gelöscht. Dies muss geändert werden, indem z.B. eine neue Header Datei erstellt wird.