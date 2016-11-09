#include <stdio.h>

#define EMPTY 0
#define MAX 3

int main(void) {
  int xvalue = 0, yvalue = 0;
  _Bool is_spielzug_valid = 0;
  int spielfeld[MAX][MAX];
 
  // Felder des Spielfelds mit EMPTY vorbelegen
  for(int i = 0; i < MAX; i++) {
    for(int j = 0; j < MAX; j++) {
      spielfeld[i][j] = EMPTY;
    }
  }

  do {
    // Spielzug erfragen
    printf("X-Koordinate: ");
    scanf("%d", &xvalue);
    printf("Y-Koordinate: ");
    scanf("%d", &yvalue);
  } while(xvalue >= 0 && yvalue >= 0 && xvalue < MAX && yvalue < MAX);
  
  // Zum Testen:
  printf("(%d:%d)\n", xvalue, yvalue);

  return 0;
}
