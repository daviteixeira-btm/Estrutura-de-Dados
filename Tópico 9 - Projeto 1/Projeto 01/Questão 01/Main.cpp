/*-----------------------------------------------------
|    Autores: Aline Araujo Souza  | Matrícula: 473383 |
|             Davi Teixeira Silva | Matrícula: 433951 |
------------------------------------------------------*/

#include <iostream>
#include <climits>
#include "Lista.h"

using namespace std;

int main(){

    //List(): Construtor da classe
    List *lista = new List();
    cout << "\n|-----------------------------------------|" << endl;
    cout <<   "|            A lista foi criada!          |"   << endl;
    cout <<   "|-----------------------------------------|\n" << endl;

    int escolha;

    cout << "|-----------------Bem vindo(a) ao criador de lista circular duplamente encadeada-------------------|" << endl;
    cout << "|--------------------------------------------------------------------------------------------------|" << endl;
    cout << "| (02) Funcao push_back         | (03) Funcao pop_back          | (04) Funcao insertAfter          |" << endl;
    cout << "| (05) Funcao removeNode        | (06) Funcao remove            | (07) Funcao removeAll            |" << endl;
    cout << "| (08) Funcao RemoveNodeAt      | (09) Funcao print             | (10) Funcao printReverse         |" << endl;
    cout << "| (11) Funcao empty             | (12) Funcao size              | (13) Funcao clear                |" << endl;
    cout << "| (14) Funcao concat            | (15) Funcao *copy             | (16) Funcao copyArray            |" << endl;
    cout << "| (17) Funcao equal             | (18) Funcao separate          | (19) Funcao merge_lists          |" << endl;
    cout << "|                                                                               ___________________|" << endl;
    cout << "|                                                                              |(00) Destruir/Sair |" << endl;
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
                cout << "|-----------------Bem vindo(a) ao criador de lista circular duplamente encadeada-------------------|" << endl;
                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                cout << "| (02) Funcao push_back         | (03) Funcao pop_back          | (04) Funcao insertAfter          |" << endl;
                cout << "| (05) Funcao removeNode        | (06) Funcao remove            | (07) Funcao removeAll            |" << endl;
                cout << "| (08) Funcao RemoveNodeAt      | (09) Funcao print             | (10) Funcao printReverse         |" << endl;
                cout << "| (11) Funcao empty             | (12) Funcao size              | (13) Funcao clear                |" << endl;
                cout << "| (14) Funcao concat            | (15) Funcao *copy             | (16) Funcao copyArray            |" << endl;
                cout << "| (17) Funcao equal             | (18) Funcao separate          | (19) Funcao merge_lists          |" << endl;
                cout << "|                                                                               ___________________|" << endl;
                cout << "|                                                                              |(00) Destruir/Sair |" << endl;
                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
            }
                break;
            case 2: {
                //void push back(int key): Insere um inteiro key ao final da lista.
                int valor;
                cout << "Insira o valor a ser adicionado: ";
                cin >> valor;
                lista->push_back(valor);
                cout << "\nUm novo elemento foi adicionado!" << endl;
            }
                break;
            case 3:{
                //int pop back(): Remove elemento do final da lista e retorna seu valor
                cout << "\nElemento " <<  lista->pop_back() << " foi removido!"<< endl;
            }
                break;
            case 4: {
                //void insertAfter(int key, int k): Insere um novo no com valor key apos o k-esimo no da lista.
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
            case 5: {
                //void removeNode(Node *p): Remove da lista o no apontado pelo ponteiro p
                int valor;
                cout << "Qual o valor que voce quer remover? ";
                cin >> valor;
                lista->removeNode(lista->search(valor));
                cout << "\nNo removido!" << endl;
            }
                break;
            case 6: {
                //void remove(int key): Remove da lista a primeira ocorrencia do inteiro key
                int key;
                cout << "Qual inteiro voce quer remover? ";
                cin >> key;
                lista->remove(key);
                cout << "\nValor removido!" << endl;
            }
                break;
            case 7: {
                //void removeAll(int key): Remove da lista todas as ocorrencias do inteiro key
                int key;
                cout << "Insira o valor a ser removido de toda a lista: ";
                cin >> key;
                lista->removeAll(key);
            }
                break;
            case 8: {
                //int removeNodeAt(int k): Remove o k-esimo no da lista encadeada e retorna o seu valor
                int k;
                cout << "Insira a posicao a ser removida: ";
                cin >> k;
                cout << "\nO valor " << lista->removeNodeAt(k) << " foi removido!" << endl;
            }
                break;
            case 9: {
                //void print(): Imprime os elementos da lista
                if(lista->isEmpty()){
                    cout << "\nSua lista esta vazia..." << endl;
                }else{
                    cout << "\nAqui esta a sua lista: " << endl;
                    lista->print();
                }
            }
                break;
            case 10: {
                //void printReverse(): Imprime os elementos da lista em ordem reversa.
                cout << "\nA lista atual: " << endl;
                lista->print();
                cout << "\nUsando a funcao Reverse, a lista passa a ficar assim: " << endl;
                lista->printReverse();
            }
                break;
            case 11: {
                //bool empty(): Retorna true se a lista estiver vazia e false caso contr´ario.
                cout << "A lista esta cheia? Resposta: " << endl;
                if(lista->isEmpty())
                    cout << "\nA lista esta vazia" << endl;
                else
                    cout << "\nA lista nao esta vazia" << endl;
            }
                break;
            case 12: {
                //int size(): Retorna o numero de nos da lista
                cout << "\nA lista tem " << lista->size() << " nos" << endl;
            }
                break;
            case 13: {
                //void clear(): Remove todos os elementos da lista e deixa apenas o no cabeca.
                lista->clear();
                cout << "\nA lista foi esvaziada! " << endl;   
            }
                break;
            case 14: {
                /* void concat(List *lst): Concatena a lista atual com a lista lst passada por
                parametro. Apos essa operacao ser executada, lst sera uma lista vazia, ou seja, o
                unico no de lst sera o no cabeca. */
                List *lst = new List();
                int elementos;
                cout << "\nQuantos elementos voce quer na sua nova lista? ";
                cin >> elementos;

                for(int i = 1; i <= elementos; i++){
                    int valor;
                    cout << "\nDigite o elemento de numero " << i << ":" << endl;
                    cin >> valor; 
                    lst->push_back(valor);
                }

                cout << "\nA lista que sera concatenada: ";
                lst->print();

                lista->concat(lst);
                cout << "\nA lista resultante: ";
                lista->print();
            }
                break;
            case 15: {
                // List *copy(): Retorna um ponteiro para uma copia desta lista.
                cout << "A lista e: ";
                lista->print();
                cout << "A copia da lista ->: ";
                (lista->copy())->print();
            }
                break;
            case 16: {
                /* void copyArray(int n, int arr[]): Copia os elementos do array arr para a
                lista. O array arr tem n elementos. Todos os elementos anteriores da lista sao
                mantidos e os elementos do array arr devem ser adicionados apos os elementos
                originais. */
                int tamanho = 5;
                int v[] = {27,28,29,30,31};
                lista->copyArray(tamanho, v);
                cout << "A nova lista ->: ";
                lista->print();
            }
                break;
            case 17: {
                /* bool equal(List *lst): Determina se a lista passada por parametro e igual a
                lista em questao. Duas listas sao iguais se elas possuem o mesmo tamanho e o valor
                do k-esimo elemento da primeira lista e igual ao k-esimo elemento da segunda lista */
                
                List *lista2 = new List();
                for(int i = 1; i <= 5; i++)
                    lista2->push_back(i);

                cout << "\nA sua lista atual eh: ";
                lista->print();
                cout << "A lista que sera comparada: ";
                lista2->print();

                if (lista->equal(lista2)){
                    cout << "\nSao iguais!" << endl;
                }else{
                    cout << "\nSao diferentes!" << endl;
                }
            }
                break;
            case 18: {
                /*List separate(int n): Recebe como parametro um valor inteiro n e divide a
                lista em duas, de forma a segunda lista comecar no primeiro no logo apos a primeira
                ocorrencia de n na lista original. A funcao deve retornar um ponteiro para a segunda
                subdivisao da lista original, enquanto a cabeca da lista original deve continuar
                apontando para o primeiro elemento da primeira lista, caso ele nao tenha sido o
                primeiro a ter valor n*/
				int valor;
				cout<<"\tDigite o elemento separador: ";
				cin>>valor;
                lista->separate(valor)->print();
					
				//lista->print();

            }
                break;
            case 19: {
                /*void merge lists(List *list2): Recebe uma List como parametro e constroi
                uma nova lista com a intercalacao dos nos da lista original com os nos da lista
                passada por parametro. Ao final desta operacao, list2 deve ficar vazia.*/
                List *list2 = new List();
                int elementos;
                cout << "\nQuantos elementos voce quer na sua nova lista? ";
                cin >> elementos;

                for(int i = 1; i <= elementos; i++){
                    int valor;
                    cout << "\nDigite o elemento de numero " << i << ":" << endl;
                    cin >> valor; 
                    list2->push_back(valor);
                }
                cout << "A lista que sera misturada eh: ";
                list2->print();
                lista->merge_lists(list2);
                cout << "A lista resultante eh: ";
                lista->print();
            }
                break;
            default:
                cout << "Entrada invalida, Informe novamente!" << endl;
                break;           
        }
    }while (escolha != 0);
}