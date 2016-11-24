#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int test_queue_create() {
    int errors = 0;
    Queue* q = NULL;
    q = queue_create(10);

    if(q == NULL) {
        // Fehler: wir haben keine Queue von Create erhalten
        printf("TEST_QUEUE_CREATE: keine Queue erhalten\n");
        errors += 1;
    }

    // TODO: hier weitere Tests einbauen ...

    return errors;
}

int main() {
    int errors = 0;
    errors += test_queue_create();
}