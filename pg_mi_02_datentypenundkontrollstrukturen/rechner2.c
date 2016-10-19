#include <stdio.h>

#define EXIT_CODE 1

int main(void) {
  int response = 0;
  int z1 = 0, z2 = 0;
  char op[10] = "";
  do {
    printf("Zahl 1: ");
    scanf("%d", &z1);
    printf("Operator: ");
    scanf("%s", op);
    printf("Zahl 2: ");
    scanf("%d", &z2);

    switch(op[0]) {
      case '+':
        printf("%d + %d = %d\n", z1, z2, z1+z2);
        break;
      case '-':
        printf("%d - %d = %d\n", z1, z2, z1-z2);
        break;
      case '*':
        printf("%d * %d = %d\n", z1, z2, z1*z2);
        break;
      default:
        printf("Ungültiger Operator");
        break;
    }   

    printf("Zum Beenden bitte die 1 eingeben: ");
    scanf("%d", &response);
  } while(response != EXIT_CODE);
  return 0;
}
