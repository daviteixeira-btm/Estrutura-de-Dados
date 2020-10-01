#include <iostream>

using namespace std;

int fibonacci(int numero){
    if(numero == 0){ //caso base
        return 0;
    }else if(numero == 1){
        return 1;
    }else{ //recursão
        return fibonacci(numero-1) + fibonacci(numero-2);
    }
}

int main(){
    
    int numero;
    cin >> numero;
    
    cout << fibonacci(numero) << endl;
}