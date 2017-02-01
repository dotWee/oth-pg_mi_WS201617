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

    // Fragen nach Länge
    printf("Länge: ");
    int laenge = lese_zahl();

    // Fragen nach Höhe
    printf("Höhe: ");
    int hoehe = lese_zahl();

    // Berechnen
    int flaeche = laenge * hoehe;
    printf("---------\n");
    printf("Fläche: %d", flaeche);

    return 0;
}