#include "charbuffer.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    CharBuffer* buf = charbuffer_create(100);

    char *txt = "abcdefghijklmnopqrstuvwxzy";
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 26; j++) {
            charbuffer_append_char(buf, txt[j]);
        }
    }

    printf("%s\n", buf->array);

    charbuffer_free(buf);
    return 0;
}