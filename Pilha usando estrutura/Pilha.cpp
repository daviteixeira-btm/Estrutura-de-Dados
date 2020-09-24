//  Inclusao  das  bibliotecas
#include <iostream>
#include "Item.h"
#include "Pilha.h"

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
    p->topo = 0;
    return p;
}

// Supoe  que a pilha  nao  esta  cheia
void pilha_push(Pilha *p, Item v){
    p->vec[p->topo] = v;
    p->topo ++;
}
// Supoe  que a pilha  nao  esta  vazia
Item pilha_pop(Pilha *p){
    p->topo--;
    return p->vec[p->topo];
}

Item pilha_top(Pilha *p){ //  Supoe  pilha  naovazia
    return p->vec[p->topo - 1];
}

bool pilha_vazia(Pilha *p){
    return (p->topo == 0);
}

bool pilha_cheia(Pilha *p){
    return (p->topo == p->capacity);
}

void  pilha_destruir(Pilha **p){
    if(*p != NULL){
        if((*p)->vec != NULL)
        delete [] (*p)->vec;
        delete *p;
    }
    
    *p = NULL;
}