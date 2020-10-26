#include <iostream>

#include "ponto.h"
#include "circulo.h"

using namespace std;

int main(){

    Circulo c(2, 2, 5);

    c.imprime_ponto();

    cout << c.area() << endl;
    cout << c.perimetro() << endl;

    Ponto p1(3,3);
    Ponto p2(20,20);

    cout << c.dentro(p1) << endl;
    cout << c.dentro(p2) << endl;
    
    return 0;
}