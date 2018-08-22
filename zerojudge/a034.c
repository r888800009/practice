#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define int_max 32
int main(int argc, char *argv[])
{

    uint32_t num;   
    char buffer[10 + 3]; //log_10 2^32
    while (scanf("%u", &num) != EOF) {
        int i = 0, shift = -1;
        
        while (!(num & (0x80000000 >> ++shift)) && int_max > shift); 
        
        for (;shift < int_max; i++, shift++) {
            if (num & (0x80000000 >> shift))
                buffer[i] = '1';
            else
                buffer[i] = '0';
        }
        buffer[i++] = '\0';
        puts(buffer);
    }

    return 0;
}

