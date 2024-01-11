#include <stdio.h>
#include "string.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main() 
{
    char* text_dizisi = "The LIS2HH12 is an ultra-low-power highperformance three-axis linear accelerometer belonging to the “pico” family. \
The LIS2HH12 has full scales of 2g/4g/8g and is capable of measuring accelerations with output data rates from 10 Hz to 800 Hz. \
The self-test capability allows the user to check the functioning of the sensor in the final application. The LIS2HH12 has an \
integrated first-in, first-out (FIFO) buffer allowing the user to store data in order to limit intervention by the host processor. \
The LIS2HH12 is available in a small thin plastic land grid array package (LGA) and it is guaranteed to operate over an extended \
temperature range from -40 °C to +85 °C \0";

#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
#elif //This one works under Linux
    printf("\x1b[31m"); // Red text
#endif

    char* temp;
    temp = text_dizisi;
    while (*temp) {
        if (strncmp(temp, "h", strlen("h")) == 0) 
        {
            for(int i=0;i<30;i++)
            {
                printf("%c",*(temp+i));
            }

            printf("\twhat you searched for is at %ld\n",(char*)temp - text_dizisi);
            
        }
        temp++;
    }

#ifdef _WIN32
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#elif //This one works under Linux
    printf("\x1b[0m"); // Reset text color to default
#endif



    // for(;*text_dizisi;text_dizisi++)
    // {
    //     printf("%c",*(text_dizisi));
    // }

    // static int i = 0;
    // while(*(text_dizisi+i) != '\0')
    // {
    //     printf("%c",*(text_dizisi+i++));
        
    // }
    // printf("\ntotal number of chars here in this text is %d",strlen(text_dizisi));

    // static int a = 0;
    // a = getchar(); // Wait for Enter key
    // if(a == 65)
    // printf("baba");

    getchar(); // Wait for Enter key
    return 0;
}
