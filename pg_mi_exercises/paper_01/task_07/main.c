#include <stdio.h>

int main(void) {

    int start = 0, temp = 0;

    while (0 == 0) {
        printf("Number:");
        scanf("%d", &temp);

        int tempSum;
        tempSum = start + temp;
        printf("Calculate %d %c %d = %d", start, operator, temp, tempSum);
        start = tempSum;
    }

    return 0;
}