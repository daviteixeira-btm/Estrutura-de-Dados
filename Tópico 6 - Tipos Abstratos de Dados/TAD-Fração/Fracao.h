#ifndef FRACAO_H
#define FRACAO_H

class Fracao {
    private:
        int N;
        int D;
    public:
        Fracao();                       // construtor
        Fracao(int N, int D);           // construtor
        int numerador();                // getter
        int denominador();              // getter
        void setNumerador(int x);       // setter
        void setDenominador(int x);     // setter
        Fracao soma( Fracao f2 );       // soma f2 com a fracao atual
        ~Fracao();
};

#endif