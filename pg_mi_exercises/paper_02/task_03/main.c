#include <stdio.h>

int main(int argc, char *argv[]) {

    int zahl1;
    printf("Wert Zahl 1: ");
    scanf("%d", &zahl1);

    int zahl2;
    printf("Wert Zahl 2: ");
    scanf("%d", &zahl2);

    printf("\nAdresse Zahl 1: %p", &zahl1);
    printf("\nAdresse Zahl 2: %p", &zahl2);

    printf("\n\n");

    int ergebnis = zahl1 + zahl2;
    printf("Wert Ergebnis: %d", ergebnis);
    printf("\nAdresse Ergebn: %p", &ergebnis);

    return 0;
}