#include <iostream>
#include <string.h>

using namespace std;

void imprimir(char **Ord, int n){
    for(int i = 0; i < n; i++){
        cout << Ord[i] << "\n";
    }
}

int lexico(char* A, char* B){
    for(int i = 0; A[i] || B[i]; i++){
        if(A[i] > B[i]){
            return 1;
        }else if(A[i] < B[i]){
            return -1;
        }
    }
    return 0;
}

void ordena_vetor(char **Ord, int n){
    
    for(int i = 0; i < n; i++){ //ordenação do vetor
        for(int j = 0; j < n-1; j++){
            if(lexico(Ord[j], Ord[j+1]) == 1){
                swap(Ord[j], Ord[j+1]);
            }
        }
    }
}

int main(){
    
    int n;
    cin >> n;
    
    char **v = new (nothrow) char *[n];
    
    int tamanho_linhas;
    
    for(int i = 0; i < n; i++){
        cin >> tamanho_linhas;
        
        v[i] = new (nothrow) char[tamanho_linhas];
        cin.ignore();
        cin.getline(v[i], tamanho_linhas+1);
        
        if(v == nullptr){
            cout << "Por favor, peça menos memoria.";
            return 0;
        }
        
    }
    
    ordena_vetor(v, n);
    imprimir(v, n);
    
    for(int i = 0; i < n; i++)
        delete v[i];
        
	delete[] v;
    
}