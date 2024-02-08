#include <stdio.h>
#include "toplama.h"

int main()
{
    // int baba = 0b11111111;
    // baba = (baba << 11) & ~(0b1111); 

    // printf("Number: 0x%x\n", baba);

    int baba = 0b11111111;
    baba = ( (baba << 11) & ~(0x3FF) ) | 0x000003FF | 0xC0000000;

    printf("Number: 0x%x\n", baba);

    return 0;
}

             1100 0000 0000 0111 1111 1011 1111 1111
0x7f800                     0111 1111 1000 0000 0000
//0xc007fbff 1100 0000 0000 0111 1111 1011 1111 1111
//0x7F800   0b0111 1111 1000 0000 0000

