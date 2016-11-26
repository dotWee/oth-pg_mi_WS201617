#ifndef _MAP_H
#define _MAP_H

// Konstanten
#define SUCCESS 0
#define NO_MAP_DEFINED 1
#define NO_ELEMENT_KEY_ERROR 2
#define NO_ELEMENT_VALUE_ERROR 2
#define MAP_FULL_ERROR 4

// Structs
typedef struct _map {
    void **key_elements;
    void **value_elements;

    int max_elements;
    int size;
} Map;

/**
 * Diese Funktion initialisiert eine neue Map.
 *
 * @param max_elements
 * @return Eine neue Map
 */
Map *map_create(int max_elements);

/**
 * Diese Funktion schreibt einen neuen Key-String und Value-String in eine
 * gegebene Map und aktualisiert seinen Size Status. Es werden nur Adressen
 * akzeptiert, die vorher im Speicher reserviert wurden.
 *
 * @param map
 * @param key_element Adresse des neuen Key-Strings
 * @param value_element Adresse des neuen Value-Strings
 * @return NULL falls die Map auch null ist, ansonsten einen definierten Error-Code
 */
int map_enqueue(Map *map, void *key_element, void *value_element);

/**
 * Diese Funktion ließt den älteste Value-String aus einer gegebenen Map und gibt
 * seine Speicheradresse als Pointer zurück.
 *
 * @param map Map aus dem der Value-String gelesen werden soll
 * @return Ältester Value-String aus einer gegebenen Map
 */
void *map_value_dequeue(Map *map);

/**
 * Diese Funktion aktualisiert den Size-Status einer gegebenen Map. Diese Funktion
 * sollte immer nach dem holen eines Key und Value Strings aufgerufen werden,
 * ansonsten können Elemente vergessen werden.
 *
 * @param map
 * @return
 */
void *map_size_dequeue(Map *map);

/**
 * Diese Funktion ließt den ältesten Key-String aus einer gegebenen Map und gibt
 * seine Speicheradresse als Pointer zurück.
 *
 * @param map Map aus dem der Key-String gelesen werden soll
 * @return Ältester Key-String aus einer gegebenen Map
 */
void *map_key_dequeue(Map *map);

/**
 * Diese Funktion ließt das älteste Element (Key und Value) einer gegebenen Map,
 * gibt es aus und markiert den davon belegten Speicher als frei.
 *
 * @param map
 */
void map_dequeue(Map *map);

/**
 * Diese Funktion leert eine Map und gibt den belegten Speicher wieder frei.
 *
 * @param map
 */
void map_free(Map *map);

#endif