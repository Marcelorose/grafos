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


	GrafoMatriz gr = criarGrafoArquivo <GrafoMatriz>("Grafos/trabalho-28cores.txt");

	cout << gr.welsh_e_powell();

	/*GrafoMatriz gm = new GrafoMatriz();

	gm.inserirVertice("A"); //0
	gm.inserirVertice("B"); //1
	gm.inserirVertice("C"); //2
	gm.inserirVertice("D"); //3
	gm.inserirVertice("E"); //4
	gm.inserirVertice("F"); //5
	gm.inserirVertice("G"); //6 
	gm.inserirVertice("H"); //7
	gm.inserirVertice("I"); //8
	gm.inserirVertice("J"); //9

	gm.inserirAresta(0, 1);
	gm.inserirAresta(1, 2);
	gm.inserirAresta(5, 1);
	gm.inserirAresta(5, 2);
	gm.inserirAresta(0, 3);
	gm.inserirAresta(9, 8);
	gm.inserirAresta(6, 3);
	gm.inserirAresta(0, 2);
	gm.inserirAresta(2, 4);
	gm.inserirAresta(0, 6);
	gm.inserirAresta(8, 4);
	gm.inserirAresta(8, 1);
	gm.inserirAresta(0, 9);
	gm.inserirAresta(7, 1);
	gm.inserirAresta(0, 1);
	gm.inserirAresta(6, 0);
	gm.inserirAresta(3, 5);
	gm.inserirAresta(6, 2);

	cout << gm.welsh_e_powell();*/

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