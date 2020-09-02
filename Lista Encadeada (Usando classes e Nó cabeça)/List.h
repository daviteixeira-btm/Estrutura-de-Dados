#ifndef LIST_H
#define LIST_H

struct Node;

class List {
    private:
        Node *head; // Ponteiro para a cabeça da lista
        // Operação auxiliar: retorna no antecessor do nó
        // com valor x, ou NULL caso x não esteja presente.
        Node *search(int x);
        Node *clearRecursive(Node *node); // Clear recursivo.
        void printRecursive(Node *node); // Print recursivo.
        void printRecursiveReverso(Node *node); // Print recursivo de tras pra frente.
        Node *auxReverse(Node *aux);
    public:
        List(); // construtor.
        ~List(); // Destrutor: libera memoria alocada.
/*(V)*/        void add(int x); // Insere x ao final da lista.
/*(V)*/        void remove(int x); // remove o primeiro nó com valor x.
/*(V)*/        void print(); // Imprime elementos.
/*(V)*/        void printReverso(); // Imprime de tras pra frente.
/*(V)*/        void clear(); // deixa a lista vazia.
/*(V)*/        bool isEmpty(); // Esta vazia?
/*(V)*/        int size(); // retorna número de nós.

/*(V)*/        /*(V)*/ void removeAll(int x); // remove todo nó com valor x.
/*(X)*/        /*(X)*/ int removeNodeAt(int k); // Remove a k-ésima célula da lista encadeada e retorna o seu valor.
/*(V)*/        /*(V)*/ void insertAfter(int x, int k); // Insere um novo nó com valor x após o k-ésimo nó da lista.
/*(V)*/        /*(V)*/ List *copy(); // Retorna um ponteiro para uma cópia desta lista.
/*(V)*/        /*(V)*/ void copyArray(int v[], int n); // Copia os elementos do array v para a lista.
/*(V)*/        /*(V)*/ bool equal(List *lst); // Determina se a lista lst, passada por parâmetro, é igual a lista em questão.
/*(V)*/        /*(V)*/ void concatenate(List *lst); // Concatena a lista atual com a lista lst passada por referência.
/*(V)*/        /*(V)*/ void reverse(); // Inverte a ordem dos nós (o primeiro nó passa a ser o último, o segundo passa a ser o penúltimo, etc.)

};
#endif