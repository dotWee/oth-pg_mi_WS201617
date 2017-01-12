#include "charbuffer.h"

#include <stdlib.h>

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

int charbuffer_append_char(CharBuffer* buf, char c) {
    if(buf == NULL) {
        return NO_CHAR_BUFFER_ERROR;
    }
    if(buf->laenge >= buf->max_laenge-1) {
        char* ptr = realloc(buf->array, buf->max_laenge+100);
        if(ptr != NULL) {
            buf->array = ptr;
            buf->max_laenge += 100;
        } else {
            return NO_MORE_MEMORY_ERROR;
        }
    }
    buf->array[buf->laenge] = c;
    buf->laenge += 1;
    buf->array[buf->laenge] = '\0';
    return SUCCESS;
}