#include <stdio.h>
#include <stdlib.h>

// Konstanten
#define SUCCESS 0
#define NO_LISTARRAY_ERROR 1
#define NO_ELEMENT_KEY_ERROR 2
#define NO_ELEMENT_VALUE_ERROR 2
#define LISTARRAY_FULL_ERROR 4

// Structs definieren
typedef struct _listarray {
    void **key_elements;
    void **value_elements;

    int max_elements;
    int size;
} Listarray;

Listarray *listarray_create(int max_elements) {
    Listarray *listarray = malloc(sizeof(Listarray));

    listarray->key_elements = calloc(sizeof(void *), max_elements);
    listarray->value_elements = calloc(sizeof(void *), max_elements);

    listarray->max_elements = max_elements;
    listarray->size = 0;

    return listarray;
}

int listarray_enqueue(Listarray *listarray, void *key_element, void *value_element) {
    if (listarray == NULL) {
        return NO_LISTARRAY_ERROR;
    }
    if (key_element == NULL) {
        return NO_ELEMENT_KEY_ERROR;
    }
    if (value_element == NULL) {
        return NO_ELEMENT_VALUE_ERROR;
    }

    listarray->key_elements[listarray->size] = key_element;
    listarray->value_elements[listarray->size] = value_element;
    listarray->size += 1;

    return SUCCESS;
}

void *listarray_value_dequeue(Listarray *listarray) {
    if (listarray == NULL) {
        return NULL;
    }
    if (listarray->size == 0) {
        return NULL;
    } else {
        void *element_to_return = listarray->value_elements[0];
        for (int i = 1; i < listarray->size; i++) {
            listarray->value_elements[i - 1] = listarray->value_elements[i];
        }
        return element_to_return;
    }
}

void *listarray_size_dequeue(Listarray *listarray) {
    if (listarray == NULL) {
        return NULL;
    }
    if (listarray->size == 0) {
        return NULL;
    } else {
        listarray->size -= 1;
        return SUCCESS;
    }
}

void *listarray_key_dequeue(Listarray *listarray) {
    if (listarray == NULL) {
        return NULL;
    }
    if (listarray->size == 0) {
        return NULL;
    } else {
        void *element_to_return = listarray->key_elements[0];
        for (int i = 1; i < listarray->size; i++) {
            listarray->key_elements[i - 1] = listarray->key_elements[i];
        }
        return element_to_return;
    }
}

void listarray_dequeue(Listarray *listarray) {
    char *key = listarray_key_dequeue(listarray);
    char *value = listarray_value_dequeue(listarray);
    listarray_size_dequeue(listarray);

    // Gib Element aus
    printf("%s=%s\n", key, value);
}

// Nur verwenden, wenn die Listarray keine Elemente mehr enthält, die
// dynamisch mit Malloc etc. angelegt wurden.
void listarray_free(Listarray *listarray) {
    if (listarray != NULL) {
        // TODO: Für Elemente aus dem Heap müsste hier noch was rein!
        free(listarray->key_elements);
        free(listarray->value_elements);
        free(listarray);
    }
}

int main(int argc, const char *argv[]) {

    // Neue Listarray definieren;
    Listarray *listarray = listarray_create(10);

    // Neues Element einfügen
    listarray_enqueue(listarray, "Vorname", "Lukas");

    // Aktuelles Element ausgeben
    listarray_dequeue(listarray);

    // Speicher leeren
    listarray_free(listarray);

    return 0;
}