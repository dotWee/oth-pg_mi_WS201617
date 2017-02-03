#include <stdio.h>
#include <string.h>

#define ERROR_PARAMETER 1

void tausche_char(char *char1, char *char2) {
    char temp = *char1;

    *char1 = *char2;
    *char2 = temp;
}

void permute(int start, int ende, char *string) {
    if (start == ende) {
        printf("%s\n", string);
    } else {
        for (int i = start; i <= ende; ++i) {

            tausche_char(s))
        }
    }
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Fehler bei den Parametern");
        return ERROR_PARAMETER;
    }

    char *string = argv[1];
    int laenge = strlen(string) - 1;

    permute(0, laenge, string);

    return 0;
}