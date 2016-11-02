#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char* basis = "Hallo Welt";

  char ziel[11];
  char irgendwas[10] = "123456789";

  for(int i = 0; i < 11; i++) {
    ziel[i] = basis[i];

    if(basis[i] == '\0') {
      break;
    }
  }

  // Da mein gcc hier mehrere Null-Bytes zwischen den 
  // beiden Char-Arrays angelegt hat. Lücke mit 'A's auffüllen
  irgendwas[9] = 'A';
  irgendwas[10] = 'A';
  irgendwas[11] = 'A';
  irgendwas[12] = 'A';
  irgendwas[13] = 'A';
  irgendwas[14] = 'A';
  irgendwas[15] = 'A';

  printf("Quelle: %s\nZiel: %s\n", basis, ziel);
  printf("Ziel:\t\t %p\nIrgendwas:\t %p\n", &ziel, &irgendwas);
  printf("Ziel: %s\nIrgendwas: %s\n", ziel, irgendwas);

  // So ähnlich aber besser!
  strncpy(ziel, basis, 10);

  printf("Ziel: %s\n", ziel);

  strncpy(ziel, irgendwas, 10);

  printf("Ziel: %s\n", ziel);

  return 0;
}
