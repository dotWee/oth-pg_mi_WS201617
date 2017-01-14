#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "charbuffer.h"

#define ST_HEADER 0
#define ST_NUMMER 1
#define ST_VORNAME 2
#define ST_NACHNAME 3

typedef struct _kunde {
    int nummer;
    char* vorname;
    char nachname[20];
} Kunde;

// Aufgabe: Einlesen der Datei und Umwandeln in eine
//          Liste von Kunden (struct _kunde)
List* parse(char *filename) {
    static const int BUF_SIZE = 1024;
    char buf[BUF_SIZE+1];
    int len = 0;
    char c = ' ';
    int state = ST_HEADER;
    Kunde *current = malloc(sizeof(Kunde));
    CharBuffer* cbuf = charbuffer_create(256);
    List* lst = list_new();
    FILE *f = fopen(filename, "r");

    while((len = fread(buf, sizeof(char), BUF_SIZE, f)) > 0) {
        for(int i = 0; i < len; i++) {
            c = buf[i];
            switch(state) {
                case ST_HEADER:
                    if(c == '\n') {
                        state = ST_NUMMER;
                    } 
                    break;
                case ST_NUMMER:
                    if(c == ';') {
                        // Ende des Felds Nummer erreicht
                        charbuffer_append_char(cbuf, '\0');
                        current->nummer = atoi(cbuf->array);
                        cbuf->laenge = 0;
                        state = ST_VORNAME;

                        printf("Nummer: %d\n", current->nummer);
                    } else if(c >= '0' && c <= '9') {
                        // c ist eine Ziffer
                        charbuffer_append_char(cbuf, c);
                    } else {
                        // Unerwartetes falsches Zeichen
                        printf("Formatfehler: Falsches Zeichen %c\n", c);
                    }
                    break;
                case ST_VORNAME:
                    if(c == ';') {
                        // Ende des Felds Nummer erreicht
                        charbuffer_append_char(cbuf, '\0');
                        current->vorname = calloc(1, cbuf->laenge);
                        strncpy(current->vorname, cbuf->array, cbuf->laenge);
                        cbuf->laenge = 0;
                        state = ST_NACHNAME;

                        printf("Vorname: %s\n", current->vorname);
                    } else {
                        // c ist eine Ziffer
                        charbuffer_append_char(cbuf, c);
                    } 
                    break;
                case ST_NACHNAME:
                    if(c == '\n') {
                        // Ende des Felds Nummer erreicht
                        charbuffer_append_char(cbuf, '\0');
                        strncpy(current->nachname, cbuf->array, 19);
                        cbuf->laenge = 0;
                        state = ST_NUMMER;
                        list_append(lst, current);
                        printf("Nachname: %s\n\n", current->nachname);
                        current = malloc(sizeof(Kunde));
                    } else if(cbuf->laenge < 19) {
                        // c ist eine Ziffer
                        charbuffer_append_char(cbuf, c);
                    } else {
                        printf("Formatfehler: Der Nachname ist zu lang\n");
                    }
                    break;
                default:
                    printf("ERROR: invalid state\n");
                    return NULL;
            }
        }
    }

    if(state == ST_NACHNAME) {
        charbuffer_append_char(cbuf, '\0');
        strncpy(current->nachname, cbuf->array, 19);
        cbuf->laenge = 0;

        list_append(lst, current);
        printf("Nachname: %s\n\n", current->nachname);
        current = malloc(sizeof(Kunde));
    }

    fclose(f);
    return lst;
}

int main() {    

    List* lst = parse("daten.csv");

    if(list_iterate_start(lst) == LIST_SUCCESS) {
        Kunde *k = NULL;
        while((k = list_iterate_get_next(lst)) != NULL) {
            printf("%d - %s - %s\n", k->nummer, k->vorname, k->nachname);
        }
    }

    // Achtung Leck: Kunde.vorname wird nicht freigegeben
    list_free(lst, free);

    return 0;
}