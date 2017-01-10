#include <stdio.h>
#include <stdlib.h>

#define LEN 30

typedef struct _pat {
    int pat_id;
    char vorname[LEN];
    char nachname[LEN];
} Patient;

int main() {
    Patient p;
    FILE *f = fopen("binary.dat", "r");

    fseek(f, sizeof(Patient)*4, SEEK_SET);
    fread(&p, sizeof(Patient), 1, f);
    printf("%d %s %s\n", p.pat_id, p.vorname, p.nachname);

    fread(&p, sizeof(Patient), 1, f);
    printf("%d %s %s\n", p.pat_id, p.vorname, p.nachname);

    fclose(f);
    return 0;
}