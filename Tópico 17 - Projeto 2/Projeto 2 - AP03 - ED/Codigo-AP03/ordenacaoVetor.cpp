/*-----------------------------------------------------
|    Autores: Aline Araujo Souza  | Matrícula: 473383 |
|             Davi Teixeira Silva | Matrícula: 433951 |
------------------------------------------------------*/

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <chrono>

#include "ordenacaoVetor.h"

using namespace std;

/**
 * Implementacao dos quatro algoritmos:
 * InsertionSort, SelectionSort, MergeSort e QuickSort.
**/

// Algoritmo BubbleSort --------------------------------------------------------------------------
// Ordena um vetor A[0..n-1]

void BubbleSort(int n, int A[]){   
    for (int i = 0; i < n-1; i++)
        // Os elementos do último i já estão no lugar      
		for (int j = 0; j < n-i-1; j++)  
			if (A[j] > A[j+1])  
				std::swap(A[j], A[j+1]);  
}

// Algoritmo CockTailSort -------------------------------------------------------------------------
// Esta funcao ordena um vetor A[0..n-1]  

void CocktailSort(int n, int A[]) { 
    bool trocou = true; 
    int inicio = 0; 
    int fim = n-1; 
  
    while (trocou){  
        trocou = false; 
  
        // varre o vetor da esquerda para a direita, 
        // assim como o bubblesort 
        for (int i = inicio; i < fim; i++) 
            if (A[i] > A[i+1]){ 
                std::swap(A[i], A[i + 1]); 
                trocou = true; 
            } 
  
        // se nenhuma troca ocorreu, entao o vetor
        // ja esta ordenado 
        if (!trocou) 
			break;
		else
			// caso contrario, a variavel 'trocou' 
			// volta a ser 'false' para que a 
			// proxima iteração do loop while ocorra  
			trocou = false; 
  
        // como o elemento na posicao 'fim' e todos os 
        // elementos apos ele (se existirem) ja estao
        // ordenados, decrementamos 'fim'  
        fim--; 
  
        // varremos o vetor agora da direita para a esquerda, 
        // fazendo a mesma comparacao que no estagio anterior 
        for (int i = fim-1; i >= inicio; i--) 
            if (A[i] > A[i+1]) { 
                std::swap(A[i],A[i+1]); 
                trocou = true; 
            } 
  
        // incrementamos a variavel inicio', pois no 
        // ultimo loop 'for' o proximo menor elemento 
        // foi colocado no seu devido lugar 
        inicio++; 
    } 
} 

//-------------------------------------------------------------------------------------------------

