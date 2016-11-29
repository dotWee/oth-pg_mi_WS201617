#include <stdio.h>
#include <string.h>
#include "map.h"

#define TEST_MAX_ELEMENTS 3
#define TEST_ELEMENT_VALUE "Value"
#define TEST_ELEMENT_KEY "Key"

Map *get_test_map() {
    return map_create(TEST_MAX_ELEMENTS);
}

int test_map_create(Map *map) {
    int errors = 0;

    if (map == NULL) {
        printf("Map ist null\n");
        errors++;
    }

    if (map->size != 0) {
        printf("Voreingestelle Map->Size ist %d. Erwartet: 0\n", map->size);
        errors++;
    }

    if (map->max_elements != TEST_MAX_ELEMENTS) {
        printf("Definierte Map->max_elements ist %d. Erwartet: %d\n", map->max_elements, TEST_MAX_ELEMENTS);
        errors++;
    }

    return errors;
}

Element *get_test_element() {
    return element_create(TEST_ELEMENT_KEY, TEST_ELEMENT_VALUE);
}

int test_element_create(Element *element) {
    int errors = 0;

    if (element == NULL) {
        printf("Erstelltes Element ist null\n");
        errors++;
    }
    if (strcmp(element->key, TEST_ELEMENT_KEY) != 0) {
        printf("Erwarter Key %s ungleich dem Key im Element: %s\n", element->key, TEST_ELEMENT_KEY);
        errors++;
    }
    if (strcmp(element->value, TEST_ELEMENT_VALUE) != 0) {
        printf("Erwarter Value %s ungleich dem Value im Element: %s\n", element->value, TEST_ELEMENT_VALUE);
        errors++;
    }

    return errors;
}

int test_map_enqueue(Map *map, void *element) {
    int errors = 0;

    int result = map_enqueue(map, element);
    if (result != SUCCESS) {
        printf("Funktion map_enqueue gab Code %d zurück. Erwartet: %d\n", result, SUCCESS);
        errors++;
    }

    return errors;
}

int test_map_dequeue(Map *map, Element *expected) {
    Element *returned = map_dequeue(map);
    int errors = 0;

    if (&expected == &returned) {
        printf("Adressen des Test-Elements und Return-Elements passen nicht zusammen. Return: %p Erwartet: %p\n",
               &returned, &expected);
        errors++;
    }
    if (strcmp(returned->key, expected->key) != 0) {
        printf("Keys des Test-Elements und Return-Elements passen nicht zusammen. Return: %s Erwartet: %s\n",
               returned->key, expected->key);
        errors++;
    }
    if (strcmp(returned->value, expected->value) != 0) {
        printf("Values des Test-Elements und Return-Elements passen nicht zusammen. Return: %s Erwartet: %s\n",
               returned->value, expected->value);
        errors++;
    }

    return errors;
}


int main(int argc, const char *argv[]) {
    int errors = 0;

    // Initialisiere neue Test-Map
    Map *map = get_test_map();

    // Teste map_create() Funktion
    errors += test_map_create(map);

    // Initialisiere Test-Element
    Element *element = get_test_element();

    // Teste element_create() Funktion
    errors += test_element_create(element);

    // Teste map_enqueue() Funktion
    errors += test_map_enqueue(map, element);

    // Teste map_dequeue() Funktion
    errors += test_map_dequeue(map, element);

    return errors;
}