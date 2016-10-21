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

    if (exponent == -1) {
        result = 0 - basis;
    } else if (exponent == 0) {
        result = 1;
    } else if (exponent == 1) {
        result = basis;
    } else if (exponent > 1) {
        result = 1;

        for (int n = 1; n <= exponent; n++) {
            result = result * basis;
        }
    } else if (exponent < -1) {
        result = 1;

        for (int n = 0; n > exponent; n--) {
            result = result / basis;
        }
    }

    printf("Ergebnis: %lf\n", result);
    return 0;
}