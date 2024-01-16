#include <stdio.h>
#include "stdint.h"
#include <windows.h>

uint16_t str_len(uint8_t* string)
{
    uint16_t ret = 0;
    while(*string)
    {
        ret++;
        string++;
    }
    return ret;
}

uint8_t str_compare(uint8_t* string1, uint8_t* string2, uint8_t size) 
{
    uint8_t ret =0;
    for(uint16_t i=0;i<str_len(string2);i++)
    {
        if(string1[i] != string2[i])
        {
            ret = 1;
            return ret;
        }
    }
    return ret;
}

//char text[10] = {'m','u','s','t','a','f','a','m','u','s'};
uint8_t text[] = {"mustafamustafamustafamustafamustafamustafamustafamustafamustafamustafamustafamustafamustafamustafamustafa\0"};

//char* text = "mustafa";
uint8_t aranan[3] = {"must"};
uint8_t* tx_ptr;

void main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitleA("MFB SEARCH ENGINE");

    tx_ptr = text;

    printf("PROGRAM STARTED\n");
    while(*tx_ptr)
    {
        if(str_compare(tx_ptr,aranan,3) == 0)
        {
            for(int i=0;i<str_len(aranan);i++)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("%c",*tx_ptr);
                tx_ptr++;
                //printf("x");
            }
            //tx_ptr=tx_ptr+str_len(aranan);
        }
        else
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("%c",*tx_ptr);
            tx_ptr++;
        }
        
    }

    printf("\n\nPROGRAM FINISHED\n");
    
}

