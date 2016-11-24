#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define NO_QUEUE_ERROR 1
#define NO_ELEMENT_ERROR 2
#define QUEUE_FULL_ERROR 3

typedef struct _queue {
    void** elements;
    int max_elements;
    int size;
} Queue;

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

// Nur verwenden, wenn die Queue keine Elemente mehr enthält, die
// dynamisch mit Malloc etc. angelegt wurden.
void queue_free(Queue* q) {
    if(q != NULL) {
        // Für Elemente aus dem Heap müsste hier noch was rein!
        free(q->elements);
        free(q);
    }
}

int main(void) {
    Queue* q = queue_create(100);
    // Ab hier mit der Queue arbeiten...
    int error = queue_enqueue(q, "Max Mustermann");
    if(error == QUEUE_FULL_ERROR) {
        printf("Queue ist voll, der Eintrag konnte nicht hinzugefügt werden\n");
        return 1;
    }
    char* result = queue_dequeue(q);
    if(result != NULL) {
        printf("Ergebnis: %s\n", result);
    }
    // Queue wieder löschen...
    queue_free(q);
    return 0;
}