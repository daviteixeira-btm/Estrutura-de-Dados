#ifndef Pilha_H
#define Pilha_H

#include "Item.h"

struct  Pilha;

Pilha *pilha_criar(int n);              // Cria  pilha  vazia


void  pilha_pushA(Pilha *p, Item v);     // Insere  no topo
void  pilha_pushB(Pilha *p, Item v);     // Insere  no topo
Item  pilha_popA(Pilha *p);              //  Remove  do topo
Item  pilha_popB(Pilha *p);              //  Remove  do topo
Item  pilha_topA(Pilha *p);              //  Consulta  topo
Item  pilha_topB(Pilha *p);              //  Consulta  topo
bool  pilha_vaziaA(Pilha *p);            //  Pilha  esta  vazia?
bool  pilha_vaziaB(Pilha *p);            //  Pilha  esta  vazia?
bool  pilha_cheiaA(Pilha *p);            //  Pilha  esta  cheia?
bool  pilha_cheiaB(Pilha *p);            //  Pilha  esta  cheia?
void  pilha_destruir(Pilha  **p);        //  Libera  pilha

#endif