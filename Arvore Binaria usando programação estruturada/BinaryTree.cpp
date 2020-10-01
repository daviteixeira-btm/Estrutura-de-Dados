#include <stack>
#include <iostream>
#include "BinaryTree.h"

using namespace std;

struct Node{        // Sem ponteiro para o pai;
    int key;
    Node *left;     // Sub arvore esquerda;
    Node *right;    // Sub arvore direita.
};

Node* bt_emptyTree(){
    return NULL;
}

/*Função que cria um nó em uma Árvore Binária.*/
Node* bt_create(int key, Node* l, Node* r){
    Node* novo = new Node{};
    novo->key = key;
    novo->left = l;
    novo->right = r;
    return novo;
}

/*Testa se uma Árvore Binária é vazia.*/
bool bt_empty(Node* node){
    return (node == NULL);
}

/*Função que determina se um inteiro pertence à Árvore.*/
bool bt_contains(Node* node, int key){
    if(node == NULL)
        return false; // Sub-arvore vazia
    else
        return node->key == key ||
               bt_contains(node->left, key) ||
               bt_contains(node->right, key);
    
}

/*Libera o espaço alocado para uma Árvore Binária.*/
Node* bt_destroy(Node* node){
    if(node != NULL){
        node->left = bt_destroy(node->left);
        node->right = bt_destroy(node->right);
        cout << "Deleting " << node->key << endl;
        delete node;
    }
    return NULL;
}

// Funções requeridas e auxiliares

int bt_countLeaf(Node* node) {
	if(bt_empty(node)){
		return 0;
	} else {
		if(bt_empty(node->left) && bt_empty(node->right)){
			return 1;
		} else {
			int l = bt_countLeaf(node->left);
            int r = bt_countLeaf(node->right);
            return l+r;
		}
	}
}

bool isLeaf(Node* node){
    return node->left == NULL && node->right == NULL;
}

Node* bt_deletaLeaf(Node* node){
    if(node == NULL){
        return NULL;
    }else if(isLeaf(node)){
        delete node;
        return NULL;
    }else{
        node->left = bt_deletaLeaf(node->left);
        node->right = bt_deletaLeaf(node->right);
        return node;
    }
}

bool bt_identicas(Node *a1, Node *a2){
    if(a1 == NULL && a2 == NULL){                           // caso base
        return true;
    }else if(a1 == NULL || a2 == NULL){
        cout << "*";
        return false;   
    }else{                                                  // chamada da recursão
        if(a1->key == a2->key){                             // se os valores forem iguais, continuo verificando se tem alguma diferença nos filhos esquerdos
            bool l = bt_identicas(a1->left, a2->left);
            bool r = bt_identicas(a1->right, a2->right);
            return l&&r;                                    // retorna quandos os dois são iguais
        }else{
            return false;
        }
    }
}

Node* bt_copia(Node* root){
    if(root == NULL){
        return NULL;
    }else{
        Node* novo = new Node;                  // Cria um novo nó para receber um valor da árvore original.
        novo->key = root->key;
        cout << root->key << endl;
        novo->right = bt_copia(root->left);
        novo->left = bt_copia(root->right);     
        return novo;                            // Retorna para o nó anterior, para que a ligação entre os nós seja feita.
    }
}

/*Função que imprime os elementos de uma Árvore Binária.*/
void bt_print(Node* node){
    if(! bt_empty(node)){
        cout << node->key << endl;
        bt_print(node->left);
        bt_print(node->right);
    }
}

/*Função que imprime os elementos de uma Árvore Binária e a quantidade de nós de forma interativa.*/
int bt_numNos_iterativo(Node *no){
    int quantidade = 0;
    std::stack<Node*> p;
    
    Node* node = no;

    while(node != NULL || !p.empty()){
        if(node != NULL){
            quantidade++;
            p.push(node);
            cout << node->key << endl;
            node = node->left;
        }else{
            node = p.top();
            p.pop();
            node = node->right;
        }
    }
    return quantidade;
}

int bt_um_filho(Node* root){
  if((root == NULL) || (root->left == NULL && root->right == NULL)){
      return 0;
  }
  return 1 + bt_um_filho(root->left) + bt_um_filho(root->right);
}

// Outras formas de printar a arvore

void bt_preorder(Node* node){
    if(node != NULL){
        cout << node->key << endl; /* visita raiz */
        bt_preorder(node->left);
        bt_preorder(node->right);
    }
}

void bt_postorder(Node* node){
    if(node != NULL){
        bt_preorder(node->left);
        bt_preorder(node->right);
        cout << node->key << endl; /* visita raiz */
    }
}

void bt_inorder(Node* node){
    if(node != NULL){
        bt_preorder(node->left);
        cout << node->key << endl; /* visita raiz */
        bt_preorder(node->right);
    }
}