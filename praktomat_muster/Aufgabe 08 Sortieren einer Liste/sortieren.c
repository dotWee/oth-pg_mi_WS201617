#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int len = argc-1;
    int zahlen[len];
    for(int i = 0; i < len; i++) {
        zahlen[i] = atoi(argv[i+1]);
    }

    // Bitte hier den Code zum Sortieren einfügen
    int h = 0;
    for(int j = len-1; j >= 0; j--) {
        for(int i = 0; i < j; i++) {
            if(zahlen[i] > zahlen[i+1]) {
                h = zahlen[i];
                zahlen[i] = zahlen[i+1];
                zahlen[i+1] = h;
            }
        }
    } 

    printf("Ausgabe:");
    for(int i = 0; i < len; i++) {
        printf(" %d", zahlen[i]);
    }
    printf("\n");
}
