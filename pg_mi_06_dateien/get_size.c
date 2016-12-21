#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

#define LEN 20

int main() {
    struct stat s;
    if(stat("datei.txt", &s) == 0) {
        printf("Die Datei hat %ld Bytes\n", s.st_size);
    } else {
        printf("Datei nicht gefunden\n");
    }
    return 0;
}