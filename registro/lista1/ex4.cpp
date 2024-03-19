/*Escreva um programa que simule contas bancárias, com as seguintes especificações:
 Ao iniciar o programa, o programa deve criar contas bancárias para três clientes.
○ Cada conta terá o nome e o CPF do cliente associado a ela.
○ No ato da criação da conta o cliente precisará fazer um depósito inicial.
 -Após as contas serem criadas, o sistema deverá possibilitar realizações de saques
ou depósitos nas contas.
○ Sempre que uma operação de saque ou depósito seja realizada, o sistema
deverá imprimir o nome do titular e o saldo final da conta*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define TRES 1

typedef struct tConta
{
    char nome[MAX];
    int cpf;
    float saldo;

}novaConta;

void criar_conta(novaConta conta[])
{
    struct tConta *p;
    for (p = conta; p < conta + TRES; p++)
    {
        printf("NOME: ");
        scanf("%[^\n]", p->nome);
        getchar();

        printf("CPF: ");
        scanf("%d", &p->cpf);
        getchar();

        printf("SALDO INICIAL:");
        scanf("%f", &p->saldo);
        getchar();
    }
}


void imprime(novaConta conta[])
{
    for (int i = 0; i < 3; i++)
    {
        printf("O saldo de %s eh: %.2f\n", conta[i].nome, conta[i].saldo);
    }
}
void deposito(novaConta conta[], int cpf)
{
    struct tConta *p;
    float soma;
    int aux = 0;
    for (p = conta; p < conta + TRES; p++)
    {
        if (cpf == p->cpf)
        {
            printf("Adicione um saldo: ");
            scanf("%f", &soma);
            getchar();
            p->saldo += soma;
            aux = 1;
            imprime(conta);
            break;
        }
        if (aux == 0)
        {
            printf("CPF NAO ENCONTRADO\n");
        }
    }
}

void saque(novaConta conta[])
{
    float retira;
    int n;
    printf("Escolha uma conta para fazer o saque: ");
    scanf("%d", &n);
    for (int i = 0; i < 1; i++)
    {
        if (n == 1)
        {
            printf("Faça o deposito: R$");
            scanf("%f", &retira);
            conta[i].saldo = conta[i].saldo - retira;
            break;
        }
        else if (n == 2)
        {
            printf("Faça o deposito: R$");
            scanf("%f", &retira);
            conta[i].saldo = conta[i].saldo - retira;
            break;
        }
        else if (n == 3)
        {
            printf("Faça o deposito: R$");
            scanf("%f", &retira);
            conta[i].saldo = conta[i].saldo - retira;

            break;
        }
    }
    printf("Insira um valor valido\n");
}

int main()
{
    novaConta conta[MAX];
    int numero;
    do
    {
        printf("1 - Criar conta\n");
        printf("2 - Depositar\n");
        printf("3 - Sacar\n");
        printf("4 - Sair\n");

        printf("Escolha uma das opcoes\n");
        scanf("%d", &numero);
        getchar();

        switch (numero)
        {
        case 1:
            criar_conta(conta);
            break;

        case 2:
            int cpf;
            printf("INFORME O CPF: ");
            scanf("%d", &cpf);

            deposito(conta, cpf);

            break;

        case 3:
            saque(conta);
            imprime(conta);

            break;

        case 4:
            exit(0);
        default:
            printf("INSIRA UM VALOR VALIDO!!!");
        }
    } while (numero != 0);
}