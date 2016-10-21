#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Verwendung: getsquareroot ZAHL\n");
        return 1;
    }
    int zahl = atoi(argv[1]);

    // Hier bitte den Code zur Berechnung der Quadratwurzel einfügen
    // Anwendung des Newton Verfahrens zur Berechnung der Quadratwurzel
    double abweichung = 0.0000001;
    double f1 = abweichung;

    while (f1 * f1 <= zahl) {
        f1 += abweichung;
    }

    printf("Ergebnis: %lf\n", f1);
    return 0;
}