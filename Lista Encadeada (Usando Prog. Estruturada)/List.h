#ifndef LIST_H
#define LIST_H

//declaração do tipo Node.
struct Node;

// Funcao que cria uma lista vazia
// e retorna nullptr
Node *criaListaVazia();

// Recebe uma chave x e um ponteiro para a lista
// e insere x na lista
Node *adiciona(int x, Node* l);

// Busca uma chave na lista. Se a chave existir, 
// retorna um ponteiro pro no que contem a chave,
// senao, retorna nullptr.
Node *busca(int x, Node *l);

// Retorna o tamanho da lista
int size(Node *l);

// Funcao que recebe como parametro o 
// ponteiro para uma lista e libera todos
// os seus nos para a memoria.
Node *libera(Node *l);

// Remove x da lista se existir 
// Retorna um ponteiro para o primeiro no da lista final
Node *remove(int x, Node *l);

//recebe a cabeça da lista e imprime a lista se tiver nós.
void print(Node *l);

#endif