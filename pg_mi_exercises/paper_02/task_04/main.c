#include <stdio.h>

int main(int argc, char *argv[]) {

    int zahl = 0;

    // Immer einen Schritt
    for (int i = 0; i < 200; ++i) {
        printf("Adresse darunter: %p\n", &zahl - i);
    }

    return 0;
}
