#include <stdio.h>

void call_by_value(int a) {
  a = a + 5;
  printf("In-Funktion-By-Value: %d\n", a);
}

void call_by_reference(int *a) {
  *a = *a + 5;
  printf("In-Funktion-By-Ref  : %d\n", *a);
}

int main(void) {
  int a = 0;

  printf("Wert 1: ");
  scanf("%d", &a);

  printf("Ausgangswert Main: %d\n", a);

  call_by_value(a);

  printf("Zwischenwert Main: %d\n", a);

  call_by_reference(&a);

  printf("Endwert      Main: %d\n", a);
  return 0;
}
