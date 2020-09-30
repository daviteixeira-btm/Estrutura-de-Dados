// Arvore Binaria usando programação estruturada.

#ifndef ARVOREBIN.H
#define ARVOREBIN.H

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

#endif