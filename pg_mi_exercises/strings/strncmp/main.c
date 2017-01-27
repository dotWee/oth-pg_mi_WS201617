#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

int strncmp_own(char *string1, char *string2, int n) {
    int errors = 0;

    int lowest_length;
    int length1 = strlen(string1);
    int length2 = strlen(string2);
    if (length1 <= length2) {
        lowest_length = length1;
    } else lowest_length = length2;


    // n darf nicht größer der länge sein
    if (n > lowest_length) {
        errors++;
        return errors;
    }

    // vergleiche die einzelnen chars
    for (int i = 0; i < n; ++i) {
        if (string1[i] != string2[i]) {
            errors++;
        }
    }

    return errors;
}

int main(int argc, char *argv[]) {

    char test1[] = "abc123";
    char buffer[BUFFER_SIZE];
    int nChars = 0;

    printf("Gib einen Text ein, der mit %s verglichen werden soll:\n", test1);

    // Vorsicht bei fgets, das setzt ein NEWLINE-Zeichen am Ende des Strings,
    // welches wir für Test-Zwecke entfernen müssen
    fgets(buffer, BUFFER_SIZE, stdin);

    if (buffer[strlen(buffer) - 1] == '\n') {
        buffer[strlen(buffer) - 1] = '\0';
    }

    printf("Gib die Anzahl der Chars ein, die verglichen werden sollen:\n");
    scanf("%d", &nChars);


    printf("Sind %s und %s nach strcmp ähnlich: %s\n", test1, buffer, !strncmp(test1, buffer, nChars) ? "Ja" : "Nein");
    printf("Sind %s und %s nach eigener Implementation ähnlich: %s\n", test1, buffer,
           !strncmp_own(test1, buffer, nChars) ? "Ja" : "Nein");

    return 0;
}