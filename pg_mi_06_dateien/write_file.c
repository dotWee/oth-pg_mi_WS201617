#include <stdio.h>

int main() {
    char *buf = "Hallo Datei\n";
    int LEN = 12;

    FILE *f = fopen("datei.txt", "r");
    fwrite(buf, sizeof(char), LEN, f);
    fclose(f);
    return 0;
}