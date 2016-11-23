#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int buf_size = 100;
  int buf_length = 0;

  char *buf = malloc(sizeof(char)*buf_size);
  if(buf == NULL) {
    printf("Kein Speicher reservierbar\n");
    return 1;
  }

  while(1==1) {
    buf = fgets(buf, 100, stdin); 

// Vorgemerkt
    buf_size += 100;
    char *tmp = buf;
    buf = realloc(buf, sizeof(char)*buf_size);
    if(buf == NULL) {
      printf("Realloc konnte keinen weiteren Speicher reservieren\n");
      free(tmp);
      return 2;
    }

    printf("Realloc konnten Speicher reservieren\n");
  }

  free(buf);
  return 0;
}
