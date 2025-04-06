#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    struct node* raiz;
    int key;

    printf("Vamos criar uma arvore binaria!\n");
    printf("Digite o valor numerico da raiz da arvore\n");

    if(scanf("%d", &key) == 1)
        raiz = nodeCreate(key);
    else
        return -1;

    printf("Digite agora os proximos valores numericos da arvore\n");
    printf("Caso queira finalizar o programa digite qualquer caractere\n");

    while(scanf("%d", &key) == 1)
    {
        binary(raiz, key, raiz->dad);
        printf("Digite a chave para inserir a arvore binaria:\n");
    }

    printTreePreOrder(raiz);
    destroyTree(raiz);

    return 0;
}
