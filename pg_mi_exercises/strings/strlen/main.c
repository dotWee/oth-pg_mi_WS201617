#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

int strlen_own(char *string) {
    int count = 0;

    // Solange das char mit der Position count kein null-byte ist...
    while (string[count]) {
        count++;
    }

    return count;
}

int main(int argc, char *argv[]) {

    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);

    int length_own = strlen_own(buffer);
    printf("Länge eigen: %d\n", length_own);

    int length_lib = strlen(buffer);
    printf("Länge lib: %d\n", length_lib);

    return 0;
}