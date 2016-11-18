#include <stdio.h>

int fakultaet(int n) {
  if(n > 1) {
    printf("%d * ", n);
    return n * fakultaet(n-1);
  } else if(n == 1) {
    return 1;
  } else {
    return 1;
  }
}

int main(void) {
  int n = 0;
  // Berechne n!
  printf("Zahl: ");
  scanf("%d", &n);

  printf("Ergebnis: %d", fakultaet(n));
  
  return 0;
}
