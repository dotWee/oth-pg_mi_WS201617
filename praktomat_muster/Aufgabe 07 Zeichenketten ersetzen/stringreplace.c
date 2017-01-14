#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *result = NULL;
    if(argc != 4) {
        printf("Korrekter Aufruf: %s \"string to replace\" \"replacement\" \"String\"\n", argv[0]);
        return 0;
    }

    char *to_replace = argv[1];
    int to_replace_len = strlen(to_replace);
    char *replacement = argv[2];
    int replacement_len = strlen(replacement);
    char *base = argv[3];
    int base_len = strlen(base);

    int number_of_replacements = 0;
    int tmp_hitchars = 0;
    char temp[to_replace_len];
    memset(temp, 0, to_replace_len);

    // Ermitteln, wie viele Treffer ersetzt werden müssen
    for(int i = 0; i <= base_len; i++) {
        if(tmp_hitchars >= to_replace_len) {
            number_of_replacements++;
            tmp_hitchars = 0;
            memset(temp, 0, to_replace_len);
        }
        if(base[i] == to_replace[tmp_hitchars]) {
            tmp_hitchars++;
        } else {
            tmp_hitchars = 0;
            memset(temp, 0, to_replace_len);
        }
    }
    //printf("Anzahl der Treffer: %d\n", number_of_replacements);

    int result_len = base_len - (number_of_replacements*to_replace_len) + (number_of_replacements*replacement_len)+1;
    result = calloc(sizeof(char), result_len);
    tmp_hitchars = 0;
    memset(temp, 0, to_replace_len);

    // Treffer ersetzen
    char *insert_ptr = result;
    for(int i = 0; i <= base_len; i++) {
        if(tmp_hitchars >= to_replace_len) {
            insert_ptr -= to_replace_len;            
            for(int z = 0; z < replacement_len; z++) {
                *insert_ptr = replacement[z];
                insert_ptr++;
            }
            tmp_hitchars = 0;
        }

        if(base[i] == to_replace[tmp_hitchars]) {
            tmp_hitchars++;
        } else {
            tmp_hitchars = 0;
        }
        *insert_ptr = base[i];
        insert_ptr++;
    }
    insert_ptr = '\0';

    // Ergebnis ausgeben
    if(result != NULL) {
        printf("%s\n", result);
    }
    
    free(result);
    return 0;
}