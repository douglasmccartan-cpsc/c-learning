#include <stdio.h>
#include <stdint.h>

typedef union {
    uint8_t raw;
    struct {
        uint8_t enable : 1;
        uint8_t speed : 2;
        uint8_t int_en : 1;
        uint8_t error : 1;
        uint8_t ready : 1;
        uint8_t reserved : 2;
    } bits;
} ControlReg;

char *binString(unsigned short n){
    static char bin[9];

    for(int i = 0; i < 8; i++){
        bin[i] = n & 0x80 ? '1' : '0';
        n <<= 1;
    }

    bin[8] = '\0';

        return (bin);
}

int main(void) {
    ControlReg reg = {.raw = 0};

    reg.bits.enable = 1;
    reg.bits.speed = 2;
    reg.bits.int_en = 1;
    // reg.bits.speed = 4; | this sets speed to 0 as 4 is two large to fit in a two bit space

    printf("raw = 0x%02X\n", reg.raw);
    printf("raw = bin:%s\n", binString(reg.raw));

    reg.raw = 0x30;

    // sets error and ready flags
    printf("raw = 0x%02X\n", reg.raw);
    printf("raw = bin:%s\n", binString(reg.raw));

    printf("size of ControlReg: %zu\n", sizeof(ControlReg));

    return 0;

}