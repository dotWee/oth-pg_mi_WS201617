#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define FILENAME "primzahlen.txt"

void read_file() {
    FILE *f = fopen(FILENAME, "r");
    static const int BUF_SIZE = 20;
    char buf[BUF_SIZE];

    if(f == NULL) return; // Abbrechen wenn f nicht offen

    int zaehler = 0;
    while(fgets(buf, BUF_SIZE, f) != NULL) {
        zaehler++;
        if(zaehler >= 49 && zaehler <= 51) {
            printf("%d -> %s\n", zaehler, buf);
        }
    }

    fclose(f);
}

void read_file2() {
    long array[100];
    int array_len = sizeof(array)/sizeof(array[0]);

    FILE *f = fopen(FILENAME, "r");
    static const int BUF_SIZE = 20;
    char buf[BUF_SIZE];

    if(f == NULL) return; // Abbrechen wenn f nicht offen

    int zaehler = 0;
    while(fgets(buf, BUF_SIZE, f) != NULL 
            && zaehler < array_len) {
        array[zaehler] = atol(buf);
        zaehler ++;
    }

    fclose(f);

    printf("49 -> %ld\n", array[49-1]);
    printf("50 -> %ld\n", array[50-1]);
    printf("51 -> %ld\n", array[51-1]);
}

_Bool is_prime(int zahl) {
    for(int i = 2; i < zahl/2; i++) {
        if(zahl % i == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void create_file() {
    FILE *f = fopen(FILENAME, "w");
    if(f == NULL) return; // Abbrechen wenn das File nicht geöffnet werden konnte
    
    int zahl = 2;
    int treffer = 0;
    while(treffer < 100) {
        if(is_prime(zahl)) {
            treffer++;
            fprintf(f, "%d\n", zahl);
        }
        zahl++;
    }

    fclose(f);
}

int main() {
    create_file();
    read_file();
    read_file2();
    return 0;
}