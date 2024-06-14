#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celula
{
    int chave;
    struct celula *prox;
    struct celula *ant;
};

void adicionaFim(celula *&lst, int val)
{
    celula *novo = (celula *)calloc(1, sizeof(celula));
    novo->chave = val;
    novo->prox = NULL;

    if (lst == NULL)
    {
        lst = novo;
        novo->ant = NULL;
    }
    else
    {
        celula *aux = lst;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        novo->ant = aux;
    }
}

void adicionaComeco(celula *&lst, int val)
{
    celula *novo = (celula *)calloc(1, sizeof(celula));
    novo->chave = val;
    novo->prox = NULL;
    if (lst == NULL)
    {
        lst = novo;
        novo->ant = NULL;
    }
    else
    {
        novo->prox = lst;
        novo->ant = NULL;
        lst->ant = novo;
        lst = lst->ant;
    }
}

void preencheLista(celula *&lst)
{
    for (int i = 0; i < 10; i++)
    {
        adicionaComeco(lst, i);
    }
}
void printLista(celula *&lst)
{
    for (celula *p = lst; p != NULL; p = p->prox)
    {
        printf("%d ", p->chave);
    }
}

void libera(celula *&lst)
{
    celula *aux;
    while (lst != NULL)
    {
        aux = lst;
        lst = lst->prox;
        free(aux);
    }
}
int main()
{
    celula *lista = NULL;
    celula *lista2 = NULL;

    preencheLista(lista);
    printf("Adiciona COMECO\n");
    printLista(lista);

    libera(lista);

    printf("\n");
    printf("\n");

    preencheLista(lista2);
    printf("Adiciona FIM\n");
    printLista(lista2);
    printf("\n");


    libera(lista2);
}