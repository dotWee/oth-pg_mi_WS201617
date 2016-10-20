//
// Created by lukas on 20.10.2016.
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int len = argc-1;
    double zahlen[len];
    double durchschnitt = 0;
    for(int i = 0; i < len; i++) {
        zahlen[i] = atof(argv[i+1]);
    }

    // Bitte hier den Code für die Berechnung des Durchschnitts einbauen
    double summe = 0;
    for (int j = 0; j < len; ++j) {
        summe = summe + zahlen[j];
    }

    durchschnitt = summe / len;

    printf("Durchschnitt: %lf\n", durchschnitt);
    return 0;
}