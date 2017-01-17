#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("Korrekter Aufruf: %s A B \"String\"\n", argv[0]);
        return 0;
    }
    char a = argv[1][0];
    char b = argv[2][0];
    char *str =argv[3];

    for(int i = 0; str[i]!='\0'; i++)
    {
        if (str[i] == a)
        {
            str[i]= b;
        }
    }

    printf("%s\n", str);
    return 0;
}
