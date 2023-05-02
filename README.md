# TouchMenu

# Next Meeting

Date: 05-05-2023, 15:00

ToDo:
- Anforderungen / Features detailierter definieren und hier hinterlegen
- erste Variante der Klassenstruktur aufstellen (Hinweis: Interaktion und Rendering entkoppeln, schaut doch mal bei anderen GUI Libs, wie die das machen)
- Skizzen / Diagramme mit entsprechenden Tools in Grafiken/SVG umwandeln und hier einbinden
- denkt nochmal über eine Roadmap nach: 
  - Was ist euer Ziel? 
  - Welche Schritte müsst ihr gehen, um da hin zu kommen? 
  - Wann wollt ihr welche Zwischenziele erreicht haben?

- **Sprecht euch ab, wer welche Aufgaben hat!**

Auszug aus dem Modulkatalog:

Lernziele & erworbene Kompetenzen:
Teamarbeit (insbesondere Vergabe und Annahme von Verantwortung, Führung, Delegation und Absprache von Aufgaben,
Vereinbarung von Zusammenarbeitskriterien) Projektarbeit (insbesondere Vereinbarung von Zielen, Lasten-
und Pflichtenheft, Planung von Meilensteinen und Arbeitspaketen, Projektdurchführung, Dokumentation und
Präsentation eines Projektes und dessen Ergebnisse)Erstellung eines Software-Paketes im Team. Dieses Modul
wird durch unterschiedliche Lehrveranstaltungen implementiert. Fachliche Lehrziele sind angebotsspezifisch.


------

# Anforderungen:

**1) Hauptziele – Must have**
- Bedienung per Touchscreen und Drehknopf
    - Soll mit verschiedenen Screenarten-/größen funktionieren
    - Auch für Bildschirme ohne Touch 
- Grid-Screen
    - „Hauptscreen“ mit Einteilung in Rastern
- Elemente 
   - Button
   - Textfelder
   - Slider
   - Bilder/Icons 

**2)	Should have**

- Auf anderen Microcontrollern nutzbar sein
- Line-Screen
- Listenmenü
- Custom Screen
    - Leeres Seite auf der Nutzer selber etwas gestalten kann
- Zusätzliche Elemente:
    - Farbrad
    - Slider zur Zahleneingabe
- Bedienung mit anderen (externen) Tasten
    - z.B. Funktionen für Pfeiltasten

**3)	Could have**

- Gestlatungsoptionen für Elemente
- Graph-Screen
    - Diagramme darstellen 
- Virtuelle Tastatur
    - Zur Toucheingabe 
- Sidebar
    - Direkte Verknüpfungen zu verschiedenen Screens an der Seite


**4)	 Won’t have**

- Elemente haben keine eigene Funktionen 
    - Nutzer der library integriert selber Funktionen 