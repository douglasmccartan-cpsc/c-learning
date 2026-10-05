#include <stdio.h>


int main(void){  // variables have types such as the listed below
    char a = 'D'; // char is a single character or byte 
    char hello[] = "Hello World"; // char[] holds an array of characters or bytes
    int number = 42; // int holds an intager
    float pie = 3.14; // float holds a floating point number up to 8 digits
    double long_decimal = 1.23456789; // double holds a floating point number up to 16 digits

    printf(
        "%c,\n%s,\n%d,\n%f,\n%f,\n%.2f\n", // each format typer must be the same as its variable
        a,
        hello,
        number,
        pie,
        long_decimal,
        long_decimal
    );
    return 0;
}