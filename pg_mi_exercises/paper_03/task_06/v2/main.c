#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/map.h"

#define MAX_ENTRIES 10
#define MAX_STRING_LENGTH 80

char *lese_zeile() {
    char buffer[MAX_STRING_LENGTH];
    char *zeile = 0;
    int speicherbedarf = 0;

    // Eine Zeile einlesen, höchstens MAX_STRING_LENGTH Zeichen
    fgets(buffer, MAX_STRING_LENGTH, stdin);

    // Hier Ende, wenn die Zeile nur aus einem Punkt besteht
    if ((buffer[0] == '.') && ((buffer[1] == '\n') || (buffer[1] == '\r'))) {
        return NULL;
    }

    // Wenn der String mit einer Newline ('\n') endet, entferne es
    // um Aufgaben wie      Vorname
    //                      =Nachname
    // anstelle von
    //                      Vorname=Nachname
    // zu vermeiden
    if (buffer[strlen(buffer) - 1] == '\n') {
        buffer[strlen(buffer) - 1] = '\0';
    }

    // Speicherbedarf des Strings ermitteln
    // Stringlaenge + 1 Zeichen fuer \0 am Ende
    speicherbedarf = strlen(buffer) + 1;

    // Speicher reservieren
    // Länge entspricht dem Speicherbedarf in Bytes
    zeile = malloc(speicherbedarf);

    // Buffer kopieren
    strncpy(zeile, buffer, speicherbedarf);

    // Zeiger zurückgeben
    return zeile;
}

int main(int argc, const char *argv[]) {

    // Neue Map definieren
    Map *map = map_create(MAX_ENTRIES);


    for (int i = 0; i < MAX_ENTRIES; ++i) {
        char *key = lese_zeile();
        char *value = lese_zeile();

        // Neues Element erstellen
        Element *element = element_create(key, value);

        // Füg Element der Map hinzu
        map_enqueue(map, element);
    }

    // Führe aus, so lange wie die Größe ungleich 0 ist
    while (map->size != 0) {

        // Hole das älteste Element aus der Map
        Element *element = map_dequeue(map);

        // Gib es aus
        printf("%s=%s", element->key, element->value);

        // Gib Speicher wieder frei
        element_free(element);
    }

    // Speicher leeren
    map_free(map);

    return 0;
}