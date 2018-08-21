#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n,drop;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &drop);
            printf("%d ", i);
        }    
        putchar('\b');
        putchar('\n');
    } 
    return 0;
}
