/*
In C, macros are a way to perform textual substitution in the code before compilation, and they don't directly support passing arguments by reference.
However, you can use pointers to achieve a similar effect. Here's an example:
In this example, the UPDATE_VARIABLE macro takes a variable var as an argument and uses a do-while loop to avoid issues with semicolon placement 
when the macro is used in an if statement or other control flow structures. Inside the loop, you can perform calculations and then update the variable.

Keep in mind that using macros for such purposes can make your code harder to read and maintain. It's often preferable to use inline functions or 
regular functions when possible.
*/
#include <stdio.h>

#define POSITION_SHIFT(var,shift) do { \
                                int new_value = var<<shift; \
                                var = new_value; \
                              } while(0)

int main() {
    int myVariable = 8;

    printf("Before: %d\n", myVariable);

    POSITION_SHIFT(myVariable,2);

    printf("After: %d\n", myVariable);

    return 0;
}
