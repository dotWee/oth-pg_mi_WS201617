#include <stdio.h>
#include <stdlib.h>

#define ERROR_FALSCHER_OPERATOR 1

#define MAX_LENGTH 100
#define OPERATOR_LENGTH 6

int lese_zahl() {

    // Definiere Ziele
    char *ziel = malloc(sizeof(char) * MAX_LENGTH);
    fgets(ziel, MAX_LENGTH, stdin);

    // Umwandlung in Zahl
    int zahl = atoi(ziel);

    // Speicher freigeben
    free(ziel);

    // Zahl zurückgeben
    return zahl;
}

char *lese_operator() {

    // Definiere Ziele
    char *ziel = malloc(sizeof(char) * OPERATOR_LENGTH);
    fgets(ziel, OPERATOR_LENGTH, stdin);

    return ziel;
}

int main(int argc, char *argv[]) {

    // 1. Zahl einlesen
    printf("Zahl 1: ");
    int zahl1 = lese_zahl();

    // Operator einlesen
    printf("Operator: ");
    char *operator = lese_operator();

    // 2. Zahl einlesen2
    printf("Zahl 2: ");
    int zahl2 = lese_zahl();

    // Berechnen
    int ergebnis;
    switch (operator[0]) {

        case '+':
            ergebnis = zahl1 + zahl2;
            break;

        case '-':
            ergebnis = zahl1 - zahl2;
            break;

        case '*':
            ergebnis = zahl1 * zahl2;
            break;

        case '/':
            ergebnis = zahl1 / zahl2;
            break;

        default:
            printf("Falscher Operator");
            return ERROR_FALSCHER_OPERATOR;
    }

    // Speicher leeren
    free(operator);

    // Ausgeben
    printf("Ergebnis: %d", ergebnis);

    return 0;
}