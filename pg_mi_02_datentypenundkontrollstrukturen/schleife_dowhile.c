#include <stdio.h>

int main(void) {
  int zahl = 0;
  printf("Zahl: ");
  scanf("%d", &zahl);

  int z = 0;
  int zwerg = zahl;
  do {
    if(zwerg > 1) {
      zwerg = zwerg / 2;
      z++;
    } else {
      printf("A bisserl zu klein die Zahl?\n");
    }
  } while(zwerg > 1);

  printf("%d ist %d mal durch 2 teilbar\n", zahl, z);
  return 0;
}
