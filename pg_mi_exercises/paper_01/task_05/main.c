#include <stdio.h>

int main(void) {
    int start = 0, temp = 0;
    char operator = 0;

    printf("\nOperator:");
    scanf(" %c", &operator);

    printf("Number:");
    scanf("%d", &temp);

    int tempSum;
    switch (operator) {

        case '+':
            tempSum = start + temp;
            break;

        case '-':
            tempSum = start - temp;
            break;

        case '*':
            tempSum = start * temp;
            break;

        case '/':
            tempSum = start / temp;
            break;

        default:
            return 1;
    }

    printf("Calculate %d %c %d = %d", start, operator, temp, tempSum);

    return 0;
}