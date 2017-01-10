#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 30

/*
 * ACHTUNG: Dieses Beispiel zeigt einen typischen Fehler:
 *          Statt der Inhalte der Felder vorname und nachname
 *          werden die Adressen der Strings in die Datei geschrieben.
 */

typedef struct _pat {
    int pat_id;
    char *vorname;
    char *nachname;
} Patient;

int main() {
    Patient p;
    p.vorname = malloc(LEN);
    p.nachname = malloc(LEN);
    strncpy(p.vorname, "Max", LEN);
    strncpy(p.nachname, "Mustermann", LEN);

    FILE *f = fopen("binary2.dat", "w");

    for(int i = 0; i < 10; i++) {
        p.pat_id = i+1;
        fwrite(&p, sizeof(Patient), 1, f);
    }

    free(p.vorname);
    free(p.nachname);
    fclose(f);
    f = fopen("binary2.dat", "r");

    // Warum kommt hier unerwarteter Weise das "richtige"
    // Ergebnis raus!
    fread(&p, sizeof(Patient), 1, f);
    printf("%d %s %s\n", p.pat_id, p.vorname, p.nachname);

    fclose(f);
    return 0;
}
