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

Node* bt_create(int key, Node* l, Node* r){
    Node* novo = new Node{};
    novo->key = key;
    novo->left = l;
    novo->right = r;
    return novo;
}

bool bt_empty(Node* node){
    return (node == NULL);
}

void bt_print(Node* node){
    if(! bt_empty(node)){
        cout << node->key << endl;
        bt_print(node->left);
        bt_print(node->right);
    }
}

bool bt_contains(Node* node, int key){
    if(node == NULL)
        return false; // Sub-arvore vazia
    else
        return node->key == key ||
               bt_contains(node->left, key) ||
               bt_contains(node->right, key);
    
}
Node* bt_destroy(Node* node){
    if(node != NULL){
        node->left = bt_destroy(node->left);
        node->right = bt_destroy(node->right);
        cout << "Deleting " << node->key << endl;
        delete node;
    }
    return NULL;
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