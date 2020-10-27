#include <iostream>
#include "Fracao.h"
using namespace std;

int main() {
    Fracao f1 {2, 5};
    Fracao f2 {34, 5};

    Fracao f3 = f1.soma(f2);

    cout << f3.numerador() << "/" << f3.denominador() << endl;

    return 0;
}