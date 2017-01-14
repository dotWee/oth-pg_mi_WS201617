#include <stdio.h>

typedef struct _cust {
    int number;
    char *prename;
    char *surname;
} Customer;

int main(){
    Customer c;
    c.number = 1;
    c.prename = "Max";
    c.surname = "Musterman";

    FILE *f;
    f = fopen("customer.csv", "w");

    fprintf(f, "number;prename;surname\n");
    for(int i = 0; i < 10; i++) {
        fprintf(f, "%d;%s;%s\n", c.number, c.prename, c.surname);
    }

    fclose(f);
    return 0;
}