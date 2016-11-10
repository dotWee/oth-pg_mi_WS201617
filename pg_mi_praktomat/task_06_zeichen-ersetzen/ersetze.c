#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Korrekter Aufruf: %s A B \"String\"\n", argv[0]);
        return 0;
    }

    // Implementierung hier einfügen
    for (int i = 0; i < strlen(argv[3]); ++i) {
        if (*argv[1] == argv[3][i]) {
            argv[3][i] = *argv[2];
        }
    }

    printf("%s\n", argv[3]);
    return 0;
}