#include <stdio.h>

int main() {
    FILE *f = fopen("datei_append.txt", "a");
    if(f == NULL) {
        printf("Datei datei_append.txt nicht gefunden\n");
        return 1;
    }

    fprintf(f, "Und eine Zeile hinzugefügt\n");

    fclose(f);
    return 0;
}