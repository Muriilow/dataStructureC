#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    struct node* raiz;
    struct node* nodo;
    int key;

    key = 0;
    nodo = NULL;
    raiz = NULL;

    printf("Vamos criar uma arvore binaria!\n");
    printf("Digite o valor numerico da raiz da arvore\n");

    if(scanf("%d", &key) == 1)
        raiz = nodeCreate(key, NULL);
    else
        return -1;

    printf("Digite agora os proximos valores numericos da arvore\n");
    printf("Caso queira finalizar o programa digite qualquer caractere\n");

    while(scanf("%d", &key) == 1)
    {
        nodeInsert(raiz, key, raiz->dad);
        printf("Digite a chave para inserir a arvore binaria:\n");
    }

    printTreeInOrder(raiz);
    printTreePreOrder(raiz);
    printTreePosOrder(raiz);

    getchar(); //Limpando buffer;

    printf("Agora digite um valor para procurar na arvore\n");

    if(scanf("%d", &key) == 1)
        nodo = nodeSearch(raiz, key);

    if(nodo != NULL)
        printf("O valor existe! %d\n", nodo->key);
    else
        printf("O valor nao existe :v");

    destroyTree(raiz);

    return 0;
}
