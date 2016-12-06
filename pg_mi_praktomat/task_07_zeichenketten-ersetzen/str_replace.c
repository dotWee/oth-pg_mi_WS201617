#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_replace(char *original, char *stringToLookFor, char *stringReplacement) {

    // Unser fertige String der zurück gegeben wird
    char *result;

    // Stelle, an der der Ersatz-String eingefügt werden muss
    char *insert;

    // Wird als Buffer genutzt
    char *buffer;

    // Länge des zu ersetzenden Strings
    int lengthStringToLookFor = strlen(stringToLookFor);

    // Länge des Ersatz-Strings
    int lengthStringReplacement = strlen(stringReplacement);

    // Distanz zwischen den zu ersetzenden Strings (siehe lengthStringToLookFor)
    int lengthReplacementDistance;

    // Anzahl der ersetzen-Vorgänge
    int count;

    // Zähle wie oft ein Substring ersetzt werden muss
    insert = original;
    buffer = strstr(insert, stringToLookFor);
    for (count = 0; buffer; ++count) {
        insert = buffer + lengthStringToLookFor;
        buffer = strstr(insert, stringToLookFor);
    }

    // Berechne die entgültige Länge des Strings welcher zurückgegeben werden soll und reserviere einen Speicher
    buffer = result = malloc(strlen(original) + (lengthStringReplacement - lengthStringToLookFor) * count + 1);

    // Führe Aktion durch, bis alle Substrings ersetzt wurden
    while (count--) {
        // Log aktuellen Vorgang
        //printf("-----Start-----\n");
        //printf("original=%s\n", original);

        // Ins zeigt auf das nächste Vorkommen des Replacement Strings im Original
        insert = strstr(original, stringToLookFor);
        lengthReplacementDistance = insert - original;

        // Buffer zeigt auf das Ende des result Strings
        buffer = strncpy(buffer, original, lengthReplacementDistance) + lengthReplacementDistance;

        // Führe eigentlichen Ersetzungsvorgang durch
        buffer = strcpy(buffer, stringReplacement) + lengthStringReplacement;
        //printf("ersetze=%s mit=%s\n", stringToLookFor, stringReplacement);

        // Original zeigt auf den Rest des Original Strings
        original += lengthReplacementDistance + lengthStringToLookFor;

        //printf("original=%s\n", original);
        //printf("-----Ende-----\n\n");
    }

    printf("-----Return-----\n");
    printf("result=%s\n", result);
    strcpy(buffer, original);
    return result;
}

int main(int argc, char *argv[]) {
    char *result = NULL;
    if (argc != 4) {
        printf("Korrekter Aufruf: %s \"string to replace\" \"stringToLookFor\" \"String\"\n", argv[0]);
        return 0;
    }

    // Implementierung hier einfügen

    // Der originale String
    char *original = argv[3];
    char *stringToLookFor = argv[1];
    char *stringReplacement = argv[2];

    result = string_replace(original, stringToLookFor, stringReplacement);

    if (result != NULL) {
        printf("%s\n", result);
    }

    free(result);
    return 0;
}