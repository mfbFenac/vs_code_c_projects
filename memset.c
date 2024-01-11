#include <stdio.h>
#include <string.h>

int main()
{
	char str[5];
    for(int i = 0;i<sizeof(str); i++)
	printf("%d", str[i]);


    printf("\n-----\n");

	// Fill 8 characters starting from str[13] with '.'
	memset(str + 2, 1, 2);

    for(int i = 0;i<sizeof(str); i++)
	printf("%d", str[i]);
    
	return 0;
}

