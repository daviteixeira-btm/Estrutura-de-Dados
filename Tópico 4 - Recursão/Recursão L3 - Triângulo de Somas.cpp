#include <iostream>

using namespace std;

void triangulo(int *vetor, int n){
    int aux[n];
    
    for(int i = 0; i < n; i++)
        aux[i] = vetor[i];
        
    if(n < 1){ //Caso base
        return;
    }
        
    for(int i = 0; i < n; i++) //Soma posições adjacentes
        vetor[i] += vetor[i+1];
        
    triangulo(vetor, n-1); //Chama a função recursivamente
    
    
    cout << "[";    
    for(int i = 0; i < n; i++) //Emprime do vetor empilhado
        cout << aux[i] << ", ";
    cout << "]\n";
}

int main(){
    
    int n;
    cin >> n;
    
    int *vetor = new (nothrow) int [n];
    
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    
    triangulo(vetor, n);
    
    delete[] vetor;
    
    vetor = NULL;
    
    return 0;
}