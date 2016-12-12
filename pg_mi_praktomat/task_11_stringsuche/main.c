#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *suche(char *str, char *such, unsigned int n) {

    int vorkommen;

    char *insert, *buffer;

    insert = str;
    buffer = strstr(insert, such);
    for (vorkommen = 1; buffer; ++vorkommen) {
        if (n == vorkommen) {
            return buffer;
        }

        insert = buffer + strlen(such);
        buffer = strstr(insert, such);
    }

    return NULL;
}

int main(int argc, char *argv[]) {

    printf("%s\n", suche("dreierleieierei", "ei", 1)); // ergibt: eierleieierei
    printf("%s\n", suche("dreierleieierei", "ei", 3)); // ergibt: eierei
    printf("%s\n", suche("dreierleieierei", "ei", 4)); // ergibt: ei

    if (suche("barbara macht barbarei ", "asdf", 1) == NULL) {
        printf("nicht vorhanden!\n");
    } // sollte ausgegeben werden, da es nicht vorkommt
    if (suche("barbara macht barbarei ", "barba", 3) == NULL) {
        printf("nicht vorhanden!\n");
    } // sollte ausgegeben werden, da es nur 2-mal vorkommt

    return 0;
}
