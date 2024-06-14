#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*tipo para marca */
struct marca
{
      int codigo;
      float  nota;
      struct marca* prox;
      struct marca* ant;
};


/*tipo para carro */
struct carro
{
    char modelo[40];
    int ano;
    int codigomarca;
    struct carro *prox;
};


void inserirM(marca **lst, int codigo, float nota);


float buscaMarca(marca *m, int codigo);


void inserirC(carro **lst, char *modelo, int ano, int codigo);


void listagem(marca *m, carro *c);


void removerM(marca *&m, carro *c, int codigo);


void desalocaMarca(marca *&);


void desalocaCarro(carro *&);


