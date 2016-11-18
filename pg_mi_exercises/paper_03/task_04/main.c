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

    int ergebnis = count_substring(argv[2], argv[1]);
    printf("Ergebnis: %d", ergebnis);

    return 0;
}