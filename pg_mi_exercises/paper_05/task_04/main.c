#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define FILEPATH "D:\\Projekte\\Studium\\pg_mi_WS201617\\pg_mi_exercises\\paper_05\\task_04\\"
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
    char *nachname;
    char *vorname;

    char *alter;
    char *geschlecht;
} Person;

Person *person_new(char *nachname, char *vorname, char *alter, char *geschlecht) {
    Person *person = malloc(sizeof(person));

    person->nachname = nachname;
    person->vorname = vorname;

    person->alter = alter;
    person->geschlecht = geschlecht;

    return person;
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

void person_free(Person *person) {
    free(person->nachname);
    free(person->vorname);
    free(person->alter);
    free(person->geschlecht);
}

char **str_split(char *a_str, const char a_delim) {
    char **result = 0;
    size_t count = 0;
    char *tmp = a_str;
    char *last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp) {
        if (a_delim == *tmp) {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char *) * count);

    if (result) {
        size_t idx = 0;
        char *token = strtok(a_str, delim);

        while (token) {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

Person *person_from_line(char *line) {
    Person *person = malloc(sizeof(person));
    char **value_array = str_split(line, ';');

    char *nachname = value_array[0];
    person->nachname = nachname;

    char *vorname = value_array[1];
    person->vorname = vorname;

    char *alter = value_array[2];
    person->alter = alter;

    char *geschlecht = value_array[3];
    person->geschlecht = geschlecht;

    return person;
}


int main(int argc, const char *argv[]) {
    // Dateipfad mit Dateinamen
    char *ziel = get_filename();

    // Datei einlesen
    FILE *file = fopen(ziel, "r");
    if (file == NULL) {
        printf("Fehler, Datei ist null");
        return -1;
    }

    // Personen Array anlegen
    int lines = get_lines(ziel);
    Person **personen = malloc(sizeof(void) * (lines - 1));

    // Erste Zeile überspringen
    char line[256];
    fgets(line, sizeof(line), file);

    // Für jede restliche Zeile in der Datei
    int position = 0;
    while (fgets(line, sizeof(line), file)) {
        // Neue Person aus der Zeile erstellen
        Person *person = person_from_line(line);

        // Person ausgeben
        printf("Nachname=%s Vorname=%s Alter=%d, Geschlecht=%s\n", person->nachname, person->vorname, *person->alter,
               person->geschlecht);

        // Personen ins Array schreiben
        personen[position] = person;
        position++;
    }

    // Speicher freigeben
    free(ziel);

    // Datei Pointer schließen
    fclose(file);

    return 0;
}