#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n); 
    getchar();

    for (int i = 0; i < n; i++) {
        unsigned long long int o = 0;
        unsigned long long int addW = 0;
        unsigned long long int a = 0;
        unsigned long long int addNew = 0;
        char c;
        while ((c = getchar()) != '\n') {
            if (c == 'O') {
                if (addW) {
                    addNew += addW * o;

                    if (addNew > 1000000007)
                        addNew -= 1000000007;
   
                    addW  = 0;
                }
                a += addNew;
                if (a > 1000000007)
                    a -= 1000000007;
                o++;
            } else if(c == 'w' && o > 0)
                addW++;
        }
        printf("%llu\n", a);

    }

    return 0;
}
