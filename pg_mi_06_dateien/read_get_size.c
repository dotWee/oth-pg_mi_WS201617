#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define LEN 20

int main() {
    char *filename = "datei.txt";
    struct stat s;
    if(stat(filename, &s) == 0) {
        printf("Die Datei hat %ld Bytes\n", s.st_size);
    } else {
        printf("Datei nicht gefunden\n");
        return 1;
    }

    FILE *f = fopen(filename, "r");
    char *buf = calloc(sizeof(char), s.st_size+1);
    fread(buf, sizeof(char), s.st_size, f);
    fclose(f);

    printf("Inhalt: %s", buf);

    free(buf);
    return 0;
}