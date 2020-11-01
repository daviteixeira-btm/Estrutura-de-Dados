//  Inclusao  das  bibliotecas
#include <iostream >
#include "Item.h"
#include "Stack.h"

//  Construtor: recebe  capacidade  total da  pilha
Stack::Stack(int n) {
    _vec = new  Item[n];
    _capacity = n;
    _top = 0;
}
    
//  Destrutor: libera o vetor  que  foi  alocado
Stack::~Stack(){
    if(_vec !=  NULL) delete [] _vec;
}

//  isEmpty () -- Pilha  esta  vazia?
bool Stack::empty(){
    return (_top == 0);
}

//  isFull () -- Pilha  esta  cheia?
bool Stack::full(){
    return (_top ==  _capacity);
}

// top() -- Consulta  valor do  elemento  no topo
// Supoe  que  pilha  nao  esta  vazia
Item Stack::top(){
    return  _vec[_top -1];
}

// push() -- Insere  elemento  no topo
// Supoe  que a pilha  nao  esta  cheia
void Stack::push(Item v){
    _vec[_top] = v;
    _top ++;
}

// pop() -- Remove  elemento  do topo e retornavalor
// Supoe  que a pilha  nao  esta  vazia
Item Stack::pop(){
    _top --;
    Item v = _vec[_top];
    return v;
}