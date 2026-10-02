#include <stdio.h>

int main(void){

    int a, b;

    puts("input a number between 1 and 10");
    // this loads an input from the terminal and places it inside "b"
    scanf("%d", &b);

    if(b>10 || b<1){
        puts("error out of range");
        // returning 1 tells the OS there was an error
        return 1;
    }

    for(a=1; a<=b; a++){
        // prints a - b values with a new line and repeats untill a = b
        printf("%d - %d\n", a, b);

    }

    return 0;
}