#include <stdio.h>
#include <stdlib.h>

int *invert(int tree[], int deep)
{
    int *newTree = (int *) malloc(sizeof(int) * ((1 << deep) - 1));
    for (int d = 1, i = 0 ; d <= deep; d++) {
        for (int j = (1 << d) - 2;i < (1 << d) - 1; j--)    
            newTree[j] = tree[i++];
    }   
    free(tree);
    return newTree;
}

void printTree(int tree[] , int deep) 
{
    for (int d = 1, i = 0 ; d <= deep; d++) {
        //print data
        while (i < (1 << d) - 1)    
            printf("%3d", tree[i++]); 
        putchar('\n');
    }
}

int main(int argc, char *argv[])
{
    
    int deep, i;
    printf("how is deep?");
    scanf("%d", &deep);
    
    //sum = 2^(k+1)-1
    int size = (1 << deep) - 1;
    printf("size is %d\n", size);

    int *tree = (int *) malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
        scanf("%d", tree + i);
    printTree(tree, deep);
    tree = invert(tree, deep);
    printf("invert\n");
    printTree(tree, deep);
    
    return 0;
}

