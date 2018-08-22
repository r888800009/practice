#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define url_length 100 + 1
#define url_num 10

int main(int argc, char *argv[])
{
    int n, max = 0;
    scanf("%d", &n);   
    char urls[url_num][url_length];
    int same = 0;

    for (int i = 1; i <= n; i++) {
        char getURL[url_length];
        unsigned char getRank;
        for (int j = 0; j < url_num; j++) {
            scanf("%s %hhu", getURL, &getRank); 
            if (getRank > max) {
                same = 0;
                max = getRank;
                memcpy(urls[same++], getURL, url_length);
            } else if (getRank == max) {
                memcpy(urls[same++], getURL, url_length);
            }

        }
        printf("Case #%d:\n", i);
        for (int j = 0; j < same; j++)
            puts(urls[j]);

        max = 0;
    }

    return 0;
}
