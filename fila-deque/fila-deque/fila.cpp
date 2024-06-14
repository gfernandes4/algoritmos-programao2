/*fila simplesmente encadeada - FILA DE CARACTERES*/
#include "fila.h"

// enfileira
void enfilera(char *nome, celulaF *&i, celulaF *&f)
{
    celulaF *novo = (celulaF *)calloc(1, sizeof(celulaF));
    // definindo novo
    strcpy(novo->nome,nome);
    novo->prox = NULL;

    //verificando o inicio
    if (i == NULL)
    {
        i = f = novo;
    }
    else{
        f->prox = novo;
        f = novo;
    }
    
}
/*Fun��o recebe um ponteiro para o inicio da fila, um ponteiro para o final da fila e o
elemento x que deseja inserir*/
void inject(char *x, celulaF *&i, celulaF *&f)
{
    celulaF *nova;

    // alocando o no
    nova = (celulaF *)calloc(1, sizeof(celulaF));
    // alocando a string nome
    nova->nome = (char *)calloc(strlen(x) + 1, sizeof(char));
    strcpy(nova->nome, x);

    if (i == NULL)
        i = f = nova;
    else
    {
        f->prox = nova;
        f = nova;
    }
}

/*Fun��o recebe o ponteiro para o inicio da fila (e ponteiro
para o ultimo no), remove o primeiro e retorna
 o valor do mesmo*/
char *desempilha(celulaF *&i, celulaF *&f)
{
    celulaF *aux;
    char *temp;

    if (i == NULL) // RETORNA NULL SE FILA ESTA VAZIA
        return NULL;
    else
    {
        temp = i->nome;
        aux = i;
        i = i->prox;
        if (i == NULL)
            f = NULL;

        free(aux);
        return temp;
    }
}

/*Funcao que apaga todos os n�s da lista L*/
void desalocarF(celulaF *&L)
{
    celulaF *aux;

    while (L != NULL)
    {
        aux = L;
        L = L->prox;
        printf("\n Desalocando %s ", aux->nome);
        free(aux->nome);
        free(aux);
    }
}

// Imprime a lista L
void imprimeF(celulaF *L)
{
    celulaF *p;
    for (p = L; p != NULL; p = p->prox)
        printf("%s ", p->nome);
}
