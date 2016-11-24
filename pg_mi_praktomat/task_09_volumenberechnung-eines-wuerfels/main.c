#include <stdio.h>

int cube(int *n) {
    int value = *n;

    return value * value * value;
}

int main() {
    int number;

    scanf("%d", &number);

    printf("%d^3 = %d\n", number, cube(&number));

    return 0;
}

