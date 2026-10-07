#include <stdio.h>
#include <string.h>

int main(void){

    struct date{
        int day;
        int month;
        int year;
    };

    struct info {
        struct date birthday;
        float height;
        char name[25];
    } me;

    me.birthday.day = 8;
    me.birthday.month = 1;
    me.birthday.year = 2003;
    me.height = 6.3;
    strcpy(me.name, "Dougie");

    printf("\nMy birthday is %d.%d.%d\nMy height is: %0.2ffeet\nMy name is %s.\n", 
        me.birthday.day, 
        me.birthday.month, 
        me.birthday.year, 
        me.height, 
        me.name);
    
    struct info you = {
        {9, 8, 2007},
        5.6,
        "Yvette"
        };

    printf("My birthday is %d.%d.%d\nMy height is: %0.2ffeet\nMy name is %s.\n", 
        you.birthday.day, 
        you.birthday.month, 
        you.birthday.year, 
        you.height, 
        you.name);
    return 0;
}