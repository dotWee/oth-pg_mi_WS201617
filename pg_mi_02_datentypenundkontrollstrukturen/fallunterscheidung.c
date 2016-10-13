#include <stdio.h>

#define ERROR_DIVISION_BY_ZERO 1
#define SUCCESS 0

/*
 * Beispiel zur Fallunterscheidung
 * @author ich
 * @date 12.10.2016
 */
int main(int argc, char *argv[]) {
  int v1, v2;

  printf("Es wurden %d Argumente aus der Kommandozeile übergeben\n", argc);

  printf("Wert 1: ");
  scanf("%d", &v1);

  printf("Wert 2: ");
  scanf("%d", &v2);

  // 1. Fall: Ist mindestens eine 0 am Ausdruck beteiligt
  if(v1 == 0 || v2 == 0) {
    printf("Null beteiligt\n");
    // 2. Fall: Division durch 0
    if(v2 == 0) {
      printf("Division durch 0 wird nicht unterstützt\n");
      return ERROR_DIVISION_BY_ZERO;
    }
    return SUCCESS;
  // 3. Fall: Vernünftig rechenbar...
  } else { 
    printf("%d / %d = %d", v1, v2, (v1/v2));
  }
  
  return SUCCESS;
}
