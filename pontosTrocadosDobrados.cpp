#include <iostream>

using namespace std;


struct Ponto {
    float x;
    float y;
};

void trocarPonto(Ponto *p1, Ponto *p2){
    Ponto aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

void dobrarPonto(Ponto *p){
    p->x = p->x * 2;
    p->y = p->y * 2;
}

int main(){
    Ponto a = {2, 3};
    Ponto b = {4, 5};

    trocarPonto(&a, &b);
    cout << "Os pontos trocados: " << a.x << ", " << a.y << endl;
    cout << "Os pontos trocados: " << b.x << ", " << b.y << endl;
    
    dobrarPonto(&a);
    dobrarPonto(&b);

    cout << "Os pontos dobrados: " << a.x << ", " << a.y << endl; 
    cout << "Os pontos dobrados: " << b.x << ", " << b.y << endl;

    return 0; 

}
