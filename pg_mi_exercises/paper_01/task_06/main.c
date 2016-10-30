#include <stdio.h>

int main(void) {
    int zahl = 0;
    printf("Zahl: ");
    scanf("%d", &zahl);

    int istPrimzahl = -1;
    if (zahl <= 1) {
        // Keine Primzahl
        istPrimzahl = 0;
    }

    if (zahl % 2 == 0 && zahl > 2) {
        // Keine Primzahl
        istPrimzahl = 0;
    }

    for (int i = 3; i < zahl / 2; i += 2) {
        if (zahl % i == 0) {
            // Keine Primzahl
            istPrimzahl = 0;
        }
    }

    if (istPrimzahl == -1) {
        printf("\nZahl ist eine Primzahl");
    }

    if (istPrimzahl == 0) {
        printf("\nZahl ist keine Primzahl");
    }

    return 0;
}