#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILEPATH "G:\\pg_mi_WS201617\\pg_mi_exercises\\paper_05\\task_01\\"
#define FILENAME "hello.txt"
#define TEXT "Hello World\n"

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
    fprintf(f, TEXT);

    // Datei Pointer schließen
    fclose(f);

    return 0;
}