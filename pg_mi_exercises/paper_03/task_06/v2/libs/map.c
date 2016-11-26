#include "map.h"
#include <stdlib.h>
#include <stdio.h>

Map *map_create(int max_elements) {

    Map *map = malloc(sizeof(Map));

    // Anzahl der Elemente die zugewiesen werden sollen
    size_t nElements = sizeof(void *);

    // Größe der Elemente
    size_t size = (size_t) max_elements;

    // Benötigten Speicher initialisieren
    map->elements = calloc(nElements, size);

    map->max_elements = max_elements;
    map->size = 0;

    return map;
}

Element *element_create(void *key, void *value) {
    Element *element = malloc(sizeof(Map));

    element->key = key;
    element->value = value;

    return element;
}

int map_enqueue(Map *map, void *element) {

    // Map darf nicht null sein
    if (map == NULL) {
        return NO_MAP_DEFINED;
    }
    if (map->size == map->max_elements) {
        return MAP_FULL_ERROR;
    }
    if (element == NULL) {
        return NO_ELEMENT_ERROR;
    }

    map->elements[map->size] = element;
    map->size += 1;

    return SUCCESS;
}

void *map_dequeue(Map *map) {
    if (map == NULL) {
        return NULL;
    }
    if (map->size == 0) {
        return NULL;
    } else {
        // Hole das Älteste Element
        void *element_to_return = map->elements[0];

        // Rücke die Anderen nach
        for (int i = 1; i < map->size; i++) {
            map->elements[i - 1] = map->elements[i];
        }

        // Aktualisiere den Size Status
        map->size -= 1;

        // Gib das Älteste Element zurück
        return element_to_return;
    }
}

void element_free(Element *element) {
    free(element->key);
    free(element->value);
    free(element);
}

void map_free(Map *map) {
    if (map != NULL) {

        // Leere Map vor dem entgültigen Löschen
        while (map->size != 0) {
            Element *element = map_dequeue(map);
            element_free(element);
        }

        free(map->elements);
        free(map);
    }
}