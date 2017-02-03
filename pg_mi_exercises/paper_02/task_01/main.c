#include <stdio.h>
#include <stdlib.h>

#define ERROR_ASTREIHEN 1

void print_leerzeichen(int anzahl) {
    for (int i = 0; i < anzahl; ++i) {
        printf(" ");
    }
}

void print_stern(int anzahl) {
    for (int i = 0; i < anzahl; ++i) {
        printf("*");
    }
}

void print_stamm() {
    for (int i = 0; i < 3; ++i) {
        printf("|");
    }
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Fehler: Keine Anzahl der Astreihen gegeben");
        return ERROR_ASTREIHEN;
    }

    // Astreihen auslesen
    int astreihen = atoi(argv[1]);
    printf("Astreihen: %d", astreihen);

    return 0;
}