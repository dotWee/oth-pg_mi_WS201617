#include <stdio.h>
#include <string.h>

#define LEN 30

typedef struct _pat {
    int pat_id;
    char vorname[LEN];
    char nachname[LEN];
} Patient;

int main() {
    Patient p;
    strncpy(p.vorname, "MMMMMMM", LEN);
    strncpy(p.nachname, "Musterer", LEN);

    FILE *f = fopen("binary.dat", "w");

    for(int i = 0; i < 10; i++) {
        p.pat_id = i+1;
        fwrite(&p, sizeof(Patient), 1, f);
    }

    fclose(f);
    return 0;
}