#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>

#define LIST_SUCCESS 0
#define LIST_NO_LIST_ERROR 1
#define LIST_NO_ITEM_ERROR 2

typedef struct _listitem {
    void *value;
    void *next;
} ListItem;

typedef struct _list {
    ListItem *root;
    ListItem *top;
    ListItem *iteration_current;
    size_t size;
    int error;
} List;

List* list_new();
void list_append(List* lst, void* item);
int list_get_error(List* lst);
size_t list_get_size(List* lst);
int list_iterate_start(List* lst);
void* list_iterate_get_next(List* lst);
void list_free(List* lst, void freefunc(void*));

#endif