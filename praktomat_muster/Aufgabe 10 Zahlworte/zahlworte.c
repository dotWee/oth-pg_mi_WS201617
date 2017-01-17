#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 30

/*
 * Liefert einen Zeiger auf ein Ziffer-Wort
 */
static char* get_word_ptr_for_digit(int digit) {
    static char* worte[] = {
        "null", "eins", "zwei", "drei", "vier", 
        "fünf", "sechs", "sieben", "acht", "neun"        
    };

    if(digit < 0 || digit > 9) {
        printf("ERROR: Invalid digit, must be between 0 and 9");
        return NULL;
    }

    return worte[digit];
}

/*
 * Zahlwort aufbauen
 */
void zahlworte(int zahl, char* array) {
    int tmp = zahl;
    int rest = 0;
    int digit = 0;
    char* stack[STACK_SIZE];
    unsigned stack_ptr = 0;

    array[0] = '\0';

    // Sonderfälle 0 und negative Zahl berücksichtigen
    if(tmp == 0) {
        strcat(array, "null");
        return;
    } else if(tmp < 0) {
        strcat(array, "minus ");
        tmp *= -1;
    }

    // Zifferworte schrittweise in den Stack legen
    while(tmp > 0) {
        rest = tmp / 10;
        digit = tmp - (10 * rest);
        tmp = rest;

        if(stack_ptr < STACK_SIZE-1) {
            stack[stack_ptr++] = get_word_ptr_for_digit(digit);
        } else {
            printf("ERROR: To much digits for Stack!");
            return;
        }
    }

    // Zifferworte aus dem Stack holen und in Ausgabe-Array schreiben
    while(stack_ptr > 0) {
        array = strcat(array, stack[--stack_ptr]);

        if(stack_ptr > 0) {
            array = strcat(array, " ");
        }
    }
}

/*
int main(void) {
    int zahl = -15876;
    char buffer[1024];

    zahlworte(zahl, buffer);
    printf("%d -> |%s|\n", zahl, buffer);

    zahl = 0;
    zahlworte(zahl, buffer);
    printf("%d -> |%s|\n", zahl, buffer);

    zahl = 1024;
    zahlworte(zahl, buffer);
    printf("%d -> |%s|\n", zahl, buffer);

    return 0;
}
*/