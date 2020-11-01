#ifndef Pilha_H
#define Pilha_H

#include "Item.h"

struct  Pilha;

Pilha *pilha_criar(int n);              // Cria  pilha  vazia

void  pilha_push(Pilha *p, Item v);     // Insere  no topo
Item  pilha_pop(Pilha *p);              //  Remove  do topo
Item  pilha_top(Pilha *p);              //  Consulta  topo
bool  pilha_vazia(Pilha *p);            //  Pilha  esta  vazia?
bool  pilha_cheia(Pilha *p);            //  Pilha  esta  cheia?
void  pilha_destruir(Pilha  **p);       //  Libera  pilha

#endif