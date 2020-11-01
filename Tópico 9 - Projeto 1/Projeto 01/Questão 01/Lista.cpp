/*-----------------------------------------------------
|    Autores: Aline Araujo Souza  | Matrícula: 473383 |
|             Davi Teixeira Silva | Matrícula: 433951 |
------------------------------------------------------*/

#include <iostream>
#include <climits>
#include "Lista.h"

using namespace std;

struct Node{
	int valor;
	Node *proximo;
	Node *anterior; 
};

//Método construtor;
List::List(){
    head = new Node;        // cria o nó cabeça;
    head->valor = 0;        // valor padrão;
                            // Inicialmente tanto o anterior como o proximo apontam para a cabeça.
    head->proximo = head;
    head->anterior = head;
    return;
}

// Método que cria e adiciona um nó com valor key;
void List::push_back(int key){
    Node *novoNode = new Node;                // Cria um ponteiro que aponta para um novo nó;

    head->anterior->proximo = novoNode;       // O (head anterior) aponta para o proximo recebe o novoNode;
    novoNode->valor = key;                    // O novoNode recebe um novo valor;
    novoNode->proximo = head;                 // O (novoNode proximo) aponta para o head;
    novoNode->anterior = head->anterior;
    head->anterior = novoNode;                // Por fim, o (head anterior) aponta para o novoNode.
}

int List::pop_back(){
    if(!isEmpty()){
        Node *auxiliar = head->anterior;     // Receber o endereço do (head anterior) que aponta para o último;
        int elemento = auxiliar->valor;      // Recebe o valor que sera retornado e apagado da lista;
        
        head->anterior = auxiliar->anterior; // Agora, o (head anterior) vai apontar para o (auxiliar anterior);
        auxiliar->anterior->proximo = head;  // Por fim, o ultimo nó vai apontar para a cabeça;
        
        delete auxiliar;
        return elemento;
    }else{
        return INT_MIN;
    }
}

void List::insertAfter(int key, int k){
    if(k >= 0 && k < size()){
        Node *auxiliar = head->proximo;         // Faço auxiliar receber a cabeça da lista;

        for(int i = 0; i < k; i++)              // Percorre a lista até encontrar o k-ésimo nó; 
            auxiliar = auxiliar->proximo;
        
        Node *novoNode = new Node;

        novoNode->valor = key;                  // novoNode recebe o valor passado;
        novoNode->proximo = auxiliar->proximo;  // Com isso mudamos todas as posicoes dos nós posteriores; 
        novoNode->anterior = auxiliar;          // Faço o node anterior receber o auxiliar que tem o endereço da cabeça;
        auxiliar->proximo->anterior = novoNode; // A cabeça aponta para o novoNode;
        auxiliar->proximo = novoNode;           // A (cabeça proximo) recebe o novoNode.
    }else{
        cout << "O indice eh invalido" << endl;
    }
}

Node* List::search (int key) {
    Node *auxiliar = head->proximo;

    while(auxiliar != head && auxiliar->valor != key)  // Essa função vai procurar até achar o valor passado pelo usuario,
        auxiliar = auxiliar->proximo;                  // retornando o ponteiro desse valor.
    return (auxiliar == head) ? NULL : auxiliar;
}

void List::removeNode(Node *p){
    p->anterior->proximo = p->proximo;          // O nó p-1 ira receber o endereço do anterior de p;
    p->proximo->anterior = p->anterior;         // O anterior do nó p+1 vai receber o endereço do proximo do p-1.

    p->proximo = NULL;
    p->anterior = NULL;

    delete p;
}

void List::remove(int key){
    Node *auxiliar = head->proximo;

    while(auxiliar != head){
        if(auxiliar->valor == key){ // caso ocorra, ela irá puxar os valores das posiçoes do anteriores e posteriores do valor removido.
            auxiliar->anterior->proximo = auxiliar->proximo;
            auxiliar->proximo->anterior = auxiliar->anterior;

            auxiliar->proximo = NULL;
            auxiliar->anterior = NULL;
            delete auxiliar;
            return;
        }
        auxiliar = auxiliar->proximo;
    }
    cout << "\nValor nao encontrado" << endl;
}

void List::removeAll(int key){
    Node *auxiliar = head->proximo;
    int sinal = 0;

    while(auxiliar != head){
        if(auxiliar->valor == key){
            Node *apaga = auxiliar;                        // Esse nó "apaga" serve para guardar o valor que sera apagado,
                                                           // em todas as ocorrencias que esse valor for encontrado dentro
                                                           // do while.
            apaga->anterior->proximo = apaga->proximo;
            apaga->proximo->anterior = apaga->anterior;
            auxiliar = auxiliar->proximo;

            apaga->proximo = NULL;
            apaga->anterior = NULL;
            delete apaga;
            sinal = 1;
        }else{
            auxiliar = auxiliar->proximo;
        }
    }

    if(sinal)
        cout << "\nElementos " << key << " removidos!" << endl;
    else
        cout << "\n Nao existe esse valor " << key << " na lista!" << endl;
}

