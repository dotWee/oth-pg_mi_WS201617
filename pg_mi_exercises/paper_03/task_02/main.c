#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define PATIENTEN_ANZAHL 4

typedef struct patient {
    int nummer;
    char name[BUFFER_SIZE];
    char vorname[BUFFER_SIZE];

    char strasse[BUFFER_SIZE];
    char postleitzahl[BUFFER_SIZE];
    char ort[BUFFER_SIZE];
} Patient;

Patient scan_patient(int id) {
    // Deklariere neuen Patient
    Patient p;

    // Setze neue Nummer fest
    p.nummer = id;

    // Name einlesen
    printf("Name: ");
    fgets(p.name, BUFFER_SIZE, stdin);

    // Vorname einlesen
    printf("Vorname: ");
    fgets(p.vorname, BUFFER_SIZE, stdin);

    // Straße einlesen
    printf("Straße: ");
    fgets(p.strasse, BUFFER_SIZE, stdin);

    // Postleitzahl einlesen
    printf("Postleitzahl: ");
    fgets(p.postleitzahl, BUFFER_SIZE, stdin);

    // Ort einlesen
    printf("Ort: ");
    fgets(p.ort, BUFFER_SIZE, stdin);

    // Neuen Patient zurückgeben
    return p;
}

void sortp(Patient patienten[PATIENTEN_ANZAHL]) {
    Patient temp;
    for (int i = 0; i < PATIENTEN_ANZAHL; i++) {
        for (int j = 1; j < PATIENTEN_ANZAHL; j++) {
            if (strncmp(patienten[j - 1].name, patienten[j].name, BUFFER_SIZE) > 0) {
                temp = patienten[j - 1];
                patienten[j - 1] = patienten[j];
                patienten[j] = temp;
            }
        }
    }
}

void printp(Patient *patient) {
    printf("Patient: nummer=%d name=%s vorname=%s strasse=%s postleitzahl=%s ort=%s", patient->nummer, patient->name,
           patient->vorname, patient->strasse, patient->postleitzahl, patient->ort);
}

int main(int argc, const char *argv[]) {
    Patient patienten[PATIENTEN_ANZAHL];

    // 4 Patienten einlesen und in Array speichern
    for (int i = 0; i < PATIENTEN_ANZAHL; i++) {

        // Patient in Array speichern
        patienten[i] = scan_patient(i + 1);
    }

    // Patienten Array sortieren
    sortp(patienten);

    // Patienten Array ausgeben
    for (int i = 0; i < PATIENTEN_ANZAHL; i++) {
        printp(&patienten[i]);
    }

    return 0;
}