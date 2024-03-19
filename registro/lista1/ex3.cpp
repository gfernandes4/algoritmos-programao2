/* Escreva um programa que cadastre vários produtos (código, nome, preço). Em seguida,
imprima uma lista com o código e nome da cada produto (tamanho máximo 50). Por último,
consulte o preço de um produto através de seu código (informado pelo usuário). Permita
que várias consultas sejam realizadas até que se digite um código igual a 0 (zero).
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define TOTAL 50

struct tProduto
{
    int codigo;
    char nome[MAX];
    float preco;
};

void cadastro(tProduto prod[], int qnt_produtos)
{
    for (int i = 0; i < qnt_produtos; i++)
    {
        printf("Codigo: ");
        scanf("%d", &prod[i].codigo);
        printf("Nome: ");
        scanf("%s", prod[i].nome);
        printf("Preco: R$");
        scanf("%f", &prod[i].preco);
        printf("\n");

    }
}

void imprimeProd(tProduto prod[], int qnt_produtos)
{
    for (int i = 0; i < qnt_produtos; i++)
    {
        printf("\nCodigo: %d", prod[i].codigo);
        printf("\nNome: %s", prod[i].nome);
        printf("\nPreco: R$%.2f", prod[i].preco);
        printf("\n");
    }
}

void buscaPreco(tProduto prod[], int codigo, int qnt_produtos)
{
    for (int i = 0; i < qnt_produtos; i++)
    {
        if (codigo == prod[i].codigo)
        {
            printf("O preco do(a) %s eh R$%.2f\n", prod[i].nome, prod[i].preco);
            printf("\n");

            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

int main()
{
    tProduto produto[TOTAL];
    int numero, n = 0;

    do
    {
        printf("\n");
        printf("1 - Cadastrar um produto\n");
        printf("2 - Lista dos produtos cadastrados\n");
        printf("3 - Consultar preco pelo codigo\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &numero);

        switch (numero)
        {
        case 1:

            printf("Quantos produtos deseja cadastrar?\n");
            scanf("%d", &n);
            cadastro(produto, n);

            break;

        case 2:
            printf("Lista dos produtos cadastrados:\n");
            imprimeProd(produto, n);
            break;

        case 3:
            int cod;
            printf("Insira o codigo do produto para ver seu valor:\n");
            scanf("%d", &cod);
            buscaPreco(produto, cod, n);
            break;
        case 0:
            exit(0);
        default:
            printf("INSIRA UM NUMERO VALIDO!\n");
            break;
        }

    } while (numero != 0);
    return 0;
}