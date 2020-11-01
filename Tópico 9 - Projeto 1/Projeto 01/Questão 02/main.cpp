/*-----------------------------------------------------
|    Autores: Aline Araujo Souza  | Matrícula: 473383 |
|             Davi Teixeira Silva | Matrícula: 433951 |
------------------------------------------------------*/

#include <iostream>
#include <climits>
#include "conjunto.h"

using namespace std;

int main(){

    int capacidade_A, capacidade_B;

    cout << "\nInforme a capacidade do conjunto A: ";
    cin >> capacidade_A;
    cout << "\nInforme a capacidade do conjunto B: ";
    cin >> capacidade_B;

    Conjunto A = Conjunto(capacidade_A);
    Conjunto B = Conjunto(capacidade_B); 

    cout << "\n|-----------------------------------------|" << endl;
    cout <<   "|       Os Conjuntos foram criados!       |" << endl;
    cout <<   "|-----------------------------------------|\n" << endl;

    int comando;
    cout << "Escolha a opcao do menu: " << endl;

    cout << "\n|-------- MENU --------|" << endl;  
    cout <<   "| (1) Conjunto A       |" << endl;
    cout <<   "| (2) Conjunto B       |" << endl;
    cout <<   "|----------------------|\n" << endl;
    cout << "Desejo escolher o Conjunto: ";
    cin >> comando;
    
    Conjunto *Conj_Principal, *Conj_Secundario;

    if(comando == 1){
        cout << "\nVoce escolheu o Conjunto A como principal!" << endl;
        Conj_Principal = &A;
        Conj_Secundario = &B;
    }else if(comando == 2){
        cout << "\nVoce escolheu o Conjunto B como principal!" << endl;
        Conj_Principal = &B;
        Conj_Secundario = &A;
    }else{
        cout << "Entrada invalida, Informe novamente!" << endl;
    }

    int escolha;

        do{

        cout << "\nDigite 1 para chamar o menu, ou: " << endl;
        cout << "\nEscolha a opcao do menu: "; 
        cin >> escolha;


            switch (escolha){
                case 0:{
                    cout << "\n|-----------------------------------------|" << endl;
                    cout << "|          O Conjunto foi liberado!       |"   << endl;
                    cout << "|          Programa foi FINALIZADO        |"   << endl;
                    cout << "|-----------------------------------------|\n" << endl;
                }
                    break;
                case 1: {
                    cout << "\n|-------------Bem vindo(a) ao criador de TAD Conjuntos--------------|" << endl;
                    cout << "|-------------------------------------------------------------------|" << endl;
                    cout << "| (02) Funcao Uniao            | (03) Funcao Interseccao            |" << endl;
                    cout << "| (04) Funcao Diferenca        | (05) Funcao Diferenca Simetrica    |" << endl;
                    cout << "| (06) Funcao Membro           | (07) Funcao Insere                 |" << endl;
                    cout << "| (08) Funcao Remove           | (09) Funcao Copia                  |" << endl;
                    cout << "| (10) Funcao Min              | (11) Funcao Max                    |" << endl;
                    cout << "| (12) Funcao Igual            | (13) Funcao Print                  |" << endl;
                    cout << "|                                                ___________________|" << endl;
                    cout << "|                                               |(00) Destruir/Sair |" << endl;
                    cout << "|-------------------------------------------------------------------|" << endl;
                }
                    break;
                case 2: {
                    cout << "\nA Uniao dos Conjuntos eh:" << endl;
                    Conj_Principal->uniao(*Conj_Secundario);
                    Conj_Principal->print();
                }
                    break;
                case 3: {
                    cout << "A Interseccao dos Conjuntos eh:" << endl;
                    Conj_Principal->interseccao(*Conj_Secundario);
                    Conj_Principal->print();
                }
                    break;
                case 4: {
                    cout << "\nA Diferenca dos Conjuntos eh:" << endl;
                    Conj_Principal->diferenca(*Conj_Secundario);
                    Conj_Principal->print();
                }
                    break;
                case 5: {
                    cout << "\nA Diferenca Simetrica dos Conjuntos eh:" << endl;
                    Conj_Principal->diferencaSimetrica(*Conj_Secundario);
                    Conj_Principal->print();
                }
                    break;
                case 6: {
                    int valor;
                    cout << "Qual valor voce quer buscar? ";
                    cin >> valor;
                    if(Conj_Principal->membro(valor) == true){
                        cout << "\nValor " << valor << " foi encontrado!" << endl;
                    }else{
                        cout << "\nValor " << valor << " não foi encontrado!" << endl;
                    }
                }
                    break;
                case 7: {
                    int comando;
                    cout << "Escolha em qual conjunto voce quer inserir um valor: " << endl;
                    cout << "\n|-------- MENU --------|" << endl;  
                    cout <<   "| (1) Conjunto A       |" << endl;
                    cout <<   "| (2) Conjunto B       |" << endl;
                    cout <<   "|----------------------|\n" << endl;
                    cout << "Desejo escolher o Conjunto: ";
                    cin >> comando;

                    if(comando == 1){
                        cout << "\nVoce escolheu inserir valores no Conjunto A!" << endl;
                        int valor01;
                        cout << "\nInsira um elemento: ";
                        cin >> valor01;
                        Conj_Principal->insere(valor01);
                        cout << "\nO valor (" << valor01 << ") foi adicionado!" << endl;
                    }else if(comando == 2){
                        cout << "\nVoce escolheu inserir valores no Conjunto B!" << endl;
                        int valor02;
                        cout << "\nInsira um elemento: ";
                        cin >> valor02;
                        Conj_Secundario->insere(valor02);
                        cout << "\nO valor (" << valor02 << ") foi adicionado!" << endl;
                    }else{
                        cout << "Entrada invalida, Informe novamente!" << endl;
                    }
                }
                    break;
                case 8: {

                    int comando;
                    cout << "Escolha em qual conjunto voce quer remover um valor: " << endl;
                    cout << "\n|-------- MENU --------|" << endl;  
                    cout <<   "| (1) Conjunto A       |" << endl;
                    cout <<   "| (2) Conjunto B       |" << endl;
                    cout <<   "|----------------------|\n" << endl;
                    cout << "Desejo escolher o Conjunto: ";
                    cin >> comando;

                    if(comando == 1){
                        cout << "\nVoce escolheu remover um valor no Conjunto A!" << endl;
                        int valor01;
                        cout << "\nQual elemento voce quer remover?: ";
                        cin >> valor01;
                        Conj_Principal->remove(valor01);
                        cout << "\nO valor (" << valor01 << ") foi removido!" << endl;
                    }else if(comando == 2){
                        cout << "\nVoce escolheu remover um valor no Conjunto B!" << endl;
                        int valor02;
                        cout << "\nQual elemento voce quer remover?: ";
                        cin >> valor02;
                        Conj_Secundario->remove(valor02);
                        cout << "\nO valor (" << valor02 << ") foi removido!" << endl;
                    }else{
                        cout << "Entrada invalida, Informe novamente!" << endl;
                    }
                }
                    break;
                case 9: {
                    cout << "\nA copia do Conjunto Principal eh:" << endl;
                    Conj_Secundario->copia(*Conj_Secundario);
                }
                    break;
                case 10: {
                    cout << "\nO menor valor do Conjunto eh:" << endl;
                    cout << (Conj_Principal->min(*Conj_Principal)) << endl;
                }
                    break;
                case 11: {
                    cout << "\nO maior valor do Conjunto eh:" << endl;
                    cout << (Conj_Principal->max(*Conj_Principal)) << endl;
                }
                    break;
                case 12: {
                    if(Conj_Principal->igual(*Conj_Secundario)){
                        cout << "\nOs conjuntos sao iguais!" << endl;
                    }else{
                        cout << "\nOs conjuntos sao diferentes!" << endl;
                    }
                }
                    break;
                case 13: {
                    int comando;
                    cout << "Escolha em qual conjunto voce deseja Printar: " << endl;
                    cout << "\n|-------- MENU --------|" << endl;  
                    cout <<   "| (1) Conjunto A       |" << endl;
                    cout <<   "| (2) Conjunto B       |" << endl;
                    cout <<   "|----------------------|\n" << endl;
                    cout << "Desejo printar o Conjunto: ";
                    cin >> comando;

                    if(comando == 1){
                        cout << "\nEsse eh o Conjunto A:" << endl;
                        Conj_Principal->print();
                    }else if(comando == 2){
                        cout << "\nEsse eh o Conjunto B:" << endl;
                        Conj_Secundario->print();
                    }else{
                        cout << "Entrada invalida, Informe novamente!" << endl;
                    }
                }
                    break;
                default:
                    cout << "Entrada invalida, Informe novamente!" << endl;
                    break;           
            }
        }while (escolha != 0);
}