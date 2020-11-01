#ifndef  QXSTACK_H
#define  QXSTACK_H

#include <iostream>

#include "Item.h"

class  QX_Stack {
    private:
        Item *vetor = NULL;             //  Ponteiro  para um  vetor  de Item
        int  topo = 0;                  //  Posicao  do  proximo  slot  disponivel
        int  capacidade = 0;            //  Tamanho  total  do  vetor
    public:
        QX_Stack(int n);                //  Construtor: recebe  capacidade
        ~QX_Stack();                    //  Destrutor: libera  memoria  alocada
        void  push(Item v);             //  Inserir  elemento  no topo
        Item  pop();                    //  Remover  elemento  do topo
        Item  top();                    //  Consulta  elemento  no topo
        bool  isEmpty();                //  Pilha  esta  vazia?
        bool  isFull();                 //  Pilha  esta  cheia?
};

#endif