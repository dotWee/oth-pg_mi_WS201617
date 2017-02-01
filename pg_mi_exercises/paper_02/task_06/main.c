#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

#define ENTSCHLUESSELN 0
#define VERSCHLUESSELN 1

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


void entschluesseln(char *string, int n) {
    for (int i = 0; i < strlen(string); ++i) {
        int asciiwert = string[i];
        string[i] = asciiwert - n;
    }
}

void verschluesseln(char *string, int n) {
    for (int i = 0; i < strlen(string); ++i) {
        int asciiwert = string[i];
        string[i] = asciiwert + n;
    }
}

int main(int argc, char *argv[]) {

    printf("Gib 1 für verschlüsseln und 0 fur entschlüsseln ein: ");
    int wahl = lese_zahl();

    printf("Gib einen Text ein, der verarbeitet werden soll: ");
    char *string = malloc(sizeof(char) * MAX_LENGTH);
    fgets(string, MAX_LENGTH, stdin);

    printf("Gib eine Zahl ein, mit der verschlüsselt wurde / verschlüsselt werden soll: ");
    int n = lese_zahl();

    switch (wahl) {

        case VERSCHLUESSELN:
            verschluesseln(string, n);
            break;

        case ENTSCHLUESSELN:
            entschluesseln(string, n);
            break;

        default:
            printf("Fehler");
            return 1;
    }

    printf("\n\nResultat: %s", string);
    free(string);

    return 0;
}