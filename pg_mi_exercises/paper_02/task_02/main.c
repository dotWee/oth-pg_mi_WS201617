#include <stdio.h>
#include <string.h>

/**
 * Diese Funktion tauscht den Wert von zwei Charactern
 * untereinander.
 *
 * @param char1 Char das an char2 kopiert werden soll
 * @param char2 Char das an char1 kopiert werden soll
 */
void swap(char *char1, char *char2) {
    char temp = *char1;

    *char1 = *char2;
    *char2 = temp;
}

/**
 *
 * @param string
 * @param start
 * @param ende
 */
void permute(char *string, int start, int ende) {
    if (start == ende) {
        printf("%s\n", string);
    } else {
        for (int i = start; i <= ende; i++) {
            //printf("PERMUTE / vorher=%s\n", string);

            swap((string + start), (string + i));
            permute(string, start + 1, ende);
            swap((string + start), (string + i));

            //printf("PERMUTE / nachher=%s\n", string);
        }
    }
}

int main(int argc, char *argv[]) {

    char *stringToPermute = argv[1];
    int start = 0;
    int ende = strlen(stringToPermute) - 1;

    //printf("MAIN / string=%s start=%d ende=%d\n", stringToPermute, start, ende);
    permute(stringToPermute, start, ende);

    return 0;
}
