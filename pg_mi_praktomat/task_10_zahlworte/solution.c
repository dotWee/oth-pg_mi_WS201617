#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define MINUS "minus"

void zahlworte(int zahl, char *array) {

    // zahl als string einlesen
    //char *zahl_string = itoa(zahl, malloc(sizeof(char) * BUFFER_SIZE), 10);
    char *zahl_string = malloc(sizeof(char) * BUFFER_SIZE);
    sprintf(zahl_string, "%d", zahl);


    // wenn zahl negativ, füge 'minus' hinzu
    if (zahl < 0) {
        strcat(array, MINUS);
    }


    // für jedes char im string
    int i;
    for (i = 0; i < strlen(zahl_string); ++i) {

        // buchstabe aus string lesen
        char buchstabe = zahl_string[i];
        // printf("%c\n", zahl_einzeln);

        // zahl-buchstabe als string holen
        char *zahl_wort = NULL;
        switch (atoi(&buchstabe)) {
            case 0:
                zahl_wort = "null";
                break;

            case 1:
                zahl_wort = "ein";
                break;

            case 2:
                zahl_wort = "zwei";
                break;

            case 3:
                zahl_wort = "drei";
                break;

            case 4:
                zahl_wort = "vier";
                break;

            case 5:
                zahl_wort = "fünf";
                break;

            case 6:
                zahl_wort = "sechs";
                break;

            case 7:
                zahl_wort = "sieben";
                break;

            case 8:
                zahl_wort = "acht";
                break;

            case 9:
                zahl_wort = "neun";
                break;

            default:
                zahl_wort = "fehler";
                break;
        }
        // printf("%s\n", zahl_wort);

        // zahl-buchstabe zum string hinzufügen
        strcat(array, " ");
        strcat(array, zahl_wort);
    }


    // ergebnis ausgeben
    printf("|%s|", array);
}