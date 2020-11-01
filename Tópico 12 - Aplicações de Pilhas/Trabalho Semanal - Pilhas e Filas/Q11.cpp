#include <iostream>
#include <queue>
#include <climits>

using namespace std;

void insert(queue<int> *principal, int x){
    principal->push(x);
}

void remove(queue<int> *principal, queue<int> *auxiliar){
    if(!principal->empty()){
        int n = principal->size();
        //pega todos (menos 1) os elementos da principal e manda para a auxiliar
        for(int i = 0; i < n-1; i++){
            int k = principal->front();
            principal->pop();
            auxiliar->push(k);
        }
        // salvo o ultimo elemento (o que vou retornar)
        int resposta = principal->front();
        //retiro o ultimo elemento
        principal->pop();
        while(!auxiliar->empty()){
            //pega o primeiro elemento do aux e add na principal.
            principal->push(auxiliar->front());
            auxiliar->pop();
        }
        return resposta;
    }else{
        return INT_MIN;
    }
}

int main(){
    queue<int> *f1;
    queue<int> *f2;

    //alocar
    f1 = new queue<int>;
    f2 = new queue<int>;

    int n, k;
    cout << "qtd: add: ";
    cin >> n;

    for(int i= 0; i < n; i++){
        cin >> k;
        insert(f1, k);
    }

    while(!f1->empty()){
        cout << "Removendo: " << remove(f1, f2) << ",";
    }
    cout << "\n";
}