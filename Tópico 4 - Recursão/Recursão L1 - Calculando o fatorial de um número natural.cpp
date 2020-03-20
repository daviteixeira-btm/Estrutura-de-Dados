#include <iostream>

using namespace std;

int fatorial(int numero){
    if((numero == 0) || (numero == 1)){ // caso base
        return 1;
    }else{ // recursão
        return numero * fatorial(numero-1);
    }
}

int main(){
    int numero;
    cin >> numero;
    
    cout << fatorial(numero) << endl; 
    
    return 0;
}