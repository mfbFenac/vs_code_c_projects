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

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitleA("MFB SEARCH ENGINE");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

    static char* temp;
    temp = text_dizisi;

    while(*temp)
    {
        if( strncmp(temp,"user",strlen("user")) == 0)
        {
            for(int i=0;i<strlen("user");i++)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("%c",*(temp+i));
            }
            temp = temp + strlen("user");
            
        }
        else
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("%c",*temp);
        }
        temp++;
    }

    

    getchar(); // Wait for Enter key
    return 0;
}
