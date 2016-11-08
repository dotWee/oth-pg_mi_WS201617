#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char vorlage[7] = "abcdef";
  char *ptr = NULL;
  
  if(argc != 2) {
    printf("Aufruf: %s 123\n", argv[0]);
    return 1;
  }

  int len = atoi(argv[1]);

  for(int i = 0; i < 4; i++) {
    ptr = (char*)malloc(sizeof(char) * len);

    printf("vorlage: %p\n", vorlage);
    printf("ptr    : %p\n", ptr);

    for(int j = 0; j < len-1; j++) {
      ptr[j] = vorlage[j%6];
    }
    ptr[len-1] = '\0';

    printf("Inhalt %s\n", ptr);

    free(ptr);
  }

//  free(ptr);
  return 0;
}
