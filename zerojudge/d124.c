#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define buffer_size 32
int main(int argc, char *argv[])
{
    char buffer[buffer_size];
    int bufferlen, i = 0, counter = 0;
    bufferlen = read(STDIN_FILENO, buffer, buffer_size);

    while (bufferlen > 0) {
        char c = buffer[i++]; 
        if (c == '\n') {
            if (counter % 3)
                puts("no");
            else 
                puts("yes");
            counter = 0;
        } else if ('0' <= c || c <= '9') {
            counter += c - '0';
            if (counter >= 10)
                counter += -10 + 1;
        }

        if (i >= bufferlen) {
            bufferlen = read(STDIN_FILENO, buffer, buffer_size);
            i = 0;
        }
    }
        
    return 0;
}

