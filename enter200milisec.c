#include <stdio.h>
#include <windows.h>

int main()
{
    while (1)
    {
        Sleep(200); // wait for 200milisec 
        keybd_event(VK_RETURN, 0, 0, 0); // press the Enter key
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0); // release the Enter key

        printf("enter ket hit. CTRL + C to stop program\n");
    }

    return 0;
}



