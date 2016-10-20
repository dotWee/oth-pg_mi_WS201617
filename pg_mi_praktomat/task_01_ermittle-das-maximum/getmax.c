//
// Created by lukas on 19.10.2016.
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int len = argc-1;
    int zahlen[len];
    int maximum = 0;

    for(int i = 0; i < len; i++) {
        zahlen[i] = atoi(argv[i+1]);
    }

    // Bitte hier den Code zum Ermitteln des Maximums eingeben
    for (int j = 0; j < len; ++j) {
        if (zahlen[j] >= maximum) {
            maximum = zahlen[j];
        }
    }

    printf("Maximum: %d\n", maximum);
    return 0;
}