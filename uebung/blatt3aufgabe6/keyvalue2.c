#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ST_KEY 0
#define ST_VALUE 1
#define BUF_LEN 1024

// Wir machen hier 7 statt 10 Zeilen!

typedef struct {
    char* key;
    char* value;
} KeyValue;

int main() {
    KeyValue result;
    char buf[BUF_LEN];

    printf("Zeile eingeben:\n");
    fgets(buf, BUF_LEN, stdin);

    // Parser-Status
    int zeile = 0;
    int feld = ST_KEY;

    char *ptr = buf;
    int len = strnlen(buf, BUF_LEN);

    for(int i = 0; i < len; i++) {
        if(buf[i] == '=' && feld == ST_KEY) {
            feld == ST_VALUE;
            buf[i] = '\0';
            result.key = ptr;

            if(i+1 < len) {
                ptr = (buf+i+1);
            }
        } else if(buf[i] == '\n') {
            if(feld != ST_VALUE) {
                printf("Fehler, kein Key gefunden!\n");
            }
            feld == ST_KEY;
            buf[i] = '\0';
            result.value = ptr;

            if(i+1 < len) {
                ptr = (buf+i+1);
            }
        } 
    }

    printf("%s -> %s\n", result.key, result.value);

    return 0;
}