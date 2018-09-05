#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define buffer_size 2048
char buffer_in[buffer_size];
char buffer_out[buffer_size];
int cursor;

void display() 
{
   write(STDOUT_FILENO, buffer_out, cursor + 1); 
   cursor = 0;
}

void putInBuffer(int num)
{
    if (cursor + 4 >= buffer_size)
        display();

    if (num >= 10) {
        buffer_out[++cursor] = '0' + num / 10;
        buffer_out[++cursor] = '0' + num % 10;
    } else 
        buffer_out[++cursor] = '0' + num;

    buffer_out[++cursor] = '\n';
}

int main(int argc, char *argv[])
{
    int i, j = 0;
    i = read(STDIN_FILENO, buffer_in, buffer_size);
    cursor = 0; 
    int m = 0;
    while (i > 0) {
        if (buffer_in[j] == '\n')
            putInBuffer(m), m = 0;
        else if (isdigit(buffer_in[j])) {
            m = 10 * m + buffer_in[j] - '0';
            while (m >= 91) 
                m -= 91;
        }

        j++;
        if (j > i) 
            i = read(STDIN_FILENO, buffer_in, buffer_size), j = 0;
    }
    display();
    return 0;
}
