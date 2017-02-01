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

int main(int argc, char *argv[]) {
    int buffer = 0;

    while (1) {

        // Zahl einlesen
        int zahl = lese_zahl();

        // Aufsummieren
        buffer = buffer + zahl;

        // Ausgeben
        printf("Summe: %d\n", buffer);
    }

    return 0;
}