#include <stdio.h>
#include <string.h>

typedef struct patient {
  unsigned int patient_id;
  char nachname[50];
  char vorname[50];
  char geburtsort[50];
} Patient;

int main(void) {
  Patient p;

  p.patient_id = 1;
  strncpy(p.nachname, "Mustermann", 50);
  strncpy(p.vorname, "Moritz", 50);
  strncpy(p.geburtsort, "Musterstedt", 50);

  printf("Patient-ID:\t%u\n", p.patient_id);
  printf("Nachname:\t%s\n", p.nachname);
  printf("Vorname:\t%s\n", p.vorname);
  printf("Geburtsort:\t%s\n", p.geburtsort);

  printf("Eingabe:\nNachname:");
  scanf("%s", p.nachname);

  printf("Patient-ID:\t%u\n", p.patient_id);
  printf("Nachname:\t%s\n", p.nachname);
  printf("Vorname:\t%s\n", p.vorname);
  printf("Geburtsort:\t%s\n", p.geburtsort);

  return 0;
}
