#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define PATIENTEN_ANZAHL 4

typedef struct patient {
    int nummer;
    char name[MAX_LENGTH];
    char vorname[MAX_LENGTH];

    char strasse[MAX_LENGTH];
    char postleitzahl[MAX_LENGTH];
    char ort[MAX_LENGTH];
} Patient;

int main(int argc, char *argv[]) {
    Patient patienten[PATIENTEN_ANZAHL];

    // 4 Patienten einlesen und in Array speichern
    for (int i = 0; i < PATIENTEN_ANZAHL; i++) {

        // Deklariere neuen Patient
        Patient p;

        // Setze neue Nummer fest
        p.nummer = i + 1;

        // Name einlesen
        printf("Name: ");
        fgets(p.name, MAX_LENGTH, stdin);

        // Vorname einlesen
        printf("Vorname: ");
        fgets(p.vorname, MAX_LENGTH, stdin);

        // Straße einlesen
        printf("Straße: ");
        fgets(p.strasse, MAX_LENGTH, stdin);

        // Postleitzahl einlesen
        printf("Postleitzahl: ");
        fgets(p.postleitzahl, MAX_LENGTH, stdin);

        // Ort einlesen
        printf("Ort: ");
        fgets(p.ort, MAX_LENGTH, stdin);

        // Patient in Array speichern
        patienten[i] = p;
    }

    // Patienten Array sortieren
    Patient temp;
    for (int i = 0; i < PATIENTEN_ANZAHL; i++) {
        for (int j = 1; j < PATIENTEN_ANZAHL; j++) {
            if (strncmp(patienten[j - 1].name, patienten[j].name, MAX_LENGTH) > 0) {
                temp = patienten[j - 1];
                patienten[j - 1] = patienten[j];
                patienten[j] = temp;
            }
        }
    }

    // Patienten Array ausgeben
    for (int i = 0; i < PATIENTEN_ANZAHL; i++) {
        temp = patienten[i];
        printf("Patient: nummer=%d name=%s vorname=%s strasse=%s postleitzahl=%s ort=%s", temp.nummer, temp.name,
               temp.vorname, temp.strasse, temp.postleitzahl, temp.ort);
    }

    return 0;
}
