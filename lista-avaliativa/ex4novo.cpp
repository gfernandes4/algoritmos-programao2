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

void ordenaCrescente(celula *&l, int val)
{
    if (l == NULL)
    {
        celula *aux = (celula *)calloc(1, sizeof(celula));
        l = aux;
        aux->valor = val;
        aux->prox = NULL;
    }
    else
    {
        if (l->valor > val)
        {
            // LISTA 1 2 4 5 6 9
            // ENTRADAS 6
            empilha(l, val);
        }
        else
        {
            celula *frente = l->prox;
            celula *tras = l;
            celula *aux = (celula *)calloc(1, sizeof(celula));
            aux->valor = val;
            while (frente != NULL)
            {
                if (frente->valor > val)
                {
                    tras->prox = aux;
                    aux->prox = frente;
                    break;
                }
                frente = frente->prox;
                tras = tras->prox;
            }
            if (frente == NULL)
            {
                tras->prox = aux;
                aux->prox = NULL;
            }
        }
    }
}

int main()
{
    int n, val;
    scanf("%d", &n);

    celula *lista = NULL;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        ordenaCrescente(lista, val);
    }
    imprime(lista);
}