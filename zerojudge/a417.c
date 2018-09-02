#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define n_max 100
#define num_len 5

char brush[num_len + 1];
void paint(char *buffer) 
{
    memcpy(buffer, brush, num_len); 
    //increase
    int index = num_len - 1;
    brush[index]++;
    while (index > 0 && brush[index] > '9') {
        brush[index--] = '0';
        if (brush[index] == ' ')
            brush[index] = '1';
        else
            brush[index]++;
    }  
}

int main(int argc, char *argv[])
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%d %d", &n, &m); 

        //spiral * strlen  + ln
        int line = n * num_len + 1;
        int size = n * line;
        char buffer[size + 1];         
        buffer[size] = '\0';

        //println
        for (int cursor = line - 1; cursor < size; cursor += line)
            buffer[cursor] = '\n';

        //init brash
        strcpy(brush, "    1");

        //spiral
        int x, y;
        int times = 0, lineLength = n; 
        /*
         * Spiral rotate two times
         * If times == 2 then decrease line length,
         * 1 is first time, 0 is second time
         * that is characteristics of spiral
         */
      
        //direction
         int addX, addY;
         m--;
         if (m)//counterclockwise
             addX = 0, addY =1;
         else //clockwise
             addX = 1, addY =0;
         x = -addX, y = -addY;
        while (lineLength > 0) {
            for (int j = 0; j < lineLength; j++) {
                x += addX, y += addY; 
                paint(buffer + y * line + x * num_len);
            }

            if ((times = !times))
                lineLength--;

            //rotate
            int tmpX, tmpY;
            if (m)//counterclockwise 90deg
                tmpX = addY, tmpY = -addX;
            else  //clockwise -90dag
                tmpX = -addY, tmpY = addX;
            addX = tmpX, addY = tmpY;
        }
                
        //print
        write(STDOUT_FILENO, buffer, size);
       
    }
    return 0;
}
