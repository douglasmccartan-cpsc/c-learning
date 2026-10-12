#include <stdio.h>
#include <stdint.h>

void bit_set(uint32_t *value, uint8_t n){
    *value |= (1u << n);
}

void bit_clear(uint32_t *value, uint8_t n){
    *value &= ~(1u << n);
}

void bit_toggle(uint32_t *value, uint8_t n){
    *value ^= (1u << n);
}

int bit_is_set(uint32_t value, uint8_t n){
    return ((value & (1u << n)) != 0);
}

int main(void){
    uint32_t a = 0;

    bit_set(&a, 0);

    printf("Expect: 0x00000001 | Result: 0x%08X\n", (unsigned)a);

    bit_clear(&a, 0);

    printf("Expect: 0x00000000 | Result: 0x%08X\n", (unsigned)a);

    bit_toggle(&a, 0);

    printf("Expect: 0x00000001 | Result: 0x%08X\n", (unsigned)a);

    printf("Expect: 1 | Result: %d\n", bit_is_set(a, 0));


    for(int i = 0; i < 32; i++){
        bit_set(&a, i);

        printf("Result: 0x%08X\n", (unsigned)a);

        bit_clear(&a, i);

        printf("Result: 0x%08X\n", (unsigned)a);

        bit_toggle(&a, i);

        printf("Result: 0x%08X\n", (unsigned)a);

        printf("Result: %d\n", bit_is_set(a, i));

        bit_clear(&a, i);
    }
    return 0;
}