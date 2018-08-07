#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int w = 60;
    int h = 30;
    
    float include_w = 20;
    float include_h = 10;

    float pos_x = -10;
    float pos_y = 10;


    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (abs((x - pos_x) - w / 2 ) <= include_w / 2 * ((y - pos_y) / include_h) &&
                    (y - pos_y) <= include_h)
                putchar(' ');
            else 
                putchar('*');
        }
        putchar('\n');
    }
    return 0;
}
