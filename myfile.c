#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int element1;
    char status;
} MyStruct;

MyStruct* foo() {
    MyStruct* ptr = malloc(sizeof(MyStruct));
    ptr->element1 = 42;
    ptr->status = 'A';
    return ptr;
}

int main() {
    MyStruct* ptr = foo();
    printf("element1 = %d, status = %c\n", ptr->element1, ptr->status);
    free(ptr);
    return 0;
}
