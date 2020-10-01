#include <iostream>
#include "BinaryTree.h"

// Cria uma arvore com 5 nós, imprime as chaves e finaliza
// liberando a memoria que foi alocada para a arvore.

using namespace std;

int main(){
// --- Arvore do Slide -----------------------------------
    cout << "\n<--- Arvore do Slide ------------------------------------------------------>" << endl;
    cout << "\nEssa eh a arvore 01\n" << endl;
    Node* a1 = bt_create(34, NULL, NULL);
    Node* a2 = bt_create(21, NULL, NULL);
    Node* a3 = bt_create(76, a1, a2);
    Node* a4 = bt_create(55, NULL, NULL);
    Node* raiz1 = bt_create(1, a3, a4);

    cout << "\nA quantidade de nos: "<< bt_numNos_iterativo(raiz1) << endl;
    cout << "A quantidade de folhas dessa arvore 01 eh: " << bt_countLeaf(raiz1);
    cout << "\n<-------------------------------------------------------------------------->" << endl;
// -------------------------------------------------------

// --- Arvore do Trabalho --------------------------------
    cout << "\n<--- Arvore do Trabalho --------------------------------------------------->" << endl;
    cout << "\nEssa eh a arvore 02" << endl;
    Node* b1 = bt_create(4, NULL, NULL);
    Node* b2 = bt_create(7, NULL, NULL);
    Node* b3 = bt_create(13, NULL, NULL);
    Node* b4 = bt_create(1, NULL, NULL);
    Node* b5 = bt_create(6, b1, b2);
    Node* b6 = bt_create(14, b3, NULL);
    Node* b7 = bt_create(3, b4, b5);
    Node* b8 = bt_create(10, NULL, b6);
    Node* raiz2 = bt_create(8, b7, b8);

    cout << "\nquantidade de nos: "<< bt_numNos_iterativo(raiz2) << endl;
    cout << "\nA quantidade de folhas dessa arvore 01 eh: " << bt_countLeaf(raiz2);
    cout << "\n<-------------------------------------------------------------------------->" << endl;
// -------------------------------------------------------

// -Avore do trabalho igual para testar a função identica-

    cout << "\n<---------Avore do trabalho igual para testar a função identica------------>" << endl;
    cout << "\nEssa eh a arvore 03" << endl;
    Node* c1 = bt_create(4, NULL, NULL);
    Node* c2 = bt_create(7, NULL, NULL);
    Node* c3 = bt_create(13, NULL, NULL);
    Node* c4 = bt_create(1, NULL, NULL);
    Node* c5 = bt_create(6, c1, c2);
    Node* c6 = bt_create(14, c3, NULL);
    Node* c7 = bt_create(3, c4, c5);
    Node* c8 = bt_create(10, NULL, c6);
    Node* raiz3 = bt_create(8, c7, c8);

    cout << "\nquantidade de nos: "<< bt_numNos_iterativo(raiz3) << endl;
    cout << "\nA quantidade de folhas dessa arvore 01 eh: " << bt_countLeaf(raiz3);
    cout << "\n<-------------------------------------------------------------------------->" << endl;
// -------------------------------------------------------

// -Avore binaria com apenas um filho-
    cout << "\n<---------Avore binaria com apenas um filho-------------------------------->" << endl;
    cout << "\nEssa eh a arvore 04" << endl;
    Node* d1 = bt_create(100, NULL, NULL);
    Node* d2 = bt_create(14, NULL, d1);
    Node* d3 = bt_create(15, d2, NULL);
    Node* d4 = bt_create(11, NULL, d3);
    Node* raiz4 = bt_create(9, NULL, d4);

    cout << "\nquantidade de nos: "<< bt_numNos_iterativo(raiz3) << endl;
    cout << "\nA quantidade de folhas dessa arvore 01 eh: " << bt_countLeaf(raiz3);
    cout << "\n<-------------------------------------------------------------------------->" << endl;
// -------------------------------------------------------

// Função identica ---------------------------------------
    cout << "\n<---------Funcao identica-------------------------------------------------->" << endl;
    if(bt_identicas(raiz1, raiz2)){
        cout << "\nAs arvores escolhidas sao iguais!\n" << endl;
    }else{
        cout << "\nAs arvores escolhidas sao diferentes!\n" << endl;
    }

    if(bt_identicas(raiz2, raiz3)){
        cout << "\nAs arvores escolhidas sao iguais!\n" << endl;
    }else{
        cout << "\nAs arvores escolhidas sao diferentes!\n" << endl;
    }
    cout << "\n<-------------------------------------------------------------------------->" << endl;
// -------------------------------------------------------

// Função deleta -----------------------------------------
    cout << "\n<---------Funcao deleta---------------------------------------------------->" << endl;
    bt_print(raiz2);
    bt_deletaLeaf(raiz2);
    // é para deletar as folhas 1, 4, 7 e 13
    cout << "As folhas da arvore foram deletadas!" << endl;
    bt_print(raiz2);
    // é para deletar as folhas 6 e 14
    bt_deletaLeaf(raiz2);
    cout << "As novas folhas da arvore foram deletadas!" << endl;
    bt_print(raiz2);
    cout << "\n<-------------------------------------------------------------------------->" << endl;
// -------------------------------------------------------

// --- Função bt_um_filho --------------------------------
    cout << "\n<---------Funcao Um_Filho-------------------------------------------------->" << endl;
    bt_print(raiz4);
    cout << "\nA quantidade de nos dessa arvore binaria que tem so um filho eh: " << bt_um_filho(raiz4) << endl;
    cout << "\n<-------------------------------------------------------------------------->" << endl;

// -------------------------------------------------------

// --- Função bt_copia -----------------------------------
    cout << "\n<---------Funcao Copia----------------------------------------------------->" << endl;
    bt_copia(raiz4);
    cout << "\n<-------------------------------------------------------------------------->" << endl;

// -------------------------------------------------------
    
    raiz1 = bt_destroy(raiz1);
    cout << "\n<-------------------------------------------------------------------------->" << endl;
    raiz2 = bt_destroy(raiz2);
    cout << "\n<-------------------------------------------------------------------------->" << endl;
    raiz3 = bt_destroy(raiz3);
    cout << "\n<-------------------------------------------------------------------------->" << endl;
    raiz4 = bt_destroy(raiz4);

    return 0;
}