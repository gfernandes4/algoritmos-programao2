#include <stdio.h>
#include <stdlib.h>
#include "listaMC.h"

/*funcao main*/
int main()
{
    marca *mark = NULL;
    carro *car = NULL;

    int op;
    char modelo[40];
    int ano;

    do
    {
        printf("\n1 - Cadastrar uma marca");
        printf("\n2 - Cadastrar um carro");
        printf("\n3 - Listagem de carros");
        printf("\n4 - Exclusao de uma marca");
        printf("\n5 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &op);

        if (op == 1)
        {
            int codigo;
            printf("Informe o codigo da marca: ");
            scanf("%d", &codigo);
            float nota;
            printf("Informe a nota: ");
            scanf("%f", &nota);
            inserirM(&mark, codigo, nota);
            printf("\n");
        }
        else if (op == 2)
        {
            char nome[50];
            printf("Insira o nome do carro: ");
            scanf("%s", nome);
            int ano, modelo;
            printf("Insira o ano de fabricacao: ");
            scanf("%d", &ano);
            printf("Insira o modelo: ");
            scanf("%d", &modelo);
            inserirC(&car, nome, ano, modelo);
            printf("\n");
        }
        else if (op == 3)
        {
            listagem(mark, car);
        }
        else if (op == 4)
        {
            int codigo;
            printf("Informe o codigo da marca a ser removida: ");
            scanf("%d", &codigo);
            removerM(mark, car, codigo);
            
        }
        else if (op == 6)
        {
            // fazer a busca de uma marca a partir do codigo
            int codigo;
            scanf("%d", codigo);
            float nota = buscaMarca(mark, codigo);
            if (nota == 0.0)
                printf("Codigo nao encontrado\n");
        }

    } while (op != 5);

    // desalocar listas

    return 0;
}
