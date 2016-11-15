#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 80

int main(int argc, const char *argv[]) {

    char *text = calloc(1, 1), buffer[BUFFERSIZE];

    while (fgets(buffer, BUFFERSIZE, stdin)) {
        text = realloc(text, strlen(text) + 1 + strlen(buffer));
        strcat(text, buffer);

        if (strstr(text, "ENDE")) {
            break;
        }
    }

    printf("Inhalt: \n%s\n", text);
    printf("Laenge: %d\n", strlen(text));

    return 0;
}