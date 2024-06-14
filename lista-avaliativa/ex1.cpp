#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct celula
{
   char parenteses;
   struct celula *prox;
};

// se encontrar o parenteses (, empilha
void empilha(celula **lst, char a)
{
   celula *novo = (celula *)calloc(1, sizeof(celula));

   novo->parenteses = a;
   novo->prox = *lst;
   *lst = novo;
}

// se encontrar o parenteses ), desempilha
celula *desempilha(celula **lst)
{
   // verificando se a pilha esta vazia
   if (*lst == NULL)
   {
      return NULL;
   }
   // criando ponteiro aux q aponta para o inicio da pilha
   celula *aux = *lst;

   // atualizando o topo da pilha
   *lst = aux->prox;

   // retornando a celula q vai ser removida
   return aux;
}

int verifParenteses(celula **lst, char *c)
{
   int i = 0;
   // verificar e ai vai empilhando ou desempilhando de acordo com os parenteses
   while (c[i] != '\0')
   {
      if (c[i] == '(')
      {
         empilha(lst, c[i]);
      }
      else if (c[i] == ')')
      {
         if (desempilha(lst) == NULL)
         {
            return 0;
         }
      }
      i++;
   }
   if (*lst != NULL)
   {
      // mal formulada
      return 0;
   }
   return 1;
}

int main()
{
   char expressao[100];
   scanf("%s", expressao);
   celula *conta = NULL;
   int verifica = verifParenteses(&conta, expressao);
   if (verifica == 1)
   {
      printf("Parênteses corretos\n");
   }
   else
   {
      printf("Parênteses incorretos\n");
   }
}