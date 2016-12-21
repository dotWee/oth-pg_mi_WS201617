#include <stdio.h>

#define LEN 20

int main() {
    char buf[LEN+1];
    buf[LEN] = '\0';

    FILE *f = fopen("datei.txt", "r");
    int len = fread(buf, sizeof(char), LEN, f);
    printf("Eingelesen: %d Bytes\nInhalt: %s\n", len, buf);
    fclose(f);
    return 0;
}