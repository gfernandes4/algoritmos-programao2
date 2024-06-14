#include <stdio.h>
#include <stdlib.h>
#define alok (celula *)calloc(1, sizeof(celula));

struct celula
{
    int dado;
    struct celula *prox;
};

void fila(celula *&lst, int val)
{
    celula *novo = alok;
    novo->prox = NULL;
    novo->dado = val;
    if (lst == NULL)
    {
        lst = novo;
        return;
    }
    celula *aux = lst;
    while (aux->prox != NULL)
    {
        // aux anda para o proximo
        aux = aux->prox;
    }
    aux->prox = novo;
}

void remove_k_esimo(celula *&lst, int k)
{
    celula *frente = NULL, *tras = NULL;
    int i = 1;
    if (i == k)
    {
        celula *aux = lst;
        lst = lst->prox;
        free(aux);
        return;
    }
    i = 2;
    tras = lst;
    for (frente = lst->prox; frente != NULL; frente = frente->prox)
    {
        // se colocar o i++ antes do if funciona para mais casos
        if (i == k)
        {
            tras->prox = frente->prox;
            free(frente);
            break;
        }
        tras = tras->prox;
        i++;
    }
}

int main()
{
    celula *lista = NULL;
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        fila(lista, val);
    }
    int k;
    scanf("%d", &k);

    remove_k_esimo(lista, k);
    for (celula *p = lista; p != NULL; p = p->prox)
    {
        printf("%d ", p->dado);
    }
    printf("\n");
}

// entrada 5 44 23 10 7 8 1
// saida 23 10 7 8