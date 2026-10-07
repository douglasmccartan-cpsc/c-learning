#include <stdio.h>

void swap(int *x, int *y){
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main (void){

    int a = 1;
    int b = 2;

    swap(&a, &b);

    printf("%d,\n%d\n", a, b);

    return 0;
}