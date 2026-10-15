#include <stdio.h>
#include <stdint.h>


volatile uint32_t FAKE_MODER = 0; // pin mode: 2 bits per pin
volatile uint32_t FAKE_ODR = 0;  // output data: 1 bit per pin

#define LED_PIN 5
#define LED_MODE_POS (LED_PIN * 2)
#define LED_MODE_MSK (3u << LED_MODE_POS)

#define LED2_PIN 0
#define LED2_MODE_POS (LED2_PIN * 2)
#define LED2_MODE_MSK (3u << LED2_MODE_POS)

void reg_set(volatile uint32_t *reg, uint8_t n){
    *reg |= (1u << n);
}

void reg_clear(volatile uint32_t *reg, uint8_t n){
    *reg &= ~(1u << n);
}

void reg_toggle(volatile uint32_t *reg, uint8_t n){
    *reg ^= (1u << n);
}

int reg_is_set(volatile uint32_t *reg, uint8_t n){
    return((*reg & (1u << n)) != 0);
}

void reg_write_field(volatile uint32_t *reg, uint32_t mask, uint8_t pos, uint32_t value){

    uint32_t new_bits = (value << pos) & mask;  // new bits will have the value input in correct position trimmed by mask

    uint32_t temp = *reg; // a temporary field so reg is never cleared
    temp &= ~mask;  // clear the temporary field
    temp |= new_bits;  // OR in the new trimmed bits
    *reg = temp;  // re-write reg to store new bits
}

uint32_t reg_read_field(uint32_t reg, uint32_t mask, uint8_t pos) {
    return((reg & mask) >> pos);
}

int main(void) {
    FAKE_MODER = 0xFFFFFFFF;
    FAKE_ODR = 0x00000000;
    
    reg_write_field(&FAKE_MODER, LED_MODE_MSK, LED_MODE_POS, 1);
    printf("0x%02X\n", reg_read_field(FAKE_MODER, LED_MODE_MSK, LED_MODE_POS));
    printf("0x%08X\n", FAKE_MODER);

    reg_write_field(&FAKE_MODER, LED_MODE_MSK, LED_MODE_POS, 3);
    printf("0x%02X\n", reg_read_field(FAKE_MODER, LED_MODE_MSK, LED_MODE_POS));
    printf("0x%08X\n", FAKE_MODER);

    reg_write_field(&FAKE_MODER, LED_MODE_MSK, LED_MODE_POS, 0);
    printf("0x%02X\n", reg_read_field(FAKE_MODER, LED_MODE_MSK, LED_MODE_POS));
    printf("0x%08X\n", FAKE_MODER);

    reg_write_field(&FAKE_MODER, LED_MODE_MSK, LED_MODE_POS, 7);
    printf("0x%02X\n", reg_read_field(FAKE_MODER, LED_MODE_MSK, LED_MODE_POS));
    printf("0x%08X\n", FAKE_MODER);

    for(int i = 0; i < 6; i ++){

        reg_toggle(&FAKE_ODR, LED_PIN); // toggle LED on and off
        printf("%d\n", reg_is_set(&FAKE_ODR, LED_PIN)); // 1 means LED on
        printf("0x%08X\n", FAKE_ODR); 

    }

    reg_set(&FAKE_ODR, LED_PIN);
    reg_set(&FAKE_ODR, 0);

    printf("%d\n", reg_is_set(&FAKE_ODR, LED_PIN)); // 1 means LED on
    printf("0x%08X\n", FAKE_ODR);
    printf("%d\n", reg_is_set(&FAKE_ODR, LED2_PIN)); // 1 means LED on
    printf("0x%08X\n", FAKE_ODR);

    reg_write_field(&FAKE_MODER, LED_MODE_MSK, LED_MODE_POS, 1);
    reg_write_field(&FAKE_MODER, LED2_MODE_MSK, LED2_MODE_POS, 1);

    printf("0x%02X\n", reg_read_field(FAKE_MODER, LED_MODE_MSK, LED_MODE_POS));
    printf("0x%02X\n", reg_read_field(FAKE_MODER, LED2_MODE_MSK, LED2_MODE_POS));
    printf("0x%08X\n", FAKE_MODER);

    reg_clear(&FAKE_ODR, 0);
    reg_write_field(&FAKE_MODER, LED2_MODE_MSK, LED2_MODE_POS, 0);

    printf("%d\n", reg_is_set(&FAKE_ODR, LED_PIN)); // 1 means LED on
    printf("0x%08X\n", FAKE_ODR);
    printf("%d\n", reg_is_set(&FAKE_ODR, LED2_PIN)); // 1 means LED on
    printf("0x%08X\n", FAKE_ODR);

    printf("0x%02X\n", reg_read_field(FAKE_MODER, LED_MODE_MSK, LED_MODE_POS));
    printf("0x%02X\n", reg_read_field(FAKE_MODER, LED2_MODE_MSK, LED2_MODE_POS));
    printf("0x%08X\n", FAKE_MODER);

    return 0;
}