#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILEPATH "G:\\pg_mi_WS201617\\pg_mi_exercises\\paper_05\\task_02\\"
#define FILENAME "primzahlen.txt"

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

int main(int argc, const char *argv[]) {

    // Zieldatei definieren
    char *ziel = malloc(sizeof(char) * (strlen(FILEPATH) + strlen(FILENAME) + 1));
    strcpy(ziel, FILEPATH);
    strcat(ziel, FILENAME);
    // printf("%s\n", ziel);

    // Datei Pointer anlegen
    FILE *f = NULL;
    f = fopen(ziel, "w");

    // Text in Datei schreiben
    int primzahl_nummer = 0;
    int zahl = 0;

    // Solange wir nicht 100 Primzahlen gefunden haben
    while (primzahl_nummer != 100) {

        // Wenn Zahl eine Primzahl ist
        if (ist_primzahl(zahl)) {

            // Primzahl in Datei schreiben
            fprintf(f, "%d\n", zahl);
            primzahl_nummer++;
        }
        zahl++;
    }

    // Datei Pointer schließen
    fclose(f);

    return 0;
}