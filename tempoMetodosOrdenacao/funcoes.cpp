#include <stdio.h>
#include <stdlib.h>
#define MAX 10

#include "c.h"

void troca(int *a, int *b)
{
    int aux = 0;
    aux = *a;
    *a = *b;
    *b = aux;
}

void geradorNumAleatorio(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Gera números aleatórios entre 0 e 999
    }
}

//merge
void juntaOrdenado(int *v, int inicio, int meio, int fim)
{
    int *v1;
    int *v2;
    int tamV1 = meio + 1 - inicio;
    int tamV2 = fim - meio;
    v1 = (int *)malloc(tamV1 * sizeof(int));
    v2 = (int *)malloc(tamV2 * sizeof(int));

    for (int i = 0; i < tamV1; i++)
    {
        v1[i] = v[inicio + i];
    }

    for (int i = 0; i < tamV2; i++)
    {
        v2[i] = v[meio + i + 1];
    }

    int j = 0;
    int i = 0;
    int k = inicio;
    while (i != tamV2 && j != tamV1)
    {
        if (v1[j] > v2[i])
        {
            v[k] = v2[i];
            i++;
            k++;
        }
        else
        {
            v[k] = v1[j];
            j++;
            k++;
        }
    }
    while (j != tamV1)
    {
        v[k] = v1[j];
        k++;
        j++;
    }
    while (i != tamV2)
    {
        v[k] = v2[i];
        k++;
        i++;
    }
    free(v1);
    free(v2);
}

void mergeSort(int *v1, int inicio, int fim)
{

    if (fim > inicio)
    {
        int meio = (inicio + fim) / 2;
        mergeSort(v1, inicio, meio);
        mergeSort(v1, meio + 1, fim);
        juntaOrdenado(v1, inicio, meio, fim);
    }
}


//selection

void selection(int v[], int n)
{
     for (int i = 0; i < n - 1; i++)
    {
        int indice_menor = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[indice_menor])
            {
                indice_menor = j;
            }
        }
        if (i != indice_menor)
        {
            troca(&v[i], &v[indice_menor]);
        }
    }
}

//insertion

void insertionSort(int vet[], int tamanho)
{
  for (int i = 1; i < tamanho; i++)
  {
    int chave = vet[i];
    int j = i - 1;

    
    while (chave < vet[j] && j >= 0)
    {
      vet[j + 1] = vet[j];
      --j;
    }
    vet[j + 1] = chave;
  }
}

// quick

int separa(int ini, int fim, int v[])
{
    int pivot = v[fim];
    int i = (ini - 1);
    for (int j = ini; j < fim; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i+1], &v[fim]);
    return (i+1);
}

void quick(int ini, int fim, int v[]){
    if (ini < fim){
        int meio = separa(ini, fim, v);
        quick(ini, meio-1, v);
        quick(meio+1, fim, v);
    }
}

