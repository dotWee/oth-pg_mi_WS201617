#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int len = argc-1;
	double zahlen[len];
	double durchschnitt = 0;
	for(int i = 0; i < len; i++) {
		zahlen[i] = atof(argv[i+1]);
	}

	if(len > 0) {
		double summe = 0;
		for(int i = 0; i < len; i++) {
			summe += zahlen[i];
		}
		durchschnitt = summe / len;
	}
	
	printf("Durchschnitt: %lf\n", durchschnitt);
	return 0;
}
