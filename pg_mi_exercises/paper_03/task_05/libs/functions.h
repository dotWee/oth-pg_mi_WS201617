#ifndef _MY_FUNCTIONS_H
#define _MY_FUNCTIONS_H

// Konstanten
#define MAX_ABWEICHUNG 0.0000001;

// Definition der Funktionen

/**
 * Funktion zur Berechnung der Quadratwurzel
 *
 * @param zahl Zahl dessen Quadratwurzel berechnet werden soll
 * @return Die Quadratwurzel der Zahl
 */
double my_sqrt(int zahl);

/**
 * Funktion zur Berechnung der Potenz mit bestimmten Exponent
 *
 * @param zahl Zahl dessen Potenz berechnet werden soll
 * @param exponent Expontent der Zahl
 * @return Die Potenz der Zahl
 */
double my_pow(int zahl, int exponent);

#endif