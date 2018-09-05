#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstdint>
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

int main(int argc, char *argv[])
{
    int i, j = 0;
    i = read(STDIN_FILENO, buffer_in, buffer_size);
    cursor = 0; 
    uint64_t m = 0;
    while (i > 0) {
        if (buffer_in[j] == '\n') {
            m %= 91;
            if (cursor + 4 >= buffer_size)
                    display();

                if (m >= 10) {
                    buffer_out[++cursor] = '0' + m / 10;
                    buffer_out[++cursor] = '0' + m % 10;
                } else 
                    buffer_out[++cursor] = '0' + m;

                buffer_out[++cursor] = '\n';
            m = 0;
        } else if ('0' <= buffer_in[j] && buffer_in[j] <= '9') {
            m = 10 * m + buffer_in[j] - '0';
            if (m > 1000000000000000000)  // log_10 2 ^ 64 = 19.26...
                m %= 91;
        }

        j++;
        if (j > i) 
            i = read(STDIN_FILENO, buffer_in, buffer_size), j = 0;
    }
    display();
    return 0;
}
