// Grafos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include "grafoLista.h"
#include "grafoMatriz.h"
#include "grafoArquivo.h"
#include <vector>
#include <locale.h>
#include <iostream>
#include <stack>
#include <chrono>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");


	
	GrafoMatriz gr = criarGrafoArquivo <GrafoMatriz>("Grafos/GrafosMST/50vertices25%Arestas.txt");

	auto inicio = std::chrono::high_resolution_clock::now();
	cout << gr.prim();
	auto resultado = std::chrono::high_resolution_clock::now() - inicio;

	long long milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(resultado).count();

	cout << endl << "Tempo de execucao: " << milliseconds;

	/*GrafoLista gl = GrafoLista(false, true);

	gl.inserirVertice("A"); //0
	gl.inserirVertice("B"); //1
	gl.inserirVertice("C"); //2
	gl.inserirVertice("D"); //3
	gl.inserirVertice("E"); //4
	gl.inserirVertice("F"); //5

	gl.inserirAresta(0, 2, 7);
	gl.inserirAresta(0, 4, 10);
	gl.inserirAresta(0, 3, 2);
	gl.inserirAresta(4, 2, 9);
	gl.inserirAresta(4, 3, 7);
	gl.inserirAresta(4, 5, 8);
	gl.inserirAresta(5, 1, 2);
	gl.inserirAresta(5, 2, 3);
	gl.inserirAresta(5, 3, 4);
	gl.inserirAresta(2, 1, 3);

	gl.kruskal();*/

	/*vector<int> distancia;
	distancia = gr.dijkstra(true, 0);

	cout << "Distancia dos vertices para a origem" << endl;

	for (int i = 0; i < distancia.size(); i++)
	{
		cout << " | " << distancia.at(i);
	}

	cout << " | ";

	vector<int> anterior;
	anterior = gr.dijkstra(false, 0);

	cout << endl << endl << "Vertice Anterior (Vertices que possuem -1 como anterior e porque nao possuem um anterior)" << endl;

	for (int i = 0; i < anterior.size(); i++)
	{
		cout << " | " << anterior.at(i);
	}

	cout << " | " << endl;*/


	return 0;
}