#include <stdio.h>
#include <string.h>

#include "charbuffer.h"

// CSV-Parser-Stati
#define CSV_KUNDE 0
#define CSV_REGION 1
#define CSV_BETRAG 2

#define BUF_SIZE 1024

void parse_line(char *line, int len) {
    CharBuffer *buf = charbuffer_create(100);
    int state = 0;
    char c = ' ';
    for(int i = 0; i < len; i++) {
        c = line[i];
        switch(state) {
            case CSV_KUNDE:
                if(c == ';') {
                    state = CSV_REGION;
                    charbuffer_append_char(buf, '\0');
                    printf("Kunde: %s\n", buf->array);
                    buf->laenge = 0;
                } else {
                    charbuffer_append_char(buf, c);
                }
                break;
            case CSV_REGION:
                if(c == ';') {
                    state = CSV_BETRAG;
                    charbuffer_append_char(buf, '\0');
                    printf("Region: %s\n", buf->array);
                    buf->laenge = 0;
                } else {
                    charbuffer_append_char(buf, c);
                }
                break;
            case CSV_BETRAG:
                if(c == '\n' || c == '\r') {
                    // Ignorieren
                    charbuffer_append_char(buf, '\0');
                    printf("Betrag: %s\n", buf->array);
                    buf->laenge = 0;
                } else {
                    charbuffer_append_char(buf, c);
                }
                break;
            default:
                printf("Parse-ERROR:");
                return;
        }
    }
    /*
    charbuffer_append_char(buf, '\0');
    printf("Betrag: %s\n", buf->array);
    buf->laenge = 0;
    */
    
    charbuffer_free(buf);
}

int main() {
    char *filename = "daten.csv";
    char buf[BUF_SIZE+1];
    FILE *f = NULL;

    f = fopen(filename, "r");
    while(fgets(buf, BUF_SIZE, f) != NULL) {
        printf("Zeile: %s\n", buf);
        // TODO: Rückgabewert von parse_line!
        parse_line(buf, strnlen(buf, BUF_SIZE));
    }

    fclose(f);
}