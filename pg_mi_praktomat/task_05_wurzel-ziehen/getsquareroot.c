#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Verwendung: getsquareroot ZAHL\n");
        return 1;
    }
    int zahl = atoi(argv[1]);

    // Hier bitte den Code zur Berechnung der Quadratwurzel einfügen
    double f1 = 0;
    while(count < 5)
    {
        count++;
        f1 =(f1 + wurzel / f1) /2;

    }

    printf("Ergebnis: %lf\n", f1);
    return 0;
}