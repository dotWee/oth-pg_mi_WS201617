#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main(int argc, char *argv[]) {

    // Ziel für s1
    int s1;
    char *buffer = malloc(sizeof(char) * MAX_LENGTH);
    printf("Zahl 1: ");
    fgets(buffer, MAX_LENGTH, stdin);
    s1 = atoi(buffer);
    free(buffer);

    // Ziel für s2
    int s2;
    char *buffer2 = malloc(sizeof(char) * MAX_LENGTH);
    printf("Zahl 2: ");
    fgets(buffer2, MAX_LENGTH, stdin);
    s2 = atoi(buffer2);
    free(buffer2);

    // Berechnen
    int erg = s1 + s2;

    // Ausgabe Wert
    printf("Wert Zahl 1: %d\n", s1);
    printf("Wert Zahl 2: %d\n", s2);

    // Ausgabe Adresse
    printf("Adressen:\n");
    printf("s1: %p\n", &s1);
    printf("s2: %p\n", &s2);
    printf("erg: %p\n", &erg);

    return 0;
}