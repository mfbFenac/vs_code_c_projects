#include <stdio.h>
#include "toplama.h"

int main()
{
    int number;
    char name[50];

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Enter your name: ");
    scanf(" %49[^\n]", name); // Reading a string with spaces using %[^\n]

    printf("Number: %d\n", number);
    printf("Name: %s\n", name);

    // static int sonuc = 0;
    // sonuc = topla(10,15);
    // printf("DEFINE BAS %d\n",MUSTAFA);
    // printf("sonuc %d",sonuc);
    return 0;
}
