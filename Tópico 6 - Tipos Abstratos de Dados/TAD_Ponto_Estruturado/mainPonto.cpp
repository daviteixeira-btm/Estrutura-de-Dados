#include <iostream>
#include "Ponto.h"
using namespace std;

int main() {
    Ponto *p = pto_cria(2.0, 1.0);
    Ponto *q = pto_cria(3.4, 2.1);

    double d = pto_distancia(p, q);

    cout << "Distancia entre pontos: " << d << endl;

    pto_libera(p);
    pto_libera(q);
    
    return 0;
}