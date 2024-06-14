#include "fila.h"
#include <stdio.h>
#define MAX 50

int main()
{
    int op;
    celulaF *DequeI = NULL;
    celulaF *DequeF = NULL;
    char nome[MAX + 1];
    do
    {
        printf("\n\n1-Empilha");
        printf("\n2-Desempilha");
        printf("\n3-Inject");
        printf("\n4-Eject");
        printf("\n5-Imprimir");
        printf("\n6-Sair\nOpcao: ");
        scanf("%d", &op);

        if (op == 1)
        {
            printf("Digite nome:");
            scanf("%s", nome);
            enfilera(nome, DequeI, DequeF);
        }
        if (op == 3)
        {
            printf("Digite nome:");
            scanf("%s", nome);
            inject(nome, DequeI, DequeF);
        }
        else if (op == 5)
            imprimeF(DequeI);

    } while (op != 6);

    return 0;
}