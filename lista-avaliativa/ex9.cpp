#include <stdio.h>
#include <stdlib.h>

struct celula
{
    int valor;
    struct celula *prox;
};

void enfilera(celula *&lst, int val)
{
    celula *novo = (celula *)calloc(1, sizeof(celula));
    novo->prox = NULL;
    novo->valor = val;
    if (lst == NULL)
    {
        lst = novo;
        return;
    }
    celula *aux = lst;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = novo;
}

int main()
{
    celula *lista = NULL;
    int n;
    scanf("%d", &n);
    if (n % 2 != 0)
        enfilera(lista, n);

    while (n != 0)
    {
        scanf("%d", &n);
        if (n % 2 != 0)
            enfilera(lista, n);
    }

    for (celula *p = lista; p != NULL; p = p->prox)
    {
        printf("%d ", p->valor);
    }
    printf("\n");
}