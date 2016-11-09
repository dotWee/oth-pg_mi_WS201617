#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHOICE_ENCRYPT 0
#define CHOICE_DECRYPT 1

int main(int argc, const char *argv[]) {

    int CHOICE = 0;

    if (argc > 3 || argc < 3) {
        printf("Parameter fehlen!\n");
        return -1;
    }

    printf("Bitte wähle eine Aktion:\n");
    printf("[0] Text verschlüsseln\n");
    printf("[1] Text entschlüsseln\n");
    scanf("%d", &CHOICE);

    if (CHOICE != CHOICE_ENCRYPT && CHOICE != CHOICE_DECRYPT) {
        printf("Aktion existiert nicht!\n");
        return -2;
    }

    // Anzahl der Stufen die in der ASCII-Tabelle gesprungen werden sollen
    int amount = atoi(argv[1]);

    // Für jeden Buchstaben aus dem 2. String-Parameter
    for (int i = 0; i < strlen(argv[2]); ++i) {
        char originalChar = argv[2][i];

        int asciiValue = originalChar;

        // "Verschlüssle" Char
        if (CHOICE == CHOICE_ENCRYPT) {
            asciiValue = asciiValue + amount;
        }

        if (CHOICE == CHOICE_DECRYPT) {
            asciiValue = asciiValue - amount;
        }

        char encryptedChar = asciiValue;

        printf("%c", encryptedChar);
    }

    return 0;
}