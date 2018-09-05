#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#define buffer_size 1024
#define magic 1000000007 
#define print_size 10
char buffer[buffer_size];
char writeBuffer[buffer_size];
int  writeIndex = 0;

void print()
{
    write(STDOUT_FILENO, writeBuffer, writeIndex);
    writeIndex = 0;
}

int main(int argc, char *argv[])
{
    int i = 1;
    i = read(STDIN_FILENO, buffer, buffer_size);
    
    if (i <= 0)
        return 0;

    int j = 0; 
    int n;
    sscanf(buffer, "%d", &n);
    while (buffer[j++] != '\n');

    for (int k = 0; k < n; k++) {
        int o = 0;
        int addW = 0;
        uint64_t a = 0;
        int addNew = 0;

        char c;
        while ((c = buffer[j++]) != '\n') {
            if (c == 'O') {
                if (addW) {
                    addNew += addW * o;

                    if (addNew > magic)
                        addNew -= magic;
   
                    addW  = 0;
                }

                a += addNew;
                if (a > 1000000000000000000) //log_10 2^64
                    a %= magic;
                o++;
            } else if(o > 0 && c == 'w')
                addW++;

            if (j > i) {
                i = read(STDIN_FILENO, buffer, buffer_size);
                if (i <= 0) 
                    break;
                j = 0;
            }
        }

        a %= magic;
        //add to buffer
        if (writeIndex + print_size > buffer_size)
            print();

        char intBuffer[print_size];
        int index = 0;
        intBuffer[print_size - 1 - (index++)] = '\n';
        do {
            intBuffer[print_size - 1 - (index++)] = '0' + a % 10;
        } while ((a /= 10 ) > 0);
        memmove(writeBuffer + writeIndex, intBuffer + print_size - index, index);
        writeIndex += index;
    }
    print();

    return 0;
}
