#include <stdio.h>
#include "string.h"

#ifdef _WIN32
#include <windows.h>
#else
#define ANSI_COLOR_BLACK            "\x1b[30m"
#define ANSI_COLOR_RED              "\x1b[31m"
#define ANSI_COLOR_GREEN            "\x1b[32m"
#define ANSI_COLOR_YELLOW           "\x1b[33m"
#define ANSI_COLOR_BLUE             "\x1b[34m"
#define ANSI_COLOR_MAGENTA          "\x1b[35m"
#define ANSI_COLOR_CYAN             "\x1b[36m"
#define ANSI_COLOR_WHITE            "\x1b[37m"

#define ANSI_BACKGROUND_BLACK       "\x1b[40m"
#define ANSI_BACKGROUND_RED         "\x1b[41m"
#define ANSI_BACKGROUND_GREEN       "\x1b[42m"
#define ANSI_BACKGROUND_YELLOW      "\x1b[43m"
#define ANSI_BACKGROUND_BLUE        "\x1b[44m"
#define ANSI_BACKGROUND_MAGENTA     "\x1b[45m"
#define ANSI_BACKGROUND_CYAN        "\x1b[46m"
#define ANSI_BACKGROUND_WHITE       "\x1b[47m"

#define ANSI_STYLE_BOLD             "\x1b[1m"
#define ANSI_STYLE_ITALIC           "\x1b[3m"
#define ANSI_STYLE_UNDERLINE        "\x1b[4m"
#endif

int main() 
{
    char* text_dizisi = "The LIS2HH12 is an ultra-low-power highperformance three-axis linear accelerometer belonging to the pico family. \
The LIS2HH12 has full scales of 2g/4g/8g and is capable of measuring accelerations with output data rates from 10 Hz to 800 Hz. \
The self-test capability allows the user to check the functioning of the sensor in the final application. The LIS2HH12 has an \
integrated first-in, first-out (FIFO) buffer allowing the user to store data in order to limit intervention by the host processor. \
The LIS2HH12 is available in a small thin plastic land grid array package (LGA) and it is guaranteed to operate over an extended \
temperature range from -40 degree Celsius to +85 degree Celsius \0";

#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitleA("MFB SEARCH ENGINE");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
#else //This one works under Linux
    printf(ANSI_COLOR_GREEN);
#endif

    printf("kelime :");
    const char find_this_text[1000];

    scanf(" %49[^\n]", &find_this_text); // Reading a string with spaces using %[^\n]

    printf("girdiginiz kelime : %s\n",find_this_text);

    char* temp;
    temp = text_dizisi;
    while (*temp) {
        if (strncmp(temp, find_this_text, strlen(find_this_text)) == 0) 
        {
            #ifdef _WIN32
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            #else
            printf(ANSI_COLOR_RED);
            #endif

            for(int i=0;i<strlen(find_this_text);i++)
            {
                printf("%c",*(temp+i));    
            }
            temp=temp+strlen(find_this_text);
        }
        else
        {
            #ifdef _WIN32
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            #else
            printf(ANSI_COLOR_BLUE);
            #endif

            printf("%c",*(temp));
            temp++;
        }
        
    }

#ifdef _WIN32
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#else //This one works under Linux
    printf("\x1b[0m"); // Reset text color to default for linux
#endif

    getchar(); // Wait for Enter key
    getchar(); // Wait for Enter key
    return 0;
}
