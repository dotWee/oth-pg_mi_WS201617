#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "charbuffer.h"

#define ST_HEAD 0
#define ST_NUMMER 1
#define ST_VORNAME 2
#define ST_NACHNAME 3

typedef struct _customer {
    int number;
    char* prename;
    char* surname;
} Customer;

List* parse(char* filename) {
    int len = 0;
    int line = 1, column = 0;
    // TODO: zum Testen kleiner machen, so dass mehrere Blöcke gelesen werden müssen
    static const int BUFSIZE = 1024;
    char buf[BUFSIZE+1];
    int state = ST_HEAD;
    char c = ' ';
    CharBuffer *cbuf = charbuffer_create(BUFSIZ);
    Customer *current = malloc(sizeof(Customer));
    List *lst = list_new();


    FILE *f = fopen(filename, "r");
    if(f == NULL)
        return NULL;

    while((len = fread(buf, sizeof(char), BUFSIZE, f)) > 0) {
        for(int i = 0; i < len; i++) {
            column += 1;
            c = buf[i];
            switch(state) {
                case ST_HEAD:
                    if(c == '\n') {                        
                        state = ST_NUMMER;
                        column = 0;
                        line += 1;
                    } 
                    break;
                case ST_NUMMER:
                    if(c >= '0' && c <= '9') {
                        // Ziffer => OK
                        charbuffer_append_char(cbuf, c);
                    } else if(c == ';') {
                        // Trennzeichen => OK
                        charbuffer_append_char(cbuf, '\0');
                        printf("Nummer: %s\n", cbuf->array);
                        current->number = atoi(cbuf->array);
                        cbuf->laenge = 0;
                        state = ST_VORNAME;
                    } else {
                        // Ungültiges Zeichen ...
                        printf("ERROR: ST_NUMMER: Zeile %d, Spalte %d: Ungültiges Zeichen %c\n", line, column, c);
                    }
                    break;
                case ST_VORNAME:
                    if(c == ';') {
                        // Trennzeichen => OK
                        charbuffer_append_char(cbuf, '\0');
                        printf("Vorname: %s\n", cbuf->array);
                        current->prename = malloc(cbuf->laenge);
                        strncpy(current->prename, cbuf->array, cbuf->laenge-1);
                        cbuf->laenge = 0;
                        state = ST_NACHNAME;
                    } else {
                        charbuffer_append_char(cbuf, c);
                    }
                    break;
                case ST_NACHNAME:
                    if(c == '\n' || c == '\r') {
                        // Trennzeichen => OK
                        charbuffer_append_char(cbuf, '\0');
                        printf("Nachname: %s\n", cbuf->array);
                        current->surname = malloc(cbuf->laenge);
                        strncpy(current->surname, cbuf->array, cbuf->laenge-1);
                        list_append(lst, current);
                        current = malloc(sizeof(Customer));
                        cbuf->laenge = 0;                        
                        state = ST_NUMMER;
                        // Zeilenzahl richtig mitführen
                        column = 0;
                        line += 1;
                    } else {
                        charbuffer_append_char(cbuf, c);
                    }
                    break;
                default:
                    // TODO Free list and its items                    
                    list_free(lst, free);
                    free(current);
                    printf("PARSER_ERROR: Ungültiger Status erreicht!\n");
                    return NULL;                    
            }
        }
    }

    if(state == ST_NACHNAME) {
        // Trennzeichen => OK
        charbuffer_append_char(cbuf, '\0');
        printf("Nachname: %s\n", cbuf->array);
        current->surname = malloc(cbuf->laenge);
        strncpy(current->surname, cbuf->array, cbuf->laenge-1);
        list_append(lst, current);                        
        cbuf->laenge = 0;
        state = ST_NUMMER;
    }

    fclose(f);
    charbuffer_free(cbuf);
    return lst;
}

int main() {    

    List* lst = parse("daten.csv");
    printf("\n - - - - - - - - - - - - - - - - \n\n");

    if(list_iterate_start(lst) == LIST_SUCCESS) {
        Customer *c;
        while((c = list_iterate_get_next(lst)) != NULL) {
            printf("%d - %s - %s\n", c->number, c->prename, c->surname);
        }
    } else {
        printf("Über die Liste konnte nicht iteriert werden\n");
    }

    if(lst != NULL) {
        list_free(lst, free);
    }
    
    return 0;
}