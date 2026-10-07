// swap to variables using pointers function

#include <stdio.h>

int main(void){
    int a = 1;
    int b = 2;
    int *point_a;
    int *point_b;
    int *point_temp;

    point_a = &a;
    point_b = &b;

    *point_temp = *point_a;
    *point_a = *point_b;
    *point_b = *point_temp;

    printf("%d,\n%d \n",a,b);

    return 0;
}