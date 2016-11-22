#include <stdio.h>
#include <string.h>

int count_substring(const char *string, const char *substring) {
    int amount = 0;

    const char *temp = string;
    while ((temp = strstr(temp, substring))) {
        amount++;

        temp++;
    }

    return amount;
}

int main(int argc, const char *argv[]) {

    // Check args
    int length_substring = strlen(argv[1]);
    int length_orgstring = strlen(argv[2]);

    // Wenn die Teilzeichenkette größer als die Zeichenkette ist...
    if (length_substring > length_orgstring) {
        return -1;
    } else {
        int ergebnis = count_substring(argv[2], argv[1]);
        printf("Ergebnis: %d", ergebnis);

        return 0;
    }
}