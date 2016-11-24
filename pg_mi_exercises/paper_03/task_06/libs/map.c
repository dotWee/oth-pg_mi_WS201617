#include "map.h"
#include <stdlib.h>
#include <stdio.h>

Map *map_create(int max_elements) {
    Map *map = malloc(sizeof(Map));

    map->key_elements = calloc(sizeof(void *), (size_t) max_elements);
    map->value_elements = calloc(sizeof(void *), (size_t) max_elements);

    map->max_elements = max_elements;
    map->size = 0;

    return map;
}

int map_enqueue(Map *map, void *key_element, void *value_element) {

    // Map darf nicht null sein
    if (map == NULL) {
        return NO_MAP_DEFINED;
    }
    if (map->size == map->max_elements) {
        return MAP_FULL_ERROR;
    }
    if (key_element == NULL) {
        return NO_ELEMENT_KEY_ERROR;
    }
    if (value_element == NULL) {
        return NO_ELEMENT_VALUE_ERROR;
    }

    map->key_elements[map->size] = key_element;
    map->value_elements[map->size] = value_element;
    map->size += 1;

    return SUCCESS;
}

void *map_value_dequeue(Map *map) {

    // Map darf nicht null sein
    if (map == NULL) {
        return NULL;
    }
    if (map->size == 0) {
        return NULL;
    } else {
        void *element_to_return = map->value_elements[0];
        for (int i = 1; i < map->size; i++) {
            map->value_elements[i - 1] = map->value_elements[i];
        }
        return element_to_return;
    }
}

void *map_size_dequeue(Map *map) {

    // Map darf nicht null sein
    if (map == NULL) {
        return NULL;
    }
    if (map->size == 0) {
        return NULL;
    } else {
        map->size -= 1;
        return SUCCESS;
    }
}

void *map_key_dequeue(Map *map) {
    if (map == NULL) {
        return NULL;
    }
    if (map->size == 0) {
        return NULL;
    } else {
        void *element_to_return = map->key_elements[0];
        for (int i = 1; i < map->size; i++) {
            map->key_elements[i - 1] = map->key_elements[i];
        }
        return element_to_return;
    }
}

void map_dequeue(Map *map) {
    // Hole ältesten Key aus der Map
    char *key = map_key_dequeue(map);

    // Hole ältestes Value aus der Map
    char *value = map_value_dequeue(map);

    // Aktualisiere Size Status
    map_size_dequeue(map);

    // Gib ältestes Element aus
    printf("%s=%s\n", key, value);

    // Leere Key aus dem Speicher
    free(key);

    // Leere Value aus dem Speicher
    free(value);
}

void map_free(Map *map) {
    if (map != NULL) {

        // Leere Map vor dem entgültigen Löschen
        while (map->size != 0) {
            map_dequeue(map);
        }

        free(map->key_elements);
        free(map->value_elements);
        free(map);
    }
}