#include <stdio.h>

int cube(int *n) {
  return (*n) * (*n) * (*n);
}

int main() {
  int number;

  scanf("%d", &number);

  printf("%d^3 = %d\n", number, cube(&number));

  return 0;
}
