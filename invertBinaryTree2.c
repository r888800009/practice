#include <stdio.h>
#include <stdlib.h>
typedef struct node node;
struct node {
    int data;
    node *l, *r;
};

typedef struct list list;
struct list {
    node *node;
    list *next;
};

node *invert(node *root)
{
    if (root == NULL)
        return NULL;
    node *temp = root->r; 
    root->r = invert(root->l);
    root->l = invert(temp);
    return root;
}

list *push(list *back, node *data) 
{   
    if (data == NULL)
        return back;

    list *result;
    result = (list *) malloc(sizeof(list));
    result->node = data;
    result->next = NULL;
    if (back == NULL)
        return result;
    else
        return back->next = result;
}

list *pop(list *front) 
{
    list *newFront = front->next;
    free(front); 
    return newFront;
} 

void printTree(node *root) 
{
    list *back  = push(NULL, root);
    list *front = back;
    int i = 0, j = 1;
    while (front != NULL) {
        root = front->node;
        back  = push(back, root->l);
        back  = push(back, root->r);
        printf("%3d", root->data);
        front = pop(front);
        if (++i >= j) {
            j = (j + 1) * 2 - 1;
            putchar('\n');
        }
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

    node *tree = (node *) malloc(sizeof(node) * size);
    for (i = 0; i < size; i++) {
        scanf("%d", &tree[i].data);
        int left = 2 * i + 1;
        if (left + 1 < size)
            tree[i].r = (tree[i].l = tree + left) + 1;
        else 
            tree[i].l = tree[i].r = NULL; 
    }
    printTree(tree);    
    
    printf("invert\n");
    tree = invert(tree);
    printTree(tree);    
    
    return 0;
}

