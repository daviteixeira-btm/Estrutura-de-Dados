#ifndef PONTO_H
#define PONTO_H

class Ponto{
    private:
        float x, y;

    public:
        Ponto();
        Ponto(float a, float b);
        
        ~Ponto();

        float getX();
        float getY();
        void setX(float xx);
        void setY(float yy);
        void imprime_ponto();
        float distancia(Ponto *p2);
};

#endif