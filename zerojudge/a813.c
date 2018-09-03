#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t look(uint32_t *buffer,int direction, uint32_t *last, uint32_t high) {
    uint64_t result = 0, lastMin = 0;
    if (buffer == last)
        return 0;
    
    buffer += direction;  
    while (buffer != last + direction) {
        if (*buffer > high)
            return ++result;

        if (*buffer >= lastMin)
            result++, lastMin = *buffer;

        buffer += direction;  
    } 
    return result;
}

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    uint32_t high[n];
    uint64_t result = 0; 

    for (int i = 0;i < n; i++) 
        scanf("%d", high + i);

    for (int i = 0; i < n; i++) {
        //select to end 
        result += look(high + i, 1, high + n - 1, high[i]);    
        //select to first
        result += look(high + i, -1, high, high[i]);    
    }

    printf("%lu\n", result);

    return 0;
}
