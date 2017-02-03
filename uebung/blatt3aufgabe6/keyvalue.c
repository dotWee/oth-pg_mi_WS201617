#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ST_KEY 0
#define ST_VALUE 1

// Wir machen hier 7 statt 10 Zeilen!

typedef struct {
    char* key;
    char* value;
} KeyValue;

int main() {
    char *zeilen_static = "nummer=12\nname=Mustermann\nvorname=Max\nstrasse=Musterstr.\n"
    "hausnummer=13a\npostleitzahl=93053\nwohnort=Regensburg\n";
    char *zeilen = malloc(strlen(zeilen_static));
    strncpy(zeilen, zeilen_static, strlen(zeilen_static));

    int len = strlen(zeilen);
    KeyValue result[7];

    // Parser-Status
    int zeile = 0;
    int feld = 0;
    char *ptr = zeilen;

    for(int i = 0; i < len; i++) {
        if(zeilen[i] == '=' && feld == ST_KEY) {
            feld == ST_VALUE;
            zeilen[i] = '\0';
            result[zeile].key = ptr;

            if(i+1 < len) {
                ptr = (zeilen+i+1);
            }
        } else if(zeilen[i] == '\n') {
            if(feld != ST_VALUE) {
                printf("Fehler, kein Key gefunden!\n");
            }
            feld == ST_KEY;
            zeilen[i] = '\0';
            result[zeile++].value = ptr;

            if(i+1 < len) {
                ptr = (zeilen+i+1);
            }
        } 
    }

    for(int i = 0; i < 7; i++) {
        printf("%s -> %s\n", result[i].key, result[i].value);
    }

    return 0;
}