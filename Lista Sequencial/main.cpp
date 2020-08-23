#include <iostream>
#include <climits>
#include "SeqList.h"

using namespace std;

int main() {
    int tamanho;
    
    cout << "\nQual tamanho deseja para essa lista? -> lista: ";

    cin >> tamanho;

    SeqList lista = SeqList(tamanho);

    cout << "\n|-----------------------------------------|" << endl;
    cout << "|            A lista foi criada!          |"   << endl;
    cout << "|-----------------------------------------|\n" << endl;

    int escolha;

    cout << "|-----------------------------------Bem vindo(a) ao criador de SeqList--------------------------|" << endl;
    cout << "|-----------------------------------------------------------------------------------------------|" << endl;
    cout << "| (02) Tamanho da Lista  | (03) Esta cheia?        | (04) Esvaziar lista                        |" << endl;
    cout << "| (05) Mostar Lista      | (06) Buscar um Elemento | (07) Funcao Add                            |" << endl;
    cout << "| (08) Funcao At         | (09) Funcao Remove      | (10) Funcao InsertAt                       |" << endl;
    cout << "| (11) Funcao ReplaceAt  | (12) Funcao RemoveAt    | (13) Funcao RemoveAll                      |" << endl;
    cout << "| (00) Sair                                                                                     |" << endl;
    cout << "|-----------------------------------------------------------------------------------------------|" << endl;

    do{

    cout << endl << "Digite 1 para chamar o menu, ou: \n" << endl;
    cout << "Escolha: ";
    cin >> escolha;


        switch (escolha){
            case 0:
                break;
            case 1: {
                cout << "|-----------------------------------------------------------------------------------------------|" << endl;
                cout << "| (02) Tamanho da Lista  | (03) Esta cheia?        | (04) Esvaziar lista                        |" << endl;
                cout << "| (05) Mostar Lista      | (06) Buscar um Elemento | (07) Funcao Add                            |" << endl;
                cout << "| (08) Funcao At         | (09) Funcao Remove      | (10) Funcao InsertAt                       |" << endl;
                cout << "| (11) Funcao ReplaceAt  | (12) Funcao RemoveAt    | (13) Funcao RemoveAll                      |" << endl;
                cout << "| (00) Sair                                                                                     |" << endl;
                cout << "|-----------------------------------------------------------------------------------------------|" << endl;
            }
                break;
            case 2:
                cout << "O tamanho da lista: " << lista.size() << endl;
                break;
            case 3:
                cout << "A lista esta cheia? Resposta: " << lista.full() << endl;
                break;
            case 4:
                lista.clear();
                cout << "A lista foi esvaziada! " << endl;
                break;
            case 5:
                cout << "\nAqui esta a sua lista: " << endl;
                lista.print();
                break;
            case 6: {
                int valor;
                cout << "Qual valor voce deseja procurar? Valor: ";
                cin >> valor;
                int resultado = lista.search(valor);
                if(resultado != INT_MIN)
                    cout << "O valor encontra-se no indice: " << resultado << endl;
                else
                    cout << "Indice invalido" << endl;
            }
                break;
            case 7: {
                int valor;
                cout << "Insira o valor a ser adicionado: ";
                cin >> valor;
                int resultado = lista.add(valor);
                cout << "Valor adicionado!" << endl;
            }
                break;
            case 8: {
                int element_index;
                cout << "Qual index voce deseja que seja retornado? index: ";
                cin >> element_index;
                lista.at(element_index);
                if (element_index != INT_MIN)
                    cout << "O valor no indice " << element_index << " e: " << lista.at(element_index) << endl;
                else 
                    cout << "Indice invalido" << endl;
            }
                break;
            case 9: {
                int valor;
                cout << "Insira o valor a ser removido: ";
                cin >> valor;
                lista.remove(valor);
            }
                break;
            case 10: {
                int valor;
                cout << "Insira o valor a ser adicionado na posicao index: ";
                cin >> valor;
                int index;
                cout << "Qual a posicao do index escolhida? index: ";
                cin >> index;
                lista.insertAt(valor, index);
                cout << "Valor adicionado!" << endl;
            }
                break;
            case 11: {
                int valor;
                cout << "Insira o valor a ser trocado de posicao com o index: ";
                cin >> valor;
                int index;
                cout << "Qual a posicao do index escolhida? index: ";
                cin >> index;
                lista.replaceAt(valor, index);
                cout << "Valor adicionado!" << endl;
            }
                break;
            case 12: {
                int valor;
                cout << "Insira o valor a ser removido da posicao K: ";
                cin >> valor;
                lista.removeAt(valor);
            }
                break;
            case 13: {
                int valor;
                cout << "Insira o valor a ser removido de toda a lista: ";
                cin >> valor;
                lista.removeAll(valor);
            }
                break;
            default:
                cout << "Entrada invalida, Informe novamente!" << endl;
                break;           
        }

    }while (escolha != 0);
}