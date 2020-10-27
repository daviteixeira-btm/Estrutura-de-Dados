#include <iostream>
#include <climits>
#include "List.h"

using namespace std;

struct Node {
    int value;
    Node *next;
};

// Construtor
List::List(){
    head = new Node;
    head->value = 0;
    head->next = NULL;
}

// Destrutor
List::~List(){
    clear();
    delete head;
}

// Inserção Interativo
void List::add(int x){
    Node *novo = new Node;
    novo->value = x;
    novo->next = NULL;
    Node *aux = head;
    while(aux->next != NULL)
        aux = aux->next;
    aux->next = novo;
}

// Remover Interativo
void List::remove(int x) {
    Node *anterior = search(x);
    if(anterior != NULL) {
        Node *noRemovido = anterior->next;
        anterior->next = noRemovido->next;
        delete noRemovido;
    }
}

// RemoverAll interativo
void List::removeAll(int x){
    Node *anterior = search(x);
    for (int i = x-1; i >= 0; i--)
        if (anterior != NULL)
            remove(x);
}

bool List::equal(List *lst) {
    if (size() != lst->size())
        return false;

    Node *aux = head->next;
    Node *auy = (lst->head)->next;
    
    while (aux != head && auy != lst->head) {
        if (aux->value != auy->value) 
            return false;
        aux = aux->next;
        auy = auy->next;
    }
    return true;
}

int List::removeNodeAt( int k ){
    if(k >= 0 && k <= size() && !isEmpty()){
        Node *auxiliar = head;
    //ate encontrar o next da posicao k
        for(int i = 0; i < k; i++){
            auxiliar = auxiliar->next;
        }
        auxiliar->next = auxiliar->next->next;
        cout  << "\nO valor removido foi: " << (auxiliar->next->value) << endl;
    }
    return 0;   
}

void List::insertAfter(int x, int k){
    if(k >= 0 && k <= size() && !isEmpty()){
        Node *aux = head;
        Node *auy = head;
        for(int i = 0; i < k; i++){
            aux = aux->next;
            auy = aux->next;
        }
        Node *novo = new Node;
        novo->value = x;
        aux->next = novo;
        novo->next = auy;
    }else
        cout << "Indice invalido" << endl;
}

/*
// Impressão Iterativa
void List::print(){
    Node *aux = head->next;
    while(aux != NULL){
        std::cout << aux->value << " ";
        aux = aux->next;
    }
}
*/

//Impressão recursiva
void List::print() {
    printRecursive(head->next);
    cout << endl;
}

void List::printRecursive(Node *node) {
    if(node == NULL) // Caso base: não tenho nó pra imprimir
        return;
    else {
        std::cout << node->value << " ";
        printRecursive(node->next);
    }
}

//Impressão Reversa Recursiva
void List::printReverso() {
    printRecursiveReverso(head->next);
    cout << endl;
}

void List::printRecursiveReverso(Node *node) {
    if(node == NULL) // Caso base: não tenho nó pra imprimir
        return;
    else {
        printRecursiveReverso(node->next);
        std::cout << node->value << " ";    
    }
}

/*
// clear Interativo
void List::clear(){
    while(head->next != NULL){
        Node *aux = head->next;
        head->next = aux->next;
        delete aux;
    }
}
*/

// Limpando a lista (recursivamente)
void List::clear() {
    head->next = clearRecursive(head);
}

Node *List::clearRecursive(Node *node) {
    if(node == NULL) // Caso base: lista vazia
        return NULL;
    else { // Caso geral
        node->next = clearRecursive(node->next); // 1: remover todo mundo que vem depois
        delete node; // 2: remove o no atual
        return NULL; // 3: retorna nulo para o no que vem antes de voce
    }
}

// Saber se a lista está vazia
bool List::isEmpty() {
    return (head->next == NULL);
}

// Saber o tamanho da lista
int List::size() {
    int soma = 0;
    Node *aux = head->next;
    while(aux != NULL) {
        soma++;
        aux = aux->next;
    }
    return soma;
}

// Retorna ponteiro para o nó anterior ao do elemento x,
// ou retorna NULL caso x não esteja presente

Node *List::search(int x) {
    if(head->next == NULL) return NULL; // lista vazia
    Node *aux = head;
    while((aux->next != NULL) && (aux->next)->value != x) {
        aux = aux->next;
    }
    return ((aux->next == NULL) ? NULL : aux);
}

//Concatenar listas
void List::concatenate(List *lst){
    if(isEmpty()){
        cout << "Lista está vazia" << endl;
    }else{
        Node *aux = head;
        while (aux->next != NULL){
            aux = aux->next; //chego ao ultimo campo da lista
        }        
        aux->next = lst->head->next;
        lst->head->next = NULL;
    }
    cout << "\nListas concatenadas com sucesso" << endl;
}

//Copiar Lista
List* List::copy(){
    List* lst = new List;
    if(!isEmpty()){
        Node *aux = head->next;
        while(aux != NULL){
            lst->add(aux->value);
            aux = aux->next;
        }
    }
    return lst;
}

void List::reverse(){
    if(isEmpty()){
        cout << "Lista vazia!\n";
    }else{
        head->next = auxReverse(head->next);
    }
}

Node *List::auxReverse(Node *aux){
    //caso base:
    if(aux->next == NULL){
        return aux; // retorna o ultimo
    }
    //chamada da recursão
    else{
        Node *ant = aux; // o atual
        //chamar a recursão para pegar o proximo (mover o aux)
        aux = auxReverse(aux->next);
        // proximo a aportar para o anterior

        //percorrer para achar o ultimo elemento
        Node *no = aux;
        while(no->next != NULL){
            no = no->next; //percorrer e encontrar o ultimo
        }
        no->next = ant;
        ant->next = NULL;
        return aux;
    }
}

// Copia os elementos do array v para a lista. 
// O array tem n elementos. 
// Todos os elementos anteriores da lista são apagados.
void List::copyArray(int v[], int n){
    this->clear();
    
    for(int i = 0; i < n; i++){
        this->add(v[i]);
    }
}