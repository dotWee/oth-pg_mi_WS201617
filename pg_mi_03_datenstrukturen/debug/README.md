Debugging mit GDB
=================

Zur Fehleranalyse unter Linux steht uns mit gdb ein gut brauchbarer
Debugger auf Kommandozeilenebene zur Verfügung.

Wenn wir unser Programm inclusive Debug-Symbole übersetzen, lässt sich
der Quellcode damit z. B. Schritt für Schritt durchlaufen.

gcc -g -std=c99 tictac.c -o tictac

Starten lässt sich gdb wie folgt gdb PROGRAMMNAME

gdb tictac

Wenn wir nun in Zeile 7 einen Breakpoint setzen, dann wird dort nach
dem Starten die Programmausführung unterbrochen.

break 7

Das Starten des Programms erfolgt mittels run, wobei nach run ggf. 
Kommandozeilenparameter an das Programm übergeben werden können.

run

Mit den Befehlen next oder step kann entweder in eine aufgerufene
Funktion abgestiegen (step) oder direkt zur nächsten Zeile (next)
gesprungen werden.

Mit dem Befehl print kann der Inhalt einer Variable ausgegeben werden.

print xvalue
