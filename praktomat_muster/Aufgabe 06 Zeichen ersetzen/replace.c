#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Korrekter Aufruf: %s A B \"String\"\n", argv[0]);
        return 0;
    }

    char to_replace = argv[1][0];
    char replacement = argv[2][0];
    char *string = argv[3];
    char string_len = strlen(string);

    for(int i = 0; i < string_len; i++) {
        if(string[i] == to_replace) {
            string[i] = replacement;
        }        
    }

    printf("%s\n", string);
    return 0;
}

