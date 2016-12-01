#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Header-Datei unserer Bibliothek queue.o einbinden
#include "queue.h"

void free_string(void* elem) {
    printf("Lösche: %s\n", (char*)elem);
    free(elem);
}

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

    queue_free(q, NULL);
    q = queue_create(10);

    char *str = malloc(sizeof(char)*100);
    strncpy(str, "Hallo Welt", 100);
    queue_enqueue(q, str);

    str = malloc(sizeof(char)*100);
    strncpy(str, "Und noch eins", 100);
    queue_enqueue(q, str);

    queue_free(q, free_string);

    return 0;
}