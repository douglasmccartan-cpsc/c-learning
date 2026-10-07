#include <stdio.h>

void double_all(int *arr, int length) {
    
    for(int i = 0; i<length; i++){
        *arr *= 2;
        arr ++;
    }
}

int main(void) {
    int numbers[5] = {1, 2, 3, 4, 5};

    double_all(numbers, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}