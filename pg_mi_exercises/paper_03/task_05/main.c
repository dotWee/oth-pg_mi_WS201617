#include <stdio.h>
#include <stdlib.h>

// Header-Datei unserer Bibliothek functions.o einbinden
#include "libs/functions.h"

int main(int argc, const char *argv[]) {

    // Lese Zahl aus den Parametern -> int da nur ganzzahlig!
    int zahl = atoi(argv[1]);

    // Definition des Ergebnises;
    double ergebnis;

    // Berechne Quadratwurzel
    ergebnis = my_sqrt(zahl);
    printf("Funktion my_sqrt | Wert: %d Ergebnis: %lf\n", zahl, ergebnis);

    // Berechne Potenz
    ergebnis = my_pow(zahl, zahl);
    printf("Funktion my_pow | Wert: %d Ergebnis: %lf\n", zahl, ergebnis);

    return 0;
}