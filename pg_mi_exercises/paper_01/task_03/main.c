#include <stdio.h>
#include <math.h>

int main(void) {
    int kathete1, kathete2;
    double hypotenuse;

    printf("Kathete1: ");
    scanf("%d", &kathete1);

    printf("Kathete2: ");
    scanf("%d", &kathete2);

    hypotenuse = (kathete1 * kathete1) + (kathete2 * kathete2);
    hypotenuse = sqrt(hypotenuse);

    printf("---------");
    printf("\nHypotenuse: %lf", flaeche);

    return 0;
}