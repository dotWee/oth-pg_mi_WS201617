#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("Aufruf: %s [TIEFE]\n", argv[0]);
    return 1;
  }

  int tiefe = atoi(argv[1]);

  for(int i = 0; i < tiefe; i++) {
    printf("        *        \n");
    printf("       ***       \n");
    printf("     *******     \n"); 
  }

  printf("       |||\n");

  return 0;
}
