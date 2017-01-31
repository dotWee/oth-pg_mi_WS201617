#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define MAXLENGTH 50

int strnlen_own(char *string, int maxlen) {
    int count = 0;

    // Solange das char mit der Position count kein null-byte ist und count kleiner maxlen ist...
    while ((string[count] != 0) && (count < maxlen)) {
        count++;
    }

    return count;
}

int main(int argc, char *argv[]) {

    printf("Gib einen Text ein, dessen Länge gezählt werden soll:\n");
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);

    int length_own = strnlen_own(buffer, MAXLENGTH);
    printf("Länge eigen: %d\n", length_own);

    int length_lib = strnlen(buffer, MAXLENGTH);
    printf("Länge lib: %d\n", length_lib);

    return 0;
}