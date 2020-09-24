#include <iostream>
#include "Pilha.h"

using  namespace  std;

int  main(){
    int n;
    cout  << "Digite  tamanho  da  pilha: ";
    cin  >> n;
    
    Pilha *p = pilha_criar(n); // Cria  uma  pilha  vazia
    
    double  valor;
    
    while (!pilha_cheia(p)){
        cout  << "Digite  um  numero a ser  empilhado: ";
        cin  >> valor;
        pilha_push(p, valor); // Empilha  elementos
    }
    
    while (!pilha_vazia(p)) cout  << pilha_pop(p) << " ";
    
    pilha_destruir (&p); // Libera a pilha
    return  0;
    
}