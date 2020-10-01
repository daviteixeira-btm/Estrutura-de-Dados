// Arvore Binaria usando programação estruturada.

#ifndef ARVOREBIN_H
#define ARVOREBIN_H

struct Node;                                    // Cada nó é do tipo Node;
Node* bt_emptyTree();                           // Retorna nulo, indicando arvore vazia;
Node* bt_create(int key, Node* l, Node* r);     // Cria nó com cha "key";
Node* bt_destroy(Node* node);                   // Libera todos os nós alocados.
bool bt_empty(Node* node);                      // Arvore enraizada em nó esta vazia?;
void bt_print(Node* node);                      // Imprime as chaves da arvore;
bool bt_contains(Node* node, int key);          // Essa chave pertence?;

// Outras formas de printar a arvore
void bt_preorder(Node* node);
void bt_postorder(Node* node);
void bt_inorder(Node* node);

// Funções requeridas e auxiliares 
bool isLeaf(Node* node);                        // Função que retorna true se as folhas da esquerda e direita forem nulas;
int bt_countLeaf(Node* node);                   // Conta o número de folhas de uma árvore binária;
Node* bt_copia(Node *root);                     // Função que crie uma cópia de uma árvore binária;
int bt_numNos_iterativo(Node *no);              // Função não-recursiva que calcula o número de nós de uma árvore binária dada como entrada;
bool bt_identicas(Node *a1, Node *a2);          // Função recursiva que recebe duas árvores binárias como entrada e devolve true se elas forem idênticas; e false, caso contrário.
Node* bt_deletaLeaf(Node* node);                // Função que exclua todas as folhas de uma árvore binária;
int bt_um_filho(Node *root);                    // Função que retorne a quantidade de nós de uma árvore binária que possuem apenas um filho.
#endif