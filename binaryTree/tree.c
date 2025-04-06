#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct node* nodeCreate(int key)
{
    struct node* n = malloc(sizeof(struct node));

    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->dad = NULL;

    return n;
}

struct node* binary(struct node* n, int key, struct node* dad)
{
    if(n == NULL)
    {
        n = nodeCreate(key);
        n->dad = dad;

        if(dad->key > n->key)
            dad->left = n;

        else if(dad->key <= n->key)
            dad->right = n;

        return n;
    }

    if(n->key > key)
        return binary(n->left, key, n);


    return binary(n->right, key, n);
}

void printTreeInOrder(struct node* n)
{
    if(n == NULL)
        return;

    printTreeInOrder(n->left);

    printf("%d\n", n->key);

    printTreeInOrder(n->right);
}

void printTreePreOrder(struct node* n)
{
    if(n == NULL)
        return;

    printf("%d\n", n->key);

    printTreePreOrder(n->left);

    printTreePreOrder(n->right);
}

void printTreePosOrder(struct node* n)
{
    if(n == NULL)
        return;

    printTreePosOrder(n->left);

    printTreePosOrder(n->right);

    printf("%d\n", n->key);
}

struct node* findMin(struct node* n)
{
    if(n->left != NULL)
        return findMin(n->left);

    return n;
}

struct node* findMax(struct node* n)
{
    if(n->right != NULL)
        return findMax(n->right);

    return n;
}

void destroyTree(struct node* n)
{
    if(n->left != NULL)
        destroyTree(n->left);

    if(n->right != NULL)
        destroyTree(n->right);

    free(n);
    n = NULL;
}

/*Change the y node to the x node*/
struct node* leftRotation(struct node* x)
{
    struct node* y;

    y = x->right;
    x->right = y->left;
    
    if(y->left != NULL)
        y->left->dad = x;

    y->dad = x->dad;

    if(x == x->dad->left)
        x->dad->left = y;
    else
        x->dad->right = y;

    y->left = x;
    x->dad = y;

    return y;
}

struct node* rightRotation(struct node* x)
{
    struct node* y;

    y = x->left;
    x->left = y->right;
    
    if(y->right != NULL)
        y->right->dad = x;

    y->dad = x->dad;

    if(x == x->dad->left)
        x->dad->left = y;
    else
        x->dad->right = y;

    y->right = x;
    x->dad = y;

    return y;
}
