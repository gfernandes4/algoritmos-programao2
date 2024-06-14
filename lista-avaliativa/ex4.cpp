#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ================================================

// VER A LOGICA DE ORDENAÇÃO DE NOVO

//=================================================
struct celula
{
    int valor;
    struct celula *prox;
};

void empilha(celula *&lst, int x)
{
    celula *novo = (celula *)calloc(1, sizeof(celula));
    novo->valor = x;
    novo->prox = lst;
    lst = novo;
}

void imprime(celula *l)
{
    celula *p;
    for (p = l; p != NULL; p = p->prox)
        printf("%d ", p->valor);
}

celula *ordenaCrescente(celula *l)
{
    celula *aux = l;
    celula *novo;
    int x = 0;
    while (aux != NULL)
    {
        novo = aux->prox;
        while (novo != NULL)
        {
            if (aux->valor > novo->valor)
            {
                x = aux->valor;
                aux->valor = novo->valor;
                novo->valor = x;
            }
            novo = novo->prox;
        }
        aux = aux->prox;
    }
    return l;
}

int main()
{
    int n, val;
    scanf("%d", &n);

    celula *lista = NULL;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        empilha(lista, val);
    }
    ordenaCrescente(lista);
    imprime(lista);
}