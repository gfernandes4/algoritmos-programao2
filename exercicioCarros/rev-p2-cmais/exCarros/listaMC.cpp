#include <stdlib.h>
#include <string.h>

#include "listaMC.h"

void inserirM(marca **lst, int codigo, float nota)
{
    marca *novo = (marca *)calloc(1, sizeof(marca));
    novo->codigo = codigo;
    novo->nota = nota;
    novo->prox = *lst;

    if (*lst != NULL)
    {
        (*lst)->ant = *lst;
    }

    *lst = novo;
}

float buscaMarca(marca *m, int codigo)
{
    // retorna a nota do carro que corresponde ao codigo do parametro
    marca *novo = (marca *)calloc(1, sizeof(marca));
    novo = m;
    for (marca *p = m; p != NULL; p = p->prox)
    {
        if (novo->codigo == codigo)
        {
            return novo->nota;
            break;
        }
    }
    return 0.0;
}

void inserirC(carro **lst, char *modelo, int ano, int codigo)
{
    carro *novo = (carro *)calloc(1, sizeof(carro));

    novo->ano = ano;
    novo->codigomarca = codigo;
    strcpy(novo->modelo, modelo);
    novo->prox = *lst;
    *lst = novo;
}

void listagem(marca *m, carro *c)
{
    for (marca *p = m; p != NULL; p = p->prox)
    {
        for (carro *q = c; q != NULL; q = q->prox)
        {
            if (q->codigomarca == p->codigo)
                printf("Modelo: %s\nAno: %d\nNota da marca: %f", q->modelo, q->ano, p->nota);
            printf("\n");
        }
    }
}

//refazer essa função pq fiz olhando o material e n entendi direito como q remove :/
void removerM(marca *&m, carro *c, int codigo)
{
    int flag = 0;
    for (carro *p = c; p != NULL; p = p->prox)
    {
        if (p->codigomarca == codigo)
        {
            flag = 1;
            break;
        }
    }

    marca *novo = m;
    if (flag == 0)
    {
        while (novo != NULL && novo->codigo != codigo)
        {
            novo = novo->prox;
        }
        if (novo == NULL)
        {
            printf("\nnao encontrado\n");
        }
        else
        {
            if (novo->ant == NULL)
            {
                m = m->prox;
                if (m != NULL)
                    m->ant = NULL;
            }
            else
            {
                novo->ant->prox = novo->prox;
                if (novo->prox != NULL)
                {
                    novo->prox->ant = novo->ant;
                }
            }
            free(novo);
            printf("\nMarca removida com sucesso\n");
        }
    }
    else
    {
        printf("Esta marca esta associada e nao pode ser removida\n");
    }
}

void desalocaMarca(marca *&lst)
{
}

void desalocaCarro(carro *&)
{
}
