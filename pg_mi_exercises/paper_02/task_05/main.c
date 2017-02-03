#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ANZAHL_PATIENTEN 4
#define MAX_LENGTH 100

typedef struct _patient {
    int nummer;

    char *name;
    char *vorname;

    char *strasse;
    char *postleitzahl;
    char *ort;

} Patient;

void printp(Patient *patient) {
    printf("Name für Patient %d: %s\n", patient->nummer, patient->name);
    printf("Vorname für Patient %d: %s\n", patient->nummer, patient->vorname);
    printf("Straße für Patient %d: %s\n", patient->nummer, patient->strasse);
    printf("Postleitzahl für Patient %d: %s\n", patient->nummer, patient->postleitzahl);
    printf("Ort für Patient %d: %s\n", patient->nummer, patient->ort);
}

char *lese_zeile() {

    // Buffer
    char *buffer = malloc(sizeof(char) * MAX_LENGTH);

    // Einlesen
    fgets(buffer, MAX_LENGTH, stdin);

    return buffer;
}

int main(int argc, char *argv[]) {
    Patient patienten[ANZAHL_PATIENTEN];

    // 4 Mal einlesen
    for (int i = 0; i < ANZAHL_PATIENTEN; ++i) {
        // Patient definieren
        Patient patient;
        int nummer = i;
        patient.nummer = nummer;

        // Neuen Patienten einlesen
        printf("Name für Patient %d: ", i);
        char *name = lese_zeile();
        patient.name = name;

        printf("Vorname für Patient %d: ", i);
        char *vorname = lese_zeile();
        patient.vorname = vorname;

        printf("Straße für Patient %d: ", i);
        char *strasse = lese_zeile();
        patient.strasse = strasse;

        printf("Postleitzahl für Patient %d: ", i);
        char *postleitzahl = lese_zeile();
        patient.postleitzahl = postleitzahl;

        printf("Ort für Patient %d: ", i);
        char *ort = lese_zeile();
        patient.ort = ort;


        // Speichern in Array
        patienten[i] = patient;
    }

    // Arrray sortieren
    Patient temp;
    for (int i = 0; i < ANZAHL_PATIENTEN; ++i) {

        for (int j = 1; j < ANZAHL_PATIENTEN; ++j) {
            if (strncmp(patienten[j - 1].name, patienten[j].name, MAX_LENGTH)) {
                temp = patienten[j - 1];
                patienten[j - 1] = patienten[j];
                patienten[j] = temp;
            }
        }
    }

    // Array ausgeben
    for (int k = 0; k < ANZAHL_PATIENTEN; ++k) {
        printp(&patienten[k]);
    }

    return 0;
}