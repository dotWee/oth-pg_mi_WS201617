#include <stdio.h>
#include <string.h>

int anzahl_treffer(char* haystack, char* needle) {
    int counter = 0;
    int len = strlen(haystack);
    for(int i = 0; i < len; i++) {
        if(strncmp(needle, haystack, strlen(needle)-1) == 0) {
            counter += 1;
        }
        haystack++;
    }
    return counter;
}

int main() {
    /*
    char *haystack = "abcblablablafest";
    char *needle = "blab";
    */

    char *haystack = "Der Nette mit der Kette";
    char *needle = "ette";

    printf("%s kommt in %s %d mal vor\n", 
        needle, haystack, 
        anzahl_treffer(haystack, needle));

    return 0;
}