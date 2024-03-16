/* ) Escreva um programa que cadastre o nome, a altura, o peso, o cpf e sexo de algumas
pessoas. Com os dados cadastrados, em seguida, localize uma pessoa através do seu CPF
(informado pelo usuário) e imprima o seu IMC (IMC = PESO/ALTURA^2).
Funcionalidade adicional 1: permita consultar várias vezes, até que se digite 0 (zero) para
terminar.
Funcionalidade adicional 2: crie um menu no programa para que, além de consultar IMC por
CPF, liste (IMC e nome) de todas as pessoas do sexo masculino.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct tPessoa
{
    char nome[MAX];
    float altura, peso;
    int cpf;
    char sexo[MAX];
};

int main()
{
    tPessoa pessoa[MAX];
    int numero, i;
    float imc;

    do
    {
        printf("\n");

        printf("1 - Cadastrar uma pessoa\n");
        printf("2 - Verificar o IMC\n");
        printf("3 - Ver lista de IMC dos homens\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &numero);

        switch (numero)
        {
        case 1:

            int num_pessoas;
            printf("Quantas pessoas voce vai cadastrar?\n");
            scanf("%d", &num_pessoas);

            for (i = 0; i < num_pessoas; i++)
            {
                printf("Nome: ");
                scanf("%s", pessoa[i].nome);
                printf("Altura: ");
                scanf("%f", &pessoa[i].altura);
                printf("Peso: ");
                scanf("%f", &pessoa[i].peso);
                printf("CPF: ");
                scanf("%d", &pessoa[i].cpf);
                printf("Sexo (Informe M para masculino\ne F para feminino): ");
                scanf("%s", pessoa[i].sexo);
            }
            break;
            printf("\n");

        case 2:
            int cpf;

            printf("Insira o cpf da pessoa:\n");
            scanf("%d", &cpf);
            for (i = 0; i < 1; i++)
            {
                if (cpf == pessoa[i].cpf)
                {
                    imc = pessoa[i].peso / (pessoa[i].altura * pessoa[i].altura);
                    printf("O IMC de %s eh %.2f\n", pessoa[i].nome, imc);
                    printf("\n");
                }
                else
                {
                    printf("CPF INVALIDO\n");
                }
                break;
            }
            break;
            printf("\n");
        case 3:
            int ok;
            printf("LISTA DO IMC DOS HOMENS:\n");
            for (i = 0; i < num_pessoas; i++)
            {
                ok = strcmp(pessoa[i].sexo, "M");
                ok = strcmp(pessoa[i].sexo, "m");
                if (ok == 0)
                {
                    imc = pessoa[i].peso / (pessoa[i].altura * pessoa[i].altura);
                    printf("O IMC de %s eh %.2f\n", pessoa[i].nome, imc);
                    printf("\n");
                }
            }
            break;
            printf("\n");

        case 0:
            exit(0);
            break;
        default:
            printf("INSIRA UM NUMERO VALIDO!\n");
        }
    } while (numero != 0);
    return 0;
}
