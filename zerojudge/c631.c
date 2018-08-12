#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    unsigned n;
    scanf("%u", &n);
    
    getchar();
    char *data = malloc(n + 1);
    fread(data, 1, n, stdin);
    data[n] = '\0';

    unsigned left, right;

    while (scanf("%u %u", &left, &right) != EOF) {
        for (unsigned i = left - 1; i < right; i++) 
            putchar(data[i]);
        putchar('\n');
    }


    return 0;
}
