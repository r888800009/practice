#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// dont optimize this code
// gcc -O0 -o cpu cpu.c
int main(int argc, char *argv[])
{
    // start time measurement
    clock_t start = clock();

    // do some work
    // we do 3G times of memory access
    long long int len = (long long) 1000 * 1000 * 1000 * 3;
    int a = 1;
    for (long long int i = 0; i < len; i++)
      a = 1;

    // end time measurement
    clock_t end = clock();
    printf("time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
