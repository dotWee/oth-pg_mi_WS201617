#include <stdio.h>

int main(void) {
    double result = 0.0;

    // Hier bitte den Code zum Erfragen der ganzzahligen Basis,
    int basis = 0;
    printf("Basis: ");
    scanf("%d", &basis);

    // des ganzzahligen Exponenten und zur Berechnung des
    int exponent = 0;
    printf("Exponent: ");
    scanf("%d", &exponent);

    // Ergebnisses von Typ double einfügen.
    result = basis;
    while (exponent != 0) {
        result = result * exponent;
        exponent = exponent - 1;
    }

    printf("Ergebnis: %lf\n", result);
}