#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Korrekter Aufruf: %s A B \"String\"\n", argv[0]);
        return 0;
    }

    int len = strlen(argv[3]), i = 0;
    char result[len];
    result[len] ='\0';

    for (  i = 0; i < len; i++){
        if (argv[3][i] == *argv[1]){
            argv[3][i] = *argv[2];
        }
        result[i] = argv[3][i];

    }

    printf("%s\n", result);
    return 0;
}
