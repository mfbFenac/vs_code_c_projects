#include <stdio.h>

int main() 
{

    printf("hello");
    static int a = 0;
    a = getchar(); // Wait for Enter key
    if(a == 65)
    printf("baba");

    getchar(); // Wait for Enter key
    return 0;
}
