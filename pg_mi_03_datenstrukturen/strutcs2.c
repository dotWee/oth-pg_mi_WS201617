#include <stdio.h>
#include <string.h>

typedef struct patient {
  unsigned int patient_id;
  char nachname[50];
  char vorname[50];
  char geburtsort[50];
} Patient;

int main(void) {
  Patient patienten[5];
  int patienten_len = sizeof(patienten)/sizeof(Patient);
  printf("Patienten-Array-Größe: %d\n", patienten_len);
  
  for(int i = 0; i < patienten_len; i++) {
    patienten[i].patient_id = i+1;
    
    // Achtung: scanf hat keine Längenprüfung!!!    
    printf("Nachname:");
    scanf("%s", patienten[i].nachname);
    printf("Vorname:");
    scanf("%s", patienten[i].vorname);
    printf("Geburtsort:");
    scanf("%s", patienten[i].geburtsort);  
  }

  // Sortieren nach Nachname
  Patient temp;
  for(int i = 0; i < patienten_len; i++) {
    for(int j = 1; j < patienten_len-i; j++) {
      if(strncmp(patienten[j-1].nachname, patienten[j].nachname, 50) > 0) {
        temp = patienten[j-1];
        patienten[j-1] = patienten[j];
        patienten[j] = temp;
      }
    }
  }

  for(int i = 0; i < patienten_len; i++) {
    printf("Patient-ID:\t%u\n", patienten[i].patient_id);
    printf("Nachname:\t%s\n", patienten[i].nachname);
    printf("Vorname:\t%s\n", patienten[i].vorname);
    printf("Geburtsort:\t%s\n", patienten[i].geburtsort);
  }

  return 0;
}
