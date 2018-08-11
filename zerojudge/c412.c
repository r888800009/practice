#include <stdio.h>
#include <stdlib.h>

long long int combin(int a, int b) 
{
    if (a - b < 0)
        return 0;

    long long int result = 1;
    for (int i = a; i > a - b; i--)
        result *= i;  

    for (int i = b; i > b; i--)
        result /= i;

    return result;
}

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n); 
    getchar();

    for (int i = 0; i < n; i++) {
        int o = 0;
        int w = 0, wtmp = 0;
        char c;
        while ((c = getchar()) != '\n') {
            if (c == 'O') {
                o++;
                w += wtmp;
                wtmp = 0;
            } else if(c == 'w' && o > 0)
                wtmp++;
        }
        printf("%d\n", (o - 1) >=1 ? ((o - 1) * w) % 1000000007 : 0);

    }

    return 0;
}
