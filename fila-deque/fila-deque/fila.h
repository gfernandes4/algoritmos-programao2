/*fila simplesmente encadeada - FILA DE nomes*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct celulaF{
    char *nome;
    struct celulaF *prox;
};


// enfilera
void enfilera(char *nome, celulaF *&i, celulaF *&f);

// acrescenta um novo no ao final da FILA
void inject(char *x, celulaF *&i, celulaF *&f);
// remove o primeiro no da FILA, retorna o valor que estava la armazenado
char* desempilha(celulaF *&i, celulaF *&f);

// desaloca todos os nos da FILA
void desalocarF(celulaF *&L);
// imprime todos os valores da FILA
void imprimeF(celulaF *p);

