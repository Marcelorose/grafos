// Grafos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include "grafoLista.h"
#include "grafoMatriz.h"
#include "vertice.h"
#include <vector>
#include <locale.h>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");

	GrafoMatriz gr = GrafoMatriz(true, false);

	gr.inserirVertice("A"); // 0
	gr.inserirVertice("B"); // 1
	gr.inserirVertice("C"); // 2
	gr.inserirVertice("D"); // 3
	gr.inserirVertice("E"); // 4

	gr.inserirAresta(0, 1);
	gr.inserirAresta(0, 3);
	gr.inserirAresta(1, 3);
	gr.inserirAresta(3, 4);
	gr.inserirAresta(4, 1);
	gr.inserirAresta(1, 2);
	gr.inserirAresta(2, 4);

	cout << gr.welsh_e_powell();

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