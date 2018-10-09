#include <stdio.h>

void space(int n) 
{
    for (int i = 0; i < n - 1; i++)
        printf("\t");
    n--;
}

void pascal(int n) 
{
    int triangle[n][n], count = 0;
    while (n > 0) {
        space(n);    
        int x = count, y = 0;
        while (x >= 0) {
            if (x - 1 >= 0 && y - 1 >= 0)
                triangle[x][y] = triangle[x - 1][y] + triangle[x][y - 1];
            else
                triangle[x][y] = 1;
            printf("%d\t\t", triangle[x][y]);
            x--, y++;
        }
        printf("\n");
        n--, count++;
    }
}

int main() 
{
    pascal(7);
    return 0;
}        
