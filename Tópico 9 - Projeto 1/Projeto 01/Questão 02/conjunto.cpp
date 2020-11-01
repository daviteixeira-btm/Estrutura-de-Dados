/*-----------------------------------------------------
|    Autores: Aline Araujo Souza  | Matrícula: 473383 |
|             Davi Teixeira Silva | Matrícula: 433951 |
------------------------------------------------------*/

#include <iostream>
#include <climits>

#include "stdlib.h"
#include "conjunto.h"

using namespace std;

// Construtor supõe que n > 0
Conjunto::Conjunto(int capacidade){
	vetor = new int[capacidade];
    tamanho = 0;
    this->capacidade = capacidade;
    if (vetor == NULL) {
        cout << "Memoria insuficiente" << endl;
        return ;
    }
}

// Destrutor
Conjunto::~Conjunto(){
    if(vetor != NULL){ //se le apontar para uma região de memoria valida
        delete[] vetor;
    }
}

/* Ela vai adicionar um novo elemento ao final do conjunto, caso seja atingido o limite,
 a função realoca mais memória e aumenta a capacidade do conjunto de acordo com a quantidade de elementos passados*/

bool Conjunto::insere(int y){
	if(membro(y)){
		return false;
	}else{
		if(tamanho < capacidade){
			vetor[tamanho] = y;
			tamanho++;
			capacidade++;
			return true;
		}else{
			vetor = (int *) realloc(vetor, sizeof(int)*capacidade);
			tamanho++;
            vetor[tamanho] = y;
            return true;
		}
	}
	return false;
}

/* Remove do conjunto o inteiro y, e puxa os valores das posições posteriores do valor removido */

bool Conjunto::remove(int y){
	if(membro(y)){
    	for(int i = 0; i < tamanho; i++){
            if(vetor[i] == y){
            	for(int j = i+1; j < tamanho; j++){
                    vetor[j-1] = vetor[j];
                }
                
				tamanho--;
                return true;
            } 
        }
        	return false;
    }else{
        return false;
	}
}

//  Recebe um elemento y e retorna um 1 se y pertence ao conjunto passado e 0 caso contrário. 
bool Conjunto::membro(int y){
	for(int i = 0; i < tamanho; i++){
    	if(vetor[i] == y){
        	return true;
        }  
    }
    return false;  
}

//  Recebe um elemento y e retorna um 0 se y pertence ao conjunto passado e 1 caso contrário. 
bool Conjunto::nao_membro(int y){
	for(int i = 0; i < tamanho; i++){
    	if(vetor[i] == y){
        	return false;
        }  
    }
    return true;  
}

/* Verifica  todos os elementos do conjunto passado, com a função membro(), 
depois verifica se o elemento já existe no conjunto principal, senão insere o elemento. */

void Conjunto::uniao(Conjunto &conj){
    for(int j = 0; j < conj.tamanho; j++){
        if(!(membro(conj.vetor[j]))){
            insere(conj.vetor[j]);
        }
    }
}

/*Usa a função membro() verificando se o valor passado é membro dos dois conjuntos, se sim, adiciona ao vetor temporário.*/

void Conjunto::interseccao(Conjunto &conj){

	int *temporario = new int[tamanho];

	for(int l = 0; l < tamanho; l++) {
    	temporario[l] = 0;
	}
  
	if(conj.tamanho == 0){
    	this->tamanho = 0;
	}
  
	for (int i = 0; i < tamanho; i++){
		if((conj.membro(vetor[i]))){
    		temporario[i] = vetor[i];
    	}
	}
  
	for(int i = 0; i < tamanho; i++){
		vetor[i] = temporario[i];
	}
	delete[] temporario;
}

// Apenas printa os elementos do conjunto passado.
void Conjunto::print(){
    for(int i = 0; i < tamanho; i++)
        cout << "(i)[" << i << "]:" << vetor[i] << " ";
    cout << endl;
}

/* Depois de selecionado o conjunto, é chamada a função membro(), 
para certificar que o valor pertence ao conjunto, ao encontrar a 
posição correspondente ao valor que quer remover , modifica as posições, 
e diminui o tamanho do conjunto.*/
void Conjunto::diferenca(Conjunto &conj){

	int *temporario = new int[tamanho];     // vetor temporario de tamanho zero

	for(int l = 0; l < tamanho; l++) {      // zera todo o vetor
    	temporario[l] = 0;
	}
  
	if(conj.tamanho == 0){                  // conferir
    	this->tamanho = 0;
	}
  
	for (int i = 0; i < tamanho; i++){      // se o valor estiver contido no conj principal   
		if((conj.nao_membro(vetor[i]))){
    		temporario[i] = vetor[i];       // o vetor temporario recebe esse valor
    	}
	}
  
	for(int i = 0; i < tamanho; i++){       // for que mostra o reajuste de valores
		vetor[i] = temporario[i];
	}
}

// Retorna o valor mínimo do conjunto escolhido
int Conjunto::min(Conjunto &conj){

    int menor_valor = conj.vetor[0];

    for(int i = 1; i < tamanho; i++){
        if(conj.vetor[i] <= menor_valor){
            menor_valor = vetor[i];
        }
    }

    for(int i = 0; i < tamanho; i++){
        if(conj.vetor[i] == menor_valor){
            return menor_valor;
        }
    }
	return tamanho;
}

// retorna o valor maximo do conjunto escolhido
int Conjunto::max(Conjunto &conj){

    int maior_valor = conj.vetor[0];

    for(int i = 1; i < tamanho; i++){
        if(conj.vetor[i] >= maior_valor){
            maior_valor = vetor[i];
        }
    }

    for(int i = 0; i < tamanho; i++){
        if(conj.vetor[i] == maior_valor){
            return maior_valor;
        }
    }
	return tamanho;
}

/* Retorna true se os conjuntos A e B são iguais e false caso contrário, 
passando assim por vários testes para saber se os valores são iguais usando a função membro(). */
bool Conjunto::igual(Conjunto &conj){
	for(int i = 0; i < tamanho; i++){
    	if(membro(conj.vetor[i])){
        	return true;
        }
    }
    return false;
}

// Copia todos os elementos do conjunto principal para o secundário.
void Conjunto::copia(Conjunto &conj){
    for(int i = 0; i < conj.tamanho; i++)
        insere(conj.vetor[i]);                     // usamos a função insere para add os elementos do conjunto principal no conjunto secundario.
    cout << "\nConjunto copiado." << endl;
}

// Infelizmente a equipe não concluiu a implementação a tempo para a entrega do trabalho.
void Conjunto::diferencaSimetrica(Conjunto &conj){

	int *temporario = new int[tamanho];

	for(int l = 0; l < tamanho; l++) {
    	temporario[l] = 0;
	}
  
	if(conj.tamanho == 0){
    	this->tamanho = 0;
	}
  
	for (int i = 0; i < tamanho; i++){
		if((conj.membro(vetor[i]))){
    		temporario[i] = vetor[i];
    	}
	}
  
	for(int i = 0; i < tamanho; i++){
		vetor[i] = temporario[i];
	}
}