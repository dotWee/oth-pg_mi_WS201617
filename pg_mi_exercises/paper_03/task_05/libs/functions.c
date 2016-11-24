#include "functions.h"

/**
 * Funktion zur Berechnung der Quadratwurzel
 *
 * @param zahl Zahl dessen Quadratwurzel berechnet werden soll
 * @return Die Quadratwurzel der Zahl
 */
double my_sqrt(int zahl) {
    // Definition des Rückgabewerts
    double sqrt = MAX_ABWEICHUNG;

    // Anwendung des Newton Verfahrens zur Berechnung der Quadratwurzel
    while (sqrt * sqrt <= zahl) {
        sqrt += MAX_ABWEICHUNG;
    }

    // Gib Ergebnis zurück
    return sqrt;
}

/**
 * Funktion zur Berechnung der Potenz mit bestimmten Exponent
 *
 * @param zahl Zahl dessen Potenz berechnet werden soll
 * @param exponent Expontent der Zahl
 * @return Die Potenz der Zahl
 */
double my_pow(int zahl, int exponent) {
    // Definition des Rückgabewerts
    double pow = 0.0;

    switch (exponent) {

        case -1:
            pow = 0 - zahl;
            break;

        case 0:
            pow = 1;
            break;

        case 1:
            pow = zahl;
            break;

        default:
            if (exponent > 1) {
                pow = 1;

                for (int n = 1; n <= exponent; n++) {
                    pow = pow * zahl;
                }
            } else if (exponent < -1) {
                pow = 1;

                for (int n = 0; n > exponent; n--) {
                    pow = pow / zahl;
                }
            }
            break;
    }

    // Gib Ergebnis zurück
    return pow;
}