#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILEPATH "G:\\pg_mi_WS201617\\pg_mi_exercises\\paper_05\\task_03\\"
#define FILENAME "primzahlen.txt"

char *get_filename() {

    // Zieldatei definieren
    char *ziel = malloc(sizeof(char) * (strlen(FILEPATH) + strlen(FILENAME) + 1));
    strcpy(ziel, FILEPATH);
    strcat(ziel, FILENAME);

    // printf("%s\n", ziel);

    return ziel;
}

int get_lines(char *filename) {
    FILE *file = fopen(filename, "r");

    int lines = 0;

    // Wenn Datei NULL ist, gib 0 zurück
    if (file == NULL) {
        return lines;
    }

    int ch = 0;

    lines++;
    while (!feof(file)) {
        ch = fgetc(file);

        if (ch == '\n') {
            lines++;
        }
    }

    fclose(file);
    return lines;
}

int main(int argc, const char *argv[]) {

    // Dateipfad mit Dateinamen
    char *ziel = get_filename();

    // Datei einlesen
    FILE *file = fopen(ziel, "r");

    // Lese Anzahl der Zeilen der Datei
    int lines = get_lines(ziel);

    // Primzahlarray definieren
    long *prime_array = malloc(sizeof(long) * lines);

    // Für jede Zeile in der Datei
    char line[256];
    int position = 0;

    while (fgets(line, sizeof(line), file)) {

        // Primzahl aus Zeile lesen
        long prime_number = atoi(line);
        //printf("%ld\n", prime_number);

        // Long in array schreiben
        prime_array[position] = prime_number;
        position++;
    }

    // 49ste Primzahl ausgeben
    printf("%ld\n", prime_array[48]);

    // 50ste Primzahl ausgeben
    printf("%ld\n", prime_array[49]);

    // 51ste Primzahl ausgeben
    printf("%ld\n", prime_array[50]);

    // Speicher freigeben
    free(prime_array);
    free(ziel);

    // Datei Pointer schließen
    fclose(file);

    return 0;
}