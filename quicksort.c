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
    int endIndex  = size - 1;
    int headIndex = 0;
    
    while (headIndex < endIndex)
    {   
        if (list[headIndex] > list[endIndex]) {
            swap(list + endIndex, list + endIndex - 1);
            if (endIndex - headIndex > 1)
                swap(list + endIndex, list + headIndex);
            endIndex--;
        } else {
            headIndex++;
        }
    }
    if (size > 2) {
        quicksort(list, endIndex);
        quicksort(list + endIndex + 1, size - (endIndex + 1));
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
