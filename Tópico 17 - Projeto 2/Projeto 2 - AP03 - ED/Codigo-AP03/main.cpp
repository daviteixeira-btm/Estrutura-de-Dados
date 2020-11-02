/*-----------------------------------------------------
|    Autores: Aline Araujo Souza  | Matrícula: 473383 |
|             Davi Teixeira Silva | Matrícula: 433951 |
------------------------------------------------------*/

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <chrono>

#include "ordenacaoVetor.h"
#include "gerardados.h"

using namespace std;

// Funcao Principal
int main(){ 
	// Os tamanhos dos vetores a serem testados estao
	// guardados neste vetor 'tam'
	const int tam[] = {500,1000,2000,3000,4000,5000,6000,7000,8000,9000,
	10000,11000,12000,13000,14000,15000,16000,17000,18000,19000,20000};
	
	int TOTAL_N = sizeof(tam)/sizeof(tam[0]); // determina tamanho do vetor 'tam'
	
	// Etapa 1: Gerar arquivos contendo numeros aleatorios
	gera_dados(TOTAL_N, tam);
	
	//-------------------------------------------------------------
	// Etapa 2 - Execucao do CocktailSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	
	std::ofstream ofs("resultados/resultadoCocktail.txt", std::ofstream::out); // abre arquivo de resultados do cocktail
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
		
		long double duracao_media_cocktail = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o cocktail sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++){	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// CocktailSort ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();
		
			CocktailSort(tamanho_vetor, vetor); // ordena o vetor usando o CocktailSort
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_cocktail = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_cocktail += duracao_cocktail;
			
		}
		
		duracao_media_cocktail = duracao_media_cocktail / 5.0;
		cout << "[Cocktail] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_cocktail << " microssegundos" << endl;
		ofs << tamanho_vetor << " " << duracao_media_cocktail << "\n"; // grava no arquivo de resultados do cocktail
	}
	
	ofs.close(); // fecha arquivo de resultados do CockTail Sort
	// ------------------------------------------------------------
	
	// ------------------------------------------------------------
	// Etapa 3 - Execução do BubbleSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	
	std::ofstream ofs2("resultados/resultadoBubble.txt", std::ofstream::out ); // abre arquivo de resultados do bubblesort
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_bubble = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o bubblesort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++){	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// BubbleSort ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = std::chrono::high_resolution_clock::now();
		
			BubbleSort(tamanho_vetor, vetor); // ordena o vetor usando o BubbleSort
		
			// obtendo o tempo final
			auto fim2 = std::chrono::high_resolution_clock::now();
		
			// obtendo a duracao total da ordenacao
			auto duracao_bubble = std::chrono::duration_cast<std::chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_bubble += duracao_bubble;			
		}	
		
		duracao_media_bubble = duracao_media_bubble / 5.0;
		cout << "[Bubble] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_bubble << " microssegundos" << endl;
		ofs2 << tamanho_vetor << " " << duracao_media_bubble << "\n"; // grava no arquivo de resultados do bubble
	}
	
	ofs2.close(); // fecha arquivo de resultados do Bubble Sort
	// ------------------------------------------------------------
	
	//-------------------------------------------------------------
	// Etapa 3 - Execucao do InsertionSort - Iterativo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
		
	std::ofstream ofs3("resultados/resultadoInsertionSort_Iterativo.txt", std::ofstream::out); // abre arquivo de resultados do InsertionSort Iterativo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
		
		long double duracao_media_InsertionSort_Iterativo = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o InsertionSort Iterativo para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++){	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// InsertionSort Iterativo ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();
		
			iterativo_InsertionSort(vetor, tamanho_vetor); // ordena o vetor usando o IsertionSort Iterativo
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_InsertionSort_Iterativo = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_InsertionSort_Iterativo += duracao_InsertionSort_Iterativo;
			
		}
		
		duracao_media_InsertionSort_Iterativo = duracao_media_InsertionSort_Iterativo / 5.0;
		cout << "[InsertionSort_Iterativo] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_InsertionSort_Iterativo << " microssegundos" << endl;
		ofs3 << tamanho_vetor << " " << duracao_media_InsertionSort_Iterativo << "\n"; // grava no arquivo de resultados do InsertionSort Interativo
	}
	
	ofs3.close(); // fecha arquivo de resultados do InsertionSort Iterativo
	
	//-------------------------------------------------------------

	//-------------------------------------------------------------
	// Etapa 4 - Execucao do InsertionSort - Recursivo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	
	std::ofstream ofs4("resultados/resultadoInsertionSort_Recursivo.txt", std::ofstream::out); // abre arquivo de resultados do InsertionSort Recursivo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
		
		long double duracao_media_InsertionSort_Recursivo = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o InsertionSort Recursivo para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++){	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// InsertionSort Recursivo ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();
		
			recursivo_InsertionSort(vetor, tamanho_vetor); // ordena o vetor usando o IsertionSort Recursivo
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_InsertionSort_Recursivo = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_InsertionSort_Recursivo += duracao_InsertionSort_Recursivo;
			
		}
		
		duracao_media_InsertionSort_Recursivo = duracao_media_InsertionSort_Recursivo / 5.0;
		cout << "[InsertionSort_Recursivo] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_InsertionSort_Recursivo << " microssegundos" << endl;
		ofs4 << tamanho_vetor << " " << duracao_media_InsertionSort_Recursivo << "\n"; // grava no arquivo de resultados do InsertionSort Recursivo
	}
	
	ofs4.close(); // fecha arquivo de resultados do InsertionSort Recursivo
	
	//-------------------------------------------------------------
	
	//-------------------------------------------------------------
	// Etapa 5 - Execucao do SelectionSort - Iterativo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	
	std::ofstream ofs5("resultados/resultadoSelectionSort_Iterativo.txt", std::ofstream::out); // abre arquivo de resultados do SelectionSort Iterativo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
		
		long double duracao_media_SelectionSort_Iterativo = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o SelectionSort Iterativo para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++){	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// SelectionSort Iterativo ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();
		
			iterativo_SelectionSort(vetor, tamanho_vetor); // ordena o vetor usando o SelectionSort Iterativo
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_SelectionSort_Iterativo = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_SelectionSort_Iterativo += duracao_SelectionSort_Iterativo;
			
		}
		
		duracao_media_SelectionSort_Iterativo = duracao_media_SelectionSort_Iterativo / 5.0;
		cout << "[SelectionSort_Iterativo] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_SelectionSort_Iterativo << " microssegundos" << endl;
		ofs5 << tamanho_vetor << " " << duracao_media_SelectionSort_Iterativo << "\n"; // grava no arquivo de resultados do SelectionSort Iterativo
	}
	
	ofs5.close(); // fecha arquivo de resultados do SelectionSort Iterativo
	
	//-------------------------------------------------------------

	//-------------------------------------------------------------
	// Etapa 6 - Execucao do SelectionSort - Recursivo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	
	std::ofstream ofs6("resultados/resultadoSelectionSort_Recursivo.txt", std::ofstream::out); // abre arquivo de resultados do SelectionSort Recursivo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
		
		long double duracao_media_SelectionSort_Recursivo = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o SelectionSort Recursivo para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++){	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// SelectionSort Recursivo ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();
		
			recursivo_SelectionSort(vetor, tamanho_vetor); // ordena o vetor usando o SelectionSort Recursivo
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_SelectionSort_Recursivo = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_SelectionSort_Recursivo += duracao_SelectionSort_Recursivo;
			
		}
		
		duracao_media_SelectionSort_Recursivo = duracao_media_SelectionSort_Recursivo / 5.0;
		cout << "[SelectionSort_Recursivo] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_SelectionSort_Recursivo << " microssegundos" << endl;
		ofs6 << tamanho_vetor << " " << duracao_media_SelectionSort_Recursivo << "\n"; // grava no arquivo de resultados do SelectionSort Recursivo
	}
	
	ofs6.close(); // fecha arquivo de resultados do SelectionSort Recursivo
	
	//-------------------------------------------------------------

	//-------------------------------------------------------------
	// Etapa 7 - Execucao do MergeSort - Iterativo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	
	std::ofstream ofs7("resultados/resultadoMergeSort_Iterativo.txt", std::ofstream::out); // abre arquivo de resultados do MergeSort Interativo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
		
		long double duracao_media_MergeSort_Interativo = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o MergeSort Interativo para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++){	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// MergeSort_Interativo ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();
		
			iterativo_MergeSort(vetor, tamanho_vetor); // ordena o vetor usando o MergeSort Interativo
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_MergeSort_Interativo = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_MergeSort_Interativo += duracao_MergeSort_Interativo;
			
		}
		
		duracao_media_MergeSort_Interativo = duracao_media_MergeSort_Interativo / 5.0;
		cout << "[MergeSort_Interativo] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_MergeSort_Interativo << " microssegundos" << endl;
		ofs7 << tamanho_vetor << " " << duracao_media_MergeSort_Interativo << "\n"; // grava no arquivo de resultados do MergeSort Interativo
	}
	
	ofs7.close(); // fecha arquivo de resultados do MergeSort Interativo
	
	//-------------------------------------------------------------

	//-------------------------------------------------------------
	// Etapa 8 - Execucao do MergeSort - Recursivo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	
	std::ofstream ofs8("resultados/resultadoMergeSort_Recursivo.txt", std::ofstream::out); // abre arquivo de resultados do MergeSort Recursivo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
		
		long double duracao_media_MergeSort_Recursivo = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o MergeSort Recursivo para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++){	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// MergeSort Recursivo ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();
		
			recursivo_MergeSort(vetor, 0, tamanho_vetor); // ordena o vetor usando o MergeSort Recursivo
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_MergeSort_Recursivo = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_MergeSort_Recursivo += duracao_MergeSort_Recursivo;
			
		}
		
		duracao_media_MergeSort_Recursivo = duracao_media_MergeSort_Recursivo / 5.0;
		cout << "[MergeSort_Recursivo] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_MergeSort_Recursivo << " microssegundos" << endl;
		ofs8 << tamanho_vetor << " " << duracao_media_MergeSort_Recursivo << "\n"; // grava no arquivo de resultados do MergeSort Recursivo
	}
	
	ofs8.close(); // fecha arquivo de resultados do MergeSort Recursivo
	
	//-------------------------------------------------------------

	//-------------------------------------------------------------
	// Etapa 9 - Execucao do QuickSort - Iterativo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	
	std::ofstream ofs9("resultados/resultadoQuickSort_Iterativo.txt", std::ofstream::out); // abre arquivo de resultados do QuickSort Iterativo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
		
		long double duracao_media_QuickSort_Iterativo = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o QuickSort Iterativo para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++){	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// QuickSort Iterativo ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();
		
			iterativo_QuickSort(vetor, 0, tamanho_vetor); // ordena o vetor usando o QuickSort Iterativo
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_QuickSort_Iterativo = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_QuickSort_Iterativo += duracao_QuickSort_Iterativo;
			
		}
		
		duracao_media_QuickSort_Iterativo = duracao_media_QuickSort_Iterativo / 5.0;
		cout << "[QuickSort_Iterativo] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_QuickSort_Iterativo << " microssegundos" << endl;
		ofs9 << tamanho_vetor << " " << duracao_media_QuickSort_Iterativo << "\n"; // grava no arquivo de resultados do QuickSort Iterativo
	}
	
	ofs9.close(); // fecha arquivo de resultados do QuickSort Iterativo
	
	//-------------------------------------------------------------

	//-------------------------------------------------------------
	// Etapa 10 - Execucao do QuickSort - Recursivo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.

	std::ofstream ofs10("resultados/resultadoQuickSort_Recursivo.txt", std::ofstream::out); // abre arquivo de resultados do QuickSort Recursivo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
		
		long double duracao_media_QuickSort_Recursivo = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o QuickSort Recursivo para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++){	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// QuickSort Recursivo ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();
		
			recursivo_QuickSort(vetor, 0, tamanho_vetor); // ordena o vetor usando o QuickSort Iterativo
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_QuickSort_Recursivo = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_QuickSort_Recursivo += duracao_QuickSort_Recursivo;
			
		}
		
		duracao_media_QuickSort_Recursivo = duracao_media_QuickSort_Recursivo / 5.0;
		cout << "[QuickSort_Recursivo] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_QuickSort_Recursivo << " microssegundos" << endl;
		ofs10 << tamanho_vetor << " " << duracao_media_QuickSort_Recursivo << "\n"; // grava no arquivo de resultados do QuickSort Recursivo
	}
	
	ofs10.close(); // fecha arquivo de resultados do QuickSort Recursivo

	//-------------------------------------------------------------

	return 0;
}