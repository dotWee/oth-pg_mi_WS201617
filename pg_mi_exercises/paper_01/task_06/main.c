#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int lese_zahl() {

    // Definiere Ziele
    char *ziel = malloc(sizeof(char) * MAX_LENGTH);
    fgets(ziel, MAX_LENGTH, stdin);

    // Umwandlung in Zahl
    int zahl = atoi(ziel);

    // Speicher freigeben
    free(ziel);

    // Zahl zurückgeben
    return zahl;
}

/**
 * Diese Funktion checkt ob eine Zahl eine Primzahl ist oder nicht
 *
 * @param zahl Die überprüft werden soll
 * @return 0 wenn falsch, 1 wenn wahr
 */
int ist_primzahl(int zahl) {

    if (zahl <= 1) {
        return 0;
    }

    if (zahl % 2 == 0 && zahl > 2) {
        return 0;
    }

    for (int i = 3; i < zahl / 2; i += 2) {
        if (zahl % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char *argv[]) {

    // Zahl einlesen
    int zahl = lese_zahl();

    // Überprüfen
    int istPrimzahl = ist_primzahl(zahl);

    // Ausgeben
    if (istPrimzahl == 0) {
        printf("Ist keine Primzahl");
    } else {
        printf("Ist eine Primzahl");
    }

    // Optional:
    //printf("Ist Primzahl: %s", istPrimzahl ? "Wahr" : "Falsch");

    return 0;
}