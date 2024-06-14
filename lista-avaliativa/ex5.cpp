#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celula
{
    char nome[31];
    struct celula *prox;
};

void empilha(char *nome, celula *&lst)
{
    celula *novo = (celula *)calloc(1, sizeof(celula));
    strcpy(novo->nome, nome);
    novo->prox = lst;
    lst = novo;
}

celula *interseccao(celula *L1, celula *L2)
{
    celula *l3 = NULL;
    celula *atual1;
    celula *atual2;

    for (atual1 = L1; atual1 != NULL; atual1 = atual1->prox)
    {
        for (atual2 = L2; atual2 != NULL; atual2 = atual2->prox)
        {
            if (strcmp(atual1->nome, atual2->nome) == 0)
            {
                empilha(atual1->nome, l3);
                break;
            }
        }
    }

    return l3;
}

void imprime(celula *lst)
{
    celula *p;
    if (lst == NULL)
    {
        printf("VAZIA\n");
        return;
    }
    for (p = lst; p != NULL; p = p->prox)
    {
        printf("%s ", p->nome);
    }
    printf("\n");
}

void leitura(celula *&lst)
{
    char nome[31];
    while (1)
    {
        scanf(" %[^\n]", nome);
        if (strcmp(nome, "FIM") == 1)
            break;
        empilha(nome, lst);
    }
}

void liberarMemoria(celula *lst)
{
    celula *temp;
    while (lst != NULL)
    {
        temp = lst;
        lst = lst->prox;
        free(temp);
    }
}
int main()
{
    celula *lista1 = NULL, *lista2 = NULL;
    leitura(lista1);
    leitura(lista2);
    celula *l3 = interseccao(lista1, lista2);
    imprime(l3);

    // liberando memoria
    liberarMemoria(lista1);
    liberarMemoria(lista2);
    liberarMemoria(l3);

    return 0;
}