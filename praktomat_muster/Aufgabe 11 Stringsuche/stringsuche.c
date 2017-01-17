#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Achtung!!!: In der Praxis nie so machen!!!
// die Längen der Strings (Feldgröße) str und such müssen
// von außen mit an die Funktion übergeben und während
// der Ausführung geprüft werden, eine reine Prüfung auf \0
// ist immer dann unsicher, wenn die Char-Pointer von außen kommen!!!
char* suche (char *str, char *such, unsigned int n) {
    char* haystack = str;
    char* needle = such;
    unsigned match = 0;
    unsigned such_len = strlen(such);

    while(*haystack != '\0' && match < n) {
        while(*haystack != '\0' && *needle != '\0') {
            if(*haystack == *needle) {
                needle += 1;
                haystack += 1;
            } else {
                haystack = haystack - ((needle-such)-1);
                needle = such;
            }
        }
        if(*needle == '\0') {
            // Treffer
            match += 1;
            if(match == n) {
                return haystack-such_len;
            } else {
                haystack = haystack - ((needle-such)-1);
                needle = such;
            }
        } else {
            return NULL;
        }
    }
    return NULL;
}

/*
int main() {

    char *string = "dreierleieierei";
    char *such = "eie";

    printf("%s ist das 1. Ei in %s\n", suche(string, such, 1), string);
    printf("%s ist das 2. Ei in %s\n", suche(string, such, 2), string);
    printf("%s ist das 3. Ei in %s\n", suche(string, such, 3), string);

    return 0;
}
*/