#include "queue.h"

#include <stdlib.h>

// Implementierung der Funktionen
Queue* queue_create(int max_elements) {
    Queue* q = malloc(sizeof(Queue));
    q->elements = calloc(sizeof(void*), max_elements);
    q->max_elements = max_elements;
    q->size = 0;
    return q;
}

int queue_enqueue(Queue* q, void* element) {
    if(q == NULL) {
        return NO_QUEUE_ERROR;
    } 
    if(element == NULL) {
        return NO_ELEMENT_ERROR;
    }
    if(q->size >= q->max_elements) {
        return QUEUE_FULL_ERROR;
    }

    q->elements[q->size] = element;
    q->size += 1;

    return SUCCESS;
}

void* queue_dequeue(Queue* q) {
    if(q == NULL) {
        return NULL;
    }
    if(q->size == 0) {
        return NULL;
    } else {
        void* element_to_return = q->elements[0];
        for(int i = 1; i < q->size; i++) {
            q->elements[i-1] = q->elements[i];
        }
        q->size -= 1;
        return element_to_return;
    }
}


void queue_free(Queue* q, void free_element(void*)) {
    if(q != NULL) {
        // evtl. Elemente aus dem Heap löschen
        if(free_element != NULL) {
            for(int i = 0; i < q->size; i++) {
                free_element(q->elements[i]);
            }
        }
        free(q->elements);
        free(q);
    }
}