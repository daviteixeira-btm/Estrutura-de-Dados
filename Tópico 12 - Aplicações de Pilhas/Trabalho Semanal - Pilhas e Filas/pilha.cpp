#include <iostream>
#include "Item.h"
#include "pilha.h"

using namespace std;

//  Definicao  do  struct  Pilha
struct Pilha{
    Item *vec = NULL; //  vetor  de  inteiros
    int  topo = 0; //  indice  do  proximo  slot
    int  capacity = 0; //  tamanho  do  vetor
};

// Cria  pilha  vazia  com n slots
Pilha *pilha_criar(int n){
    Pilha *p = new  Pilha;
    p->vec = new  Item[n]; //  falta  checar  sucesso
    p->capacity = n;
    p->topoA = 0;
    p->topoB = n -1;
    return p;
}

// Supoe  que a pilha  nao  esta  cheia
void pilha_pushA(Pilha *p, Item v){
    p->vec[p->topoA] = v;
    p->topoA ++;
}

void pilha_pushB(Pilha *p, Item v){
    p->vec[p->topoB] = v;
    p->topoB ++;
}
// Supoe  que a pilha  nao  esta  vazia
Item pilha_popA(Pilha *p){
    p->topoA--;
    return p->vec[p->topoA];
}

Item pilha_popB(Pilha *p){
    p->topoB--;
    return p->vec[p->topoB];
}

Item pilha_topA(Pilha *p){ //  Supoe  pilha  nao vazia
    return p->vec[p->topoA - 1];
}

Item pilha_topB(Pilha *p){ //  Supoe  pilha  nao vazia
    return p->vec[p->topoB - 1];
}

bool pilha_vaziaA(Pilha *p){
    return (p->topoA == 0);
}

bool pilha_vaziaB(Pilha *p){
    return (p->topoB == 0);
}


bool pilha_cheiaA(Pilha *p){
    return (p->topoA == p->capacity);
}

bool pilha_cheiaB(Pilha *p){
    return (p->topoB == p->capacity);
}

void  pilha_destruir(Pilha **p){
    if(*p != NULL){
        if((*p)->vec != NULL)
        delete [] (*p)->vec;
        delete *p;
    }
    
    *p = NULL;
}