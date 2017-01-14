#include <stdio.h>
#include <string.h>

int anzahl_treffer(char* haystack, char* needle) {
    int counter = 0;
    for(int i = 0; i < strlen(haystack); i++) {
        if(strncmp(needle, haystack, strlen(needle)) == 0) {
            counter += 1;
        }
        haystack++;
    }
    return counter;
}

int main() {
    char *haystack = "abcblablablafest";
    char *needle = "blab";

    printf("%s kommt in %s %d mal vor\n", 
        needle, haystack, 
        anzahl_treffer(haystack, needle));

    return 0;
}