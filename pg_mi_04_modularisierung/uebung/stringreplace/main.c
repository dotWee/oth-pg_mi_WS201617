// Zeichenkette in einer Zeichenkette durch andere Zeichenkette ersetzen
//
// replace "abc" "cdefg" "Hallo duch kannst ja noch nicht mal das abc."
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc != 4) {
        return 1;
    }
    char *to_replace = argv[1];
    char *replacement = argv[2];
    char *string = argv[3];
    int to_replace_len = strlen(to_replace);
    int replacement_len = strlen(replacement);
    int string_len = strlen(string);

    int treffer = 0;
    int ptr = 0;
    // Schritt 1: Länge des Ergebnisstrings berechnen
    for(int i = 0; i < string_len; i++) {
        if(string[i] == to_replace[ptr]) {
            ptr = ptr + 1;
            if(ptr == to_replace_len) {
                treffer += 1;
                ptr = 0;
            }
        } else {
            ptr = 0;
        }
    }

    // Schritt 2: Speicher für Ergebnisstring reservieren
    int target_len = string_len + ((replacement_len - to_replace_len) * treffer);
    char* target = malloc(sizeof(char)*target_len+1);

    // Schritt 3: String kopieren und dabei die Ersetzung vornehmen
    char* work_ptr = string;
    ptr = 0;
    for(int i = 0; i < target_len; i++) {
        if((*work_ptr) == to_replace[ptr]) {
            ptr = ptr + 1;
            target[i] = *work_ptr;
            work_ptr += 1;
            if(ptr == to_replace_len) {
                i = i - (to_replace_len - 1);
                ptr = 0;
                // Fügen wir statt dessen to_replace eine
                for(int j = 0; j < replacement_len; j++) {
                    target[i] = replacement[j];
                    i++;
                }
                i = i-1;
            } 
        } else {
            ptr = 0;
            target[i] = *work_ptr;
            work_ptr += 1;
        }
    }

    // Schritt 4: Ergebnisstring ausgeben

    printf("%s", target);

    free(target);
    return 0;
}