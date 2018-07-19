#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int *list, int size) 
{
    int *endPtr  = list + size - 1;
    int *headPtr = list;
    
    while (headPtr < endPtr)
    {   
        if (*headPtr > *endPtr) {
            swap(endPtr, endPtr - 1);
            if (endPtr - headPtr > 1)
                swap(endPtr, headPtr);
            endPtr--;
        } else {
            headPtr++;
        }
    }
    if (size > 2) {
        quicksort(list, endPtr - list);
        quicksort(endPtr + 1, size - (endPtr - list + 1));
    }
}

int main(int argc, char *argv[])
{
    int n;
    int *list;
    printf("n: ");
    scanf("%d", &n);
    list = (int *)  malloc(n * sizeof(int));
    printf("Data Entry:\n");

    for (int i = 0; i < n; i++) 
        scanf("%d", list + i);
  
    quicksort(list, n);

    printf("Data Sort:\n");
    for (int i = 0; i < n; i++) 
        printf("%d\n", list[i]);

    return 0;
}
