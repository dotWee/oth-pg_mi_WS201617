#include "charbuffer.h"

CharBuffer* charbuffer_create(int initial_size) {
    CharBuffer* buf = malloc(sizeof(CharBuffer));
    buf->max_laenge = initial_size;
    buf->array = malloc(sizeof(char)*initial_size);
    buf->laenge = 0;
    return buf;
}

void charbuffer_free(CharBuffer* buf) {
    if(buf != NULL) {
        if(buf->array != NULL) {
            free(buf->array);
        }
        free(buf);
    }
}

void charbuffer_append_char(CharBuffer* buf, char c) {
    // Speicher reicht nicht (laenge >= max_laenge-1)
    // -- Neuen reservieren
    // -- max_laenge + NEU
    // -- array -> realloc(max_laenge)
    // Speicher reicht
    // -- Char am Schluss (buf->laenge) einfügen
    // -- laenge += 1
}