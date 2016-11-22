#include <stdio.h>

void print_leerzeichen(int menge) {
    for (int i = 0; i < menge; ++i) {
        printf(" ");
    }
}

void print_stern(int menge) {
    for (int i = 0; i < menge; ++i) {
        printf("*");
    }
}

void print_newline() {
    printf("\n");
}

void print_astreihe(int leerzeichen, int breite) {
    print_leerzeichen(leerzeichen);
    print_stern(breite);
    print_newline();
}

void print_stamm(int leerzeichen) {
    print_leerzeichen(leerzeichen);
    printf("|||\n");
}

void printLeerzeichen() {
    printf(" ");
}

int main(int argc, char *argv[]) {

    int eingabe = 0;
    printf("Anzahl der Äste: ");
    scanf("%d", &eingabe);

    int gesamteZeichen = 10 + eingabe;

    int anfangsStern = 1;
    int g = 0;

    for (int a = 0; a < eingabe; a++) {

        for (int b = 0; b < 3; b++) {
            int anzahlFreizeichen = gesamteZeichen - anfangsStern + g;
            print_astreihe(anzahlFreizeichen + b, anfangsStern);

            anfangsStern = anfangsStern + 2;
        }
        anfangsStern = anfangsStern - 4;
        g++;
    }

    print_stamm(gesamteZeichen - 2);

    return 0;
}