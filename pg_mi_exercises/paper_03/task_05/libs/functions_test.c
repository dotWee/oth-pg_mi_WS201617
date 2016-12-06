#include <stdio.h>
#include "functions.h"

int test_my_sqrt(int testwert, double erwartung) {
    int error = 0;

    double resultat = my_sqrt(testwert);
    double resultat_plus_abweichung = resultat + MAX_ABWEICHUNG;
    double resultat_minus_abweichung = resultat - MAX_ABWEICHUNG;


    // Wenn das Resultat nicht im Bereich der Abweiung liegt
    int ist_kleiner_maxwert = erwartung <= resultat_plus_abweichung;
    int ist_groesser_minwert = erwartung >= resultat_minus_abweichung;
    if (!ist_kleiner_maxwert || !ist_groesser_minwert) {
        // Fehler
        printf("Fehler bei my_sqrt: Resultat %lf aus Testwert %d ungleich der Erwartung %lf | istKleinerAlsMaxwert=%s | istGroesserAlsMinwert=%s\n",
               resultat, testwert, erwartung, ist_kleiner_maxwert ? "true" : "false",
               ist_groesser_minwert ? "true" : "false");
        error += 1;
    }

    return error;
}

int test_my_pow(int testwert, int exponent, double erwartung) {
    int error = 0;

    double resultat = my_pow(testwert, exponent);

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
    errors += test_my_pow(testwert_pow_positiv, testwert_pow_positiv, erwartung_pow_positiv);

    // Teste my_pow Funktion NEGATIV
    int testwert_pow_negativ = -2;
    double erwartung_pow_negativ = 0.250000;
    errors += test_my_pow(testwert_pow_negativ, testwert_pow_negativ, erwartung_pow_negativ);

    // Teste my_pow Funktion POSITIVER TESTWERT NEGATIVER EXPONENT
    int testwert_pow_positiv_negativ = 5;
    int testwert_pow_exponent_positiv_negativ = -1;
    double erwartung_pow_positiv_negativ = 0.200000;
    errors += test_my_pow(testwert_pow_positiv_negativ, testwert_pow_exponent_positiv_negativ,
                          erwartung_pow_positiv_negativ);

    // Teste my_pow Funktion NULL
    int testwert_pow_null = 0;
    double erwartung_pow_null = 1.000000;
    errors += test_my_pow(testwert_pow_null, testwert_pow_null, erwartung_pow_null);

    return errors;
}