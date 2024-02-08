#include <stdio.h>
#include "main.h"
#include "adding.h"
#include "subtracting.h"
#include "multiplying.h"
#include "dividing.h"

struct result result1;

int main() 
{
    int x = 5;
    int y = 2;

    result1.addition = addXY(x,y);
    printf("result1.addition: %f\n",result1.addition);

    result1.subtraction = subXY(x,y);
    printf("result1.subtraction: %f\n",result1.subtraction);

    result1.multiplication = mulXY(x,y);
    printf("result1.multiplication: %f\n",result1.multiplication);

    result1.division = divXY(x,y);
    printf("result1.division: %f\n",result1.division);

    return 0;
}
