#ifndef _CHARBUFFER_H
#define _CHARBUFFER_H

#define SUCCESS 0
#define NO_MORE_MEMORY_ERROR 1
#define NO_CHAR_BUFFER_ERROR 2

typedef struct _charbuf {
    char* array;
    int laenge;
    int max_laenge;
} CharBuffer;

CharBuffer* charbuffer_create(int initial_size);
void charbuffer_free(CharBuffer* buf);
int charbuffer_append_char(CharBuffer* buf, char c);

#endif