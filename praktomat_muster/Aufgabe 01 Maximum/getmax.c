#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int len = argc-1;
    int zahlen[len];
    int maximum = 0;
    for(int i = 0; i < len; i++) {
    	zahlen[i] = atoi(argv[i+1]);
    }

	if(len > 0) {
		maximum = zahlen[0];
		for(int i = 1; i < len; i++) {
			if(zahlen[i] > maximum) {
				maximum = zahlen[i];
			}
		}
	}

    printf("Maximum: %d\n", maximum);
    return 0;
}