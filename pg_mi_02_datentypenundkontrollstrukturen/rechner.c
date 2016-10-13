#include <stdio.h>

int main(void) {
  int value1 = 0;
  int value2 = 0;
  int erg = 0;

  printf("Wert 1 : ");
  scanf("%d", &value1);

  printf("Wert 2 : ");
  scanf("%d", &value2);

  erg = value1 + value2;
  printf("%d + %d = %d\n", value1, value2, erg);

  erg = value1 - value2;
  printf("%d - %d = %d\n", value1, value2, erg);

  erg = value1 / value2;
  printf("%d / %d = %d\n", value1, value2, erg);

  return 0;
}
