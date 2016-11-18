#include <stdio.h>

#define EMPTY 0
#define SPIELER1 1
#define SPIELER2 2
#define MAX 3

_Bool spielfeld_check_senkr(int spielfeld[MAX][MAX], int spieler);
_Bool spielfeld_check_wagr(int spielfeld[MAX][MAX], int spieler);
_Bool spielfeld_check_diag(int spielfeld[MAX][MAX], int spieler);

void spielfeld_init(int spielfeld[MAX][MAX], int max) {
  // Felder des Spielfelds mit EMPTY vorbelegen
  for(int i = 0; i < max; i++) {
    for(int j = 0; j < max; j++) {
      spielfeld[i][j] = EMPTY;
    }
  }
}

void spielzug_erfragen(int spielfeld[MAX][MAX], int* xvalue, int* yvalue) {
  _Bool is_zug_invalid = 0;
  do {
      // Spielzug erfragen
      printf("X-Koordinate: ");
      scanf("%d", xvalue);
      printf("Y-Koordinate: ");
      scanf("%d", yvalue);

      is_zug_invalid = (*xvalue < 0 || *xvalue >= MAX)
         || (*yvalue < 0 || *yvalue >= MAX);

      if(!is_zug_invalid) {
        is_zug_invalid = (spielfeld[*xvalue][*yvalue] != EMPTY);
      }

      if(is_zug_invalid) {
        printf("Ihr Zug war ungültig, bitte versuchen Sie es erneut\n");
      }
    } while(is_zug_invalid);
}

void spielfeld_print(int spielfeld[MAX][MAX]) {
  // Spielfeld ausgeben
  for(int i = 0; i < MAX; i++) {
    for(int j = 0; j < MAX; j++) {
      printf("%d ", spielfeld[j][i]);
    }
    printf("\n");
  }
}

_Bool spielfeld_is_solved(int spielfeld[MAX][MAX], int spieler) {
  // Senkrechte prüfen
  if(spielfeld_check_senkr(spielfeld, spieler)) {
    return 1;
  }
  // Wagrechte prüfen
  if(spielfeld_check_wagr(spielfeld, spieler)) {
    return 1;
  }
  // Diagonalen prüfen
  if(spielfeld_check_diag(spielfeld, spieler)) {
    return 1;
  }
  return 0;
}

_Bool spielfeld_check_senkr(int spielfeld[MAX][MAX], int spieler) { 
  // Senkrechte prüfen
  for(int i = 0; i < MAX; i++) {
    if(spielfeld[i][0] != 0
       && spielfeld[i][0] == spielfeld[i][1]
       && spielfeld[i][0] == spielfeld[i][2]) {
      printf("Spieler %d hat gewonnen\n", spieler);
      return 1;
    }
  }
  return 0;
}

_Bool spielfeld_check_wagr(int spielfeld[MAX][MAX], int spieler) {
  // Wagrechte prüfen
  for(int i = 0; i < MAX; i++) {
    if(spielfeld[0][i] != 0
       && spielfeld[0][i] == spielfeld[1][i]
       && spielfeld[0][i] == spielfeld[2][i]) {
      printf("Spieler %d hat gewonnen\n", spieler);
      return 1;
    }
  }
  return 0;
}

_Bool spielfeld_check_diag(int spielfeld[MAX][MAX], int spieler) {
  if(spielfeld[0][0] != 0
     && spielfeld[0][0] == spielfeld[1][1]
     && spielfeld[0][0] == spielfeld[2][2]) {
    printf("Spieler %d hat gewonnen\n", spieler);
    return 1;
  }

  if(spielfeld[0][2] != 0
     && spielfeld[0][2] == spielfeld[1][1]
     && spielfeld[0][2] == spielfeld[2][0]) {
    printf("Spieler %d hat gewonnen\n", spieler);
    return 1;
  }

  return 0;
}

// Spiel
int main(void) {
  int spieler = SPIELER1;
  int xvalue = 0, yvalue = 0;
  int spielfeld[MAX][MAX];
 
  // Felder des Spielfelds mit EMPTY vorbelegen
  spielfeld_init(spielfeld, MAX);

  _Bool is_zug_invalid = 0;
  for(int z = 0; z < 9; z++) {
    printf("Spieler: %d\n", spieler);
    spielzug_erfragen(spielfeld, &xvalue, &yvalue);
  
    // Spielzug ins Spielfeld schreiben
    spielfeld[xvalue][yvalue] = spieler;

    spielfeld_print(spielfeld);

    if(spielfeld_is_solved(spielfeld, spieler)) {
      return 0;
    }
    if(spieler == SPIELER1) {
      spieler = SPIELER2;
    } else {
      spieler = SPIELER1;
    }
  }

  return 0;
}
