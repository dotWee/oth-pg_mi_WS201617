#include <stdio.h>

int main(void) {
	int exponent = 0;
	int basis = 0;
	double result = 0;

	printf("Basis: ");
	scanf("%d", &basis);

	printf("Exponent: ");
	scanf("%d", &exponent);

	if(exponent > 0) {
		result = basis;
		for(int i = 0; i < exponent-1; i++) {
			result *= basis;
		}
	} else if(exponent < 0) {
		result = basis;
		for(int i = 0; i > exponent-1; i--) {
			result = result / basis;
		}
	} else {
		result = 1;
	}

	printf("Ergebnis: %lf\n", result);
}
