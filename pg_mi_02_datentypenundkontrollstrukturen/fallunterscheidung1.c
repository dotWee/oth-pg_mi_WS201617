#include <stdio.h>

#define ERROR_DIVISION_BY_INFINITY 2
#define ERROR_DIVISION_BY_ZERO 1
#define SUCCESS 0

int main(int argc, char *argv[]) {
  int v1, v2;

  printf("Es wurden %d Argumente aus der Kommandozeile übergeben\n", argc);

  printf("Wert 1: ");
  scanf("%d", &v1);

  printf("Wert 2: ");
  scanf("%d", &v2);

  if(v2 == 0) {
    printf("Division durch 0 wird nicht unterstützt\n");
    return ERROR_DIVISION_BY_ZERO;
  } else {
    printf("%d / %d = %d", v1, v2, (v1/v2));
  }
  
  return SUCCESS;
}
