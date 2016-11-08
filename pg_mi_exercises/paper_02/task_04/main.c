#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[]) {
	
	int i = 0;
	
	// Gehe 200 Positionen nach unten
	int location;
	for (location = 0; location <= 200; location++) {
		printf("Value %c von Adresse %p, %d Stufen unter i\n", *(char*)(&i - location), &i - location, location);
	}

	return 0;
}
