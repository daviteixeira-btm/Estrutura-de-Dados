#include <iostream>
#include <climits> // usado para chamar a constante INT_MIN que define o menor inteiro que um int pode armazenar.
#include "SeqList.h"

using std::cout;
using std::cin;
using std::endl;

// Construtor supõe que n > 0
SeqList::SeqList(int n) {
    size_vec = 0;
    capacity_vec = n;
    vec = new (std::nothrow) int[n];
    if (vec == NULL) {
        cout << "Memoria insuficiente" << endl;
        return ;
    }
}

// Destrutor
SeqList::~SeqList() {
    if(vec != NULL){ //se le apontar para uma região de memoria valida
        delete[] vec;
        cout << "\n|-----------------------------------------|" << endl;
        cout << "|          A lista foi liberada!          |"   << endl;
        cout << "|          Programa foi FINALIZADO        |"   << endl;
        cout << "|-----------------------------------------|\n" << endl;
    }
}

//Devolve o tamanho da lista
int SeqList::size(){
    return size_vec;
}

// Retorna true se lista cheia e false caso contrario
bool SeqList::full() {
    //está cheia quando o tamanho for igual a capacidade
    return (size_vec == capacity_vec);
}

//Deixa a lista vazia
void SeqList::clear(){
    size_vec = 0;
}

//Imprime todos os elementos da lista em uma unica linha.
void SeqList::print(){
    for(int i = 0; i < size_vec; i++)
        cout << "(i)[" << i << "]:" << vec[i] << ", ";
    cout << endl;
}

// Busca x e retorna indice se x estiver no vetor
// senao, retorna -1
int SeqList::search(int x) {
    for(int i = 0; i < size_vec; i++){ //percorrer o vetor 
        if(vec[i] == x)
            return i;
    }
    return -1;
}

//Retorna o N-ésimo elemento da lista, ou devolve INT_MIN caso não exista.

int SeqList::at(int index){
    if(index >= 0 && index <= size_vec-1)
        return vec[index];
    return INT_MIN;
}

// Recebe um inteiro x e o adiciona ao final da lista
bool SeqList::add(int x) {
    if( ! full() ) { // se a lista não estiver cheia
        vec[size_vec] = x; // add x na posição size_vec
        size_vec++; // icrementar para ter mais um elemento
        return true;
    }
    else return false;
}

// Remove o primeiro x da lista
void SeqList::remove(int x) {
    int index = search(x); // usar a função search para pegar o indice de x
    if(index > -1) { 
        vec[index] = vec[size_vec-1]; //pega o ultimo e coloca na posição do x
        size_vec--;
        std::cout << "Elemento Removido\n";
    }
} 

//Adiciona o elemento x na posicao 'index'

void SeqList::insertAt(int x, int index) {
    if (size_vec == capacity_vec) return;

    int temp = index; 

    for(int i = size_vec; i >= temp; i--) {
        vec[i + 1] = vec[i];
    }
    
    vec[temp] = x;
    size_vec++;
}

//Troca o elemento na posicao 'index' pelo elemento x
bool SeqList::replaceAt(int x, int index){
    if(index >= 0 && index <= size_vec -1){
        vec[index] = x;
        return true;
    }
    return false;
}

//Remove o elemento na posicao k da lista

bool SeqList::removeAt(int k) {
    //caso o indice seja invalido ou a lista esteja vazia
    if (k >= this->size_vec || this->size_vec == 0) {
        return false;
    }

    for (int i = (k + 1); i < this->size_vec; i++) {
        //voltando 1 casa ate o elemento do indice para remover ele
        this->vec[i - 1] = this->vec[i];
    }
    //diminuindo em 1 unidade o tamnho doa lista
    this->size_vec--;

    return true;
}

//Remove todas as ocorrencias do elemento x na lista
void SeqList::removeAll(int dado){
    for(int i = 0; i <= size_vec - 1; i++)
        if(vec[i] == dado)
            remove(dado);
}
