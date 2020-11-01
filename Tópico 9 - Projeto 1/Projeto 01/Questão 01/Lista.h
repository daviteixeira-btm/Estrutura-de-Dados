/*-----------------------------------------------------
|    Autores: Aline Araujo Souza  | Matrícula: 473383 |
|             Davi Teixeira Silva | Matrícula: 433951 |
------------------------------------------------------*/

#ifndef LISTA_H
#define LISTA_H

struct Node;

class List {

    private:                              // Metodos privados existentes no arquivo List.cpp;
	    Node *head;                       // Nó cabeça;          
    public:                               // Metodos públicos existentes no arquivo List.cpp;
	    List();                           // Construtor;
	    void push_back(int key);          // (02) -> Adicionar valor key após o ultimo nó da lista;
        int pop_back();                   // (03) -> Remove o ultmo nó da lista e printa seu valor;
        void insertAfter(int key, int k); // (04) -> Cria um novo nó com valor key após o nó de indice k;
        void removeNode(Node *p);         // (05) -> Remove um nó apontado pelo ponteiro p;
        void remove(int key);             // (06) -> Remove o nó com valor igual a key;
	    void removeAll(int key);          // (07) -> Remove todos os nós com a ocorrencia do valor key;
        int removeNodeAt(int k);          // (08) -> Remove o nó na "posição" k;
	    void print();                     // (09) -> Printa os valores da lista;
        void printReverse();              // (10) -> Imprime de forma invertida os valores da lista;
	    bool isEmpty();                   // (11) -> Retorna se a lista está ou não vazia;
	    int size();                       // (12) -> Retorna a quantidade de nós da lista;
	    void clear();                     // (13) -> Deleta os nós da lista e a torna uma lista vazia;
	    void concat(List *lst);           // (14) -> Concatena duas listas, limpando a lista passada;
	    List *copy();                     // (15) -> Retorna uma nova lista que é cópia da lista que chama;
	    void copyArray(int n, int *arr);  // (16) -> Recebe um array e seu tamanho e os insere na lista;
	    bool equal(List *lst);            // (17) -> Retorna se uma lista é ou não igual a lista passada;
	    List *separate(int n);            // (18) -> Separa uma lista apartir da primeira ocorrencia do valor n, retorna uma lista que é uma nova lista formada com os elementos restantes;	
	    void merge_lists(List *list2);    // (19) -> Retorna uma lista que é a intercalação da lista que chama e a lista passada;	
        Node *search (int key);           //Busca um valor e retorna um ponteiro; 
		~List();                          // Destrutor.
};

#endif