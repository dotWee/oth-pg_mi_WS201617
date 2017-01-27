#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

int strcmp_own(char *string1, char *string2) {
    int errors = 0;

    // vergleiche die string länge
    int len1 = strlen(string1);
    int len2 = strlen(string2);

    if (len1 != len2) {
        errors++;
        return errors;
    }

    // vergleiche die einzelnen chars
    int count = 0;
    while (string1[count]) {
        count++;

        if (string1[count] != string2[count]) {
            errors++;
        }
    }

    return errors;
}

int main(int argc, char *argv[]) {

    char test1[] = "abc123";
    char buffer[BUFFER_SIZE];

    printf("Gib einen Text ein, der mit %s verglichen werden soll:\n", test1);

    // Vorsicht bei fgets, das setzt ein NEWLINE-Zeichen am Ende des Strings,
    // welches wir für Test-Zwecke entfernen müssen
    fgets(buffer, BUFFER_SIZE, stdin);

    if (buffer[strlen(buffer) - 1] == '\n') {
        buffer[strlen(buffer) - 1] = '\0';
    }

    printf("Sind %s und %s nach strcmp ähnlich: %s\n", test1, buffer, !strcmp(test1, buffer) ? "Ja" : "Nein");
    printf("Sind %s und %s nach eigener Implementation ähnlich: %s\n", test1, buffer,
           !strcmp_own(test1, buffer) ? "Ja" : "Nein");

    return 0;
}