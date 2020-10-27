#include <iostream>
#include "List.h"
using namespace std;

int main() {
    Node *lista = criaListaVazia();

    lista = adiciona(32, lista);
    lista = adiciona(34, lista);
    lista = adiciona(384756, lista);
    lista = adiciona(87, lista);
    
    cout << size(lista) << endl;
    print(lista);
    cout << endl;

    lista = remove(34, lista);
    print(lista);
    cout << endl;

    return 0;
}