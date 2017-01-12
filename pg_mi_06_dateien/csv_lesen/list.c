#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List* list_new() {
    List* lst = malloc(sizeof(List));
    lst->root = 0;
    lst->top = 0;
    lst->size = 0;
    lst->error = 0;
    return lst;
}

void list_append(List* lst, void* item) {
    if(lst == NULL) {
        return;
    }
    if(item == NULL) {
        lst->error = LIST_NO_ITEM_ERROR;
        return;
    }

    ListItem *i = malloc(sizeof(ListItem));
    i->value = item;
    i->next = NULL;

    if(lst->root == NULL) {        
        lst->root = i;
        lst->top = i;
        lst->size = 1;
        lst->error = 0;
    } else {        
        lst->top->next = i;
        lst->top = i;
        lst->size += 1;
        lst->error = 0;
    }
}

int list_get_error(List* lst) {
    if(lst == NULL) 
        return LIST_NO_LIST_ERROR;
    
    return lst->error;
}

size_t list_get_size(List* lst) {
    if(lst == NULL) 
        return 0;

    return lst->size;
}

int list_iterate_start(List* lst) {
    if(lst == NULL) 
        return LIST_NO_LIST_ERROR;
    
    lst->iteration_current = lst->root;

    return LIST_SUCCESS;
}

void* list_iterate_get_next(List* lst) {
    if(lst == NULL)
        return NULL;

    ListItem* temp = lst->iteration_current;
    if(lst->iteration_current != NULL) {
        lst->iteration_current = lst->iteration_current->next;
        return temp->value;
    } else {
        return NULL;
    }    
}

void list_free(List* lst, void freefunc(void*)) {
    if(lst == NULL)
        return;
    
    while(lst->root != NULL) {
        ListItem* tmp = lst->root;
        lst->root = tmp->next;
        if(freefunc != NULL) {
            freefunc(tmp->value);
        }
        free(tmp);
    }
    free(lst);
}