#ifndef CIRCULO_H
#define CURCULO_H

#include "ponto.h"

class Circulo{
    private:
        Ponto c;
        float r;

    public:
        //cria um cı́rculo cujo centro é um atributo do tipo Ponto e raio é um float
        Circulo(float xx, float yy, float rr);

        Circulo(Ponto cc, float rr);
        
        //Libera memória alocada, se for necessário
        ~Circulo();

    public:
        Ponto getCentro();
        float getRaio();

        void setCentro(Ponto cc);
        void setRaio(float rr);

        float area();
        float perimetro();
        bool dentro(Ponto p2);
        

    public:
        void imprime_ponto();
    
};

#endif