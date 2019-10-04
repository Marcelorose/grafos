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

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");


	//GrafoLista gr = criarGrafoArquivo <GrafoLista>("Grafos/trabalho-28cores.txt");

	GrafoLista gr = GrafoLista(false, false);

	gr.inserirVertice("A");
	gr.inserirVertice("B");
	gr.inserirVertice("C");
	gr.inserirVertice("D");
	gr.inserirVertice("E");

	gr.inserirAresta(0, 1);
	gr.inserirAresta(0, 3);
	gr.inserirAresta(1, 4);
	gr.inserirAresta(1, 2);
	gr.inserirAresta(2, 4);
	gr.inserirAresta(3, 4);


	cout << gr.dsatur();



	cout << gr.welsh_e_powell();

	/*GrafoMatriz gm = new GrafoMatriz(1,0);

	gm.inserirVertice("A"); //0
	gm.inserirVertice("B"); //1
	gm.inserirVertice("C"); //2
	gm.inserirVertice("D"); //3
	gm.inserirVertice("E"); //4

	gm.inserirAresta(0, 1);
	gm.inserirAresta(0, 3);
	gm.inserirAresta(1, 4);
	gm.inserirAresta(1, 2);
	gm.inserirAresta(3, 4);
	gm.inserirAresta(4, 2);

	cout << gm.dsatur();*/

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