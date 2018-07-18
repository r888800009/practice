#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 256

int strToIntArray(int *number, char *str, int intLimit) 
{
    int length = strlen(str);
    int result = 0;
    char buffer[MAX];
    int i;
   
    sprintf(buffer, "%%%dd", intLimit);
    for (i = length - intLimit; i >= 0; i -= intLimit) {
        sscanf(str + i, buffer, number++);
        result++;
    }
    if (i && i + intLimit > 0) {
        i += intLimit;
        sprintf(buffer, "%%%dd", i);
        sscanf(str, buffer, number++);
        result++;
    }
    
    return result; 
}

int main(int argc, char *argv[])
{
    int nums[MAX][MAX];
    int num1[MAX], num2[MAX];
    int num3[2 * MAX + 1] = {0};
    int size = 4; // log_2 10^(4 * 2) < 32
    int overflow = pow(10, size);
    char numStr1[MAX * size], numStr2[MAX * size];
    int num3Max = 0;

    int length1, length2;
    scanf("%s %s", numStr1, numStr2);
    //
    length1 = strToIntArray(num1, numStr1, size);
    length2 = strToIntArray(num2, numStr2, size);

    //
    for (int x = 0; x < length1; x++)
        for (int y = 0; y < length2; y++) 
            nums[x][y] = num1[x] * num2[y];
     
    // 
    for (int x = 0; x < length1; x++) {
        for (int y = 0; y < length2; y++) {
            num3[x + y] += nums[x][y];
            if (num3Max < x + y)
                num3Max = x + y;
            if (num3[x + y] >= overflow) {
                num3[x + y + 1] += num3[x + y] / overflow;
                num3[x + y] = num3[x + y] % overflow;
                if (num3Max < x + y + 1)
                    num3Max = x + y + 1;
            }
        }
    }
    
    //
    int i = num3Max;
    printf("%d,", num3[i--]);
    for(; i >= 0; i--)
        printf("%04d ", num3[i]); 
    putchar('\n');
    
    return 0;
}

