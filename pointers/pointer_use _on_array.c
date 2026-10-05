#include <stdio.h>

int main(void){

    int fib[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int *ptr;

    ptr = fib;  // & is not needed as the name of the array is the starting address of the array

    printf("First number = %d in address %p\n", *(ptr+0),(ptr+0));
    printf("Second number = %d in address %p\n", *(ptr+1),(ptr+1));
    printf("Third number = %d in address %p\n", *(ptr+2),(ptr+2));
    printf("Fourth number = %d in address %p\n", *(ptr+3),(ptr+3));
    printf("Fifth number = %d in address %p\n", *(ptr+4),(ptr+4));
    printf("Sixth number = %d in address %p\n", *(ptr+5),(ptr+5));
    printf("Seventh number = %d in address %p\n", *(ptr+6),(ptr+6));
    printf("Eighth number = %d in address %p\n", *(ptr+7),(ptr+7));



    return 0;
}