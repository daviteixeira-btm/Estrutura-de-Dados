#include <iostream>
#include "BinaryTree.h"

// Cria uma arvore com 5 nós, imprime as chaves e finaliza
// liberando a memoria que foi alocada para a arvore.

int main(){
    Node* a1 = bt_create(34, NULL, NULL);
    Node* a2 = bt_create(21, NULL, NULL);
    Node* a3 = bt_create(76, a1, a2);
    Node* a4 = bt_create(55, NULL, NULL);
    Node* raiz = bt_create(1, a3, a4);

    bt_print(raiz);

    raiz = bt_destroy(raiz);

    return 0;
}