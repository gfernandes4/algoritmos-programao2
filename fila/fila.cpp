#include <stdio.h>
#include <stdlib.h>
#define aloc (celula *)calloc(1, sizeof(celula));

struct celula
{
    int valor;
    struct celula *prox;
};

void enfilera(celula **lst, int val)
{
    celula *novo = aloc;
    novo->valor = val;
    novo->prox = NULL;
    if (*lst == NULL)
    {
        *lst = novo;
        return;
    }
    celula *ini = *lst;
    while (ini->prox != NULL)
    {
        ini = ini->prox;
    }
    ini->prox = novo;
}

celula desenfilera(celula **lst)
{
    celula *aux = *lst;
    *lst = (*lst)->prox;
    celula saida = *aux;
    free(aux);
    return saida;
}

int main()
{
    celula *lista = NULL;
    for (int i = 0; i < 10; i++)
    {
        enfilera(&lista, i);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", desenfilera(&lista).valor);
    }
    printf("\n");
}