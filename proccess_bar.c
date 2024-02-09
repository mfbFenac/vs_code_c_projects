#include <stdio.h>
#include <unistd.h>

int progress_old = 0;
void progressBar(int progress)
{
    if(progress_old == 0)
    {
        printf("(");
        setCursorPosition(109,0);
        printf(")");
        //setCursorPosition(0,0);
    }

    if(progress - progress_old > 0)
    {
        for(int i=0;i<=(progress - progress_old);i++)
        {
            printf("=");
        }
    }
    else
    {
        setCursorPosition(progress+1,0);
        for(int i=0;i<=progress_old;i++)
        {
            printf(" ");
        }
    }
    
    setCursorPosition(110,0);
    printf("%%% d   ",progress);
    setCursorPosition(progress+1,0);
    progress_old = progress;
}

void setCursorPosition(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

// Delay function in seconds
void delaySeconds(unsigned int seconds) {
    sleep(seconds);
}

// Delay function in milliseconds
void delayMilliseconds(unsigned int milliseconds) {
    usleep(milliseconds * 1000); // usleep takes microseconds
}

void clearScreen() {
    printf("\033[2J"); // Clear screen escape sequence
    printf("\033[H");  // Move cursor to the top-left corner
}

int main() 
{   
    clearScreen();

    static int aralik = 1;
    for(int i=0;i<=100;i=i+aralik)
    {
        if(i == 100) aralik = -1;
        else if(i == 0) aralik = +1;
        progressBar(i);
        delayMilliseconds(20);
    }

    printf("\n");
    return 0;
}