int List::removeNodeAt(int k){
	Node *auxiliar = head->proximo;
    
    int cont = 0;
	while(auxiliar != head){

		if(cont == k){                       // Quando o cont for equivalente a k,
			int guarda = auxiliar->valor;    // o valor vai ser guardado e o auxiliar vai ser removido.
			this->removeNode(auxiliar);
			return guarda;
		}
        auxiliar = auxiliar->proximo;
        cont+=1;
	}
    return INT_MIN;
}

void List::print() {
    Node *auxiliar = head->proximo;

    while (auxiliar != head) {
        cout << auxiliar->valor << " ";
        auxiliar = auxiliar->proximo;
    }
    cout << endl;
}

// Percorre a lista ao contrário printando seus valores.
void List::printReverse(){
    Node *auxiliar = head->anterior; //em vez de usarmos o (head proximo) usamos o (head anterior).

    while (auxiliar != head) {
        cout << auxiliar->valor << " ";
        auxiliar = auxiliar->anterior; 
    }
    cout << endl;
}

// Verificar se a lista está vazia.
bool List::isEmpty(){
    return head->proximo == head;
}

// Percorre a lista contando a quatidade de elementos.
int List::size() {
    Node *auxiliar = head->proximo;
    int cout = 0;

    while (auxiliar != head) {
        cout++;
        auxiliar = auxiliar->proximo;
    }
    return cout;
}

void List::clear(){
    if (!isEmpty()){
        Node *aux_frente;
        Node *aux_atras;

        while (!isEmpty()) {
            aux_atras = head->anterior;              //operação circular
            head->anterior = aux_atras->anterior;

            aux_frente = head->proximo;             //operação circular
            head->proximo = aux_frente->proximo;
                                                    //por fim o head vai guardar um ponteiro para o ultimo endereço que estava 
                                                    //no aux_frente e no aux_atras, caso principal para limpar a lista totalmente
            delete aux_frente;
            delete aux_atras;
        }
    }
    else
        cout << "A lista ja esta vazia" << endl;
}

void List::concat(List* lst){
    if(!lst->isEmpty()){
        //feita completamente usando só manipulação de ponteiors.
        this->head->anterior->proximo = lst->head->proximo;
        lst->head->proximo->anterior = this->head->anterior;
        lst->head->anterior->proximo = this->head;
        this->head->anterior = lst->head->anterior;
        lst->head->anterior = lst->head;
        lst->head->proximo = lst->head;
    }
    cout << "\nListas concatenadas com sucesso" << endl;
}

List *List::copy() {
    List *listaCopia = new List();              // cria uma uma nova lista,
    Node *auxiliar = head->proximo;             // e um ponteiro que aponta para ela;

    while (auxiliar != head) {
        listaCopia->push_back(auxiliar->valor); // adiciona os elementoda da lista a ser copiada na nova.
        auxiliar = auxiliar->proximo;
    }
    return listaCopia;
}

void List::copyArray (int n, int *arr) {
    for (int i = 0; i < n; i++)
        push_back(arr[i]);                    // usamos a função push_back para add os elementos do vetor na lista copiada.
    cout << "Array copiado." << endl;
}

bool List::equal(List *lst) {
    if(size() != lst->size())      // Aqui, verificamos se os tamanhos são iguais;
        return false;    
    
    Node *auxiliar1 = head->proximo;
    Node *auxiliar2 = (lst->head)->proximo;

    while (auxiliar1 != head && auxiliar2 != lst->head) {
        
        if (auxiliar1->valor != auxiliar2->valor) // aqui verificamos se os valores são diferentes;
            return false;
        
        auxiliar1 = auxiliar1->proximo;           // aqui percorremos todas as posições das duas listas.  
        auxiliar2 = auxiliar2->proximo;
    }
    return true;
}

List *List::separate(int n){
    List *separada = new List();
    Node *auxiliar = head->proximo; //ultimo

    while(auxiliar != head){ //procurar o n
        if(auxiliar->valor == n){
            
            separada->head->proximo = auxiliar->proximo;  //passo a preencher a nova lista com os valores que separei
            separada->head->anterior = head->anterior;    //faco ela apontar para o head anterior == ultimo, para atuar de forma circula
            
            auxiliar->proximo->anterior = separada->head;
            head->anterior->proximo = separada->head;
            auxiliar->proximo = head;
            head->anterior = auxiliar;
            return separada;
        }
    }
    return separada;
}
	
void List::merge_lists (List *list2) {
    int index = 0;
    while (!list2->isEmpty()) {
        Node *auxiliar = (list2->head)->proximo;
        insertAfter(auxiliar->valor, index);   //insiro os valores da nova lista sempre de 2 em 2 (index+=2)
        list2->removeNode(auxiliar);           //chamo o remove node e removo o no auxiliar que criei para percorrer a nova lista
        index += 2;
    }
    cout << "Listas misturadas com sucesso" << endl;
}

List::~List(){  // Metodo destrutor.
    clear();
    delete head;
}