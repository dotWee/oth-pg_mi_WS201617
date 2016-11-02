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

  ziel[10] = 'A';

  printf("Quelle: %s\nZiel: %s\n", basis, ziel);

  // So ähnlich aber besser!
  strncpy(ziel, basis, 10);

  printf("Ziel: %s\n", ziel);

  strncpy(ziel, irgendwas, 10);

  printf("Ziel: %s\n", ziel);

  return 0;
}
