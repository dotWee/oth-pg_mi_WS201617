
#include <stdio.h>

int main(void) {

    // Frange nach Namen
    printf("Wie ist ihr name? ");

    // Lese Eingabe
    char name[100];
    scanf("%s", name);

    // Gib Name aus
    printf("Hallo %s\n", name);

    return 0;
}