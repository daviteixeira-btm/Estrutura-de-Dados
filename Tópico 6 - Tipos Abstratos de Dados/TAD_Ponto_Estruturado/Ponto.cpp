// Arquivo Ponto.cpp
// Implementacao do TAD Ponto Usando Programação Estruturada

#include <iostream>
#include <cmath>
#include "Ponto.h"
using namespace std;

struct Ponto {
    double x;
    double y;
};

Ponto *pto_cria(double x, double y){
    Ponto *p = new Ponto;
    if(p == nullptr) {
        cout << "Memoria insuficiente" << endl;
        return nullptr;
    }
    p->x = x;
    p->y = y;
    return p;
}

// Libera a memoria de um ponto previamente criado
void pto_libera(Ponto *p){
    if(p != nullptr) delete p;
}

// Retorna os valores das coordenadas de um ponto
void pto_acessa(Ponto *p, double* x, double *y){
    *x = p->x;
    *y = p->y;
}

// Atribui novos valores as coordenadas de um ponto
void pto_atribui(Ponto *p, double x, double y){
    p->x = x;
    p->y = y;
}

// Retorna a distancia entre dois pontos
double pto_distancia(Ponto* p1, Ponto* p2){
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    return sqrt(dx*dx + dy*dy);
}