#include <stdio.h>
#include <stdlib.h>

#define UINT_MAX 2

typedef struct uintX {
    unsigned long long int i[UINT_MAX];
} uintX;

uintX uintSet0()
{
    uintX a
    for (int i = 0; i < UINT_MAX; i++)
        a.i[i] = 0;
    return a;
}

uintX uintXadd(uintX a, uintX b)
{
    
}

uintX uintXpp(uintX a)
{
    
}

uintX uintXtimes(uintx a, uintX b)
{

}

void uintXprint(uintX a)
{
    return a[0] % 1000000007;
}

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n); 
    getchar();

    for (int i = 0; i < n; i++) {
        uintX o = 0;
        uintX w = 0, addW = 0;
        uintX a = 0, prevA = 0;
        uintX prevAdd = 0;
        char c;
        while ((c = getchar()) != '\n') {
            if (c == 'O') {
                uintX new_1 = addW * o;
                uintX addNew  = prevAdd + new_1;

                a += addNew;

                o++;
                w += addW;
                addW  = uintXset0();

                prevA   = a; 
                prevAdd = addNew;
            } else if(c == 'w' && o > 0)
                addW = uintXpp(addW);
        }
        uintXprint(a);
    }

    return 0;
}
