/* Escreva um programa que cadastre o nome, a matrícula e duas notas de N alunos
(N≤50). Em seguida, imprima a matrícula, o nome e a média de cada um deles */
#include <stdio.h>
#define MAX 100
#define MAX_ALUNO 100

struct tipoAluno
{
    char nome[MAX];
    int matricula;
    float nota1, nota2;
};

int main()
{
    tipoAluno aluno[MAX_ALUNO];

    int n_alunos, i;
    float media[MAX];

    scanf("%d", &n_alunos);

    //o codigo n funciona com palavra com espaço
    for (i = 0; i <= n_alunos; i++)
    {
        //o fgets só funciona se nao vier seguido de um scanf
        fgets(aluno[i].nome, MAX, stdin);
       // scanf("%s", &aluno[i].matricula);
        scanf("%d", &aluno[i].matricula);
        scanf("%f", &aluno[i].nota1);
        scanf("%f", &aluno[i].nota2);
        
        media[i] = (aluno[i].nota1 + aluno[i].nota2) / 2;
    }
    for (i = 0; i < n_alunos; i++)
    {
        printf("A matricula eh: %d\n", aluno[i].matricula);
        printf("O estudante se chama: %s\n", aluno[i].nome);
        printf("Sua media eh: %.2f\n", media[i]);
    }
    return 0;
}