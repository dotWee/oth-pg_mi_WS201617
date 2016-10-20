#include <stdio.h>

#define HOEHE 12
#define BREITE 13

int main(void) {
	int laenge = 0;

	printf("Laenge: ");
	scanf("%d", &laenge);

	int result = laenge * BREITE;

        int result2 = laenge * BREITE * HOEHE;

	printf("Flaeche: %d", result);
}
