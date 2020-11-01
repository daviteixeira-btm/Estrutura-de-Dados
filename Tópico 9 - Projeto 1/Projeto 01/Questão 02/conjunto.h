/*-----------------------------------------------------
|    Autores: Aline Araujo Souza  | Matrícula: 473383 |
|             Davi Teixeira Silva | Matrícula: 433951 |
------------------------------------------------------*/

#ifndef CONJUNTO_H
#define CONJUNTO_H

class Conjunto{

    private:                                        // Metodos privados existentes no arquivo List.cpp;
	    int *vetor = NULL;                          // Vetor de inteiros;
        int tamanho;                                // Qtd de elementos no vetor;
        int capacidade;                             // Capacidade total do vetor;

    public:                                         // Metodos públicos existentes no arquivo List.cpp;
        Conjunto(int capacidade);                   // Cria um conjunto vazio e retorna o conjunto criado;
        ~Conjunto();
        bool insere(int y);                         // Recebe o conjunto A e um elemento y e adiciona y ao conjunto A, isto e, A = A ∪ y;
        bool remove(int y);                         // Recebe o conjunto A e um elemento y e remove y do conjunto A, isto e, A = A - y;
        bool membro(int y);                         // Recebe o conjunto A e um elemento y e retorna um 1 se y ∈ A e 0 caso contrario;
        void uniao(Conjunto &conj);                 // Recebe os conjuntos A e B como parametro e retorna o conjunto C = A ∪ B;
        void interseccao(Conjunto &conj);           // Recebe os conjuntos A e B como parametro e retorna o conjunto C = A ∩ B;
        void diferenca(Conjunto &conj);             // Recebe os conjuntos A e B como parametro e retorna o conjunto C = A - B;
        int min(Conjunto &conj);                    // Retorna o valor mınimo do conjunto A;
        int max(Conjunto &conj);                    // Retorna o valor maximo do conjunto A;
        bool igual(Conjunto &conj);                 // Retorna true se os conjuntos A e B são iguais e false caso contrario;
        void copia(Conjunto &conj);                 // Faz uma copia do conjunto A em B;
        void diferencaSimetrica(Conjunto &conj);    // Recebe os conjuntos A e B como parametro e retorna o conjunto C = A o B;

        // Métodos auxiliares

        void print();                               // Essa função serve para printar os valores dos conjuntos.
        bool nao_membro(int y);                     // Recebe o conjunto A e um elemento y e retorna um 0 se y ∈ A e 1 caso contrario.
};

#endif