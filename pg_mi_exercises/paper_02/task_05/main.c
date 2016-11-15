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

/**
 * Diese Funktion gibt eine gegebene Patienten Liste aus.
 *
 * @param patienten
 */
void printp(Patient patienten[]) {
    Patient temp;
    for (int i = 0; i < PATIENTEN_ANZAHL; i++) {
        temp = patienten[i];
        printf("Patient: nummer=%d name=%s vorname=%s strasse=%s postleitzahl=%s ort=%s", temp.nummer, temp.name,
               temp.vorname, temp.strasse, temp.postleitzahl, temp.ort);
    }
}

/**
 * Diese Funktion sortiert eine Patienten Liste nach
 * aufsteigendem Nachnamen.
 *
 * @param patienten
 */
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

/**
 * Diese Funktion liest eine bestimmte Anzahl von Patienten in
 * eine vordefinierte Liste ein.
 *
 * @param patienten
 */
void readp(Patient patienten[PATIENTEN_ANZAHL]) {
    for (int i = 0; i < PATIENTEN_ANZAHL; i++) {

        // Deklariere neuen Patient
        Patient p;

        // Setze neue Nummer fest
        p.nummer = i + 1;

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

        // Patient in Array speichern
        patienten[i] = p;
    }
}

int main(int argc, char *argv[]) {
    Patient patienten[PATIENTEN_ANZAHL];

    // Patienten einlesen und in Array speichern
    readp(patienten);

    // Patienten Array sortieren
    sortp(patienten);

    // Patienten Array ausgeben
    printp(patienten);

    return 0;
}