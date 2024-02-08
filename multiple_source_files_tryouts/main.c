#include <stdio.h>
#include "bambaska.h"

extern int global_variable;
int main()
{
    static int sonuc = 0;
    sonuc = topla(10,15);
    printf("DEFINE BAS %d\n",MUSTAFA);
    printf("topla(10,15);  %d\n",sonuc);
    printf("global_variable declared in other c file : %d",global_variable);
    return 0;
}
