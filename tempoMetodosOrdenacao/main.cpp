#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "funcoes.cpp"

int main()
{
    printf("Insira o tamanho do vetor: ");
    int *v, tam;
    scanf("%d", &tam);
    v = (int *)calloc(tam, sizeof(int));
    // gerenado numeros aleatorios
    geradorNumAleatorio(v, tam);
    int nunsRandom[tam];
    printf("\n");
    
    for (int i = 0; i < tam; i++)
        nunsRandom[i] = v[i];
    //quick
    double inicio = omp_get_wtime();
    quick(0, tam-1, nunsRandom);
    double fim = omp_get_wtime();
    double tempo = fim - inicio;
    printf("Tempo de execução do Quick Sort: %lf\n", tempo);

    for (int i = 0; i < tam; i++)
        nunsRandom[i] = v[i];
    //merge
    inicio = omp_get_wtime();
    mergeSort(nunsRandom, 0, tam-1);
    fim = omp_get_wtime();
    tempo = fim - inicio;
    printf("Tempo de execução do Merge Sort: %lf\n", tempo);
    
    //insertion
    for (int i = 0; i < tam; i++)
        nunsRandom[i] = v[i];
    inicio = omp_get_wtime();
    insertionSort(nunsRandom, tam);
    fim = omp_get_wtime();
    tempo = fim - inicio;
    printf("Tempo de execução do Insertion Sort: %lf\n", tempo);
    
    //selection
    for (int i = 0; i < tam; i++)
        nunsRandom[i] = v[i];
    inicio = omp_get_wtime();
    selection(nunsRandom, tam);
    fim = omp_get_wtime();
    tempo = fim - inicio;
    printf("Tempo de execução do Selection Sort: %lf\n", tempo);

    return 0;
}
