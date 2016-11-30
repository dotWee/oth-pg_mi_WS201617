#ifndef _CHARBUFFER_H
#define _CHARBUFFER_H

typedef struct _charbuf {
    char* array;
    int laenge;
    int max_laenge;
} CharBuffer;

CharBuffer* charbuffer_create(int initial_size);
void charbuffer_free(CharBuffer* buf);
void charbuffer_append_char(CharBuffer* buf, char c);

#endif