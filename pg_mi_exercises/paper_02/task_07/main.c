#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *xor(char *message, char *key) {
    int messagelen = strlen(message);
    int keylen = strlen(key);

    char *encrypted = malloc(messagelen + 1);

    // Für jeden Buchstaben
    int i;
    for (i = 0; i < messagelen; i++) {
        encrypted[i] = message[i] ^ key[i % keylen];
    }

    // Stringende definieren
    encrypted[messagelen] = '\0';

    return encrypted;
}

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Parameter fehlen!\n");
        return -1;
    }

    // Schlüssel
    char *key = argv[1];

    // Text zum verlüsseln
    char *text = argv[2];

    // Führe XOR Operation durch
    char *resultat = xor(text, key);

    // Gibt Resultat aus
    printf("%s\n", resultat);

    return 0;
}