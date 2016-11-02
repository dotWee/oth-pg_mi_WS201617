#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char zahl1[40] = "1";
  char zahl2[40] = "-1";

  if(strncmp(zahl1, zahl2, 39) > 0) {
    printf("%s > %s\n", zahl1, zahl2);
  } else if(strncmp(zahl1, zahl2, 39) == 0) {
    printf("%s == %s\n", zahl1, zahl2);
  } else {
    printf("%s < %s\n", zahl1, zahl2);
  }

  return 0;
}
