#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define ERROR_PARAMETER 1

char *lese_zeile() {

    // Definiere Ziel
    char *string = malloc(sizeof(char) * MAX_LENGTH);

    // Einlesen
    fgets(string, MAX_LENGTH, stdin);

    // Zurückgeben
    return string;
}

int main(int argc, char *argv[]) {

    // Nach Text fragen
    printf("Gib einen Text ein, der verarbeitet werden soll: ");
    char *string = lese_zeile();

    // Nach Schlüssel fragen
    printf("Gib einen Schlüssel ein: ");
    char *key = lese_zeile();

    // Verarbeitung
    char *result = malloc(sizeof(char) * MAX_LENGTH);
    for (int i = 0; i < strlen(string); ++i) {
        char character = string[i];

        result[i] = character ^ key[0];
    }

    printf("Ergebnis: %s", result);

    return 0;
}