#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    // Frage nach Radius
    printf("Radius: ");
    int radius = lese_zahl();

    // Fläche berechnen
    double flaeche = M_PI * (radius * radius);
    printf("Fläche: %lf", flaeche);

    // Erfolg
    return 0;
}