//
// Created by lukas on 19.10.2016.
//
#include <stdio.h>

int main(void) {

    int count = 0; // Zähler für die Zahl der möglichen Divisionen
    int num = 0; // Variable für die Benutzereingabe

    scanf("%d", &num);

    // Bitte hier die Lösung einfügen
    while(num != 1) {
        num = num / 2;
        count++;
    }

    printf("%d", count);

    return 0;
}