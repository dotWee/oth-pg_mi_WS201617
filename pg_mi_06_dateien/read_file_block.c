#include <stdio.h>

#define BLOCK_SIZE 20

int main() {
    int len = 0;
    char buf[BLOCK_SIZE+1];
    buf[BLOCK_SIZE] = '\0';

    FILE *f = fopen("datei.txt", "r");
    while((len = fread(buf, sizeof(char), BLOCK_SIZE, f)) > 0) {
        printf("Eingelesen: %d Bytes\nInhalt: %s\n\n", len, buf);
    }
    fclose(f);
    return 0;
}