#include <stdio.h>
#include "text_color.h"

struct tx tx = {
    {"\x1b[0m","\x1b[1m","\x1b[2m","\x1b[4m","\x1b[5m","\x1b[7m","\x1b[8m"},
    {"\x1b[30m","\x1b[31m","\x1b[32m","\x1b[33m","\x1b[34m","\x1b[35m","\x1b[36m","\x1b[37m"},
    {"\x1b[40m","\x1b[41m","\x1b[42m","\x1b[43m","\x1b[44m","\x1b[45m","\x1b[46m","\x1b[47m"}
};

int main() 
{
    printf("%s%s%s This is black text. \x1b[0m \n",tx.format.bright,tx.bgcolor.white,tx.color.black);
    printf("%s%s%s This is black text. \x1b[0m \n",tx.format.underscore,tx.bgcolor.white,tx.color.black);
    printf("%s%s This is red text. \x1b[0m \n",tx.color.red,tx.bgcolor.black);
    printf("%s This is green text. \x1b[0m \n",tx.color.green);
    printf("%s This is yellow text. \x1b[0m \n",tx.color.yellow);
    printf("%s%s This is blue text. \x1b[0m \n",tx.color.blue,tx.format.bright);
    printf("%s This is magenta text. \x1b[0m \n",tx.color.magenta);

    return 0;
}
