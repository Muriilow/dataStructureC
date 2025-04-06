#ifndef TREE_H_
#define TREE_H_

struct node
{
    int key;
    struct node *left;
    struct node *right;
    struct node *dad;
    void* value;
};


struct node* nodeCreate(int key);

struct node* binary(struct node* n, int key, struct node* dad);

void destroyTree(struct node* n);

struct node* findMin(struct node* n);

struct node* findMax(struct node* n);

struct node* leftRotation(struct node* x);

struct node* rightRotation(struct node* x);

void printTreeInOrder(struct node* n);

void printTreePreOrder(struct node* n);
    
void printTreePosOrder(struct node* n);

#endif
