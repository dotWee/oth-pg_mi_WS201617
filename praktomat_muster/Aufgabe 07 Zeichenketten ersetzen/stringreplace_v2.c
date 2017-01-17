#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *result = NULL;
    if(argc != 4) {
        printf("Korrekter Aufruf: %s \"string to replace\" \"stringToLookFor\" \"String\"\n", argv[0]);
        return 0;
    }

    // Implementierung hier einfügen
    char *original = argv[3], *stringToLookFor = argv[1], *stringReplacement = argv[2];

    char *insert, *tmp;
    int lengthStringCurrentPosition, replacementsAmount;

    int lengthStringToLookFor = (int) strlen(stringToLookFor);
    int lengthStringReplacement = (int) strlen(stringReplacement);

    insert = original;
    tmp = strstr(insert, stringToLookFor);
    for (replacementsAmount = 0; tmp; ++replacementsAmount) {
        insert = tmp + lengthStringToLookFor;
        tmp = strstr(insert, stringToLookFor);
    }

    tmp = result = malloc(strlen(original)
                          + (lengthStringReplacement - lengthStringToLookFor)
                            * replacementsAmount + 1);

    while (replacementsAmount--) {
        insert = strstr(original, stringToLookFor);
        lengthStringCurrentPosition = (int) (insert - original);

        tmp = strncpy(tmp, original, lengthStringCurrentPosition) + lengthStringCurrentPosition;
        tmp = strcpy(tmp, stringReplacement) + lengthStringReplacement;

        original += lengthStringCurrentPosition + lengthStringToLookFor;
    }
    strcpy(tmp, original);

    if(result != NULL) {
        printf("%s\n", result);
    }

    free(result);
    return 0;
}