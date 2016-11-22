#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @param original Char das verschlüsselt werden soll
 * @param amount Anzahl der Stufen die in der ASCII-Tabelle
 * nach oben gesprungen werden sollen
 * @return Verschlüsseltes Char
 */
char encrypt(char original, int amount) {

    // ACSII Integer Wert des originalen Buchstaben
    int asciiValue = original;

    // "Verschlüssle" Char durch springen von Stufen in der ASCII-Tabelle
    asciiValue = asciiValue + amount;

    // Return neues Char
    return (char) asciiValue;
}

/**
 * @param original Char das entschlüsselt werden soll
 * @param amount Anzahl der Stufen die in der ASCII-Tabelle
 * nach unten gesprungen werden sollen
 * @return Entschlüsseltes Char
 */
char decrypt(char original, int amount) {

    // ACSII Integer Wert des originalen Buchstaben
    int asciiValue = original;

    // "Verschlüssle" Char durch springen von Stufen in der ASCII-Tabelle
    asciiValue = asciiValue - amount;

    // Return neues Char
    return (char) asciiValue;
}

void print_char(char character) {
    printf("%c", character);
}

int main(int argc, const char *argv[]) {

    // Prüfe ob genug Parameter vorhanden sind
    if (argc > 3 || argc < 3) {
        printf("Fehler bei der Anzahl der Parameter!\n");
        return 1;
    }

    // Anzahl der Stufen die in der ASCII-Tabelle gesprungen werden sollen
    int amount = atoi(argv[1]);

    // Für jeden Buchstaben aus dem 2. String-Parameter
    for (int i = 0; i < strlen(argv[2]); ++i) {
        char originalChar = argv[2][i];

        char returnChar = encrypt(originalChar, amount);
        // char returnChar = decrypt(originalChar, amount);

        print_char(returnChar);
    }

    return 0;
}