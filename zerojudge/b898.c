#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define bigNumber_size 5567 // 100000/((log_10 2^64 )-1)
#define uint64_length 17    // ((log_10 2^64 )-1)

typedef struct uintbig_t {
    uint64_t big[bigNumber_size];
    int length;
} uintbig_t;

uintbig_t *keepBig(uintbig_t *big, uintbig_t *min)
{
    if (big->length < min->length)
       return min; 
    
    if (big->length > min->length)
       return big; 

    if (big->big[0] < min->big[0])
       return min; 

    return big;
}

void getBig(uintbig_t *num) {

}

void printBig(uintbig_t *num) {

}

int main(int argc, char *argv[])
{
    int n;
    uintbig_t  big1 = {0}, big2 = {0}; 
    uintbig_t *bigBig, *bigMin;
    
    bigBig = &big1;
    bigMin = &big2;

    scanf("%d", &n);
     
    for (int i = 0; i < n; i++) {
        getBig(bigBig);
        getBig(bigMin);
        bigBig = keepBig(bigBig, bigMin);
        getBig(bigMin);
        bigBig = keepBig(bigBig, bigMin);
        printBig(bigBig);
    }
    
    return 0;
}
