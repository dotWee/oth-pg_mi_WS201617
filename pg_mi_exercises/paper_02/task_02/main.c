#include <stdio.h>
#include <string.h>

void permute(char *string, int start, int ende);

void swap(char *char1, char *char2);

int main(int argc, char *argv[]) {
    permute(argv[1], 0, strlen(argv[1]) - 1);

    return 0;
}

void permute(char *string, int start, int ende) {
    if (start == ende) {
        printf("%s\n", string);
    } else {
        for (int i = start; i <= ende; i++) {
            swap((string + start), (string + i));
            permute(string, start + 1, ende);
            swap((string + start), (string + i));
        }
    }
}

void swap(char *char1, char *char2) {
    char temp = *char1;

    *char1 = *char2;
    *char2 = temp;
}
