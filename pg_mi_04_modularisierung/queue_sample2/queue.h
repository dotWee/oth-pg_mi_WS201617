#ifndef _MY_QUEUE_H
#define _MY_QUEUE_H

// Konstanten
#define SUCCESS 0
#define NO_QUEUE_ERROR 1
#define NO_ELEMENT_ERROR 2
#define QUEUE_FULL_ERROR 3

// Structs definieren
typedef struct _queue {
    void** elements;
    int max_elements;
    int size;
} Queue;

// Definition der Funktionen
Queue* queue_create(int max_elements);
int queue_enqueue(Queue* q, void* element);
void* queue_dequeue(Queue* q);
void queue_free(Queue* q);

#endif