#include <stdio.h>
#include "bambaska.h"

extern int global_variable;
int main()
{
    static int sonuc = 0;
    sonuc = topla(10,15);
    printf("DEFINE BAS %d\n",MUSTAFA);
    printf("sonuc %d\n",sonuc);
    printf("global_variable %d",global_variable);
    return 0;
}
