#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *l, *r;
    int data;
} node;

void paintTree(node *root, int deep, const char *prefix) 
{
    if (root == NULL)
        return;

    for (int i = 0; i < deep; ++i)
        printf(i == deep - 1 ? prefix : "   ");

    printf("%d\n", root->data);

    paintTree(root->l, deep + 1, "-L ");
    paintTree(root->r, deep + 1, "-R ");
}

node *newNode(int data, node *l, node *r)
{
    node *result = (node *) malloc(sizeof(node));
    result->data = data;
    result->l = l;
    result->r = r;

    return result;
}

void cutTree(node *root)
{
    if (root == NULL)
        return;

    cutTree(root->l);
    cutTree(root->r);
    free(root);
}

node *rotateLeft(node *root)
{
    if (root->r == NULL) {
        printf("What the NULL\n");
        return root;
    }
    node *result = root->r;
    root->r   = result->l;
    result->l = root;

    return result;
}

node *rotateRight(node *root)
{
    if (root->l == NULL) {
        printf("What the NULL\n");
        return root;
    }
    node *result = root->l;
    root->l = result->r;
    result->r = root;

    return result;
}

int main()
{
    node *tree = NULL;
    for (int i = 0; i < 10; ++i)
        tree = newNode(i , NULL, tree);
    paintTree(tree, 0, "");

    printf("rotateLeft\n");
    for (int i = 0; i < 5; ++i)
        tree = rotateLeft(tree);
    paintTree(tree, 0, "");

    printf("rotateRight\n");
    for (int i = 0; i < 2; ++i)
        tree->l = rotateRight(tree->l);
    paintTree(tree, 0, "");


    cutTree(tree);

    return 0;
}

