#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check(char c) 
{
    return ('A' <= c && c <= 'Z') ||
           ('a' <= c && c <= 'z');
}

int main(int argc, char *argv[])
{
    int count = 0;
    bool current  = false;
    char c;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            printf("%d\n", count);
            count = 0;
            current = false;
        } else if (check(c)) {
            if (!current) {
                current = true;
                count++;
            }
        } else {
            current = false;
        } 
    }

    return 0;
}
