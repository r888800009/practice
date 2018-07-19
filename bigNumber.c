#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 1024
int strToIntArray(int *number, char *str, int intLimit) 
{
    int result = 0;
    char buffer[MAX];
    int i;
   
    sprintf(buffer, "%%%dd", intLimit);
    for (i = strlen(str) - intLimit; i >= 0; i -= intLimit) 
        sscanf(str + i, buffer, number + result++);
        
    if ((i += intLimit) > 0) {
        sprintf(buffer, "%%%dd", i);
        sscanf(str, buffer, number + result++);
    }
    
    return result; 
}

int main(int argc, char *argv[])
{
    int num1[MAX], num2[MAX];
    int num3[2 * MAX + 1] = {0};
    int size = 4; // log_2 10^(4 * 2) < 32
    int overflow = pow(10, size);
    char numStr1[MAX * size + 1], numStr2[MAX * size + 1];
    char buffer[MAX];
    int length1, length2;
    scanf("%s %s", numStr1, numStr2);
    //
    length1 = strToIntArray(num1, numStr1, size);
    length2 = strToIntArray(num2, numStr2, size);
    
    // 
    for (int x = 0; x < length1; x++) {
        for (int y = 0; y < length2; y++) {
            num3[x + y] += num1[x] * num2[y];
            if (num3[x + y] >= overflow) {
                num3[x + y + 1] += num3[x + y] / overflow;
                num3[x + y] %= overflow;
            }
        }
    }
    
    //
    sprintf(buffer, "%%0%dd,", size);
    int i = length1 + length2 - 2;
    if (num3[i + 1])
        i++;
    printf("%d,", num3[i--]);
    while (i >= 0)
        printf(buffer, num3[i--]); 
    printf("\b \n");
    
    return 0;
}

