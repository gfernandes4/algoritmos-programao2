#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celula
{
    int valor;
    struct celula *prox;
};

void empilhar(int x, celula *&lst)
{
    celula *nova;
    nova = (celula *)calloc(1, sizeof(celula));
    nova->valor = x;
    nova->prox = lst;
    lst = nova;
}

void imprime_reverso(celula *L)
{
    celula *p;
    p = NULL;
    for (p = L->prox; p != NULL; p = p->prox)
    {
        printf("%d\n", p->valor);
    }
}

int main()
{
    celula *lista = NULL;
    int n;
    while (n >= 0)
    {
        scanf("%d", &n);
        empilhar(n, lista);
    }
    imprime_reverso(lista);
}