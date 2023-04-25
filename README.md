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




Anforderungen:

1)	Hauptziele – Must have
 a)	Bedienung per Touchscreen und Drehknopf
 -	Soll mit verschiedenen Screenarten-/größen funktionieren
 -	Auch für Bildschirme ohne Touch 
 b)	Grid-Screen
 -	„Hauptscreen“ mit Einteilung in Rastern
 c)	Elemente 
   (1)	Button
   (2)	Textfelder
   (3)	Slider
   (4)	Bilder/Icons 


2)	Should have
 a)	Auf anderen Microcontrollern nutzbar sein
 b)	Line-Screen
 -	Listenmenü 
 c)	Custom Screen
 -	Leeres Seite auf der Nutzer selber etwas gestalten kann
 d)	Zusätzliche Elemente:
  (1)	Farbrad
  (2)	Slider zur Zahleneingabe
 e)	MQTT Integration
 -	Kommunikation mit anderen Geräten/Servern
 -	In bestehende Smart Home Systeme integrieren
 f)	Gestlatungsoptionen für Elemente 


3)	Could have 
 a)	Bedienung mit anderen (externen) Tasten
 -	z.B. Funktionen für Pfeiltasten
 b)	Graph-Screen
 -	Diagramme darstellen 
 c)	Virtuelle Tastatur
 -	Zur Toucheingabe 
 d)	Sidebar
 -	Verknüpfungen zu verschiedenen Screens


4)	 Won’t have 
 a)	Elemente haben keine eigene Funktionen 
 -	Nutzer der library integriert selber Funktionen 
 
![image](https://user-images.githubusercontent.com/55583693/234297453-13ae2cdd-01bc-4595-807b-c0dd08117cb9.png)
