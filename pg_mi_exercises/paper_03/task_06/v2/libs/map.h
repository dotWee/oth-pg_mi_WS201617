#ifndef _MAP_H
#define _MAP_H

// Konstanten
#define SUCCESS 0
#define NO_MAP_DEFINED 1
#define NO_ELEMENT_ERROR 2
#define MAP_FULL_ERROR 4

// Structs
typedef struct _map {
    void **elements;

    int max_elements;
    int size;
} Map;

typedef struct _element {
    char *key;
    char *value;
} Element;

/**
 * Diese Funktion initialisiert eine neue Map.
 *
 * @param max_elements
 * @return Eine neue Map
 */
Map *map_create(int max_elements);

/**
 * Diese Funktion initialisiert ein neues Element
 * 
 * @param key 
 * @param value 
 * @return 
 */
Element *element_create(void *key, void *value);

/**
 * Diese Funktion schreibt einen neues Element in eine gegebene Map und aktualisiert
 * seinen Size Status. Es werden nur Adressen akzeptiert, die vorher im Speicher
 * reserviert wurden.
 *
 * @param map
 * @param element Adresse des neuen Elements
 * @return NULL falls die Map auch null ist, ansonsten einen definierten Error-Code
 */
int map_enqueue(Map *map, void *element);

/**
 * Diese Funktion ließt das Älteste Element aus einer gegebenen Map und gibt seine
 * Speicheradresse als Pointer zurück. Der Size-Status wird am Ende aktualisiert und
 * der belegte Speicher als frei makiert.
 *
 * @param map Map aus dem das Element gelesen werden soll
 * @return Ältestes Element aus einer gegebenen Map
 */
void *map_dequeue(Map *map);

/**
 * Diese Funktion löscht ein Element aus dem Heap und gibt den belegten Speicher
 * wieder frei. 
 * 
 * @param element 
 */
void element_free(Element *element);

/**
 * Diese Funktion leert eine Map und gibt den belegten Speicher wieder frei.
 *
 * @param map
 */
void map_free(Map *map);

#endif