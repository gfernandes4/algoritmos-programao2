#include <stdio.h>
#include <stdlib.h>
#define aloc (celula *)calloc(1, sizeof(celula));

struct celula
{
    int valor;
    struct celula *prox;
};

void empilha(celula *&lst, int val)
{
    celula *novo = aloc;
    novo->prox = lst;
    novo->valor = val;
    // atualiza a referencia do inicio da lista
    lst = novo;
}

celula desempilha(celula *&lst)
{
    celula *aux = lst;
    lst = lst->prox;
    celula tira = *aux;
    free(aux);
    return tira;
}

int main()
{
    celula *lista = NULL;
    for (int i = 0; i < 10; i++)
    {
        empilha(lista, i);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", desempilha(lista).valor);
    }
    printf("\n");
}