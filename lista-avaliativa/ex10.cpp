#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celula
{
    char site[50];
    char endereco[50];
    struct celula *prox;
};

void empilha(celula *&lst, char *nomeSite, char *linkSite)
{
    celula *aux1Nome = (celula *)calloc(1, sizeof(celula));
    celula *aux2Link = (celula *)calloc(1, sizeof(celula));
    //nome do site
    aux1Nome->prox = lst;
    strcpy(aux1Nome->site, nomeSite);
    lst = aux1Nome;
    //endereço do site
    aux2Link->prox = lst;
    strcpy(aux2Link->endereco, linkSite);
    lst = aux2Link;
}

int main()
{
    celula *lista = NULL;

    char nome[50], link[50];
    int i = 0;
    while (nome[i] != '0')
    {
        scanf("%s %s", nome, link);
        empilha(lista, nome, link);
    }
    char compara[50];
    scanf("%s", compara);
    for (celula *p = lista; p != NULL; p = p->prox)
    {
        printf("%s %s\n", p->site, p->endereco);
    }


}