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
    switch (exponent) {

        case -1:
            result = 0 - basis;
            break;

        case 0:
            result = 1;
            break;

        case 1:
            result = basis;
            break;

        default:
            if (exponent > 1) {
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
            break;
    }

    printf("Ergebnis: %lf\n", result);
    return 0;
}