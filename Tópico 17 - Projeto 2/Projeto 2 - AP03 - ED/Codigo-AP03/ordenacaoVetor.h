/*-----------------------------------------------------
|    Autores: Aline Araujo Souza  | Matrícula: 473383 |
|             Davi Teixeira Silva | Matrícula: 433951 |
------------------------------------------------------*/

#ifndef ORDENACAOVETOR_H
#define ORDENACAOVETOR_H

// BubbleSort
void BubbleSort(int n, int A[]);

// CocktailSort
void CocktailSort(int n, int A[]);

// InsertionSort Iterativo
void iterativo_InsertionSort (int A[], int n);

// InsertionSort Recursivo
void recursivo_InsertionSort (int A[], int n);

// SelectionSort Iterativo
void iterativo_SelectionSort(int A[], int n);

// SelectionSort Recursivo
void recursivo_SelectionSort(int A[], int n);

// Funcao para intercalar dois vetores
void Intercala (int A[], int p, int q, int r);

// MergeSort Iterativo
void iterativo_MergeSort(int A[], int n);

// MergeSort Recursivo
void recursivo_MergeSort(int A[], int p, int r);

// Funcao para semparar dois vetores
int separa(int A[], int p, int r);

// QuickSort Iterativo
void iterativo_QuickSort(int A[], int p, int r);

// QuickSort Recursivo
void recursivo_QuickSort(int A[], int p, int r);

#endif