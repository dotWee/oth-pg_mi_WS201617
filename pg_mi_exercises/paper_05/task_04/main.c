#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILEPATH "G:\\pg_mi_WS201617\\pg_mi_exercises\\paper_05\\task_04\\"
#define FILENAME "personen.csv"

char *get_filename() {

    // Zieldatei definieren
    char *ziel = malloc(sizeof(char) * (strlen(FILEPATH) + strlen(FILENAME) + 1));
    strcpy(ziel, FILEPATH);
    strcat(ziel, FILENAME);

    // printf("%s\n", ziel);

    return ziel;
}

typedef struct _person {
    char nachname[255];
    char vorname[255];

    int alter;
    char geschlecht;

} Person;

Person new_person(char *nachname, char *vorname, int *alter, char *geschlecht) {
    Person *person = malloc(sizeof(person));

    person->nachname = nachname;
}

int main(int argc, const char *argv[]) {

}