#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define buffer_size 1024
#define magic 1000000007 
int main(int argc, char *argv[])
{
    char buffer[buffer_size];
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
        int a = 0;
        int addNew = 0;

        char c;
        while (i > 0 && (c = buffer[j++]) != '\n') {
            if (c == 'O') {
                if (addW) {
                    addNew += addW * o;

                    if (addNew > magic)
                        addNew -= magic;
   
                    addW  = 0;
                }

                a += addNew;
                if (a > magic)
                    a -= magic;
                o++;
            } else if(c == 'w' && o > 0)
                addW++;

            if (j > i) {
                i = read(STDIN_FILENO, buffer, buffer_size);
                j = 0;
            }
        }
        printf("%d\n", a);
    }

    return 0;
}
