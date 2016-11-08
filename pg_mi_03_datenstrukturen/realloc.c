#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int size_a = 100;
  int size_b = 500;

  char *buf = malloc(sizeof(char)*size_a);
  if(buf == NULL) {
    printf("Kein Speicher reservierbar\n");
    return 1;
  }

  buf[0] = 'A';
  buf[1] = 'B';
  buf[2] = '\0';

  char *tmp = buf;
  buf = realloc(buf, sizeof(char)*size_b);
  if(buf == NULL) {
    printf("Realloc konnte keinen weiteren Speicher reservieren\n");
    free(tmp);
    return 2;
  }

  printf("Realloc konnten Speicher reservieren\n");

  free(buf);
  return 0;
}
