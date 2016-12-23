#include <stdio.h>
#include <string.h>

#define LEN 30

typedef struct _pat {
    int pat_id;
    char *vorname;
    char *nachname;
} Patient;

int main() {
    Patient p;
    p.vorname = "Max";
    p.nachname = "Musterer";

    FILE *f = fopen("binary2.dat", "w");

    for(int i = 0; i < 10; i++) {
        p.pat_id = i+1;
        fwrite(&p, sizeof(Patient), 1, f);
    }

    fclose(f);
    f = fopen("binary2.dat", "r");

    fread(&p, sizeof(Patient), 1, f);
    printf("%d %s %s\n", p.pat_id, p.vorname, p.nachname);

    fclose(f);
    return 0;
}