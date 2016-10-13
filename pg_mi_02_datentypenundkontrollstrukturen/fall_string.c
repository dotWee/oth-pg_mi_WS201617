#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 4

int main(void) {
  char vorname[1000];
  char max[MAX_LENGTH] = "Max";

  printf("Vorname: ");
  scanf("%s", vorname);

  // Vergleich der Zeichenketten mit der Funktion strncmp aus string.h
  if(strncmp(vorname, max, MAX_LENGTH) == 0) {
    printf("Servus Max\n");
  } else {
    printf("Kenn i ned\n");
  }

  // die ersten drei Zeichen manuell vergleichen
  // Problem: Hier wird auch Max und Maxi als gleich identifiziert! 
  if(max[0] == vorname[0] && max[1] == vorname[1] && max[2] == vorname[2]) {
    printf("Max hab ich auch zu Fuß gefunden\n");
  }

  return 0;
}
