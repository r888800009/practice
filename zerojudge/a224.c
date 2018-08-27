#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char *argv[])
{   
    char str[1000 + 1];
    while (scanf("%s", str) != EOF) {
        int len = strlen(str);
        int chars[256] = {0};
        for (int i = 0; i < len; i++) 
            chars[(int) str[i]]++;

        int cardinal = 0;
        for (int i = 0; i < 'z' - 'a' + 1; i++) {
            if ((chars['a' + i] + chars['A' + i]) & 1) {
                if (len & 1) {
                    if (cardinal)
                        goto no;
                    else 
                        cardinal = 1;
                } else 
                    goto no;
            } 
        }
        puts("yes !");
        continue;
    no:
        puts("no...");
    }
    return 0;
}
