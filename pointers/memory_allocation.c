#include <stdio.h>
#include <stdlib.h>

int main(void){

    size_t count = 0;
    size_t capacity = 4;
    int *num_list = malloc(sizeof(int)*capacity); // allocate memory for a num_list array

    // if there is no available memory throw back an error
    if (num_list == NULL){

        puts("ERROR: could not allocate memory");
        free(num_list);
        return 1;

    }

    int value;

    puts("Input '-1' to end.");

    // while an input is a number and not -1 repeat
    while (scanf("%d", &value) == 1 && value != -1){
        // increases size of array if array is full
        if(count == capacity){

            size_t new_capacity = capacity*2;
            int *temporary = realloc(num_list, sizeof(int)*new_capacity);  // use a temporary pointer so that if there is no space the num_list still stays where it was before instead of 'NULL'

            if (temporary == NULL){

                puts("ERROR could not reallocate memory");
                free(num_list);
                return 1;

            }

            num_list = temporary;
            capacity = new_capacity;

            puts("increased memory allocation");
        }

        num_list[count] = value;
        count++;

    }

    // loop through num list array printing the numbers stored and where
    int sum = 0;
    for (int *ptr = num_list; ptr < num_list + count; ptr++){

        printf("%d at %p,\n", *ptr, (void*)ptr);

        sum += *ptr;
    }

    printf("sum = %d\n", sum);

    if(count == 0){
        puts("average = 0");
        free(num_list);
        return 0;
    }

    // gives a sum and average of numbers in array
    float average = (float)sum/count;
    printf("average = %.2f\n", average);

    free(num_list);
    num_list = NULL;
    return 0;

}