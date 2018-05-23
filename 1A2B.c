#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N  100

int main(){ 
    char correct[N];
    char guess[N];
    scanf("%s", correct);
    scanf("%s", guess);
    
    int i, A = 0, B = 0, C = 0;
    for(int i = 0; i < strlen(correct); i++){
         if(correct[i] == guess[i]) A++;
    }  
    
    printf("%dA%dB", A, B);
    return 0;
}
