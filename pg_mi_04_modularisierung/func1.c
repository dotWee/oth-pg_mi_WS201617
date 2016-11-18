#include <stdio.h>

int add(int x1, int x2) {
  return x1 + x2;
}

void tief(int tiefe) {
  int a = 0; int b = 0;

  if(tiefe % 100 == 0) {
    printf("Tief: %d\n", tiefe);
  }
  
  tief(tiefe+1);
}

int main(void) {
  int a = 0, b = 0;

  printf("Wert 1: ");
  scanf("%d", &a);
  printf("Wert 2: ");
  scanf("%d", &b);

  // Call by Value
  int erg = add(a, b);
  int erg2 = add(erg, b);

  printf("Ergebnis: %d\n", erg);  

  tief(0);

  return 0;
}
