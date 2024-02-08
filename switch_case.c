#include <stdio.h>

int main() 
{
        static int durum = 3;
        switch(durum)
        {
                case 1:
                        printf("case 1 entered \n");
                        goto common_state;
                case 2:
                        printf("case 2 entered \n");
                        goto common_state;
                case 3:
                common_state:
                printf("this is actually common state that should be run in every case \n");
                break;
                default:
                        printf("default entered \n");
                        goto common_state;
        }

        durum = 3;
        durum = 5;
        //getchar(); // Wait for Enter key
        printf("debug finished...\n");

        return 0;
}
