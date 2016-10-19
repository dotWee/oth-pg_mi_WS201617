#include <stdio.h>

int main(int argc, char *argv[]) {
  static const int feld1_len = 10;
  int feld1[10] = {5, 4, 3, 2, 1, 9, 8, 7, 6, 0};
  int summe = 0;

  int i = 0;
  while(i < feld1_len) {
    printf("+ %d\n", feld1[i]);
    summe += feld1[i];

    i++;
  }

  printf("--------\nSum: %d\n", summe);
  return 0;
}
