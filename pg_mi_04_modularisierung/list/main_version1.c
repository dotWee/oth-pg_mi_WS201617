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

int main() {

    List lst;
// Liste mit einem Eintrag aufgebaut
    Node* n = malloc(sizeof(Node));
    n->next = NULL;
    n->element = "Hallo";

    lst.base_ptr = n;
    lst.insert_ptr = n;
    lst.size = 1;

// Fügen wir einen Eintrag zur Liste hinzu
    n = malloc(sizeof(Node));
    n->next = NULL;
    n->element = "Welt";

    lst.insert_ptr->next = n;
    lst.insert_ptr = n;
    lst.size += 1;

    return 0;
}