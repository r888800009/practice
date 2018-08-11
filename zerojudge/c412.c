#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n); 
    getchar();

    for (int i = 0; i < n; i++) {
        unsigned long long int o = 0;
        unsigned long long int w = 0, addW = 0;
        unsigned long long int a = 0, prevA = 0;
        unsigned long long int prevAdd = 0;
        char c;
        while ((c = getchar()) != '\n') {
            if (c == 'O') {
                unsigned long long int new_1 = addW * o;
                unsigned long long int addNew  = prevAdd + new_1;

                a += addNew;

                o++;
                w += addW;
                addW  = 0;

                prevA   = a; 
                prevAdd = addNew;
            } else if(c == 'w' && o > 0)
                addW++;
        }
        printf("%llu\n", a % 1000000007);

    }

    return 0;
}
