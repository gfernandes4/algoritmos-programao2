/*Crie um programa que permita armazenar o nome, a altura e da data de nascimento de
até 10 pessoas.
Cada pessoa deve ser representada por uma struct dentro de um vetor.
A data de nascimento também deve ser uma struct.
O nome e a altura de cada pessoa devem ser informados pelo teclado.
O programa deve, na tela de abertura, apresentar opções para:
● 1 - inserir uma pessoa;
● 2 - listar todos os nomes e respectivas alturas;
● 3 - listar os nomes das pessoas que nasceram antes de uma certa data fornecida.*/

#include <stdio.h>
#include <stdlib.h>
#define DEZ 1
#define MAX 100

struct tDataNasc
{
    int dia, mes, ano;
};

struct tPessoa
{
    char nome[MAX];
    float altura;
    tDataNasc dataNasc;
};

void criaPessoa(tPessoa pessoa[], tPessoa *posicao)
{
    printf("%s aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", posicao->nome);

    printf("insira o nome: ");
    scanf(" %[^\n]", posicao->nome);
    printf("insira a altura: ");
    scanf("%f", &posicao->altura);
    getchar();
    printf("insira a data de nascimento: ");
    scanf("%d/%d/%d", &posicao->dataNasc.dia, &posicao->dataNasc.mes, &posicao->dataNasc.ano);
    getchar();

    posicao += 1;
}

void list(tPessoa pessoa[])
{
    struct tPessoa *p;
    for (p = pessoa; p < pessoa + DEZ; p++)
    {
        printf("Nome: %s\nAltura: %.2f\nData de nascimento: %d/%d/%d\n", p->nome, p->altura, p->dataNasc.dia, p->dataNasc.mes, p->dataNasc.ano);
    }
}

void verificaNas(tPessoa pessoa[])
{
    int dia, mes, ano;
    struct tPessoa *d;

    printf("Insira uma data: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    mes = mes * 30;
    ano = ano * 360;
    dia = dia + ano + mes;

    int anoStruct = 0;

    for (d = pessoa; d < pessoa + DEZ; d++)
    {
        anoStruct = (d->dataNasc.ano * 360) + (d->dataNasc.mes * 30) + d->dataNasc.dia;
        if (anoStruct < dia)
        {
            printf("A pessoa %s nasceu em ", d->nome);
            printf("%d/%d/%d\n", d->dataNasc.dia, d->dataNasc.mes, d->dataNasc.ano);
        }
    }
}

int main()
{
    tPessoa pessoa[MAX], *pos;
    int numero;
    pos = &pessoa[0];

    do
    {
        printf("1 - inserir uma pessoa\n");
        printf("2 - listar todos os nomes e respectivas alturas\n");
        printf("3 - listar os nomes das pessoas que nasceram antes de uma certa data fornecida.\n");
        printf("4 - sair\n");

        printf("insira um numero\n");
        scanf("%d", &numero);

        switch (numero)
        {
        case 1:
            criaPessoa(pessoa, pos);
            break;

        case 2:
            list(pessoa);
            break;
        case 3:
            verificaNas(pessoa);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("INSIRA UM NUMERO VALIDO!!");
        }
    } while (numero != 0);
}