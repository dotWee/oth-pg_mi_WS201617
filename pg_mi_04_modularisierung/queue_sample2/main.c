#include <stdio.h>

// Header-Datei unserer Bibliothek queue.o einbinden
#include "queue.h"

int main(void) {
    // Hier kann z. B. die Queue benutzt werden
    Queue* q;
    q = queue_create(100);
    queue_enqueue(q, "Max Mustermann");
    queue_enqueue(q, "Moritz Mustermeier");
    queue_enqueue(q, "Maria Musterfrau");

    printf("Element: %s\n", (char*)queue_dequeue(q));
    printf("Element: %s\n", (char*)queue_dequeue(q));
    printf("Element: %s\n", (char*)queue_dequeue(q));
    printf("Element: %s\n", (char*)queue_dequeue(q));

    queue_free(q);

    return 0;
}