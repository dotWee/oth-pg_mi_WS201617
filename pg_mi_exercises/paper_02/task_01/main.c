
#include <stdio.h>

void printLeerzeichen();

int main(int argc, char *argv[]) {

    int eingabe = 0;


    printf("Anzahl der Äste: ");
    scanf("%d", &eingabe);

    int gesamteZeichen = 10 + eingabe;

    int anfangsStern = 1;
    int a, b, c, d, g = 0, z;

    for (a = 0; a < eingabe; a++) {

        for (b = 0; b < 3; b++) {
            int anzahlFreizeichen = gesamteZeichen - anfangsStern + g;

            for (c = 0; c < anzahlFreizeichen; c++) {
                printLeerzeichen();
            }

            if (b == 1) {
                printLeerzeichen();
            }
            if (b == 2) {
                printLeerzeichen();
                printLeerzeichen();
            }

            for (d = 0; d < anfangsStern; d++) {
                printf("*");
            }


            printf("\n");
            anfangsStern = anfangsStern + 2;
        }
        anfangsStern = anfangsStern - 4;
        g++;
    }

    for (z = 0; z < gesamteZeichen - 2; z++) {
        printLeerzeichen();
    }

    printf("|||\n");
    return 0;
}

void printLeerzeichen() {
    printf(" ");
}