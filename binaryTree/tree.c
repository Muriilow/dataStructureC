#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct node* nodeCreate(int key, struct node* dad)
{
    struct node* n = malloc(sizeof(struct node));

    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->dad = dad;

    return n;
}

struct node* nodeSearch(struct node* n, int key)
{
    if(n == NULL)
        return NULL;

    if(n->key == key)
        return n;

    if(n->key > key)
        return nodeSearch(n->left, key);

    return nodeSearch(n->right, key);
}

struct node* nodeInsert(struct node* n, int key, struct node* dad)
{
    struct node* temp;
    if(n == NULL)
    {
        n = nodeCreate(key, dad);
        return n;
    }

    if(n->key > key)
    {
        temp = nodeInsert(n->left, key, n);

        if(n->left == NULL)
            n->left = temp;

        return n->left;
    }

    temp = nodeInsert(n->right, key, n);

    if(n->right == NULL)
        n->right = temp;

    return n->right;
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

void nodeTransplant(struct node* u, struct node* v)
{
    if(u == u->dad->left)
        u->dad->left = v;
    else if(u == u->dad->right)
        u->dad->right = v;

    if(v != NULL)
        v->dad = u->dad;

}

/*Deleting node n at the tree*/
void nodeDelete(struct node* root, struct node* n)
{
    struct node* temp;

    if(n->left == NULL)
        nodeTransplant(n, n->right);
    else if(n->right == NULL)
        nodeTransplant(n, n->left);
    else
    {
        temp = findMin(n->right);
        if(temp->dad != n)
        {
            nodeTransplant(temp, temp->right);
            temp->right = n->right;
            temp->right->dad = n;
        }
        nodeTransplant(n, temp);
        temp->left = n->left;
        temp->left->dad = n;
    }
}
