#include <iostream>
#include "Fracao.h"
using namespace std;

// Construtor 1
Fracao::Fracao() {
    N = D = 1;
}

// Construtor 2
Fracao::Fracao(int numerador, int denominador) {
    N = numerador;
    D = denominador;
}

// Getters
int Fracao::numerador() {
    return N;
}

int Fracao::denominador() {
    return D;
}

void Fracao::setNumerador(int N) {
    this->N = N;
}

void Fracao::setDenominador(int D) {
    this->D = D;
}

Fracao Fracao::soma( Fracao f2 ) {
    int novoDen = this->D * f2.D;
    int novoNum = (this->N * f2.D) + (f2.N * this->D);
    Fracao nova { novoNum, novoDen };
    return nova;
}

 Fracao::~Fracao() {
     cout << "Fracao destruida" << endl;
 }