// Algoritmo InsertionSort Iterativo --------------------------------------------------------------
// Ordena um vetor A[0..n-1]
void iterativo_InsertionSort (int A[], int n){
    for (int i = 1; i < n; i++){
        int key = A[i];
        int j = i-1;
        /* Move os elementos de A[0..i-1], que são
        maior que a key, para uma posição à frente
        de sua posição atual */
        while (j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

//-------------------------------------------------------------------------------------------------

// Algoritmo InsertionSort Recursivo --------------------------------------------------------------
// Ordena um vetor A[0..n-1]

void recursivo_InsertionSort (int A[], int n){
    //Caso base onde será feita a verificação no vetor se o seu tamanho é menor ou igual a 1
    //Se for igual a 1, significa que o vetor possui um elemento, logo não é necessário a sua ordenação
    //se for igual a 0, o vetor está vazio, logo não há nada a fazer.
    if(n <= 1)
        return;

    // Ordena os primeiros n-1 elementos
    recursivo_InsertionSort(A, n-1);

    // Insire o último elemento em sua posição correta
    int k = n-2; 
    int key = A[n-1];
    
    /* Move os elementos de A[0..i-1], que são
      maior que a key, para uma posição à frente
      de sua posição atual */
    for(; A[k] > key && k >= 0; k--){
        A[k+1] = A[k];
    }
    A[k+1] = key;
}

//-------------------------------------------------------------------------------------------------

// Algoritmo SelectionSort Iterativo --------------------------------------------------------------
// Ordena um vetor A[0..n-1]

void iterativo_SelectionSort(int A[], int n){
    // Limite de movimento um a um do subarray não ordenada
    for(int i = 0; i < n-1; i++){
        // Encontra o elemento mínimo em uma array não ordenada
        int min = i;
        for(int j = i+1; j < n; j++){     
            if(A[j] < A[min]){ 
                min = j;
            }
        }
            // Troque o elemento mínimo encontrado pelo primeiro elemento
            std::swap(A[i], A[min]);
    }
}

//-------------------------------------------------------------------------------------------------

// Algoritmo SelectionSort Recursivo --------------------------------------------------------------
// Ordena um vetor A[0..n-1]

void recursivo_SelectionSort(int A[], int n){
    if (n <= 1)
        return;

    int maior = 0;
    // Encontre o maior dos elementos restantes
    for (int i = 1; i < n; i++){
        // Guarda o maior atual.
        if(A[i] > A[maior])
            maior = i;
    }
    
    // Troca quando o índice e o índice maior não são iguais
    if(A[n-1] != A[maior])
        std::swap(A[n-1], A[maior]);

    // Chamando recursivamente a função
    recursivo_SelectionSort(A, n-1);
}

//-------------------------------------------------------------------------------------------------

// Algoritmo para realizar a Intercalação de dois vetores ordenados -------------------------------

/* A função recebe vetores crescentes A[p..q] e A[q+1..r]
 * e rearranja A[p..r] em ordem crescente */
void Intercala (int A[], int p, int q, int r){
    int *W = new int[r-p+1]; // Vetor auxiliar
    int i = p;
    int j = q+1;
    int k = 0;

    // Intercala A[p..q] e A[q+1..r]
    while(i <= q && j <= r){
        if(A[i] <= A[j])
            W[k++] = A[i++];
        else
            W[k++] = A[j++];
    }
    while(i <= q) W[k++] = A[i++];
    while(j <= r) W[k++] = A[j++];

    // Copia vetor ordenado W para o vetor A
    for(i = p; i <= r; i++)
        A[i] = W[i-p];
    
    delete[] W; // Libera memoria alocada
}

//-------------------------------------------------------------------------------------------------

// Algoritmo MargeSort Iterativo ------------------------------------------------------------------
// Ordena um vetor A[0..n-1]

void iterativo_MergeSort(int A[], int n){

    // Esta função rearranja o vetor a[p..r] em ordem crescente.

   for (int tamanho_atual = 1; tamanho_atual <= n-1; tamanho_atual *= 2){

       for (int esquerdo = 0; esquerdo < n-1; esquerdo += 2*tamanho_atual){ 
           int meio = (esquerdo + tamanho_atual-1 < n-1) ? esquerdo + tamanho_atual-1 : n-1;
           int direito = (esquerdo + 2 * tamanho_atual-1 < n-1) ? esquerdo + 2 * tamanho_atual-1 : n-1; 
           
           Intercala(A, esquerdo, meio, direito); 
       }
    }
}

//-------------------------------------------------------------------------------------------------

// Algoritmo MargeSort Recursivo -----------------------------------------------------------------
// Ordena um vetor A[0..n-1]

void recursivo_MergeSort(int A[], int p, int r){
    if(p < r){
        int q = (p + r)/2; // Dividir
        // Conquistar
        recursivo_MergeSort(A, p, q);
        recursivo_MergeSort(A, q + 1, r);
        // Combinar
        Intercala(A, p, q, r);
    }
}

//-------------------------------------------------------------------------------------------------

// Algoritmo para realizar a Semparação de dois vetores -------------------------------------------

/* Recebe um vetor A[p..r] com p <= r.
 * Rearranja os elementos do vetor e devolve
 * j em p..r tal que A[p..j-1] <= A[j] < A[j+1..r].
*/

int separa(int A[], int p, int r){
    int c = A[r]; // pivô
    int j = p; // Índice do menor elemento
    for(int k = p; k < r; k++){
        // Se o elemento atual for menor que o pivô
        if(A[k] <= c){
            std::swap(A[k], A[j]);
            j++; // incrementa o índice do elemento menor
        }
    }
    A[r] = A[j];
    A[j] = c;
    return j;
}

//-------------------------------------------------------------------------------------------------

// Algoritmo QuickSort Iterativo ------------------------------------------------------------------
// Ordena um vetor A[0..n-1]

void iterativo_QuickSort(int A[], int p, int r){

    int pilha[r-p+1];   
    int topo = 0; 
    pilha[topo] = p;
	topo++;
    pilha[topo] = r; 
  
    // Continue enpilhando a pilha enquanto não estiver vazio
    while (topo >= 0) { 
        r = pilha[topo];
		topo--; 
        p = pilha[topo];
		topo--;

        // Define o elemento pivô em sua posição correta
        int q = separa(A, p, r); 
    
        // Se houver elementos no lado esquerdo do pivô,
        // então adicione o lado esquerdo para empilhar
        if (q-1 > p) { 
			topo++;
            pilha[topo] = p;
			topo++;
            pilha[topo] = q-1; 
        } 

        // Se houver elementos no lado direito do pivô,
        // então adicione o lado direito para empilhar
        if (q+1 < r){ 
			topo++;
            pilha[topo] = q+1; 
			topo++;
            pilha[topo] = r; 
        } 
    } 
}

//-------------------------------------------------------------------------------------------------

// Algoritmo QuickSort Recursivo ------------------------------------------------------------------
// Ordena um vetor A[0..n-1]

void recursivo_QuickSort(int A[], int p, int r){
    if(p < r){
        /* i é o índice de particionamento, A[p] agora esta
        no lugar certo */
        int i = separa(A, p, r);
        // Reorganiza os elementos separadamente antes
        // da partição e depois da partição.
        recursivo_QuickSort(A, p, i-1);
        recursivo_QuickSort(A, i+1, r);
    }
}

//-------------------------------------------------------------------------------------------------