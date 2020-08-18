#include <iostream>
#include <cmath>

#include "ponto.h"
#include "circulo.h"

using namespace std;

//Construtor do circulo
Circulo::Circulo(float xx, float yy, float rr){
    
    c = Ponto(xx, yy);
    r = rr;
    cout << "Foi Criado!\n";
}

//destrutor (libera memoria)
Circulo::~Circulo(){
    cout << "Circulo Foi Destruido\n";
}

//obtém o centro
Ponto Circulo::getCentro(){
    return c;
}

//obtém o raio
float Circulo::getRaio(){
    return r;
}

//atribui um novo valor ao centro
void Circulo::setCentro(Ponto cc){
    c = cc;
}

//atribui novo valor ao raio do cı́rculo
void Circulo::setRaio(float rr){
    r = rr;
}

//calcula a área do cı́rculo.
float Circulo::area(){
    return 3.1416 * r * r;
}

//calcula o perimetro
float Circulo::perimetro(){
    return 2 * 3.1416 * r;
}

//função para printar o circulo
void Circulo::imprime_ponto(){

    cout << "Centro: ";
    c.imprime_ponto();
    cout << "Raio: " << r << endl;
}

//verifica se o Ponto p está dentro do cı́rculo
bool Circulo::dentro(Ponto p2){

    float dist = c.distancia(&p2);
    if(dist <= r)
        return true;
    else
        return false;
}