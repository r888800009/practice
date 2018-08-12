#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    long long a, b;

    while (scanf("%lld %lld", &a, &b) != EOF) {
    
        a -= b;

        if (a < 0)
            a *= -1;

        printf("%lld\n", a);
    }
    return 0;
}
