#include <iostream>
#include "List.h"

//Tipo nó, de forma recursiva
struct Node {
    int value;  //valor que vai guardar o valor di elementedo da lista.
    Node *next; //ponteiro que vai aportar para o proximo nó da lista.
};

Node *criaListaVazia() {
    return NULL;
}

Node *adiciona(int x, Node* l) {
    Node *novo = new Node;
    novo->value = x;
    if(l == NULL) novo->next = NULL;
    else novo->next = l;     
    l = novo;
    return l;
}

Node *busca(int x, Node *l) {
    if (l != NULL) {
        Node *aux = l;
        while(aux != NULL) {
            if(x == aux->value)
                return aux;
            else            
                aux = aux->next;
        }
    }
    return NULL;
}

int size(Node *l) {
    int total = 0;
    for(Node *aux = l; aux != NULL; aux = aux->next) {
        total++;
    }
    return total; 
}

// Implementar
Node *libera(Node *l){    
    Node *aux = l;
    while(l != NULL){
        l = l->next;
        delete aux;
        aux = l;
    }
    return NULL;
}

// Implementar
Node *remove(int x, Node *l){
    if(l == NULL) //Caso lista vazia
        return NULL;
    Node *aux = l;
    Node *ant = l;
    while(aux != NULL && aux->value != x){
        ant = aux;
        aux = aux->next;
    }
    ant->next = aux->next;
    delete aux;
    return l;
}

void print(Node *l){
    Node *aux = l;
    while(aux != NULL){
        std::cout << aux->value << " ";
        aux = aux->next;
    }
}