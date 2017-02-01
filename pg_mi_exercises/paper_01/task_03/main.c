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

    // Fragen nach Kathete1
    printf("Kathete1: ");
    int kathete1 = lese_zahl();

    // Fragen nach Kathete2
    printf("Kathete2: ");
    int kathete2 = lese_zahl();

    // Berechnen a^2*b^2=c^2
    kathete1 = kathete1 * kathete1;
    kathete2 = kathete2 * kathete2;
    double hypotenuse = sqrt(kathete1 + kathete2);

    // Hypotenuse ausgeben
    printf("Hypotenuse: %lf", hypotenuse);

    // Erfolg zurückgeben
    return 0;
}