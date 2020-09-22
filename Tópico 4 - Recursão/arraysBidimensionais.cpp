#include <iostream>
#include <cstdlib>

using namespace std;

void imprime_matriz(int **Matriz, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            cout << Matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    int n;
    cout << "Digite a ordem da matriz: ";
    cin >> n;

    int **Ptr;
    Ptr = new (nothrow) int *[n]; // aloca uma array de ponteiros de tamanho n

    if(Ptr == NULL){ // verifica se a alocação da memoria foi bem sucedida
        cout << "Erro de Memoria" << endl; 
        exit(1);
    }

    for(int i = 0; i < n; i++){
        // aloca as colunas e inicializa com zeros
        Ptr[i] = new (nothrow) int[n];
        if(Ptr[i] == NULL){
            cout << "Erro de Memoria" << endl;
            exit(1);
        }
    }

    // Ler a Matriz
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> Ptr[i][j];
        }
    }

    imprime_matriz(Ptr, n, n); 

    // Libera a Matriz
    for(int i = 0; i < n; i++)
        delete[] Ptr[1];
    delete[] Ptr;
    
    return 0;
}