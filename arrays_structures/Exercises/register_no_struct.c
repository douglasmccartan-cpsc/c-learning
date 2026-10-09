#include <stdio.h>
#include <stdint.h>

#define ENABLE_POS 0
#define ENABLE_MSK (1u << ENABLE_POS)

#define SPEED_POS 1
#define SPEED_MSK (3u << SPEED_POS)

#define INT_EN_POS 3
#define INT_EN_MSK (1u << INT_EN_POS)

#define ERROR_POS 4
#define ERROR_MSK (1u << ERROR_POS)

#define READY_POS 5
#define READY_MSK (1u << READY_POS)

#define RESERVED_POS 6
#define RESERVED_MSK (3u << RESERVED_POS)

// a function to
void reg_set(uint8_t *reg_ptr, uint8_t mask){
    *reg_ptr |= mask;
}

void    reg_clear(uint8_t *reg_ptr, uint8_t mask){
    *reg_ptr &= ~mask;
}

int     reg_is_set(uint8_t reg, uint8_t mask){
    return (reg & mask) != 0;
}
void    reg_write_field(uint8_t *reg, uint8_t mask, uint8_t pos, uint8_t value){
     
}
uint8_t reg_read_field(uint8_t reg, uint8_t mask, uint8_t pos) { /* your code */ }

int main(void) {
    uint8_t reg = 0;

    reg_set(&reg, ENABLE_MSK);
    reg_set(&reg, SPEED_MSK);
    reg_set(&reg, INT_EN_MSK);
    reg_set(&reg, ERROR_MSK);
    reg_set(&reg, READY_MSK);
    reg_set(&reg, RESERVED_MSK);

    printf("is enable set? %d\n", reg_is_set(reg, ENABLE_MSK));
    printf("is speed set? %d\n",reg_is_set(reg, SPEED_MSK));
    printf("is int_en set? %d\n",reg_is_set(reg, INT_EN_MSK));
    printf("is error set? %d\n",reg_is_set(reg, ERROR_MSK));
    printf("is ready set? %d\n",reg_is_set(reg, READY_MSK));
    printf("is reserved set? %d\n",reg_is_set(reg, RESERVED_MSK));



    printf("A 0x%02X\n", reg);

    // add the rest of the test steps below

    return 0;
}