#include <iostream>

using namespace std;

void preencheArray(int *array, int n);
void imprimeArray(int *array, int n);


int main(){
    int n;
    cout << "Digite o tamanho da Array desejado: " << endl;
    cin >> n;
    int *array = new (std::nothrow) int[n];
    if(array == nullptr){
        cout << "Por favor, peça menos memoria." << endl;
    }else{

    preencheArray(array, n);
    imprimeArray(array, n);

    delete[] array;
    array = nullptr;
    
    }     
    return 0;
}

void preencheArray(int *array, int n){
    for(int i = 0; i < n; i++){
        cout << "Digite um valor: " << endl;
        cin >> array[i];
    }
}

void imprimeArray(int *array, int n){
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}