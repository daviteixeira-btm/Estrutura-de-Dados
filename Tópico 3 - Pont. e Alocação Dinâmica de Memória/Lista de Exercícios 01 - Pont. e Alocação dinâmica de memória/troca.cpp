#include <iostream>

using namespace std;

void troca (int *i, int *j) { 
     int temp; 
     temp = *i; 
     *i = *j; 
     *j = temp;
     //a variavel temp nao precisa ser um ponteiro
}

int main() {

    int i = 5, j = 17;

    cout << "Valor de i = " << i << endl;
    cout << "Valor de j = " << j << endl;

    troca(&i, &j);
    cout << "Esses sao os valores trocados de i = " << i << " e j = " << j << endl;
} 