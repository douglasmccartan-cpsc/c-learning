#include <stdio.h>

char *binString(unsigned short n){
    static char bin[17];

    for(int i = 0; i < 16; i++){
        bin[i] = n & 0x8000 ? '1' : '0';
        n <<= 1;
    }

    bin[16] = '\0';

        return (bin);
}

int main(void){

    unsigned short a, b, c;

    a = 0xABCD;
    b  = 0xB0B0;
    printf("A: %04X - %s\n", a, binString(a));
    printf("B: %04X - %s\n", b, binString(b));

    c = a & b;
    printf("AND: %04X - %s\n", c, binString(c));

    c = a | b;
    printf("OR: %04X - %s\n", c, binString(c));

    c = a ^ b;
    printf("XOR: %04X - %s\n", c, binString(c));

    c = ~c;
    printf("!XOR: %04X - %s\n", c, binString(c));

    return 0;
}