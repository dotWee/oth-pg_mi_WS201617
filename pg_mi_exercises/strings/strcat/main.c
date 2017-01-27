#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

char *strcat_own(char *ziel, char *quelle) {

    // + 1 wegen Null-Terminierung!
    int anzahlZiel = strlen(ziel);
    int anzahlQuelle = strlen(quelle);
    int anzahlChars = anzahlZiel + anzahlQuelle + 1;

    // neuen Speicher definieren
    char *target = malloc(sizeof(char) * anzahlChars);

    // für jeden buchstaben aus dem ziel...
    for (int i = 0; i < strlen(ziel); ++i) {
        target[i] = ziel[i];
    }

    // quelle ans ende des ziels schreiben
    for (int j = 0; j < strlen(quelle); ++j) {
        target[anzahlZiel + j] = quelle[j];
    }

    // sichergehen das der string terminiert wurde
    if (target[anzahlChars] != '\0') {
        target[anzahlChars] = '\0';
    }

    // pointer überschreiben
    ziel = target;

    // pointer zurückgeben
    return ziel;
}

int main(int argc, char *argv[]) {

    char temp[] = "Ich heiße ";

    char buffer[BUFFER_SIZE];
    printf("Gib einen Namen ein:\n");

    // Vorsicht bei fgets, das setzt ein NEWLINE-Zeichen durch die Bestätigung mit Enter am Ende des Strings,
    // welches wir für Test-Zwecke entfernen müssen
    fgets(buffer, BUFFER_SIZE, stdin);

    if (buffer[strlen(buffer) - 1] == '\n') {
        buffer[strlen(buffer) - 1] = '\0';
    }

    char *neuerString = strcat_own(temp, buffer);
    printf("Aus %s wurde %s", temp, neuerString);

    return 0;
}