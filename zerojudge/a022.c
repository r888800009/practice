#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char str[1001];
    while (scanf("%s", str) != EOF) {
        int len = strlen(str);
        for (int i = 0; i < len / 2;i++) {
            if (str[i] != str[len - 1 - i]) {
                puts("no");
                goto next;
            }
        }
        puts("yes");
        next:;
    }
   
    return 0;
}
