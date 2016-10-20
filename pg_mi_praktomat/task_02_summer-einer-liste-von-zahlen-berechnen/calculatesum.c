//
// Created by lukas on 20.10.2016.
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int len = argc-1;
    int zahlen[len];
    int summe = 0;
    for(int i = 0; i < len; i++) {
        zahlen[i] = atoi(argv[i+1]);
    }

    // Bitte hier den Code zum Ermitteln der Summe eingeben
    for (int j = 0; j < len; ++j) {
        summe = summe + zahlen[j];
    }

    printf("Summe: %d\n", summe);
    return 0;
}