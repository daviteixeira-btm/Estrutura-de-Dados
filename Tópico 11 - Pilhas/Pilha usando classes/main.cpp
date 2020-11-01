#include <iostream>

#include "Item.h"
#include "Stack.h"

using namespace  std;

int main(){
    int n;
    cout  << "Digite  tamanho  da  pilha: ";
    cin  >> n;
    
    Stack *pilha = new  Stack(n); // Cria  uma  pilha  vazia
    
    Item  valor;
    
    while (!pilha->full()){
        
        cout << "Digite  um  numero a ser  empilhado: ";
        cin  >> valor;
        pilha->push(valor);
    }
    
    while (!pilha->empty()) cout  << pilha ->pop() << " ";

    delete  pilha; //  Libera a pilha
        
    return  0;
}