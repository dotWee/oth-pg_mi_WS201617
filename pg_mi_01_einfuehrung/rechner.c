#include <stdio.h>

void main(void) {
    int s1 = 0;
    int s2 = 0;
    int erg = 0;

    printf("Summand 1: \n");
    scanf("%d", &s1);
    printf("Summand 2: \n");
    scanf("%d", &s2);

    erg = s1 + s2;

    printf("Ergebnis: %d + %d = %d\n", s1, s2, erg);
}
