#include <stdio.h>

int main(void) {
    int laenge = 0;
    int breite = 0;

    int flaeche;

    printf("Länge: ");
    scanf("%d", &laenge);

    printf("Breite: ");
    scanf("%d", &breite);

    flaeche = laenge * breite;
    printf("---------");
    printf("\nFläche: %d", flaeche);

    return 0;
}