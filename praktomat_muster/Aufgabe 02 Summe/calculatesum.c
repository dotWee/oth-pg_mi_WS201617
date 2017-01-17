#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int len = argc-1;
	int zahlen[len];
	int summe = 0;
	for(int i = 0; i < len; i++) {
		zahlen[i] = atoi(argv[i+1]);
	}

	for(int i = 0; i < len; i++) {
		summe += zahlen[i];
	}
	
	printf("Summe: %d\n", summe);
	return 0;
}
