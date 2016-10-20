#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int vorkommen = 0;
    int i = 0;
    int j = 0;

    // Für jeden Buchstaben im Alphabet
    for (j = 0; j < strlen(alphabet); ++j) {
        char buchstabeAusDemAlphabet = alphabet[j];

        // Für jeden Buchstaben im String
        for (i = 0; i < strlen(argv[1]); i++) {

            // Mach Buchstabe zu Großbuchstaben
            char buchstabeAusDemString = argv[1][i];
            buchstabeAusDemString = toupper(buchstabeAusDemString);

            // Wenn der Buchstabe aus dem String gleich mit einem aus dem Alphabet ist...
            if (buchstabeAusDemString == alphabet[j]) {
                vorkommen++;
            }
        }

        if (vorkommen != 0) {
            printf("%c:%d\n", buchstabeAusDemAlphabet, vorkommen);
            vorkommen = 0;
        }
    }

    return 0;
}