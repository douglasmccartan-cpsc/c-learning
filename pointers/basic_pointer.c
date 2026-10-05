#include <stdio.h>

int main(void){
    int num;  // initialize number
    int *ptr;  // initialize pointer

    num = 42;  // assign number = 42
    ptr = &num;  // assigns pointer to the memory address of num

    printf("The value stored in num is %d\n", num);
    printf("The address of num is %p\n", &num);
    printf("The address of ptr is %p\n",ptr);
    printf("The value stored in memory address %p is %d\n",ptr,*ptr);

    *ptr = 1;

    printf("The value stored in memory address %p is %d\n",ptr,*ptr);   

    return 0;
}