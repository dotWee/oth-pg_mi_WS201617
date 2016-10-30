#include <stdio.h>
#include <math.h>

int main(void) {
    int radius;
    double flaeche;

    printf("Radius: ");
    scanf("%d", &radius);

    flaeche = (radius * radius) * M_PI;

    printf("---------");
    printf("\nFläche: %lf", flaeche);

    return 0;
}