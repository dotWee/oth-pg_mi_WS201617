#include <stdio.h>
#include <stdlib.h>

#define PRECISION 0.0000001

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Verwendung: getsquareroot ZAHL\n");
		return 1;
	}

	int zahl = atoi(argv[1]);
	double step = 1.0;
	double f1 = 0.0;
	double value = zahl;

	while(f1*f1 != value && step > PRECISION) {
		f1 = f1 + step;
		if(f1 < value/f1) {
			//printf("%lf - %lf;\n", f1, step);
		} else {
			f1 = f1 - step;
			step = step / 10.0;
		}
	}

	printf("Ergebnis: %lf\n", f1);

	return 0;
}
