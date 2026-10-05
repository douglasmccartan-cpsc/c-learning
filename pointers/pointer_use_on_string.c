#include <stdio.h>

int main(void){

    char hello[] = "Hello world";
    char *ptr;

    ptr = hello;

    for(int i = 0; ptr[i] != '\0'; i++){

        printf("%c is located in %p\n", hello[i], (void*)(ptr+i));

    }
    
    return 0;
}