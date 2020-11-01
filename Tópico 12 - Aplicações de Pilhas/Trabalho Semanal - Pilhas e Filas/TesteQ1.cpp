#include <iostream>
#include "pilha.h"

using namespace std;

int main(){

    int escolha;

    cout << "|----------------------------------------------------------Bem vindo(a) ----------------------------------------------|" << endl;
    cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "| (01) Chamar menur        | (02) Criar pilha vazia   | (03) Empilhar Pilha A   | (04) Empilhar Pilha B               |" << endl;
    cout << "| (05) Desempilhar Pilha A | (06) Desempilhar Pilha B | (07) Topo da Pilha A    | (08) Topo da Pilha B      (00) Sair |" << endl;
    cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
    
    do{

    cout << "Digite 1 para chamar o menu, ou: \n" << endl;
    cout << "Escolha a opcao do menu: ";
    cin >> escolha;


        switch (escolha){
            case 0:{
                pilha_destruir (&p);
                cout << "\n|-----------------------------------------|" << endl;
                cout << "|          A Pilha foi liberada!          |"   << endl;
                cout << "|          Programa foi FINALIZADO        |"   << endl;
                cout << "|-----------------------------------------|\n" << endl;
            }
                break;
            case 1: {
                cout << "|----------------------------------------------------------Bem vindo(a) ----------------------------------------------|" << endl;
                cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
                cout << "| (01) Chamar menur        | (02) Criar pilha vazia   | (03) Empilhar Pilha A   | (04) Empilhar Pilha B               |" << endl;
                cout << "| (05) Desempilhar Pinha A | (06) Desempilhar Pinha B | (07) Topo da Pilha A    | (08) Topo da Pilha B      (00) Sair |" << endl;
                cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
            }
                break;
            case 2:{
                cout << "\nCriar pilha vazia " << endl;
                //chama a funcao Criar pilha vazia
                int tamanho;
                cout  << "Digite  tamanho  da  pilha: ";
                cin  >> tamanho;

                Pilha *P = pilha_criar(tamanho); // Cria  uma  pilha  vazia
            }
                break;
            case 3:{
                cout << "\nEmpilhar A" << endl; //chamar a funcao Empilhar
                while (!pilha_cheiaA(p)){
                    cout  << "Digite  um  numero a ser  empilhado: ";
                    cin  >> valor;
                    pilha_pushA(p, valor); // Empilha  elementos
                }
            }
                break;
            case 4:{
                cout << "\nEmpilhar B" << endl; //chamar a funcao Empilhar
                while (!pilha_cheiaB(p)){
                    cout  << "Digite  um  numero a ser  empilhado: ";
                    cin  >> valor;
                    pilha_pushB(p, valor); // Empilha  elementos
                }
            }
                break;
            case 5:{
                cout << "\nDesempilhar A" << endl; //chama a funcao Desempilhar
                while (!pilha_vaziaA(p)) cout  << pilha_popA(p) << " ";
            }
                break;
            case 6:{
                cout << "\nDesempilhar B" << endl; //chama a funcao Desempilhar
                while (!pilha_vaziaB(p)) cout  << pilha_popB(p) << " ";
            }
                break;
            case 7:{
                cout << "\nConsultar o topo de A" << endl; //chama a funcao Consultar o topo
                cout << "\nO topo de A: " << pilha_topA();
            }
                break;
            case 8:{
                cout << "\nConsultar o topo de B" << endl; //chama a funcao Consultar o topo
                cout << "\nO topo de B: " << pilha_topB();
            }
                break;
            default:
                cout << "Entrada invalida, Informe novamente!" << endl;
                break;           
        }

    }while (escolha != 0);
}