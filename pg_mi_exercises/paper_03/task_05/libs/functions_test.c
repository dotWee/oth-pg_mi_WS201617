#include <stdio.h>
#include "functions.h"

_Bool isBetween(double start, double end, double value) {
    return start <= value && value <= end;
}

int test_my_sqrt(int testwert, double erwartung) {
    int error = 0;

    double resultat = my_sqrt(testwert);
    double resultat_plus_abweichung = resultat + MAX_ABWEICHUNG;
    double resultat_minus_abweichung = resultat - MAX_ABWEICHUNG;

    // Wenn das Resultat aus der Funktion ungleich des erwarteten Werts ist...
    if (isBetween(resultat_minus_abweichung, resultat_plus_abweichung, erwartung)) {
        // Fehler
        printf("Fehler bei my_sqrt: Resultat %lf aus Testwert %d ungleich der Erwartung %lf\n", resultat, testwert,
               erwartung);
        error += 1;
    }

    return error;
}

int test_my_pow(int testwert, double erwartung) {
    int error = 0;

    double resultat = my_pow(testwert, testwert);

    // Wenn das Resultat aus der Funktion ungleich des erwarteten Werts ist...
    if (erwartung != resultat) {
        // Fehler
        printf("Fehler bei my_pow: Resultat %lf aus Testwert %d ungleich der Erwartung %lf\n", resultat, testwert,
               erwartung);
        error += 1;
    }

    return error;
}

int main(int argc, const char *argv[]) {
    int errors = 0;

    // Teste my_sqrt Funktion
    int testwert_sqrt = 9;
    double erwartung_sqrt = 3;
    errors += test_my_sqrt(testwert_sqrt, erwartung_sqrt);

    // Teste my_pow Funktion POSITIV
    int testwert_pow_positiv = 2;
    double erwartung_pow_positiv = 4.000000;
    errors += test_my_pow(testwert_pow_positiv, erwartung_pow_positiv);

    // Teste my_pow Funktion NEGATIV
    int testwert_pow_negativ = -2;
    double erwartung_pow_negativ = 0.250000;
    errors += test_my_pow(testwert_pow_negativ, erwartung_pow_negativ);

    // Teste my_pow Funktion NULL
    int testwert_pow_null = 0;
    double erwartung_pow_null = 1.000000;
    errors += test_my_pow(testwert_pow_null, erwartung_pow_null);

    return errors;
}