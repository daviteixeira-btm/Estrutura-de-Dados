//  Inclusao  das  bibliotecas
#include <iostream >
#include "Item.h"
#include "QX_Stack.h"

//  Construtor: recebe  capacidade  total da  pilha
QX_Stack::QX_Stack(int n) {
    vetor = new  Item[n];
    capacidade = n;
    topo = 0;
}
    
//  Destrutor: libera o vetor  que  foi  alocado
QX_Stack::~QX_Stack(){
    if(vetor !=  NULL) delete [] vetor;
}

//  isEmpty () -- Pilha  esta  vazia?
bool QX_Stack::isEmpty(){
    return (topo == 0);
}

//  isFull () -- Pilha  esta  cheia?
bool QX_Stack::isFull(){
    return (topo ==  capacidade);
}

// top() -- Consulta  valor do  elemento  no topo
// Supoe  que  pilha  nao  esta  vazia
Item QX_Stack::top(){
    return vetor[topo -1];
}

// push() -- Insere  elemento  no topo
// Supoe  que a pilha  nao  esta  cheia
void QX_Stack::push(Item v){
    vetor[topo] = v;
    topo++;
}

// pop() -- Remove  elemento  do topo e retornavalor
// Supoe  que a pilha  nao  esta  vazia
Item QX_Stack::pop(){
    topo--;
    Item v = vetor[topo];
    return v;
}