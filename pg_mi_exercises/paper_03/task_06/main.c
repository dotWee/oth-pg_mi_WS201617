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

        // Neues Element einfügen
        map_enqueue(map, key, value);
    }

    // Aktuelles Element ausgeben
    map_dequeue(map);

    // Speicher leeren
    map_free(map);

    return 0;
}