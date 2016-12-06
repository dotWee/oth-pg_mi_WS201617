/*
 * Beispiel: Einfache verkettete Liste
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    void* element;
    struct _node* next;
} Node;

typedef struct _list {
    Node* base_ptr;     // Beginn der Liste (erstes Element)
    Node* insert_ptr;   // Ende der Liste (letztes Element)
    int size;
} List;

List* list_create() {
    List* l = malloc(sizeof(List));
    l->base_ptr = NULL;
    l->insert_ptr = NULL;
    l->size = 0;
    return l;
}

void list_append(List* lst, void* element) {
    if(lst == NULL) {
        // Abbrechen mit Fehler...
    }
    Node* n = malloc(sizeof(Node));
    n->next = NULL;
    n->element = element;
    if(lst->base_ptr == NULL) {
        lst->base_ptr = n;
        lst->insert_ptr = n;
        lst->size = 1;
    } else {
        lst->insert_ptr->next = n;
        lst->insert_ptr = n;
        lst->size += 1;
    }
}

void list_free(List* lst) {
    // TODO: um Callback-Funktion erweitern
}

int main() {

    List *lst = list_create();
// Liste mit einem Eintrag aufgebaut
    list_append(lst, "Hallo");

// Fügen wir einen Eintrag zur Liste hinzu
    list_append(lst, "Welt");
   
    list_free(lst);
    
    return 0;
}