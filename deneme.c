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
