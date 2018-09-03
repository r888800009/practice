#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char buffer[32];
    while (fgets(buffer, 32, stdin) != NULL) {
        union color {
            int int32;      
            unsigned char int8[4]; 
        } color = {0};

        if (buffer[0] == '#') {
            sscanf(buffer + 1,"%x", &color.int32);
            printf("%hhu %hhu %hhu", color.int8[2], color.int8[1], color.int8[0]);
        } else { 
            sscanf(buffer, "%hhu %hhu %hhu", color.int8 + 2, color.int8 + 1, color.int8 + 0);
            printf("#%06X", color.int32);
        }
        putchar('\n');
    } 
    return 0;
}
