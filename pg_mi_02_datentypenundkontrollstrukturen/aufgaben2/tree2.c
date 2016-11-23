#include <stdio.h>
#include <stdlib.h>

#define ARR_MAX 80

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("Aufruf: %s [TIEFE]\n", argv[0]);
    return 1;
  }

  char blanks[ARR_MAX];
  char stars[ARR_MAX];

  int tiefe = atoi(argv[1]);
  if(tiefe > 10) {
    printf("%d überschreitet die maximale Tiefe von 10\n", tiefe);
    return 2;
  }

  for(int i = 0; i < tiefe; i++) {
    for(int z = 0; z < 3; z++) {
      for(int j = 0; j < 30-(i+z); j++) {
        blanks[j] = ' ';
        blanks[j+1] = '\0';
      }
      for(int j = 0; j < 1+(2*(i+z)); j++) {
        stars[j] = '*';
        stars[j+1] = '\0';
      }
      printf("%s%s\n", blanks, stars);
    }
  }

  printf("                             |||\n");

  return 0;
}
