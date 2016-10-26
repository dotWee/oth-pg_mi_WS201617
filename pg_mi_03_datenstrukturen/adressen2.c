#include <stdio.h>

int global = 33;

void main(void) {
  int a = 1;
  int b = 2;
  int c = 3;

  printf("Adresse: %p, Wert: %d\n", &a, a);
  printf("Adresse: %p, Wert: %d\n", &b, b);
  printf("Adresse: %p, Wert: %d\n", &c, c);

  int *ptr = &a;

  printf("Adresse(ptr): %p, Wert(ptr) %p, Wert(*ptr) %d\n", &ptr, ptr, *ptr);
  ptr += 1;
  printf("Adresse(ptr): %p, Wert(ptr) %p, Wert(*ptr) %d\n", &ptr, ptr, *ptr);

  *ptr = 55;

  printf("Variable b = %d\n", b);

  printf("Adresse-Global: %p, Wert %d\n", &global, global);

  char *ptr2 = (char*)&global;

  for(int i = 3000; i > 0; i--) {
    printf("%c", *(ptr2-i));
  }
  printf("---\n");
}
