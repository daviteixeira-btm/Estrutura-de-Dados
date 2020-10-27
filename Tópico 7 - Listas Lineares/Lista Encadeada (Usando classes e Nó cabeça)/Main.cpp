#include <iostream>
#include <climits>
#include "List.h"

using namespace std;

int main(){

    List *lista = new List();

    cout << "\n|-----------------------------------------|" << endl;
    cout << "|            A lista foi criada!          |"   << endl;
    cout << "|-----------------------------------------|\n" << endl;

    int escolha;

    cout << "|---------------------------Bem vindo(a) ao criador de Lista Encadeada-----------------------------|" << endl;
    cout << "|--------------------------------------------------------------------------------------------------|" << endl;
    cout << "| (02) Tamanho da Lista   | (03) Esta vazia?          | (04) Esvaziar lista                        |" << endl;
    cout << "| (05) Mostar Lista       | (06) Print Reverso        | (07) Funcao Add                            |" << endl;
    cout << "| (08) Funcao insertAfter | (09) Funcao Remove        | (10) Funcao Copy                           |" << endl;
    cout << "| (11) Funcao CopyArray   | (12) Funcao removeNodeAt  | (13) Funcao RemoveAll           ___________|" << endl;
    cout << "| (14) Funcao Equal       | (15) Funcao Concatenete   | (16) Funcao Reverse            | (00) Sair |" << endl;
    cout << "|--------------------------------------------------------------------------------------------------|" << endl;

    do{

    cout << endl << "Digite 1 para chamar o menu, ou: \n" << endl;
    cout << "Escolha a opcao do menu: ";
    cin >> escolha;


        switch (escolha){
            case 0:{
                cout << "\n|-----------------------------------------|" << endl;
                cout << "|          A lista foi liberada!          |"   << endl;
                cout << "|          Programa foi FINALIZADO        |"   << endl;
                cout << "|-----------------------------------------|\n" << endl;
            }
                break;
            case 1: {
                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                cout << "| (02) Tamanho da Lista   | (03) Esta vazia?          | (04) Esvaziar lista                        |" << endl;
                cout << "| (05) Mostar Lista       | (06) Print Reverso        | (07) Funcao Add                            |" << endl;
                cout << "| (08) Funcao insertAfter | (09) Funcao Remove        | (10) Funcao Copy                           |" << endl;
                cout << "| (11) Funcao CopyArray   | (12) Funcao removeNodeAt  | (13) Funcao RemoveAll           ___________|" << endl;
                cout << "| (14) Funcao Equal       | (15) Funcao Concatenete   | (16) Funcao Reverse            | (00) Sair |" << endl;
                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
            }
                break;
            case 2:
                cout << "\nO tamanho da lista: " << lista->size() << endl;
                break;
            case 3:
                cout << "A lista esta cheia? Resposta: " << endl;
                if(lista->isEmpty())
                    cout << "\nA lista esta vazia" << endl;
                else
                    cout << "\nA lista nao esta vazia" << endl;
                break;
            case 4:
                lista->clear();
                cout << "\nA lista foi esvaziada! " << endl;
                break;
            case 5: {
                cout << "\nAqui esta a sua lista: " << endl;
                if(lista->isEmpty())
                    cout << "\nSua lista esta vazia..." << endl;
                else    
                    lista->print();
            }
                break;
            case 6: {
                cout << "\nAqui esta a sua lista: " << endl;
                if(lista->isEmpty())
                    cout << "\nSua lista esta vazia..." << endl;
                else    
                    lista->printReverso();
            }
                break;
            case 7: {
                int valor;
                cout << "Insira o valor a ser adicionado: ";
                cin >> valor;
                lista->add(valor);
                cout << "\nValor adicionado!" << endl;
            }
                break;
            case 8: {
                int valor;
                cout << "Insira o valor a ser adicionado na posicao index: ";
                cin >> valor;
                int index;
                cout << "Qual a posicao do index escolhida? index: ";
                cin >> index;
                lista->insertAfter(valor, index);
                cout << "\nValor adicionado!" << endl;
            }
                break;
            case 9: {
                int valor;
                cout << "Insira o valor a ser removido: ";
                cin >> valor;
                lista->remove(valor);
                cout << "\nValor removido!" << endl;
            }
                break;
            case 10: {
                cout << "A lista e: ";
                lista->print();
                cout << "A copia da lista ->: ";
                (lista->copy())->print();
            }
                break;
            case 11: {
                int tamanho = 5;
                int v[] = {27,28,29,30,31};
                lista->copyArray(v, tamanho);
                cout << "A nova lista ->: ";
                lista->print();
            }
                break;
            case 12: {
                int valor;
                cout << "Insira o valor a ser removido da posicao K: ";
                cin >> valor;
                if(valor > 0 && valor < lista->size())
                    lista->removeNodeAt(valor);
                    cout << "\nO valor foi removido!" << endl;
                //cout << "Valor invalido!" << endl;
            }
                break;
            case 13: {
                int valor;
                cout << "Insira o valor a ser removido de toda a lista: ";
                cin >> valor;
                lista->removeAll(valor);
                cout << "\nValor(es) removido(s)!" << endl;
            }
                break;
            case 14: {
                List *lista2 = new List();
                for(int i = 1; i <= 5; i++)
                    lista2->add(i);
                cout << "A lista que sera comparada: ";
                lista2->print();
                if (lista->equal(lista2))
                    cout << "\nSao iguais" << endl;
                cout << "\nSao diferentes" << endl;
            }
                break;
            case 15: {
                List *lista2 = new List();
                for(int i = 1; i <= 5; i++)
                    lista2->add(i);
                cout << "A lista que sera comcatenada: ";
                lista2->print();
                lista->concatenate(lista2);
                cout << "A lista resultante: ";
                lista->print();
            }
                break;
            case 16: {
                cout << "\nA lista atual: " << endl;
                lista->print();
                lista->reverse();
                cout << "\nUsando a funcao Reverse, a lista passa a ficar assim: " << endl;
                lista->print();
            }
                break;
            default:
                cout << "Entrada invalida, Informe novamente!" << endl;
                break;           
        }

    }while (escolha != 0);
}