#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int len = argc - 1;
    int zahlen[len];
    for (int i = 0; i < len; i++) {
        zahlen[i] = atoi(argv[i + 1]);
    }

    // Bitte hier den Code zum Sortieren einfügen
    for (int i = 0; i < len; i++) {

        for (int j = 0; j < len - 1; j++) {

            if (zahlen[j] > zahlen[j + 1]) {

                int temp = zahlen[j];
                zahlen[j] = zahlen[j + 1];
                zahlen[j + 1] = temp;
            }
        }
    }

    printf("Ausgabe:");
    for (int i = 0; i < len; i++) {
        printf(" %d", zahlen[i]);
    }
    printf("\n");
}
