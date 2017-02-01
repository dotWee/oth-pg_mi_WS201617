#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main(int argc, char *argv[]) {

    // Frage nach Name
    printf("Gib einen Namen ein: ");
    char *name = malloc(sizeof(char) * MAX_LENGTH);
    // ODER: char name2[MAX_LENGTH];

    // Name einlesen
    fgets(name, MAX_LENGTH, stdin);

    // Gebe Name aus
    printf("\nHallo %s", name);

    // Gib Speicher
    free(name);

    // Gib Erfolg zurück
    return 0;
}